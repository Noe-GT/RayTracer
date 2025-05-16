/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Parser
*/

#pragma once

#include <libconfig.h++>
#include <string>
#include <iostream>
#include "IFactory.hpp"
#include "PluginHandler.hpp"
#include "Scene.hpp"
#include "Exceptions.hpp"

namespace rayTracer {
    class RayTracer;

    class Parser {
        public:
            Parser(rayTracer::PluginHandler &pluginHandler);
            ~Parser() = default;

            void loadConfig(const std::string &filePath, rayTracer::RayTracer &rayTracer);

        private:
            void parsePrimitives(rayTracer::Scene &scene);
            void parseCamera(rayTracer::Scene &scene);
            void parseGraphical(rayTracer::RayTracer &rayTracer);
            void parseImage(rayTracer::RayTracer &rayTracer);
            std::unique_ptr<Composite> addTransformation(const libconfig::Setting &primitive,std::vector<Composite> &transformations);
            std::unique_ptr<Composite> createTransformation(const libconfig::Setting &primitive, const std::string &transformationType, std::vector<Composite> &transformations);
            bool hasTransformations(const libconfig::Setting &primitive);
            void parseProcessing(rayTracer::RayTracer &rayTracer);

            const rayTracer::PluginHandler &_pluginHandler;
            libconfig::Config config;
    };
};
