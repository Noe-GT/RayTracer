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
        SFML(size_t width = 100, size_t height = 100);
        virtual ~SFML();

        void display(std::vector<std::vector<math::Color>> image) final;
        void idle() final;

    private:
        void handleEvents();
        void drawPixel(size_t x, size_t y, const math::Color &color);

        sf::RenderWindow _window;
};

class SFMLFactory: public rayTracer::IFactory<IGraphical> {
    public:
        SFMLFactory() = default;
        ~SFMLFactory() = default;

        std::shared_ptr<IGraphical> build() final;
        std::shared_ptr<IGraphical> build(size_t width, size_t height) final;
};

#endif /* !SFML_HPP_ */
