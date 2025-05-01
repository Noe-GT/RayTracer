/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Parser
*/

#include "Parser.hpp"

rayTracer::Parser::Parser()
{
}

void rayTracer::Parser::loadConfig(const std::string &filePath)
{
    try {
        config.readFile(filePath.c_str());
        std::cout << "Configuration file loaded successfully: " << filePath << std::endl;
    } catch (const libconfig::FileIOException &fioex) {
        throw std::runtime_error("I/O error while reading file.");
    } catch (const libconfig::ParseException &pex) {
        throw std::runtime_error("Parse error at " + std::string(pex.getFile()) + ":" +
                                 std::to_string(pex.getLine()) + " - " + pex.getError());
    }
    this->parseCamera();
    this->parsePrimitives();
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

void rayTracer::Parser::parsePrimitives()
{
    try {
        const libconfig::Setting &primitives = config.lookup("primitives");

        const libconfig::Setting &spheres = primitives["spheres"];
        for (int i = 0; i < spheres.getLength(); ++i) {
            const libconfig::Setting &sphere = spheres[i];
            int x = sphere["x"];
            int y = sphere["y"];
            int z = sphere["z"];
            int r = sphere["r"];
            const libconfig::Setting &color = sphere["color"];
            int rColor = color["r"];
            int gColor = color["g"];
            int bColor = color["b"];
            std::cout << "Sphere: position=(" << x << ", " << y << ", " << z << "), radius=" << r
                      << ", color=(" << rColor << ", " << gColor << ", " << bColor << ")" << std::endl;
        }

        const libconfig::Setting &planes = primitives["planes"];
        for (int i = 0; i < planes.getLength(); ++i) {
            const libconfig::Setting &plane = planes[i];
            std::string axis = plane["axis"];
            float position = plane["position"];
            const libconfig::Setting &color = plane["color"];
            int rColor = color["r"];
            int gColor = color["g"];
            int bColor = color["b"];
            std::cout << "Plane: axis=" << axis << ", position=" << position
                      << ", color=(" << rColor << ", " << gColor << ", " << bColor << ")" << std::endl;
        }
    } catch (const libconfig::SettingNotFoundException &nfex) {
        throw std::runtime_error("Missing primitives configuration: " + std::string(nfex.getPath()));
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

