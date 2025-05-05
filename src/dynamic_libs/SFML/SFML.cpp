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
    this->_window.clear(sf::Color::Black);
}

SFML::~SFML()
{
}

void SFML::setSize(const std::pair<int, int> &size)
{
    this->_window.setSize(sf::Vector2u(size.first, size.second));
}

void SFML::drawPixel(size_t x, size_t y, const math::Color &color)
{
    (void)color;

    if (!this->_window.isOpen())
        return;
    this->handleEvents();
    sf::Color SFMLcolor(color._r * 255.999, color._g * 255.999, color._b * 255.999);
    sf::Vertex pixel(sf::Vector2f(x, y), SFMLcolor);
    this->_window.draw(&pixel, 1, sf::Points);
    this->_window.display();
}

void SFML::handleEvents()
{
    sf::Event event;
    while (this->_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
    }
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
