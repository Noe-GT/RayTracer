/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include "shared/include/Ray.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
        return 84;
    std::string input_filename = argv[1];
    if (input_filename.compare("-h") == 0 || input_filename.compare("-help") == 0) {
        std::cerr << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n";
        return 1;
    }
    int image_width = 256;
    int image_height = 256;
    std::string output_filename = input_filename.substr(0, input_filename.find_last_of('.')) + ".ppm";
    std::ofstream out_file(output_filename);
    out_file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            out_file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::cout << "Fichier généré: " << output_filename << "\n";

    Ray a(1,2,4);
    Ray b(30, 65, 1);
    b += a;
    std::cout << b << std::endl;
    return 0;
}