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
    if (ac != 2)
        throw rayTracer::ArgumentsException("Invalid number of arguments");
    rayTracer::RayTracer tracer(av[1]);
    tracer.render();
    tracer.out();
}
