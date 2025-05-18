/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** tests_point
*/

#include <criterion/criterion.h>
#include "Point.hpp"
#include "Vector.hpp"

Test(Point, default_constructor)
{
    math::Point p;

    cr_expect_float_eq(p._x, 0.0, 1e-6);
    cr_expect_float_eq(p._y, 0.0, 1e-6);
    cr_expect_float_eq(p._z, 0.0, 1e-6);
}

Test(Point, constructor_with_params)
{
    math::Point p(1.0, 2.0, 3.0);

    cr_expect_float_eq(p._x, 1.0, 1e-6);
    cr_expect_float_eq(p._y, 2.0, 1e-6);
    cr_expect_float_eq(p._z, 3.0, 1e-6);
}

Test(Point, copy_constructor)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Point b(a);

    cr_expect_float_eq(b._x, 1.0, 1e-6);
    cr_expect_float_eq(b._y, 2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Point, assignment)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Point b = a;

    cr_expect_float_eq(b._x, 1.0, 1e-6);
    cr_expect_float_eq(b._y, 2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Point, inverse)
{
    math::Point a(1.0, 2.0, -3.0);
    math::Point b = -a;

    cr_expect_float_eq(b._x, -1.0, 1e-6);
    cr_expect_float_eq(b._y, -2.0, 1e-6);
    cr_expect_float_eq(b._z, 3.0, 1e-6);
}

Test(Point, addition)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Point b(4.0, 5.0, 6.0);
    math::Point c = a + b;

    cr_expect_float_eq(c._x, 5.0, 1e-6);
    cr_expect_float_eq(c._y, 7.0, 1e-6);
    cr_expect_float_eq(c._z, 9.0, 1e-6);
}

Test(Point, addition2)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Point b(1.0, 1.0, 1.0);

    a += b;
    cr_expect_float_eq(a._x, 2.0, 1e-6);
    cr_expect_float_eq(a._y, 3.0, 1e-6);
    cr_expect_float_eq(a._z, 4.0, 1e-6);
}

Test(Point, subtraction)
{
    math::Point a(5.0, 4.0, 3.0);
    math::Point b(2.0, 1.0, 1.0);
    math::Point c = a - b;

    cr_expect_float_eq(c._x, 3.0, 1e-6);
    cr_expect_float_eq(c._y, 3.0, 1e-6);
    cr_expect_float_eq(c._z, 2.0, 1e-6);
}

Test(Point, subtraction2)
{
    math::Point a(3.0, 3.0, 3.0);
    math::Point b(1.0, 1.0, 1.0);

    a -= b;
    cr_expect_float_eq(a._x, 2.0, 1e-6);
    cr_expect_float_eq(a._y, 2.0, 1e-6);
    cr_expect_float_eq(a._z, 2.0, 1e-6);
}

Test(Point, scalar_multiplication)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Point b = a * 2.0;

    cr_expect_float_eq(b._x, 2.0, 1e-6);
    cr_expect_float_eq(b._y, 4.0, 1e-6);
    cr_expect_float_eq(b._z, 6.0, 1e-6);
}

Test(Point, scalar_multiplication2)
{
    math::Point a(1.0, 2.0, 3.0);

    a *= 2.0;
    cr_expect_float_eq(a._x, 2.0, 1e-6);
    cr_expect_float_eq(a._y, 4.0, 1e-6);
    cr_expect_float_eq(a._z, 6.0, 1e-6);
}

Test(Point, scalar_division)
{
    math::Point a(1.0, 2.0, 3.0);
    math::Point b = a / 2.0;

    cr_expect_float_eq(b._x, 0.5, 1e-6);
    cr_expect_float_eq(b._y, 1.0, 1e-6);
    cr_expect_float_eq(b._z, 1.5, 1e-6);
}

Test(Point, scalar_division2)
{
    math::Point a(1.0, 2.0, 3.0);

    a /= 2.0;
    cr_expect_float_eq(a._x, 0.5, 1e-6);
    cr_expect_float_eq(a._y, 1.0, 1e-6);
    cr_expect_float_eq(a._z, 1.5, 1e-6);
}

Test(Point, division_by_zero)
{
    math::Point a(1.0, 2.0, 3.0);

    cr_expect_throw(a / 0.0, std::invalid_argument);
}

Test(Point, vector_addition)
{
    math::Point p(1.0, 2.0, 3.0);
    math::Vector v(1.0, 1.0, 1.0);
    math::Point res = p + v;

    cr_expect_float_eq(res._x, 2.0, 1e-6);
    cr_expect_float_eq(res._y, 3.0, 1e-6);
    cr_expect_float_eq(res._z, 4.0, 1e-6);
}

Test(Point, vector_addition2)
{
    math::Point p(1.0, 2.0, 3.0);
    math::Vector v(1.0, 1.0, 1.0);

    p += v;
    cr_expect_float_eq(p._x, 2.0, 1e-6);
    cr_expect_float_eq(p._y, 3.0, 1e-6);
    cr_expect_float_eq(p._z, 4.0, 1e-6);
}

Test(Point, vector_substraction)
{
    math::Point p(1.0, 2.0, 3.0);
    math::Vector v(1.0, 1.0, 1.0);
    math::Point res = p - v;

    cr_expect_float_eq(res._x, 0.0, 1e-6);
    cr_expect_float_eq(res._y, 1.0, 1e-6);
    cr_expect_float_eq(res._z, 2.0, 1e-6);
}

Test(Point, vector_substraction2)
{
    math::Point p(1.0, 2.0, 3.0);
    math::Vector v(1.0, 1.0, 1.0);

    p -= v;
    cr_expect_float_eq(p._x, 0.0, 1e-6);
    cr_expect_float_eq(p._y, 1.0, 1e-6);
    cr_expect_float_eq(p._z, 2.0, 1e-6);
}
