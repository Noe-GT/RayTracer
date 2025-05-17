/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** tests_matrix
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Matrix.hpp"

Test(Matrix, invalid_creation)
{
    cr_expect_throw(math::Matrix<std::string>(2, 2), rayTracer::TypeException);
}

Test(Matrix, dimensions)
{
    math::Matrix<int> matrix(3, 2);
    std::pair<int, int> dimensions;

    cr_expect_eq(matrix.getWidth(), 3);
    cr_expect_eq(matrix.getHeight(), 2);
    dimensions = matrix.getDimensions();
    cr_expect_eq(dimensions.first, 3);
    cr_expect_eq(dimensions.second, 2);
}

Test(Matrix, get_value)
{
    math::Matrix<int> matrix(3, 3);

    cr_expect_eq(matrix.getValue(1, 1), 0);
    matrix.setValue(1, 1, 1);
    cr_expect_eq(matrix.getValue(1, 1), 1);
    cr_expect_eq(matrix.getValue(1, 3), 0);
}

Test(Matrix, addition)
{
    math::Matrix<int> a(2, 2);
    math::Matrix<int> b(2, 2);

    a.setValue(1, 1, 1);
    a.setValue(2, 1, 2);
    a.setValue(1, 2, 3);
    a.setValue(2, 2, 4);
    b.setValue(1, 1, 3);
    b.setValue(2, 1, 2);
    b.setValue(1, 2, 4);
    b.setValue(2, 2, 1);

    math::Matrix c = a + b;

    cr_expect_eq(c.getValue(1, 1), 4);
    cr_expect_eq(c.getValue(2, 1), 4);
    cr_expect_eq(c.getValue(1, 2), 7);
    cr_expect_eq(c.getValue(2, 2), 5);
}

Test(Matrix, subtraction)
{
    math::Matrix<int> a(2, 2);
    math::Matrix<int> b(2, 2);

    a.setValue(1, 1, 1);
    a.setValue(2, 1, 2);
    a.setValue(1, 2, 3);
    a.setValue(2, 2, 4);
    b.setValue(1, 1, 3);
    b.setValue(2, 1, 2);
    b.setValue(1, 2, 4);
    b.setValue(2, 2, 1);

    math::Matrix c = a - b;

    cr_expect_eq(c.getValue(1, 1), -2);
    cr_expect_eq(c.getValue(2, 1), 0);
    cr_expect_eq(c.getValue(1, 2), -1);
    cr_expect_eq(c.getValue(2, 2), 3);
}

Test(Matrix, scalar_multiplication)
{
    math::Matrix<int> a(2, 2);

    a.setValue(1, 1, 1);
    a.setValue(2, 1, 2);
    a.setValue(1, 2, 3);
    a.setValue(2, 2, 4);

    math::Matrix b = a * 2;

    cr_expect_eq(b.getValue(1, 1), 2);
    cr_expect_eq(b.getValue(2, 1), 4);
    cr_expect_eq(b.getValue(1, 2), 6);
    cr_expect_eq(b.getValue(2, 2), 8);
}

Test(Matrix, matrix_multiplication)
{
    math::Matrix<int> a(2, 2);
    math::Matrix<int> b(2, 2);

    a.setValue(1, 1, 1);
    a.setValue(2, 1, 2);
    a.setValue(1, 2, 3);
    a.setValue(2, 2, 4);
    b.setValue(1, 1, 3);
    b.setValue(2, 1, 2);
    b.setValue(1, 2, 4);
    b.setValue(2, 2, 1);

    math::Matrix c = a * b;

    cr_expect_eq(c.getValue(1, 1), 11);
    cr_expect_eq(c.getValue(2, 1), 4);
    cr_expect_eq(c.getValue(1, 2), 25);
    cr_expect_eq(c.getValue(2, 2), 10);
}

Test(Matrix, invalid_addition)
{
    math::Matrix<int> a(2, 2);
    math::Matrix<int> b(1, 2);

    cr_expect_throw(a + b, math::Matrix<int>::MatrixException);
}

Test(Matrix, invalid_substraction)
{
    math::Matrix<int> a(2, 2);
    math::Matrix<int> b(1, 2);

    cr_expect_throw(a - b, math::Matrix<int>::MatrixException);
}

Test(Matrix, invalid_multiplication)
{
    math::Matrix<int> a(3, 3);
    math::Matrix<int> b(2, 2);

    cr_expect_throw(a * b, math::Matrix<int>::MatrixException);
}

Test(Matrix, invalid_set)
{
    math::Matrix<int> a(2, 2);

    cr_expect_throw(a.setValue(5, 0, 10), math::Matrix<int>::MatrixException);
    cr_expect_throw(a.setValue(0, 5, 10), math::Matrix<int>::MatrixException);
}

Test(Matrix, get_empty_matrix)
{
    math::Matrix<int> a(0, 0);

    cr_expect_throw(a.getWidth(), math::Matrix<int>::MatrixException);
}

Test(Matrix, reset)
{
    math::Matrix<int> matrix(2, 2);

    matrix.setValue(1, 1, 1);
    matrix.setValue(2, 1, 2);
    matrix.setValue(1, 2, 3);
    matrix.setValue(2, 2, 4);
    matrix.reset();
    cr_expect_eq(matrix.getValue(1, 1), 0);
    cr_expect_eq(matrix.getValue(2, 1), 0);
    cr_expect_eq(matrix.getValue(1, 2), 0);
    cr_expect_eq(matrix.getValue(2, 2), 0);
}

Test(Matrix, resize)
{
    math::Matrix<int> matrix(1, 1);

    matrix.setValue(1, 1, 1);
    cr_expect_eq(matrix.getValue(1, 1), 1);
    matrix.resize(2, 2);
    cr_expect_eq(matrix.getValue(1, 1), 1);
    cr_expect_eq(matrix.getValue(2, 1), 0);
    cr_expect_eq(matrix.getValue(1, 2), 0);
    cr_expect_eq(matrix.getValue(2, 2), 0);
}
