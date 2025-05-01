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

            using CreatorFunc = T*(*)();
            auto func = reinterpret_cast<CreatorFunc>(sym);

            return std::unique_ptr<T>(func());
        }

        rayTracer::PluginType getLibType() const
        {
            std::function<rayTracer::PluginType()> func = reinterpret_cast<rayTracer::PluginType (*)()>(dlsym(this->_lib, "getLibType"));

            if (!func)
                throw LibraryLoadingException(dlerror());
            return func();
        };

    private:
        void* _lib;
    };
}

#endif /* !DLLOADER_HPP_ */