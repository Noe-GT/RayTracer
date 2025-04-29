#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "../static_libs/math/Ray.hpp"
#include "../dlloader/DLLoader.hpp"
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
        std::vector<std::vector<Pixel>> _image;
        std::string _confPath;
        std::string _outpath;
        Scene _scene;
    };
}

#endif /* !RAYTRACER_HPP_ */