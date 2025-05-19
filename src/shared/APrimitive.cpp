/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** rayTracer::APrimitive
*/

#include "APrimitive.hpp"

rayTracer::APrimitive::APrimitive():
    _origin(0, 0, -1)
{
}

int &rayTracer::APrimitive::getID()
{
    return this->_id;
}

Material &rayTracer::APrimitive::getMaterial()
{
    return this->_material;
}

math::Point &rayTracer::APrimitive::getOrigin()
{
    return this->_origin;
}

void rayTracer::APrimitive::configure(const libconfig::Setting &setting, int id)
{
    this->_id = id;
    double reflectivity = 0.0;
    double blurness = 0.0;
    double transparency = 0.0;
    double brightness = 0.0;
    double refractness = 0.0;
    math::Color color;

    if (setting.exists("material")) {
        if (setting["material"].exists("reflectivity")) {
            reflectivity = setting["material"]["reflectivity"];
            reflectivity = std::clamp(reflectivity, 0.0, 1.0);
        }
        if (setting["material"].exists("transparency")) {
            transparency = setting["material"]["transparency"];
            transparency = std::clamp(transparency, 0.0, 1.0);
        }
        if (setting["material"].exists("brightness")) {
            brightness = setting["material"]["brightness"];
            brightness = std::clamp(brightness, 0.0, 1.0);
        }
        if (setting["material"].exists("blurness"))
            blurness = setting["material"]["blurness"];
        if (setting["material"].exists("refractness"))
            refractness = setting["material"]["refractness"];
        if (setting["material"].exists("color") && setting["material"]["color"].exists("r") &&
            setting["material"]["color"].exists("g") &&
            setting["material"]["color"].exists("b"))
            color = math::Color(static_cast<double>(static_cast<int>(setting["material"]["color"]["r"])) / 255.999,
                static_cast<double>(static_cast<int>(setting["material"]["color"]["g"])) / 255.999,
                static_cast<double>(static_cast<int>(setting["material"]["color"]["b"])) / 255.999);
    }
    this->_material = Material(reflectivity, blurness, transparency, brightness, refractness, color);
}
