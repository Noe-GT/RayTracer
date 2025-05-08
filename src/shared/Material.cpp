/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material.cpp
*/

#include "Material.hpp"

Material::Material()
{
}

Material::Material(double reflectivity, double blurness, double transparency, double brightness, double refractness, math::Color color)
{
    this->_reflectivity = reflectivity;
    this->_blurness = blurness;
    this->_transparency = transparency;
    this->_brightness = brightness;
    this->_color = color;
    this->_refractness = refractness;
}

double &Material::getReflectivity()
{
    return this->_reflectivity;
}

double &Material::getBlurness()
{
    return this->_blurness;
}

double &Material::getTransparency()
{
    return this->_transparency;
}

double &Material::getBrightness()
{
    return this->_brightness;
}

math::Color &Material::GetColor()
{
    return this->_color;
}

double &Material::getRefractness()
{
    return this->_refractness;
}