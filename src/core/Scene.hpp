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
#include "Composite.hpp"
#include <vector>
#include <memory>

namespace rayTracer {
    class Scene {
        public:
            Scene(const PluginHandler &PluginHandler);
            ~Scene();

            void addComposite(const Composite &composite);
            int getNextId();
            const std::vector<Composite>& getComposites() const;
            const std::vector<std::shared_ptr<IPrimitive>> getPrimitives() const;

            math::Color _ambiantLightColor;
            double _ambiantLightIntensity;
            Camera _camera;
            std::vector<Composite> _composites;
            
        private:
            void parseCompositePrimitives(const Composite& composite, std::vector<std::shared_ptr<IPrimitive>>& primitives) const;
            int _nextId;
    };
};