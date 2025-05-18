/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML(size_t width, size_t height):
    _window(sf::VideoMode(width, height), "RayTracer"),
    _displayChrono(std::chrono::steady_clock::now())
{
}

SFML::~SFML()
{
}

void SFML::drawPixel(size_t x, size_t y, const math::Color &color)
{
    sf::Color SFMLcolor(color._r * 255.999, color._g * 255.999, color._b * 255.999);
    sf::Vertex pixel(sf::Vector2f(x, y), SFMLcolor);
    this->_window.draw(&pixel, 1, sf::Points);
}

void SFML::display(std::vector<std::vector<math::Color>> image)
{
    if (!this->_window.isOpen())
        return;
    this->handleEvents();
    if (!this->doDisplay())
        return;
    this->_window.clear(sf::Color::Black);
    for (size_t y = 0; y < image.size(); ++y) {
        for (size_t x = 0; x < image[y].size(); ++x) {
            this->drawPixel(x, y, image[y][x]);
        }
    }
    this->_window.display();
    this->_displayChrono = std::chrono::steady_clock::now();
}

bool SFML::doDisplay() const
{
    return (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->_displayChrono).count() >= DISPLAY_INTERVALS);
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

void SFML::idle()
{
    this->_window.display();
    while (this->_window.isOpen())
        this->handleEvents();
}

bool SFML::isActive() const
{
    return (this->_window.isOpen());
}

std::shared_ptr<IGraphical> SFMLFactory::build()
{
    return std::make_shared<SFML>();
}

std::shared_ptr<IGraphical> SFMLFactory::build(size_t width, size_t height)
{
    return std::make_shared<SFML>(width, height);
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
