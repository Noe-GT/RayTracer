#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include "Exceptions.hpp"

namespace rayTracer {
    class DLLoader {
    public:
        DLLoader(const std::string& libName) {
            _lib = dlopen(libName.c_str(), RTLD_LAZY | RTLD_NODELETE);
            if (!_lib) {
                throw LibraryLoadingException(dlerror());
            }
        }

        ~DLLoader() {
            if (_lib) {
                dlclose(_lib);
            }
        }

        DLLoader(const DLLoader&) = delete;
        DLLoader& operator=(const DLLoader&) = delete;

        template<typename T>
        std::unique_ptr<T> getInstance(const std::string& instanceName) const {
            void* sym = dlsym(_lib, instanceName.c_str());
            if (!sym) {
                throw LibraryLoadingException(dlerror());
            }

            using CreatorFunc = T*(*)();
            auto func = reinterpret_cast<CreatorFunc>(sym);

            if (!func) {
                throw LibraryLoadingException("Invalid symbol");
            }

            return std::unique_ptr<T>(func());
        }

    private:
        void* _lib;
    };
}

#endif /* !DLLOADER_HPP_ */