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
#include <vector>
#include <string>
#include <algorithm>

class Composite {
    public:
        Composite(std::shared_ptr<IPrimitive> primitive);
        Composite(std::shared_ptr<ITransformation<double>> transformation);
        ~Composite() = default;

        void addChild(Composite child);
        std::shared_ptr<IPrimitive> getPrimitive() const;
        std::shared_ptr<ITransformation<double>> getTransformation() const;
        const std::vector<Composite>& getChildren() const;
        bool isSameTransformation(const std::shared_ptr<ITransformation<double>>& other) const;
        
    private:
        std::shared_ptr<IPrimitive> _primitive;
        std::shared_ptr<ITransformation<double>> _transformation;
        std::vector<Composite> _children;
};