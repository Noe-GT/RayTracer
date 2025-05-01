/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PluginHandler
*/

#ifndef PLUGINHANDLER_HPP_
#define PLUGINHANDLER_HPP_

#include "DLLoader.hpp"
#include "LibLister.hpp"
#include "IFactory.hpp"
#include "External.hpp"
#include "Config.hpp"
#include "Exceptions.hpp"
#include "PluginTypes.hpp"

namespace rayTracer {
    class PluginHandler {
        public:
            template <typename T>
            class Plugin {
                public:
                    Plugin(std::shared_ptr<rayTracer::DLLoader> loader, std::string name);
                    Plugin(const rayTracer::PluginHandler::Plugin<T>&) noexcept;
                    Plugin& operator=(const rayTracer::PluginHandler::Plugin<T>&) noexcept;

                    ~Plugin();

                    std::shared_ptr<rayTracer::DLLoader> _loader;
                    std::shared_ptr<rayTracer::IFactory<T>> _factory;
                    std::string _name;
            };

            PluginHandler();
            ~PluginHandler() = default;

            void display() const;
            template <typename T> std::shared_ptr<rayTracer::IFactory<T>> getPluginFactory(rayTracer::PluginType type, const std::string &name) const;

        private:
            void cstrPlugin(const std::string &fileName, const LibLister &lister);
            std::string getPluginName(const std::string &path) const;
            std::map<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> _primitivePlugins;
    };
};

#endif /* !PLUGINHANDLER_HPP_ */
