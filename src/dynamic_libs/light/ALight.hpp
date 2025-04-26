/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ALight
*/

#ifndef ALIGHT_HPP_
#define ALIGHT_HPP_

#include "ILight.hpp"

namespace light {
    class ALight : public light::ILight {
        public:
            ALight();
            ALight(math::Point origin);
            ALight(math::Point origin, math::Color color);
            ~ALight() = default;

            const math::Color &getColor() const;
            void setColor(const math::Color &color);

        protected:
            math::Point _origin;
            math::Color _color;
    };
};

#endif /* !ALIGHT_HPP_ */
