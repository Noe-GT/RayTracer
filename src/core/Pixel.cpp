/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Pixel.cpp
*/

#include "Pixel.hpp"

rayTracer::Pixel::Pixel()
    : _colorMean(0, 0, 0)
{
}

rayTracer::Pixel::Pixel(int definition, int x, int y, int imageWidth, int imageHeight, const Scene& scene)
    : _x(x), _y(y)
{
    if (definition <= 0) throw std::invalid_argument("Definition must be > 0");

    _rays.reserve(definition);
    for (int i = 0; i < definition; i++) {
        double jitterX = (rand()/(double)RAND_MAX - 0.5);
        double jitterY = (rand()/(double)RAND_MAX - 0.5);

        math::Ray ray = scene._camera.generateRay(x + jitterX, y + jitterY, imageWidth, imageHeight);
        if (ray._direction.Length() < 0.0001) {
            throw std::runtime_error("Generated ray has zero direction");
        }

        _rays.push_back(ray);
    }
}

std::vector<std::shared_ptr<IPrimitive>> rayTracer::Pixel::getLights(const Scene &scene)
{
    std::vector<std::shared_ptr<IPrimitive>> lights;

    for (const Composite& obj : scene._composites) {
        parseComposite(obj, lights);
    }
    return lights;
}

void rayTracer::Pixel::parseComposite(const Composite& node, std::vector<std::shared_ptr<IPrimitive>>& lights)
{
    std::shared_ptr<IPrimitive> primitive = node.getPrimitive();
    if (primitive && primitive->getMaterial().getBrightness() > 0)
        lights.push_back(primitive);
    
    for (const auto& child : node.getChildren())
        parseComposite(child, lights);
}


void rayTracer::Pixel::simulateRays(const Scene& scene)
{
    std::vector<std::shared_ptr<IPrimitive>> lights = this->getLights(scene);
    if (_rays.empty())
        return;

    for (math::Ray &ray : this->_rays) {
        for (const Composite& composite : scene._composites) {
            if (processComposite(composite, ray, scene, lights))
                break;
        }

        ray._color = ray._color * scene._ambiantLightIntensity;
        ray._color += {
            (scene._ambiantLightColor._r * (1.0 - scene._ambiantLightIntensity)),
            (scene._ambiantLightColor._g * (1.0 - scene._ambiantLightIntensity)),
            (scene._ambiantLightColor._b * (1.0 - scene._ambiantLightIntensity))
        };
    }
    calculateMeanColor();
}



bool rayTracer::Pixel::processComposite(const Composite& composite, math::Ray& ray, const Scene& scene, std::vector<std::shared_ptr<IPrimitive>>& lights)
{
    auto primitive = composite.getPrimitive();
    auto transformation = composite.getTransformation();
    
    if (transformation) {
        math::Ray transformedRay = applyTransformation(ray, transformation->getMatrix());
        for (const auto& child : composite.getChildren())
            processComposite(child, transformedRay, scene, lights);
        if (transformedRay._color != ray._color)
            ray._color = transformedRay._color;
    } else if (primitive) {
        if (primitive->Intersect(ray, lights, scene.getPrimitives())) {
            return true;
        }
    }
    for (const auto& child : composite.getChildren())
        processComposite(child, ray, scene, lights);
    return false;
}

math::Ray rayTracer::Pixel::applyTransformation(const math::Ray& ray, const math::Matrix<double>& transformMatrix)
{
    math::Ray transformedRay = ray;
    math::Matrix<double> directionMatrix(1, 3);

    directionMatrix.setValue(1, 1, ray._direction._x);
    directionMatrix.setValue(1, 2, ray._direction._y);
    directionMatrix.setValue(1, 3, ray._direction._z);

    math::Matrix<double> resultMatrix = transformMatrix * directionMatrix;
    transformedRay._direction._x = resultMatrix.getMatrix()[0][0];
    transformedRay._direction._y = resultMatrix.getMatrix()[0][1];
    transformedRay._direction._z = resultMatrix.getMatrix()[0][2];

    std::cout << "Old Ray Direction: (" 
              << ray._direction._x << ", " 
              << ray._direction._y << ", " 
              << ray._direction._z << ")" << std::endl;
    std::cout << "New Ray Direction: (" 
              << transformedRay._direction._x << ", " 
              << transformedRay._direction._y << ", " 
              << transformedRay._direction._z << ")" << std::endl;
    
    transformedRay._direction.normalize();

    return transformedRay;
}

void rayTracer::Pixel::calculateMeanColor() {
    if (_rays.empty()) {
        _colorMean = math::Color(0, 0, 0);
        return;
    }

    _colorMean = {0, 0, 0};
    for (const math::Ray &ray : _rays) {
        _colorMean += ray._color;
    }
    _colorMean /= static_cast<double>(_rays.size());
}

const math::Color& rayTracer::Pixel::getColor() const
{
    return _colorMean;
}

std::pair<size_t, size_t> rayTracer::Pixel::getPos() const
{
    return std::pair<size_t, size_t>(this->_x, this->_y);
}
