/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** PluginHandler
*/

#include "PluginHandler.hpp"

rayTracer::PluginHandler::PluginHandler():
    _primitivePlugins()
{
    LibLister lister;

    for (std::string plugin : lister.getLibs()) {
        this->cstrPlugin(plugin, lister);
    }
    // this->display();
}

void rayTracer::PluginHandler::cstrPlugin(const std::string &fileName, const LibLister &lister)
{
    std::string pluginName = this->getPluginName(fileName);
    std::shared_ptr<rayTracer::DLLoader> loader = std::make_shared<rayTracer::DLLoader>(lister.getLibDirectory() + fileName);

    std::cout << "Loading plugin: " << fileName << std::endl;
    switch (loader->getLibType())
    {
        case rayTracer::PluginType::PRIMITIVE:
            this->_primitivePlugins.insert_or_assign(pluginName, rayTracer::PluginHandler::Plugin<IPrimitive>(loader, pluginName));
            break;
        case rayTracer::PluginType::GRAPHICAL:
            this->_graphicalPlugins.insert_or_assign(pluginName, rayTracer::PluginHandler::Plugin<IGraphical>(loader, pluginName));
            break;
        default:
            break;
    }
}

void rayTracer::PluginHandler::display() const
{
    std::cout << "PLUGINS" << std::endl;
    for (const std::pair<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> plugin : this->_primitivePlugins) {
        std::cout << "-" << plugin.first << std::endl;
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

template <typename T>
std::shared_ptr<rayTracer::IFactory<T>> rayTracer::PluginHandler::getPluginFactory(rayTracer::PluginType type, const std::string &name) const
{
    switch (type) {
        case rayTracer::PluginType::PRIMITIVE:
            if (this->_primitivePlugins.find(name)!= this->_primitivePlugins.end())
                return this->_primitivePlugins.at(name).getFactory();
            break;
        default:
            break;
    }
    return nullptr;
}

const std::map<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> &rayTracer::PluginHandler::getPrimitivePlugins() const
{
    return this->_primitivePlugins;
}

const std::map<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> &rayTracer::PluginHandler::getGraphicalPlugins() const
{
    return this->_graphicalPlugins;
}

// template <typename T>
// rayTracer::PluginHandler::Plugin<T>::Plugin(std::shared_ptr<rayTracer::DLLoader> loader, std::string name):
//     _loader(loader),
//     _factory(this->_loader->getInstance<rayTracer::IFactory<T>>(LOADER_INSTANCE_NAME)),
//     _name(name)
// {
// }

// template <typename T>
// rayTracer::PluginHandler::Plugin<T>::Plugin(const Plugin<T>& other) noexcept:
//     _loader(other._loader),
//     _factory(other._factory),
//     _name(other._name)
// {
// }

// template <typename T>
// rayTracer::PluginHandler::Plugin<T>::~Plugin()
// {
// }

// template <typename T>
// rayTracer::PluginHandler::Plugin<T>& rayTracer::PluginHandler::Plugin<T>::operator=(const Plugin<T>& other) noexcept
// {
//     if (this != &other) {
//         this->_loader = other._loader;
//         this->_factory = other._factory;
//         this->_name = other._name;
//     }
//     return *this;
// }

// template <typename T>
// const std::string &rayTracer::PluginHandler::Plugin<T>::getName() const
// {
//     return this->_name;
// }

// template <typename T>
// const std::shared_ptr<rayTracer::IFactory<T>> &rayTracer::PluginHandler::Plugin<T>::getFactory() const
// {
//     return this->_factory;
// }
