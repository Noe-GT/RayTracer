/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** PluginHandler
*/

#ifndef PLUGINHANDLER_HPP_
#define PLUGINHANDLER_HPP_

#include "dlloader/DLLoader.hpp"
#include "dlloader/LibLister.hpp"
#include "IFactory.hpp"
#include "External.hpp"
#include "Config.hpp"

namespace rayTracer {
    class PluginHandler {
        public:
            class Plugin {
                public:
                    Plugin(std::string path);
                    Plugin(std::string path, std::string name);
                    Plugin(const rayTracer::PluginHandler::Plugin&) noexcept;
                    Plugin& operator=(const rayTracer::PluginHandler::Plugin&) noexcept;

                    ~Plugin();

                    std::shared_ptr<rayTracer::DLLoader> _loader;
                    std::shared_ptr<rayTracer::IFactory> _factory;
                    std::string _name;

                    friend std::ostream& operator<<(std::ostream& os, const rayTracer::PluginHandler::Plugin& plugin);
            };

            PluginHandler();
            ~PluginHandler() = default;

            void cstrPlugin(const std::string &name, const LibLister &lister);
            std::map<rayTracer::IFactory::ObjectType, std::vector<rayTracer::PluginHandler::Plugin>> &getPlugins();
            void display() const;

        private:
            std::map<rayTracer::IFactory::ObjectType, std::vector<rayTracer::PluginHandler::Plugin>> _plugins;
    };
};

#endif /* !PLUGINHANDLER_HPP_ */
