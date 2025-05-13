/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene.hpp
*/
#pragma once

#include "Ray.hpp"
#include <string>
#include "IPrimitive.hpp"
#include "Camera.hpp"
#include "PluginHandler.hpp"
#include <vector>
#include <memory>

namespace rayTracer {
    class Scene {
        public:
            Scene(const PluginHandler &PluginHandler);
            ~Scene();

            math::Color _ambiantLightColor;
            double _ambiantLightIntensity;
            Camera _camera;
            std::vector<Composite> _obj; //TODO:  change type to use composite;
    };
};
