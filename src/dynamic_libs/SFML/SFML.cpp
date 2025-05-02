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

void SFML::setSize(const std::pair<int, int> &size)
{
    this->_window.setSize(sf::Vector2u(size.first, size.second));
}

void SFML::drawPixel(int x, int y, const math::Color &color)
{
    sf::Color SFMLcolor(color._r, color._g, color._b);
    sf::Vertex point(sf::Vector2f(x, y), SFMLcolor);

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
