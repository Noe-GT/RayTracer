/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** tests_color
*/

#include <criterion/criterion.h>
#include "Color.hpp"

Test(Color, constructor)
{
    math::Color c;

    cr_expect_float_eq(c._r, 0.0, 1e-6);
    cr_expect_float_eq(c._g, 0.0, 1e-6);
    cr_expect_float_eq(c._b, 0.0, 1e-6);
}

Test(Color, constructor_with_params)
{
    math::Color c(0.1, 0.2, 0.3);

    cr_expect_float_eq(c._r, 0.1, 1e-6);
    cr_expect_float_eq(c._g, 0.2, 1e-6);
    cr_expect_float_eq(c._b, 0.3, 1e-6);
}

Test(Color, copy_constructor)
{
    math::Color a(0.1, 0.2, 0.3);
    math::Color b(a);

    cr_expect_float_eq(b._r, 0.1, 1e-6);
    cr_expect_float_eq(b._g, 0.2, 1e-6);
    cr_expect_float_eq(b._b, 0.3, 1e-6);
}

Test(Color, assignment)
{
    math::Color a(0.1, 0.2, 0.3);
    math::Color b = a;

    cr_expect_float_eq(b._r, 0.1, 1e-6);
    cr_expect_float_eq(b._g, 0.2, 1e-6);
    cr_expect_float_eq(b._b, 0.3, 1e-6);
}

Test(Color, inverse)
{
    math::Color a(0.1, 0.2, -0.3);
    math::Color b = -a;

    cr_expect_float_eq(b._r, -0.1, 1e-6);
    cr_expect_float_eq(b._g, -0.2, 1e-6);
    cr_expect_float_eq(b._b, 0.3, 1e-6);
}

Test(Color, addition)
{
    math::Color a(0.1, 0.2, 0.3);
    math::Color b(0.4, 0.5, 0.6);
    math::Color c = a + b;

    cr_expect_float_eq(c._r, 0.5, 1e-6);
    cr_expect_float_eq(c._g, 0.7, 1e-6);
    cr_expect_float_eq(c._b, 0.9, 1e-6);
}

Test(Color, addition2)
{
    math::Color a(0.1, 0.2, 0.3);
    math::Color b(0.1, 0.1, 0.1);

    a += b;
    cr_expect_float_eq(a._r, 0.2, 1e-6);
    cr_expect_float_eq(a._g, 0.3, 1e-6);
    cr_expect_float_eq(a._b, 0.4, 1e-6);
}

Test(Color, subtraction)
{
    math::Color a(0.7, 0.5, 0.3);
    math::Color b(0.2, 0.1, 0.1);
    math::Color c = a - b;

    cr_expect_float_eq(c._r, 0.5, 1e-6);
    cr_expect_float_eq(c._g, 0.4, 1e-6);
    cr_expect_float_eq(c._b, 0.2, 1e-6);
}

Test(Color, subtraction2)
{
    math::Color a(0.3, 0.2, 0.1);
    math::Color b(0.1, 0.1, 0.1);

    a -= b;
    cr_expect_float_eq(a._r, 0.2, 1e-6);
    cr_expect_float_eq(a._g, 0.1, 1e-6);
    cr_expect_float_eq(a._b, 0.0, 1e-6);
}

Test(Color, scalar_multiplication)
{
    math::Color a(0.1, 0.2, 0.3);
    math::Color b = a * 2.0;

    cr_expect_float_eq(b._r, 0.2, 1e-6);
    cr_expect_float_eq(b._g, 0.4, 1e-6);
    cr_expect_float_eq(b._b, 0.6, 1e-6);
}

Test(Color, scalar_multiplication2)
{
    math::Color a(0.1, 0.2, 0.3);

    a *= 2.0;
    cr_expect_float_eq(a._r, 0.2, 1e-6);
    cr_expect_float_eq(a._g, 0.4, 1e-6);
    cr_expect_float_eq(a._b, 0.6, 1e-6);
}

Test(Color, color_multiplication)
{
    math::Color a(0.1, 0.2, 0.3);
    math::Color b(0.5, 0.5, 0.5);
    math::Color c = a * b;

    cr_expect_float_eq(c._r, 0.05, 1e-6);
    cr_expect_float_eq(c._g, 0.1, 1e-6);
    cr_expect_float_eq(c._b, 0.15, 1e-6);
}

Test(Color, scalar_division)
{
    math::Color a(0.2, 0.4, 0.6);
    math::Color b = a / 2.0;

    cr_expect_float_eq(b._r, 0.1, 1e-6);
    cr_expect_float_eq(b._g, 0.2, 1e-6);
    cr_expect_float_eq(b._b, 0.3, 1e-6);
}

Test(Color, scalar_division2)
{
    math::Color a(0.2, 0.4, 0.6);

    a /= 2.0;
    cr_expect_float_eq(a._r, 0.1, 1e-6);
    cr_expect_float_eq(a._g, 0.2, 1e-6);
    cr_expect_float_eq(a._b, 0.3, 1e-6);
}

Test(Color, division_by_zero)
{
    math::Color a(0.1, 0.2, 0.3);

    cr_expect_throw(a / 0.0, std::invalid_argument);
}
