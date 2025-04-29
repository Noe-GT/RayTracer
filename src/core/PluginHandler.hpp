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
#include "Config.hpp"

namespace rayTracer {
    class PluginHandler {
        public:
            class Plugin {
                public:
                    Plugin(std::string path);
                    Plugin(Plugin&& other) noexcept;
                    Plugin& operator=(Plugin&& other) noexcept;
                    Plugin(const Plugin&) = delete;
                    Plugin& operator=(const Plugin&) = delete;

                    ~Plugin() = default;

                    std::unique_ptr<rayTracer::DLLoader> _loader;
                    std::unique_ptr<rayTracer::IFactory> _factory;
            };

            PluginHandler();
            ~PluginHandler() = default;

        private:
            std::vector<rayTracer::PluginHandler::Plugin> _plugins;
    };
};

#endif /* !PLUGINHANDLER_HPP_ */
