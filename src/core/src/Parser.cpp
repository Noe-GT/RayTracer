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
    // (void) filePath;

    try {
        config.readFile(filePath.c_str());
        // std::cout << "Configuration file loaded successfully: " << filePath << std::endl;
    } catch (const libconfig::FileIOException &fioex) {
        throw std::runtime_error("I/O error while reading file.");
    } catch (const libconfig::ParseException &pex) {
        throw std::runtime_error("Parse error at " + std::string(pex.getFile()) + ":" +
                                 std::to_string(pex.getLine()) + " - " + pex.getError());
    }
    if (config.exists("primitives"))
        this->parsePrimitives(scene);
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

void rayTracer::Parser::parseCamera()
{
    try {
        const libconfig::Setting &camera = config.lookup("camera");
        const libconfig::Setting &resolution = camera["resolution"];

        int width = resolution["width"];
        int height = resolution["height"];
        std::cout << "Camera resolution: " << width << "x" << height << std::endl;

        const libconfig::Setting &position = camera["position"];
        int x = position["x"];
        int y = position["y"];
        int z = position["z"];
        std::cout << "Camera position: (" << x << ", " << y << ", " << z << ")" << std::endl;

        float fieldOfView = camera["fieldOfView"];
        std::cout << "Camera field of view: " << fieldOfView << " degrees" << std::endl;
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Missing camera configuration: " + std::string(nfex.getPath()));
    }
}

void rayTracer::Parser::parseLights()
{
    try {
        const libconfig::Setting &lights = config.lookup("lights");

        float ambient = lights["ambient"];
        float diffuse = lights["diffuse"];
        std::cout << "Lights: ambient=" << ambient << ", diffuse=" << diffuse << std::endl;

        const libconfig::Setting &pointLights = lights["point"];
        for (int i = 0; i < pointLights.getLength(); ++i) {
            const libconfig::Setting &point = pointLights[i];
            float x = point["x"];
            float y = point["y"];
            float z = point["z"];
            std::cout << "Point light: position=(" << x << ", " << y << ", " << z << ")" << std::endl;
        }

        // const libconfig::Setting &directionalLights = lights["directional"];
        // for (int i = 0; i < directionalLights.getLength(); ++i) {
        //     const libconfig::Setting &directional = directionalLights[i];
        // }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Missing lights configuration: " + std::string(nfex.getPath()));
    }
}

