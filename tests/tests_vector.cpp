/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** tests_vector
*/

#include <criterion/criterion.h>
#include "Vector.hpp"
#include "Point.hpp"

Test(Vector, default_constructor)
{
    math::Vector v;

    cr_expect_float_eq(v._x, 0.0, 1e-6);
    cr_expect_float_eq(v._y, 0.0, 1e-6);
    cr_expect_float_eq(v._z, 0.0, 1e-6);
}

Test(Vector, constructor_with_params)
{
    math::Vector v(1.0, 2.0, 3.0);

    cr_expect_float_eq(v._x, 1.0, 1e-6);
    cr_expect_float_eq(v._y, 2.0, 1e-6);
    cr_expect_float_eq(v._z, 3.0, 1e-6);
}

Test(Vector, copy_constructor)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b(a);

    cr_expect_float_eq(b._x, 1.0, 1e-6);
    cr_expect_float_eq(b._y, 2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Vector, constructor_with_point)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Vector b(a);

    cr_expect_float_eq(b._x, 1.0, 1e-6);
    cr_expect_float_eq(b._y, 2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Vector, assignment)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b = a;

    cr_expect_float_eq(b._x, 1.0, 1e-6);
    cr_expect_float_eq(b._y, 2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Vector, inverse)
{
    math::Vector a(1.0, 2.0, -3.0);
    math::Vector b = -a;

    cr_expect_float_eq(b._x, -1.0, 1e-6);
    cr_expect_float_eq(b._y, -2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Vector, addition)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b(4.0, 5.0, 6.0);
    math::Vector c = a + b;

    cr_expect_float_eq(c._x, 5.0, 1e-6);
    cr_expect_float_eq(c._y, 7.0, 1e-6);
    cr_expect_float_eq(c._z, 9.0, 1e-6);
}

Test(Vector, addition2)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b(1.0, 1.0, 1.0);

    a += b;
    cr_expect_float_eq(a._x, 2.0, 1e-6);
    cr_expect_float_eq(a._y, 3.0, 1e-6);
    cr_expect_float_eq(a._z, 4.0, 1e-6);
}

Test(Vector, subtraction)
{
    math::Vector a(5.0, 4.0, 3.0);
    math::Vector b(2.0, 1.0, 1.0);
    math::Vector c = a - b;

    cr_expect_float_eq(c._x, 3.0, 1e-6);
    cr_expect_float_eq(c._y, 3.0, 1e-6);
    cr_expect_float_eq(c._z, 2.0, 1e-6);
}

Test(Vector, subtraction2)
{
    math::Vector a(3.0, 3.0, 3.0);
    math::Vector b(1.0, 1.0, 1.0);

    a -= b;
    cr_expect_float_eq(a._x, 2.0, 1e-6);
    cr_expect_float_eq(a._y, 2.0, 1e-6);
    cr_expect_float_eq(a._z, 2.0, 1e-6);
}

Test(Vector, scalar_multiplication)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b = a * 2.0;

    cr_expect_float_eq(b._x, 2.0, 1e-6);
    cr_expect_float_eq(b._y, 4.0, 1e-6);
    cr_expect_float_eq(b._z, 6.0, 1e-6);
}

Test(Vector, scalar_multiplication2)
{
    math::Vector a(1.0, 2.0, 3.0);

    a *= 2.0;
    cr_expect_float_eq(a._x, 2.0, 1e-6);
    cr_expect_float_eq(a._y, 4.0, 1e-6);
    cr_expect_float_eq(a._z, 6.0, 1e-6);
}

Test(Vector, scalar_division)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b = a / 2.0;

    cr_expect_float_eq(b._x, 0.5, 1e-6);
    cr_expect_float_eq(b._y, 1.0, 1e-6);
    cr_expect_float_eq(b._z, 1.5, 1e-6);
}

Test(Vector, scalar_division2)
{
    math::Vector a(1.0, 2.0, 3.0);

    a /= 2.0;
    cr_expect_float_eq(a._x, 0.5, 1e-6);
    cr_expect_float_eq(a._y, 1.0, 1e-6);
    cr_expect_float_eq(a._z, 1.5, 1e-6);
}

Test(Vector, division_by_zero)
{
    math::Vector a(1.0, 2.0, 3.0);

    cr_expect_throw(a / 0.0, std::invalid_argument);
}

Test(Vector, length_squared)
{
    math::Vector a(1.0, 2.0, 2.0);

    cr_expect_float_eq(a.LengthSquared(), 9.0, 1e-6);
}

Test(Vector, length)
{
    math::Vector a(1.0, 2.0, 2.0);

    cr_expect_float_eq(a.Length(), 3.0, 1e-6);
}

Test(Vector, dot_product)
{
    math::Vector a(1.0, 2.0, 3.0);
    math::Vector b(4.0, -5.0, 6.0);

    cr_expect_float_eq(a.dotProduct(b), 12.0, 1e-6);
}

Test(Vector, cross)
{
    math::Vector a(1.0, 0.0, 0.0);
    math::Vector b(0.0, 1.0, 0.0);
    math::Vector c = a.cross(b);

    cr_expect_float_eq(c._x, 0.0, 1e-6);
    cr_expect_float_eq(c._y, 0.0, 1e-6);
    cr_expect_float_eq(c._z, 1.0, 1e-6);
}

Test(Vector, normalize)
{
    math::Vector a(0.0, 3.0, 4.0);
    math::Vector b = a.normalize();

    cr_expect_float_eq(b._x, 0.0, 1e-6);
    cr_expect_float_eq(b._y, 0.6, 1e-6);
    cr_expect_float_eq(b._z, 0.8, 1e-6);
}

Test(Vector, normalize_zero)
{
    math::Vector a(0.0, 0.0, 0.0);
    math::Vector b = a.normalize();

    cr_expect_float_eq(b._x, 0.0, 1e-6);
    cr_expect_float_eq(b._y, 0.0, 1e-6);
    cr_expect_float_eq(b._z, 0.0, 1e-6);
}
