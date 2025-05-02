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
        config.readFile(filePath.c_str());
        if (config.exists("primitives"))
        this->parsePrimitives(rayTracer.getScene());
        if (config.exists("camera"))
            this->parseCamera(rayTracer.getScene());
    } catch (const libconfig::FileIOException &fioex) {
        throw rayTracer::ConfigException("I/O error while reading file.");
    } catch (const libconfig::ParseException &pex) {
        throw rayTracer::ConfigException("Parse error at " + std::string(pex.getFile()) + ":" +
            std::to_string(pex.getLine()) + " - " + pex.getError());
    }
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

void rayTracer::Parser::parseGraphical(rayTracer::RayTracer &rayTracer)
{
    (void) rayTracer;
    const libconfig::Setting &graphicals = config.lookup("graphical");
    const std::map<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> &gPlugins = this->_pluginHandler.getGraphicalPlugins();

    for (std::pair<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> gPair : gPlugins) {
        if (graphicals.exists(gPair.first)) {
            // scene._obj.push_back(gPair.second.getFactory()->build());
            // scene._obj.back()->configure(graphicals[gPair.first]);
            return;
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
}
