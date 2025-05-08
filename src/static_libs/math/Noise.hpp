/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Noise.hpp
*/

#pragma once

namespace math {
    class Noise {
        public:
            Noise();
            Noise(int seed);
            ~Noise();
            double getNoise(double x, double y, double z,
                double intensity = 1.0) const;
            double getNoiseFBM(double x, double y, double z, double intensity = 1.0,
                int octaves = 4, double lacunarity = 2.0,
                double persistence = 0.5) const;

            void setSeed(int seed);

        private:
            void generateGradients();
            double fade(double t) const;
            double lerp(double a, double b, double t) const;
            double dotGridGradient(int ix, int iy, int iz, double x, double y, double z) const;
            double perlin(double x, double y, double z) const;

            int _seed;
            double **_gradients;
            int _permutation[512];
    };
};
