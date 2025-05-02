/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Parser
*/

#include "Parser.hpp"

rayTracer::Parser::Parser(rayTracer::PluginHandler &pluginHandler):
    _pluginHandler(pluginHandler)
{
}

rayTracer::Scene rayTracer::Parser::loadConfig(const std::string &filePath)
{
    rayTracer::Scene scene(this->_pluginHandler);

    try {
        config.readFile(filePath.c_str());
        // std::cout << "Configuration file loaded successfully: " << filePath << std::endl;
    } catch (const libconfig::FileIOException &fioex) {
        throw rayTracer::ConfigException("I/O error while reading file.");
    } catch (const libconfig::ParseException &pex) {
        throw rayTracer::ConfigException("Parse error at " + std::string(pex.getFile()) + ":" +
                                 std::to_string(pex.getLine()) + " - " + pex.getError());
    }
    if (config.exists("primitives"))
        this->parsePrimitives(scene);
    if (config.exists("camera"))
        this->parseCamera(scene);
    return scene;
}

void rayTracer::Parser::parsePrimitives(rayTracer::Scene &scene)
{
    const libconfig::Setting &primitives = config.lookup("primitives");
    const std::map<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> &pPlugins = this->_pluginHandler.getPrimitivePlugins();

    for (std::pair<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> pPair : pPlugins) {
        if (primitives.exists(pPair.first + "s")) {
            scene._obj.push_back(pPair.second.getFactory()->build());
            scene._obj.back()->configure(primitives[pPair.first + "s"]);
        }
    }
}

void rayTracer::Parser::parseCamera(rayTracer::Scene &scene)
{
    const libconfig::Setting &cameraConf = config.lookup("camera");

    // if (cameraConf.exists("resolution") &&
    //     cameraConf.exists("resolution.width") &&
    //     cameraConf.exists("resolution.height")) {
    //     scene._camera.setResolution(cameraConf["resolution"]["width"], cameraConf["resolution"]["height"]);
    // }
    try {
        if (cameraConf.exists("position")) {
            const libconfig::Setting &posConf = cameraConf.lookup("position");
            if (posConf.exists("x") && posConf.exists("y") && posConf.exists("z")) {
                scene._camera.setPosition(math::Point(
                    static_cast<double>(static_cast<int>(posConf["x"])),
                    static_cast<double>(static_cast<int>(posConf["y"])),
                    static_cast<double>(static_cast<int>(posConf["z"]))));
            }
        }
        if (cameraConf.exists("fieldOfView")) {
            scene._camera.setFov(cameraConf["fieldOfView"]);
        }
    } catch (const libconfig::SettingTypeException &tex) {
        throw rayTracer::ConfigException("Invalid type for camera configuration: " + std::string(tex.what()));
    }
}
