/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Composite
*/

#pragma once
#include "IPrimitive.hpp"
#include "ITransformation.hpp"
#include <memory>


class Composite {
    public:
        Composite(IPrimitive &primitive);
        Composite(ITransformation<double> &transformation);
        ~Composite() = default;

    protected:
    private:
        const std::unique_ptr<IPrimitive> _primitive;
        const std::unique_ptr<ITransformation<double>> _transformation;
        std::vector<Composite> _children;
};
