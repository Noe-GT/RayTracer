#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "math/Ray.hpp"
#include "../dlloader/DLLoader.hpp"
#include "External.hpp"
#include "IPrimitive.hpp"
#include "PluginHandler.hpp"
#include "Parser.hpp"

namespace rayTracer {
    class RayTracer {
    public:
        RayTracer(const double &_pictureH, const double &_pictureW, const std::string &configFile);
        ~RayTracer();
        void run();
        math::Color ray_color(const math::Ray& r);
        void loadPlugins();

    private:
        const double _pictureH;
        const double _pictureW;
        std::vector<std::unique_ptr<IPrimitive>> _plugins;
        rayTracer::PluginHandler _pluginHandler;
    };
}

#endif /* !RAYTRACER_HPP_ */