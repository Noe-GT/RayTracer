/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Composite
*/

#include "Composite.hpp"

Composite::Composite(IPrimitive &primitive): _primitive(std::make_unique<IPrimitive>(primitive)), _transformation(nullptr)
{
}

Composite::Composite(ITransformation<double> &transformation): _transformation(std::make_unique<ITransformation<double>>(transformation)), _primitive(nullptr)
{
}
