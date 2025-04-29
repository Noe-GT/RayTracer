/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** PluginHandler
*/

#include "PluginHandler.hpp"

rayTracer::PluginHandler::PluginHandler():
    _plugins()
{
    LibLister lister;

    for (std::string plugin : lister.getLibs()) {
        std::cout << "loaded: " << plugin << std::endl;
        this->_plugins.emplace_back(lister.getLibDirectory() + plugin);
    }
}

rayTracer::PluginHandler::Plugin::Plugin(std::string path):
    _loader(std::make_unique<rayTracer::DLLoader>(path))
// _factory(std::move(this->_loader->getInstance(std::string(LOADER_INSTANCE_NAME))))
{
    this->_factory = std::move(this->_loader->getInstance<rayTracer::IFactory>(LOADER_INSTANCE_NAME));
}

rayTracer::PluginHandler::Plugin::Plugin(Plugin&& other) noexcept:
    _loader(std::move(other._loader)),
    _factory(std::move(other._factory))
{
}

rayTracer::PluginHandler::Plugin& rayTracer::PluginHandler::Plugin::operator=(Plugin&& other) noexcept
{
    if (this != &other) {
        this->_loader = std::move(other._loader);
        this->_factory = std::move(other._factory);
    }
    return *this;
}
