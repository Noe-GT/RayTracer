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
        throw ArgumentsException("Invalid number of arguments");
    rayTracer::RayTracer tracer(600, 600, std::string(av[1]));

    // tracer.run();
}
