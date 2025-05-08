/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Noise.cpp
*/

#include "Noise.hpp"
#include <cmath>
#include <random>
#include <algorithm>
#include <ctime>
math::Noise::Noise() : _seed(time(NULL)), _gradients(nullptr)
{
    generateGradients();
}

math::Noise::Noise(int seed) : _seed(seed), _gradients(nullptr)
{
    generateGradients();
}

math::Noise::~Noise()
{
    if (_gradients) {
        for (int i = 0; i < 256; i++)
            delete[] _gradients[i];
        delete[] _gradients;
    }
}

void math::Noise::generateGradients()
{
    std::mt19937 gen(_seed);
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    _gradients = new double*[256];
    for (int i = 0; i < 256; i++) {
        _gradients[i] = new double[3];
        double len;
        do {
            for (int j = 0; j < 3; j++)
                _gradients[i][j] = dist(gen);
            len = sqrt(_gradients[i][0] * _gradients[i][0] + _gradients[i][1] * _gradients[i][1] + _gradients[i][2] * _gradients[i][2]);
        } while (len < 0.0001);
        for (int j = 0; j < 3; j++)
            _gradients[i][j] /= len;
    }
    for (int i = 0; i < 256; i++)
        _permutation[i] = i;
    for (int i = 255; i > 0; i--) {
        std::uniform_int_distribution<int> intDist(0, i);
        int j = intDist(gen);
        std::swap(_permutation[i], _permutation[j]);
    }
    for (int i = 0; i < 256; i++)
        _permutation[i + 256] = _permutation[i];
}

double math::Noise::fade(double t) const
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

double math::Noise::dotGridGradient(int ix, int iy, int iz, double x, double y, double z) const
{
    int idx = _permutation[(_permutation[(_permutation[ix & 255] + iy) & 255] + iz) & 255];
    double dx = x - static_cast<double>(ix);
    double dy = y - static_cast<double>(iy);
    double dz = z - static_cast<double>(iz);
    return dx * _gradients[idx][0] + dy * _gradients[idx][1] + dz * _gradients[idx][2];
}

double math::Noise::lerp(double a, double b, double t) const
{
    return a + t * (b - a);
}

double math::Noise::perlin(double x, double y, double z) const
{
    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    int z0 = static_cast<int>(std::floor(z));
    double xf = x - x0;
    double yf = y - y0;
    double zf = z - z0;
    double u = fade(xf);
    double v = fade(yf);
    double w = fade(zf);
    double n000 = dotGridGradient(x0, y0, z0, x, y, z);
    double n001 = dotGridGradient(x0, y0, z0 + 1, x, y, z);
    double n010 = dotGridGradient(x0, y0 + 1, z0, x, y, z);
    double n011 = dotGridGradient(x0, y0 + 1, z0 + 1, x, y, z);
    double n100 = dotGridGradient(x0 + 1, y0, z0, x, y, z);
    double n101 = dotGridGradient(x0 + 1, y0, z0 + 1, x, y, z);
    double n110 = dotGridGradient(x0 + 1, y0 + 1, z0, x, y, z);
    double n111 = dotGridGradient(x0 + 1, y0 + 1, z0 + 1, x, y, z);
    double nx00 = lerp(n000, n100, u);
    double nx01 = lerp(n001, n101, u);
    double nx10 = lerp(n010, n110, u);
    double nx11 = lerp(n011, n111, u);
    double nxy0 = lerp(nx00, nx10, v);
    double nxy1 = lerp(nx01, nx11, v);
    double nxyz = lerp(nxy0, nxy1, w);
    return nxyz;
}

double math::Noise::getNoise(double x, double y, double z, double intensity) const
{
    intensity = std::max(0.0, std::min(1.0, intensity));
    if (intensity == 0.0) {
        return 0.0;
    }
    double raw = perlin(x, y, z);
    double normalized = (raw + 1.0) * 0.5;
    return 0.5 + (normalized - 0.5) * intensity;
}

double math::Noise::getNoiseFBM(double x, double y, double z, double intensity, int octaves, double lacunarity, double persistence) const
{
    intensity = std::max(0.0, std::min(1.0, intensity));

    if (intensity == 0.0 || octaves <= 0) {
        return 0.5;
    }
    double result = 0.0;
    double amplitude = 1.0;
    double frequency = 1.0;
    double totalAmplitude = 0.0;

    for (int i = 0; i < octaves; i++) {
        result += perlin(x * frequency, y * frequency, z * frequency) * amplitude;
        totalAmplitude += amplitude;
        amplitude *= persistence;
        frequency *= lacunarity;
    }
    result /= totalAmplitude;
    double normalized = (result + 1.0) * 0.5;
    return 0.5 + (normalized - 0.5) * intensity;
}

void math::Noise::setSeed(int seed)
{
    if (_seed != seed) {
        _seed = seed;
        if (_gradients) {
            for (int i = 0; i < 256; i++) {
                delete[] _gradients[i];
            }
            delete[] _gradients;
            _gradients = nullptr;
        }
        generateGradients();
    }
}