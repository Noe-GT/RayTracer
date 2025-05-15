/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** Composite
*/

#include "Composite.hpp"

Composite::Composite(std::shared_ptr<IPrimitive> primitive)
    : _primitive(primitive), _transformation(nullptr)
{
}

Composite::Composite(std::shared_ptr<ITransformation<double>> transformation)
    : _primitive(nullptr), _transformation(transformation)
{
}

void Composite::addChild(Composite child)
{
    _children.push_back(std::move(child));
}

std::shared_ptr<IPrimitive> Composite::getPrimitive() const
{
    return _primitive;
}

std::shared_ptr<ITransformation<double>> Composite::getTransformation() const
{
    return _transformation;
}

const std::vector<Composite>& Composite::getChildren() const
{
    return _children;
}


bool Composite::isSameTransformation(const std::shared_ptr<ITransformation<double>>& other) const
{
    if (this->_transformation == nullptr)
        return false;
    
    if (this->_transformation.get()->getName() != other.get()->getName())
        return false;
    if (this->_transformation.get()->getMatrix() != other.get()->getMatrix())
        return false;
    return true;
}
