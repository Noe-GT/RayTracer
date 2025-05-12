/*
** EPITECH PROJECT, 2025
** rayTracer
** File description:
** IConfigInterpreter
*/

#ifndef ICONFIGINTERPRETER_HPP_
#define ICONFIGINTERPRETER_HPP_

#include <libconfig.h++>
#include "External.hpp"

namespace rayTracer {
    class IConfigInterpreter {
        public:
            virtual ~IConfigInterpreter() = default;
    };
};

#endif /* !ICONFIGINTERPRETER_HPP_ */
