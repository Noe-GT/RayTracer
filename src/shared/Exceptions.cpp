/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

rayTracer::Exception::Exception(const std::string &exception) noexcept:
    _exception(exception)
{
}

const char *rayTracer::Exception::what() const noexcept
{
    return this->_exception.c_str();
}

rayTracer::LibraryLoadingException::LibraryLoadingException(const std::string &exception) noexcept:
    Exception(exception)
{
}

rayTracer::PathFindingException::PathFindingException(const std::string &exception) noexcept:
    Exception(exception)
{
}

rayTracer::LoadingException::LoadingException(const std::string &exception) noexcept:
    Exception(exception)
{
}

rayTracer::TypeException::TypeException(const std::string &exception) noexcept:
    Exception(exception)
{
}

rayTracer::ArgumentsException::ArgumentsException(const std::string &exception) noexcept:
    Exception(exception)
{
}

rayTracer::PluginException::PluginException(const std::string &exception) noexcept:
Exception(exception)
{
}

rayTracer::ConfigException::ConfigException(const std::string &exception) noexcept:
    Exception(exception)
{
}
