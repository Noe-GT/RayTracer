/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene.hpp
*/
#pragma once

#include "../static_libs/math/Ray.hpp"
#include <string>
#include "../../shared/IPrimitive.hpp"
#include "Camera.hpp"
#include <vector>
#include <memory>
namespace rayTracer {
    class Scene {
        public:
            Scene(std::string confPath);
            ~Scene();

            math::Color _ambiantLightColor;
            double _ambiantLightIntensity;
            Camera _camera;
            std::vector<std::unique_ptr<IPrimitive>> _obj; //TODO:  change type to use composite;
            std::vector<math::Point> _lightPoses;
        };
};
