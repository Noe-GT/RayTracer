#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include "Exceptions.hpp"
#include "PluginTypes.hpp"

namespace rayTracer {
    class DLLoader {
    public:
        DLLoader(const std::string& libName) {
            _lib = dlopen(libName.c_str(), RTLD_LAZY | RTLD_NODELETE);
            if (!_lib)
                throw rayTracer::LibraryLoadingException(dlerror());
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
            std::function<T *()> func = reinterpret_cast<T *(*)()>(dlsym(_lib, instanceName.c_str()));

            if (!func)
                throw rayTracer::LibraryLoadingException(dlerror());
            return std::unique_ptr<T>(func());
        }

        rayTracer::PluginType getLibType() const
        {
            std::function<rayTracer::PluginType()> func = reinterpret_cast<rayTracer::PluginType (*)()>(dlsym(this->_lib, "getLibType"));

            if (!func)
                throw rayTracer::LibraryLoadingException(dlerror());
            return func();
        };

    private:
        void* _lib;
    };
}

#endif /* !DLLOADER_HPP_ */