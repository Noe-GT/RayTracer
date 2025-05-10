/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** collisionUtils.cpp
*/

#include "CollisionUtils.hpp"

math::CollisionUtils::CollisionUtils()
{
}

double math::CollisionUtils::getA() const
{
    return _a;
}

double math::CollisionUtils::getB() const
{
    return _b;
}

double math::CollisionUtils::getC() const
{
    return _c;
}

double math::CollisionUtils::getT() const
{
    return _t;
}

double math::CollisionUtils::getDiscriminant() const
{
    return _discriminant;
}

math::Vector math::CollisionUtils::getHitPoint() const
{
    return _hitPoint;
}

math::Vector math::CollisionUtils::getNormal() const
{
    return _normal;
}


bool math::CollisionUtils::hasCollision() const
{
    return _hasCollision;
}


void math::CollisionUtils::setHitPoint(math::Vector newVal)
{
    this->_hitPoint = newVal;
}

void math::CollisionUtils::setNormal(math::Vector newVal)
{
    this->_normal = newVal;
}

void math::CollisionUtils::setT(double newVal)
{
    this->_t = newVal;
}

void math::CollisionUtils::setA(double newVal)
{
    this->_a = newVal;
}

void math::CollisionUtils::setB(double newVal)
{
    this->_b = newVal;
}

void math::CollisionUtils::setC(double newVal)
{
    this->_c = newVal;
}

void math::CollisionUtils::setDiscriminant(double newVal)
{
    this->_discriminant = newVal;
}

void math::CollisionUtils::setHasCollision(bool newVal)
{
    this->_hasCollision = newVal;
}

void math::CollisionUtils::computeReflection(
    IPrimitive &primitive,
    math::Ray &ray,
    const std::vector<std::shared_ptr<IPrimitive>> &lights,
    const std::vector<std::shared_ptr<IPrimitive>> &objs,
    const math::Color &ambiantColor)
{
    double reflectivity = primitive.getMaterial().getReflectivity();
    if (reflectivity <= 0)
        return;
    math::Vector reflectedDir = ray._direction.normalize() - _normal * (2 * ray._direction.normalize().dotProduct(_normal));
    double blurness = primitive.getMaterial().getBlurness();
    int numRays = 1;

    if (blurness > 0) {
        if
            (blurness < 0.3) numRays = 2 + static_cast<int>(blurness * 13);
        else if
            (blurness < 0.7) numRays = 6 + static_cast<int>((blurness - 0.3) * 25);
        else
            numRays = std::min(16 + static_cast<int>((blurness - 0.7) * 46), 30);
    }

    math::Color finalReflectedColor(0, 0, 0);
    math::Noise noiseGenerator;
    math::Vector epsilon(_normal._x * 0.00000001f, _normal._y * 0.00000001f, _normal._z * 0.00000001f);

    for (int i = 0; i < numRays; i++) {
        math::Ray secondaryRay;
        math::Vector perturbedDir = reflectedDir;
        if (i > 0 && blurness > 0) {
            double noise = noiseGenerator.getNoise(_hitPoint._x, _hitPoint._y, _hitPoint._z, blurness);
            double modulatedNoise = fmod(blurness / 10, noise);
            math::Vector perturbation(modulatedNoise, modulatedNoise, modulatedNoise);
            double rayInfluence = static_cast<double>(i) / numRays;
            perturbedDir = (reflectedDir + perturbation * (blurness * (0.2 + 0.8 * rayInfluence))).normalize();
        }
        secondaryRay._origin = {_hitPoint._x + epsilon._x, _hitPoint._y + epsilon._y, _hitPoint._z + epsilon._z};
        secondaryRay._direction = perturbedDir;
        bool hasIntersection = false;
        for (const auto &obj : objs) {
            if (obj->getID() != primitive.getID() && obj->Intersect(secondaryRay, lights, objs)) {
                finalReflectedColor += secondaryRay._color;
                hasIntersection = true;
                break;
            }
        }
        if (!hasIntersection)
            finalReflectedColor += ambiantColor;
    }
    if (numRays > 1)
        finalReflectedColor /= numRays;
    ray._color = ray._color * (1 - reflectivity) + finalReflectedColor * reflectivity;
}

void math::CollisionUtils::computeShadows(
    IPrimitive &primitive,
    math::Ray &ray,
    const std::vector<std::shared_ptr<IPrimitive>> &lights,
    const std::vector<std::shared_ptr<IPrimitive>> &objs,
    const math::Color &ambiantColor)
{
    math::Color materialColor = primitive.getMaterial().GetColor();
    float lightIntensity = 1.0f / std::max(1.0f, static_cast<float>(lights.size()));
    math::Color finalColor = {ambiantColor._r * 0.2f, ambiantColor._g * 0.2f, ambiantColor._b * 0.2f};

    for (const auto &light : lights) {
        math::Vector lightDir = (light->getOrigin() - _hitPoint);
        double distToLight = lightDir.Length();
        lightDir.normalize();
        bool inShadow = false;
        math::Vector epsilon = _normal * 0.001f;
        math::Ray shadowRay;
        shadowRay._origin = {_hitPoint._x + epsilon._x, _hitPoint._y + epsilon._y, _hitPoint._z + epsilon._z};
        shadowRay._direction = lightDir;

        for (auto &obj : objs) {
            if (obj->getID() == primitive.getID())
                continue;
            if (obj->getID() == light->getID())
                continue;
            double discr = obj->getDiscriminant(shadowRay);
            if (discr >= 0) {
                math::Vector oc = shadowRay._origin - obj->getOrigin();
                double a = shadowRay._direction.dotProduct(shadowRay._direction);
                double b = 2 * oc.dotProduct(shadowRay._direction);
                double t = (-b - sqrt(discr)) / (2 * a);
                if (t > 0.001f && t < distToLight) {
                    inShadow = true;
                    break;
                }
            }
        }
        float diffuse = std::max(0.0, _normal.dotProduct(lightDir)) * (inShadow ? 0.1f : 1.0f);
        finalColor += materialColor * (diffuse * (1 / light->getMaterial().getBrightness()));
        finalColor._r = std::min(1.0, finalColor._r);
        finalColor._g = std::min(1.0, finalColor._g);
        finalColor._b = std::min(1.0, finalColor._b);
        finalColor += (light->getMaterial().GetColor() / 2) * (diffuse * (1 / light->getMaterial().getBrightness()));
    }
    finalColor._r = std::min(1.0, finalColor._r);
    finalColor._g = std::min(1.0, finalColor._g);
    finalColor._b = std::min(1.0, finalColor._b);
    ray._color = finalColor;
}


