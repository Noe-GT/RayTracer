/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include <iostream>
#include <functional>
#include "Exceptions.hpp"

namespace rayTracer {
    class DLLoader {
        public:
            DLLoader(const std::string &libName)
            {
                this->_lib = dlopen(libName.c_str(), RTLD_LAZY);
                if (!this->_lib)
                    throw LibraryLoadingException(dlerror());
            };

            ~DLLoader()
            {
                if (this->_lib) {
                    dlclose(this->_lib);
                }
            };

            template<typename T>
            T *getInstance(const std::string &instanceName) const
            {
                std::function<T *()> func = reinterpret_cast<T *(*)()>(dlsym(this->_lib, instanceName.c_str()));

                if (!func)
                    throw LibraryLoadingException(dlerror());
                return func();
            };

        private:
            void *_lib;
    };
};

#endif /* !DLLOADER_HPP_ */
