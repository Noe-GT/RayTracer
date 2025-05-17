#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/lib/math/Ray.hpp"

Test(Ray, default_constructor) {
    {
        math::Ray r;
        cr_assert_eq(r._origin._x, 0.0);
        cr_assert_eq(r._origin._y, 0.0);
        cr_assert_eq(r._origin._z, 0.0);
        cr_assert_eq(r._direction._x, 0.0);
        cr_assert_eq(r._direction._y, 0.0);
        cr_assert_eq(r._direction._z, 0.0);
        cr_assert_eq(r._color._r, 0.0);
        cr_assert_eq(r._color._g, 0.0);
        cr_assert_eq(r._color._b, 0.0);
    }
}

Test(Ray, constructor_with_point_Vector) {
    {
        math::Point p(1, 2, 3);
        math::Vector v(4, 5, 6);
        math::Ray r(p, v);

        cr_assert_eq(r._origin._x, 1.0);
        cr_assert_eq(r._origin._y, 2.0);
        cr_assert_eq(r._origin._z, 3.0);
        cr_assert_eq(r._direction._x, 4.0);
        cr_assert_eq(r._direction._y, 5.0);
        cr_assert_eq(r._direction._z, 6.0);
    }
}

Test(Ray, constructor_with_point_coord) {
    {
        math::Ray r(1.0, 2.0, 3.0);

        cr_assert_eq(r._origin._x, 1.0);
        cr_assert_eq(r._origin._y, 2.0);
        cr_assert_eq(r._origin._z, 3.0);
        cr_assert_eq(r._direction._x, 0.0);
        cr_assert_eq(r._direction._y, 0.0);
        cr_assert_eq(r._direction._z, 0.0);
    }
}

Test(Ray, operator_add_eq) {
    {
        math::Ray r1(math::Point(1,2,3), math::Vector(4,5,6), math::Color(7,8,9));
        math::Ray r2(math::Point(10,20,30), math::Vector(40,50,60), math::Color(70,80,90));

        r1 += r2;

        cr_assert_eq(r1._origin._x, 11.0);
        cr_assert_eq(r1._origin._y, 22.0);
        cr_assert_eq(r1._origin._z, 33.0);
        cr_assert_eq(r1._direction._x, 44.0);
        cr_assert_eq(r1._direction._y, 55.0);
        cr_assert_eq(r1._direction._z, 66.0);
        cr_assert_eq(r1._color._r, 77.0);
        cr_assert_eq(r1._color._g, 88.0);
        cr_assert_eq(r1._color._b, 99.0);
    }
}

Test(Ray, operator_sub_eq) {
    {
        math::Ray r1(math::Point(10,20,30), math::Vector(40,50,60), math::Color(70,80,90));
        math::Ray r2(math::Point(1,2,3), math::Vector(4,5,6), math::Color(7,8,9));

        r1 -= r2;

        cr_assert_eq(r1._origin._x, 9.0);
        cr_assert_eq(r1._origin._y, 18.0);
        cr_assert_eq(r1._origin._z, 27.0);
        cr_assert_eq(r1._direction._x, 36.0);
        cr_assert_eq(r1._direction._y, 45.0);
        cr_assert_eq(r1._direction._z, 54.0);
        cr_assert_eq(r1._color._r, 63.0);
        cr_assert_eq(r1._color._g, 72.0);
        cr_assert_eq(r1._color._b, 81.0);
    }
}

Test(Ray, operator_mul_eq) {
    {
        math::Ray r(math::Point(1,2,3), math::Vector(4,5,6), math::Color(7,8,9));

        r *= 2.0;

        cr_assert_eq(r._origin._x, 2.0);
        cr_assert_eq(r._origin._y, 4.0);
        cr_assert_eq(r._origin._z, 6.0);
        cr_assert_eq(r._direction._x, 8.0);
        cr_assert_eq(r._direction._y, 10.0);
        cr_assert_eq(r._direction._z, 12.0);
        cr_assert_eq(r._color._r, 14.0);
        cr_assert_eq(r._color._g, 16.0);
        cr_assert_eq(r._color._b, 18.0);
    }
}

Test(Ray, arithmetic_operators) {
    // Test + avec Ray
    {
        math::Ray r1(math::Point(1,2,3), math::Vector(4,5,6), math::Color(7,8,9));
        math::Ray r2(math::Point(10,20,30), math::Vector(40,50,60), math::Color(70,80,90));

        math::Ray result = r1 + r2;

        cr_assert_eq(result._origin._x, 11.0);
        cr_assert_eq(result._origin._y, 22.0);
        cr_assert_eq(result._origin._z, 33.0);
        cr_assert_eq(result._direction._x, 44.0);
        cr_assert_eq(result._direction._y, 55.0);
        cr_assert_eq(result._direction._z, 66.0);
        cr_assert_eq(result._color._r, 77.0);
        cr_assert_eq(result._color._g, 88.0);
        cr_assert_eq(result._color._b, 99.0);
    }

    // Test * avec double
    {
        math::Ray r(math::Point(1,2,3), math::Vector(4,5,6), math::Color(7,8,9));

        math::Ray result = r * 2.0;

        cr_assert_eq(result._origin._x, 2.0);
        cr_assert_eq(result._origin._y, 4.0);
        cr_assert_eq(result._origin._z, 6.0);
        cr_assert_eq(result._direction._x, 8.0);
        cr_assert_eq(result._direction._y, 10.0);
        cr_assert_eq(result._direction._z, 12.0);
        cr_assert_eq(result._color._r, 14.0);
        cr_assert_eq(result._color._g, 16.0);
        cr_assert_eq(result._color._b, 18.0);
    }
}

Test(Ray, division_operator) {
    // Test / avec double
    {
        math::Ray r(math::Point(2,4,6), math::Vector(8,10,12), math::Color(14,16,18));

        math::Ray result = r / 2.0;

        cr_assert_eq(result._origin._x, 1.0);
        cr_assert_eq(result._origin._y, 2.0);
        cr_assert_eq(result._origin._z, 3.0);
        cr_assert_eq(result._direction._x, 4.0);
        cr_assert_eq(result._direction._y, 5.0);
        cr_assert_eq(result._direction._z, 6.0);
        cr_assert_eq(result._color._r, 7.0);
        cr_assert_eq(result._color._g, 8.0);
        cr_assert_eq(result._color._b, 9.0);
    }

    // Test division par zéro
    {
        math::Ray r(math::Point(1,1,1), math::Vector(1,1,1), math::Color(1,1,1));

        cr_expect_throw(r /= 0.0, std::runtime_error);
    }
}