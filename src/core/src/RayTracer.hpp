#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "../static_libs/math/Ray.hpp"
#include "DLLoader.hpp"
#include "PluginHandler.hpp"
#include "Parser.hpp"
#include "Scene.hpp"
#include "Pixel.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <vector>

namespace rayTracer {
    class RayTracer {
    public:
        RayTracer(std::string configfilePath);
        ~RayTracer();
        void render();
        void out();

    private:
        rayTracer::PluginHandler _pluginHandler;
        rayTracer::Parser _parser;
        Scene _scene;
        std::vector<std::vector<Pixel>> _image;
        std::string _confPath;
        std::string _outpath;
    };
}

#endif /* !RAYTRACER_HPP_ */