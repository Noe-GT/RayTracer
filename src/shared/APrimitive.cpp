/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

APrimitive::APrimitive():
    _origin(0, 0, -1)
{
}

int &APrimitive::getID()
{
    return this->_id;
}

Material &APrimitive::getMaterial()
{
    return this->_material;
}

math::Point &APrimitive::getOrigin()
{
    return this->_origin;
}

void APrimitive::configure(const libconfig::Setting &setting, int id)
{
    this->_id = id;
    double reflectivity = 0.0;
    double blurness = 0.0;
    double transparency = 0.0;
    double brightness = 0.0;
    double refractness = 0.0;
    math::Color color;

    if (setting.exists("material")) {
        if (setting["material"].exists("reflectivity"))
            reflectivity = setting["material"]["reflectivity"];
        if (setting["material"].exists("blurness"))
            blurness = setting["material"]["blurness"];
        if (setting["material"].exists("transparency"))
            transparency = setting["material"]["transparency"];
        if (setting["material"].exists("brightness"))
            brightness = setting["material"]["brightness"];
        if (setting["material"].exists("refractness"))
            refractness = setting["material"]["refractness"];
        if (setting["material"].exists("color") && setting["material"]["color"].exists("r") &&
            setting["material"]["color"].exists("g") &&
            setting["material"]["color"].exists("b"))
            color = math::Color(static_cast<double>(static_cast<int>(setting["material"]["color"]["r"])),
                static_cast<double>(static_cast<int>(setting["material"]["color"]["g"])),
                static_cast<double>(static_cast<int>(setting["material"]["color"]["b"])));
    }
    this->_material = Material(reflectivity, blurness, transparency, brightness, refractness, color);
}
