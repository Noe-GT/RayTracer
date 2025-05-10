/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material.hpp
*/
#pragma once
#include "Color.hpp"
#include "Noise.hpp"

class Material
{
    public:
        Material();
        Material(double reflectivity, double blurness, double transparency, double brightness, double refrectness, math::Color color);
        ~Material() = default;

        double &getReflectivity();
        double &getBlurness();
        double &getTransparency();
        double &getBrightness();
        double &getRefractness();
        math::Color &GetColor();

        friend std::ostream& operator<<(std::ostream& os, const Material& v);

    private:
        double _reflectivity;
        double _blurness;
        double _transparency;
        double _brightness;
        double _refractness;
        math::Color _color;
};