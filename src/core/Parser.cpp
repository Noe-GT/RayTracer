/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Parser
*/

#include "Parser.hpp"
#include "RayTracer.hpp"

rayTracer::Parser::Parser(rayTracer::PluginHandler &pluginHandler):
    _pluginHandler(pluginHandler)
{
}

void rayTracer::Parser::loadConfig(const std::string &filePath, rayTracer::RayTracer &rayTracer)
{
    try {
        config.setOptions(libconfig::Config::OptionAutoConvert);
        config.readFile(filePath.c_str());
        this->parsePrimitives(rayTracer.getScene());
        this->parseCamera(rayTracer.getScene());
        this->parseProcessing(rayTracer);
        this->parseImage(rayTracer);
        this->parseGraphical(rayTracer);
    } catch (const libconfig::FileIOException &fioex) {
        throw rayTracer::ConfigException("Invalid config file.");
    } catch (const libconfig::ParseException &pex) {
        throw rayTracer::ConfigException("Parse error at " + std::string(pex.getFile()) + ":" +
            std::to_string(pex.getLine()) + " - " + pex.getError());
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void rayTracer::Parser::parsePrimitives(rayTracer::Scene &scene)
{
    const libconfig::Setting &primitives = config.lookup("primitives");
    const std::map<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> &pPlugins = this->_pluginHandler.getPrimitivePlugins();
    std::vector<Composite> transformations;

    for (std::pair<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> pPair : pPlugins) {
        if (primitives.exists(pPair.first + "s")) {
            libconfig::Setting &primitiveList = primitives.lookup(pPair.first + "s");
            for (int i = 0; i < primitiveList.getLength(); i++) {
                std::shared_ptr<IPrimitive> primitive = pPair.second.getFactory()->build();
                int id = scene.getNextId();
                primitive->configure(primitiveList[i], id);
                Composite primitiveComposite(primitive);
                
                if (hasTransformations(primitiveList[i])) {
                    std::unique_ptr<Composite> transformationComposite = 
                        addTransformation(scene, primitiveList[i], transformations);
                    if (transformationComposite) {
                        transformationComposite->addChild(primitiveComposite);
                        scene.addComposite(*transformationComposite);
                    } else
                        scene.addComposite(primitiveComposite);
                } else {
                    scene.addComposite(primitiveComposite);
                }
            }
        }
    }
}

void rayTracer::Parser::parseGraphical(rayTracer::RayTracer &rayTracer)
{
    const libconfig::Setting &graphicalConf = config.lookup("graphical");
    std::string libraryName = graphicalConf.lookup("library");
    const std::map<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> &gPlugins = this->_pluginHandler.getGraphicalPlugins();
    std::pair<size_t, size_t> res = rayTracer.getImageResolution();

    if (graphicalConf.exists("showRender"))
        rayTracer.setShowRender(graphicalConf["showRender"]);
    for (std::pair<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> gPair : gPlugins) {
        if (libraryName == gPair.first) {
            std::shared_ptr<IGraphical> graphical = gPair.second.getFactory()->build(res.first, res.second);
            rayTracer.setGraphical(graphical);
            return;
        }
    }
}

bool rayTracer::Parser::hasTransformations(const libconfig::Setting &primitive)
{
    const auto &transformationPlugins = this->_pluginHandler.getTransformationPlugins();
    for (const auto &plugin : transformationPlugins) {
        if (primitive.exists(plugin.first)) {
            return true;
        }
    }
    return false;
}

std::unique_ptr<Composite> rayTracer::Parser::addTransformation(rayTracer::Scene &scene, const libconfig::Setting &primitive,std::vector<Composite> &transformations)
{
    const auto &transformationPlugins = this->_pluginHandler.getTransformationPlugins();
    for (const auto &plugin : transformationPlugins) {
        if (primitive.exists(plugin.first)) {
            return createTransformation(scene, primitive, plugin.first, transformations);
        }
    }
    return nullptr;
}

std::unique_ptr<Composite> rayTracer::Parser::createTransformation(rayTracer::Scene &scene, const libconfig::Setting &primitive, const std::string &transformationType, std::vector<Composite> &transformations)
{
    (void)scene;
    const libconfig::Setting &transformationSetting = primitive.lookup(transformationType);
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    if (transformationSetting.exists("x"))
        x = transformationSetting["x"];
    if (transformationSetting.exists("y"))
        y = transformationSetting["y"];
    if (transformationSetting.exists("z"))
        z = transformationSetting["z"];
              
    const auto &plugins = this->_pluginHandler.getTransformationPlugins();
    auto it = plugins.find(transformationType);
    if (it != plugins.end()) {
        std::shared_ptr<ITransformation> transform = 
            it->second.getFactory()->build(x, y, z);
        for (auto &existing : transformations) {
            if (existing.isSameTransformation(transform))
                return std::make_unique<Composite>(existing);
        }
        Composite transformComposite(transform);
        transformations.push_back(transformComposite);
        return std::make_unique<Composite>(transformations.back());
    }
    return nullptr;
}

void rayTracer::Parser::parseImage(rayTracer::RayTracer &rayTracer)
{
    const libconfig::Setting &imgConf = config.lookup("image");
    int width = 0;
    int height = 0;

    if (imgConf.exists("resolution") && imgConf["resolution"].exists("width") && imgConf["resolution"].exists("height")) {
        width = imgConf["resolution"]["width"];
        height = imgConf["resolution"]["height"];
        if (width < 0)
            width = 0;
        if (height < 0)
            height = 0;
        rayTracer.setImage(std::pair<size_t, size_t>(width, height));
    }
    if (imgConf.exists("fileName"))
        rayTracer.setOutputFilePath(imgConf["fileName"]);
}

void rayTracer::Parser::parseCamera(rayTracer::Scene &scene)
{
    const libconfig::Setting &cameraConf = config.lookup("camera");

    try {
        const libconfig::Setting &posConf = cameraConf.lookup("position");
        scene._camera.setPosition(math::Point(posConf["x"], posConf["y"], posConf["z"]));
    } catch (const libconfig::SettingNotFoundException &e) {}
    if (cameraConf.exists("fieldOfView")) {
        scene._camera.setFov(cameraConf["fieldOfView"]);
    }
}

void rayTracer::Parser::parseProcessing(rayTracer::RayTracer &rayTracer)
{
    const libconfig::Setting &processConf = config.lookup("processing");
    int rayDefinition;

    if (processConf.exists("rayDefinition")) {
        rayDefinition = processConf["rayDefinition"];
        if (rayDefinition > 1)
            rayTracer.setRayDefinition(rayDefinition);
    }
}