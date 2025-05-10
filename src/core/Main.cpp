/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Main
*/

#include "RayTracer.hpp"
#include "Exceptions.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        throw rayTracer::ArgumentsException("Invalid number of arguments");
    rayTracer::RayTracer tracer(av[1]);
    tracer.render();
    tracer.out();
}
