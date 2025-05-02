/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>
#include <string>

namespace rayTracer {
    class Exception : public std::exception
    {
        public:
            Exception(const std::string &exception) noexcept;
            ~Exception() noexcept = default;
            const char *what() const noexcept final;

        private:
            std::string _exception;
    };

    class LibraryLoadingException: public Exception
    {
        public:
            LibraryLoadingException(const std::string &exception) noexcept;
            ~LibraryLoadingException() noexcept = default;
    };

    class PathFindingException: public Exception
    {
        public:
            PathFindingException(const std::string &exception) noexcept;
            ~PathFindingException() noexcept = default;
    };

    class LoadingException: public Exception
    {
        public:
            LoadingException(const std::string &exception) noexcept;
            ~LoadingException() noexcept = default;
    };

    class TypeException: public Exception
    {
        public:
            TypeException(const std::string &exception) noexcept;
            ~TypeException() noexcept = default;
    };

    class ArgumentsException: public Exception
    {
        public:
            ArgumentsException(const std::string &exception) noexcept;
            ~ArgumentsException() noexcept = default;
    };

    class PluginException: public Exception
    {
        public:
            PluginException(const std::string &exception) noexcept;
            ~PluginException() noexcept = default;
    };

    class ConfigException: public Exception
    {
        public:
            ConfigException(const std::string &exception) noexcept;
            ~ConfigException() noexcept = default;
    };
};

#endif /* !EXCEPTIONS_HPP_ */
