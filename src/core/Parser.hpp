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

namespace rayTracer {
    class Parser {
        public:
            Parser();
            ~Parser() = default;

            void loadConfig(const std::string &filePath);
            void parseCamera();
            void parsePrimitives();
            void parseLights();

        private:
            libconfig::Config config;
    };
};
