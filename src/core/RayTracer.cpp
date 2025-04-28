#include "RayTracer.hpp"

rayTracer::RayTracer::RayTracer(const double &_pictureH,
    const double &_pictureW):
    _pictureH(_pictureH),
    _pictureW(_pictureW),
    _plugins(),
    _pluginHandler()
{
    // loadPlugins();
}

rayTracer::RayTracer::~RayTracer()
{
    _plugins.clear();
}

void rayTracer::RayTracer::run()
{
    auto viewHeight = 2.0;
    auto viewWidth = viewHeight * (double(this->_pictureW) / this->_pictureH);
    auto camPoint = math::Point(0, 0, 0);
    auto delta1 = math::Vector(viewWidth, 0, 0);
    auto delta2 = math::Vector(0, -viewHeight, 0);
    auto firstPixel = camPoint - math::Vector(0, 0, 1) - delta1 / 2 - delta2 / 2 + (delta1 / this->_pictureW + delta2 / this->_pictureH) / 2;
    std::cout << "P3\n" << this->_pictureW << " " << this->_pictureH << "\n255\n";

    for (int j = 0; j < this->_pictureH; j++) {
        for (int i = 0; i < this->_pictureW; i++) {
            auto pixel_center = firstPixel + (delta1 / this->_pictureW * i) + (delta2 / this->_pictureH * j);
            math::Point tmp = pixel_center - camPoint;
            math::Vector ray_direction(tmp._x, tmp._y, 1);
            math::Ray r(camPoint, ray_direction);
            math::Color pixel_color = this->ray_color(r);
            std::cout << pixel_color;
        }
    }
}

math::Color rayTracer::RayTracer::ray_color(const math::Ray &r)
{
    if (_plugins.empty()) {
        std::cerr << "Warning: No plugins loaded!" << std::endl;
        return math::Color(0, 0, 0);
    }

    for (auto &primitive : _plugins) {
        if (!primitive) {
            continue;
        }
        math::Ray rayCopy = r;
        if (primitive->Intersect(rayCopy)) {
            return math::Color(1, 1, 1);
        }
    }

    math::Vector unitDir(r._direction._x / r._direction.Length(), r._direction._y / r._direction.Length(), r._direction._z / r._direction.Length());
    auto a = 0.5 * (unitDir._y + 1.0);
    return math::Color(1.0, 1.0, 1.0) * (1.0 - a) + math::Color(0.5, 0.7, 1.0) * a;
}

void rayTracer::RayTracer::loadPlugins()
{
    try {
        DLLoader loader("./dynamic_libs_bin/Sphere.so");
        auto sphere = loader.getInstance<IPrimitive>("entryPoint");
        if (!sphere) {
            std::cerr << "Error: Failed to create sphere instance" << std::endl;
            return;
        }
        _plugins.push_back(std::move(sphere));
    } catch (const std::exception &e) {
        std::cerr << "Error loading plugin: " << e.what() << std::endl;
    }
}
