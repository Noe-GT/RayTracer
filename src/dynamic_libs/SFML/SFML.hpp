/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include "IGraphical.hpp"
#include "IFactory.hpp"
#include "PluginTypes.hpp"

class SFML : public IGraphical {
    public:
        SFML();
        ~SFML();

        void setSize(const std::pair<int, int> &size) final;
        void drawPixel(int x, int y, const math::Color &color) final;
    private:
        sf::RenderWindow _window;
};

class SFMLFactory: public rayTracer::IFactory<IGraphical> {
    public:
        SFMLFactory() = default;
        ~SFMLFactory() = default;

        std::shared_ptr<IGraphical> build() final;
};

#endif /* !SFML_HPP_ */
