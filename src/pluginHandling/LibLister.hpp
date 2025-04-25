/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** LibLister
*/

#ifndef LIBLISTER_HPP_
#define LIBLISTER_HPP_

#include "External.hpp"
#include "Config.hpp"
#include "Exceptions.hpp"
#include "pluginHandling/DLLoader.hpp"
#include <sys/types.h>
#include <dirent.h>

#define PLUGINS_DIR "plugins"

namespace rayTracer {
    class LibLister {
        public:
            LibLister();
            ~LibLister() = default;
            void display() const;
            std::string getLibDirectory() const;
            const std::vector<std::string> &getLibs();
            int getIndexLib(const std::string &path) const;
            void saveLib(std::string lib);

        private:
            const std::string _libDirectory;
            std::vector<std::string> _primitive;
            std::vector<std::string> _light;
            std::vector<std::string> _other;
    };
};

#endif /* !LIBLISTER_HPP_ */