void math::CollisionUtils::computeTransparency(
    IPrimitive &primitive,
    math::Ray &ray,
    const std::vector<std::shared_ptr<IPrimitive>> &lights,
    const std::vector<std::shared_ptr<IPrimitive>> &objs,
    const math::Color &ambiantColor)
{
    double refractiveIndex = primitive.getMaterial().getRefractness();
    double transparency = primitive.getMaterial().getTransparency();

    if (transparency <= 0)
        return;
    double blurness = primitive.getMaterial().getBlurness();
    int numRays = 1;

    if (blurness > 0) {
        if (blurness < 0.3)
            numRays = 2 + static_cast<int>(blurness * 13);
        else if (blurness < 0.7)
            numRays = 6 + static_cast<int>((blurness - 0.3) * 25);
        else
            numRays = std::min(16 + static_cast<int>((blurness - 0.7) * 46), 30);
    }

    math::Color finalRefractedColor(0, 0, 0);
    math::Noise noiseGenerator;
    math::Vector epsilon(_normal._x * 0.00000001f, _normal._y * 0.00000001f, _normal._z * 0.00000001f);

    for (int i = 0; i < numRays; i++) {
        double eta = (_normal.dotProduct(ray._direction) < 0 ? 1.0 / refractiveIndex : refractiveIndex);
        double cosi = -_normal.dotProduct(ray._direction.normalize());
        double k = 1.0 - eta * eta * (1.0 - cosi * cosi);
        math::Vector refractedDir;

        if (k < 0.0)
            refractedDir = ray._direction.normalize() - _normal * 2.0 * cosi;
        else
            refractedDir = ray._direction.normalize() * eta + _normal * (eta * cosi - sqrt(k));
        if (i > 0 && blurness > 0) {
            double noise = noiseGenerator.getNoise(_hitPoint._x, _hitPoint._y, _hitPoint._z, blurness);
            double modulatedNoise = fmod(blurness / 10, noise);
            math::Vector perturbation(modulatedNoise, modulatedNoise, modulatedNoise);
            double rayInfluence = static_cast<double>(i) / numRays;
            refractedDir = (refractedDir + perturbation * (blurness * (0.2 + 0.8 * rayInfluence))).normalize();
        }
        math::Ray internalRay(_hitPoint._x + epsilon._x, _hitPoint._y + epsilon._y, _hitPoint._z + epsilon._z);
        internalRay._direction = refractedDir;

        math::Vector exitPoint;
        math::Vector exitNormal;
        math::Vector oc_exit = internalRay._origin - primitive.getOrigin();
        double a_exit = internalRay._direction.dotProduct(internalRay._direction);
        double b_exit = 2 * oc_exit.dotProduct(internalRay._direction);
        double c_exit = oc_exit.dotProduct(oc_exit) - (primitive.getSize() * primitive.getSize());
        double discr_exit = b_exit * b_exit - 4 * a_exit * c_exit;

        if (discr_exit >= 0) {
            double t_exit = (-b_exit + sqrt(discr_exit)) / (2 * a_exit);
            exitPoint = internalRay._origin + internalRay._direction * t_exit;
            exitNormal = (exitPoint - primitive.getOrigin()).normalize();
            if (exitNormal.dotProduct(internalRay._direction) > 0)
                exitNormal = exitNormal * -1.0;

            double eta_exit = refractiveIndex;
            double cosi_exit = -exitNormal.dotProduct(internalRay._direction);
            double k_exit = 1.0 - (1.0 / (eta_exit * eta_exit)) * (1.0 - cosi_exit * cosi_exit);
            math::Vector finalDir;
            if (k_exit < 0.0)
                finalDir = internalRay._direction - exitNormal * 2.0 * cosi_exit;
            else
                finalDir = internalRay._direction * (1.0 / eta_exit) + exitNormal * ((1.0 / eta_exit) * cosi_exit - sqrt(k_exit));
            math::Ray finalRay;
            finalRay._origin = {exitPoint._x + finalDir._x * 0.0001, exitPoint._y + finalDir._y * 0.0001, exitPoint._z + finalDir._z * 0.0001};
            finalRay._direction = finalDir;
            finalRay._color = ray._color;

            bool hasRefraction = false;
            for (const auto &obj : objs) {
                if (obj.get()->getID() != primitive.getID() && obj->Intersect(finalRay, lights, objs)) {
                    finalRefractedColor += finalRay._color;
                    hasRefraction = true;
                    break;
                }
            }
            if (!hasRefraction)
                finalRefractedColor += ambiantColor;
        }
    }
    if (numRays > 1)
        finalRefractedColor /= numRays;
    ray._color = ray._color * (1 - transparency) + finalRefractedColor * transparency;
}