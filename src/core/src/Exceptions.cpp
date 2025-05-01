/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

Exception::Exception(const std::string &exception) noexcept:
    _exception(exception)
{
}

const char *Exception::what() const noexcept
{
    return this->_exception.c_str();
}

LibraryLoadingException::LibraryLoadingException(const std::string &exception) noexcept:
    Exception(exception)
{
}

PathFindingException::PathFindingException(const std::string &exception) noexcept:
    Exception(exception)
{
}

LoadingException::LoadingException(const std::string &exception) noexcept:
    Exception(exception)
{
}

TypeException::TypeException(const std::string &exception) noexcept:
    Exception(exception)
{
}

ArgumentsException::ArgumentsException(const std::string &exception) noexcept:
    Exception(exception)
{
}

PluginException::PluginException(const std::string &exception) noexcept:
Exception(exception)
{
}
