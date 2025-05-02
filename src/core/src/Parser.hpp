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
#include <stdexcept>
#include "IFactory.hpp"
#include "PluginHandler.hpp"
#include "Scene.hpp"
#include "Exceptions.hpp"

namespace rayTracer {
    class Parser {
        public:
            Parser(rayTracer::PluginHandler &pluginHandler);
            ~Parser() = default;

            rayTracer::Scene loadConfig(const std::string &filePath);
            void parseCamera(rayTracer::Scene &scene);
            void parsePrimitives(rayTracer::Scene &scene);
            void parseLights();

        private:
            const rayTracer::PluginHandler &_pluginHandler;
            libconfig::Config config;
    };
};
