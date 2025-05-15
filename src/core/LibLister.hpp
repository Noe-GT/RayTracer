/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** LibLister
*/

#ifndef LIBLISTER_HPP_
#define LIBLISTER_HPP_

#include "Config.hpp"
#include "Exceptions.hpp"
#include "DLLoader.hpp"
#include <filesystem>

namespace rayTracer {
    class LibLister {
        public:
            LibLister();
            ~LibLister() = default;
            void display() const;
            const std::string &getLibDirectory() const;
            const std::vector<std::string> &getLibs() const;
            int getIndexLib(const std::string &path) const;

        private:
            const std::string _libDirectory;
            std::vector<std::string> _libs;
    };
};

#endif /* !LIBLISTER_HPP_ */
