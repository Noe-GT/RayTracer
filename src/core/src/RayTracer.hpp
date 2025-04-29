#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "../static_libs/math/Ray.hpp"
#include "../dlloader/DLLoader.hpp"
#include "External.hpp"
#include "IPrimitive.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <vector>

namespace rayTracer {
    class RayTracer {
    public:
        RayTracer(const double &_pictureH, const double &_pictureW);
        ~RayTracer();
        void run();
        math::Color ray_color(const math::Ray& r);
        void loadPlugins();

    private:
        const double _pictureH;
        const double _pictureW;
        std::vector<std::unique_ptr<IPrimitive>> _plugins;
    };
}

#endif /* !RAYTRACER_HPP_ */