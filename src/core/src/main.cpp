/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** main.cpp
*/

#include "RayTracer.hpp"
#include "Exceptions.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Invalid number of arguments (is " << ac << " must be 2)" << std::endl;
        return 84;
    }
    try {
        rayTracer::RayTracer tracer(av[1]);
        tracer.render();
        tracer.out();
    } catch (const rayTracer::ConfigException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
