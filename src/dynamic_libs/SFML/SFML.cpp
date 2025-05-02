/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML():
    _window(sf::VideoMode(500, 500), "SFML")
{
    this->_window.display();
}

SFML::~SFML()
{
}

void SFML::setSize(int width, int height)
{
    this->_window.setSize(sf::Vector2u(width, height));
}

void SFML::drawPixel(int x, int y, int color)
{
    sf::Vertex point(sf::Vector2f(x, y), sf::Color(color));
    this->_window.draw(&point, 1, sf::Points);
    this->_window.display();
}

std::shared_ptr<IGraphical> SFMLFactory::build()
{
    return std::make_shared<SFML>();
}

extern "C"
{
    rayTracer::IFactory<IGraphical> *entryPoint()
    {
        return new SFMLFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::GRAPHICAL;
    }
}
