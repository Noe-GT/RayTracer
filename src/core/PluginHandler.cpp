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
}

std::map<rayTracer::IFactory::ObjectType, std::vector<rayTracer::PluginHandler::Plugin>> &rayTracer::PluginHandler::getPlugins()
{
    return this->_plugins;
}

void rayTracer::PluginHandler::cstrPlugin(const std::string &name, const LibLister &lister)
{
    rayTracer::PluginHandler::Plugin plugin(lister.getLibDirectory() + name);
    rayTracer::IFactory::ObjectType type = plugin._factory->getObjectType();

    if (this->_plugins.find(type) == this->_plugins.end())
        this->_plugins.insert({type, std::vector<rayTracer::PluginHandler::Plugin>()});
    this->_plugins.at(type).push_back(plugin);
}

void rayTracer::PluginHandler::display() const
{
    std::cout << "PLUGINS" << std::endl;
    for (std::pair<rayTracer::IFactory::ObjectType, std::vector<rayTracer::PluginHandler::Plugin>> pPair : this->_plugins) {
        std::cout << "Type: " << pPair.first << std::endl;
        for (const rayTracer::PluginHandler::Plugin &plugin : pPair.second) {
            std::cout << "-" << plugin << std::endl;
        }
    }
}

rayTracer::PluginHandler::Plugin::Plugin(std::string path):
    _loader(std::make_shared<rayTracer::DLLoader>(path)),
    _factory(this->_loader->getInstance<rayTracer::IFactory>(LOADER_INSTANCE_NAME))
{
    size_t sep = path.rfind("/");
    if (sep != path.npos)
        this->_name = path.substr(sep + 1, path.size());
    sep = this->_name.rfind(".");
    if (sep != this->_name.npos)
        this->_name = this->_name.substr(0, sep);
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
