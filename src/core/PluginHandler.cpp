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
        this->cstrPlugin(plugin, lister);
        std::cout << "loaded: " << plugin << std::endl;
    }
    this->display();
    std::shared_ptr<IPrimitive> prim = this->_plugins.at(rayTracer::IFactory::ObjectType::PRIMITIVE).at("Sphere")._factory->build();
}

std::map<rayTracer::IFactory::ObjectType, std::map<std::string, rayTracer::PluginHandler::Plugin>> &rayTracer::PluginHandler::getPlugins()
{
    return this->_plugins;
}

void rayTracer::PluginHandler::cstrPlugin(const std::string &fileName, const LibLister &lister)
{
    std::string pluginName = this->getPluginName(fileName);
    rayTracer::PluginHandler::Plugin plugin(lister.getLibDirectory() + fileName, pluginName);
    rayTracer::IFactory::ObjectType type = plugin._factory->getObjectType();

    if (this->_plugins.find(type) == this->_plugins.end())
        this->_plugins.insert({type, std::map<std::string, rayTracer::PluginHandler::Plugin>()});
    this->_plugins.at(type).insert_or_assign(pluginName, plugin);
}

void rayTracer::PluginHandler::display() const
{
    std::cout << "PLUGINS" << std::endl;
    for (std::pair<rayTracer::IFactory::ObjectType, std::map<std::string, rayTracer::PluginHandler::Plugin>> pPair : this->_plugins) {
        std::cout << "Type: " << pPair.first << std::endl;
        for (const std::pair<std::string, rayTracer::PluginHandler::Plugin> plugin : pPair.second) {
            std::cout << "-" << plugin.first << std::endl;
        }
    }
}

std::string rayTracer::PluginHandler::getPluginName(const std::string &path) const
{
    std::string name = path;
    size_t sep = name.rfind(".");

    if (sep != name.npos)
        name = name.substr(0, sep);
    return name;
}

template <typename T> T rayTracer::PluginHandler::buildPlugin(const rayTracer::IFactory::ObjectType type, const std::string &name) const
{
    if (this->_plugins.find(type) == this->_plugins.end())
        throw PluginException("Invalid plugin type");
    if (this->_plugins.at(type).find(name) == this->_plugins.at(type).end())
        throw PluginException("Invalid plugin name");
    return this->_plugins.at(type).at(name)._factory->build();
}

rayTracer::PluginHandler::Plugin::Plugin(std::string path, std::string name):
    _loader(std::make_shared<rayTracer::DLLoader>(path)),
    _factory(this->_loader->getInstance<rayTracer::IFactory>(LOADER_INSTANCE_NAME)),
    _name(name)
{
}

rayTracer::PluginHandler::Plugin::Plugin(const rayTracer::PluginHandler::Plugin& other) noexcept:
    _loader(other._loader),
    _factory(other._factory),
    _name(other._name)
{
}

rayTracer::PluginHandler::Plugin::~Plugin()
{
}

rayTracer::PluginHandler::Plugin& rayTracer::PluginHandler::Plugin::operator=(const rayTracer::PluginHandler::Plugin& other) noexcept
{
    if (this != &other) {
        this->_loader = other._loader;
        this->_factory = other._factory;
    }
    return *this;
}

namespace rayTracer {
    std::ostream& operator<<(std::ostream& os, const rayTracer::PluginHandler::Plugin& plugin) {
        os << plugin._name;
        return os;
    }
}
