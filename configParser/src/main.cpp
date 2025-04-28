/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** main
*/

#include "Parser.hpp"

int main()
{
    Parser parser;

    try {
        parser.loadConfig("raytracer.cfg");
        parser.parseCamera();
        parser.parsePrimitives();
        parser.parseLights();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}