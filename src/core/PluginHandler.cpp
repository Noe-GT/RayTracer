/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** PluginHandler
*/

#include "PluginHandler.hpp"

rayTracer::PluginHandler::PluginHandler() :
    _plugins()
{
    LibLister lister;

    for (std::string plugin : lister.getLibs()) {
        std::cout << "loaded: " << plugin << std::endl;
        this->_plugins.emplace_back(lister.getLibDirectory() + plugin);
    }
}

rayTracer::PluginHandler::Plugin::Plugin(std::string path) :
_loader(std::make_unique<rayTracer::DLLoader>(path))
{
}

// Move constructor
rayTracer::PluginHandler::Plugin::Plugin(Plugin&& other) noexcept :
    _loader(std::move(other._loader)) // Transfer ownership of the unique_ptr
{
}

// Move assignment operator
rayTracer::PluginHandler::Plugin& rayTracer::PluginHandler::Plugin::operator=(Plugin&& other) noexcept {
    if (this != &other) {
        _loader = std::move(other._loader); // Transfer ownership of the unique_ptr
    }
    return *this;
}