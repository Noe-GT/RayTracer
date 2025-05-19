/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** PluginHandler
*/

#include "PluginHandler.hpp"

rayTracer::PluginHandler::PluginHandler()
{
    LibLister lister;

    for (std::string plugin : lister.getLibs()) {
        this->cstrPlugin(plugin, lister);
    }
}

void rayTracer::PluginHandler::cstrPlugin(const std::string &fileName, const LibLister &lister)
{
    std::string pluginName = this->getPluginName(fileName);
    std::shared_ptr<rayTracer::DLLoader> loader = std::make_shared<rayTracer::DLLoader>(lister.getLibDirectory() + fileName);

    switch (loader->getLibType())
    {
        case rayTracer::PluginType::PRIMITIVE:
            this->_primitivePlugins.insert_or_assign(pluginName, rayTracer::PluginHandler::Plugin<rayTracer::IPrimitive>(loader, pluginName));
            break;
        case rayTracer::PluginType::GRAPHICAL:
            this->_graphicalPlugins.insert_or_assign(pluginName, rayTracer::PluginHandler::Plugin<IGraphical>(loader, pluginName));
            break;
        case rayTracer::PluginType::TRANSFORMATION:
            this->_transformationPlugins.insert_or_assign(pluginName, rayTracer::PluginHandler::Plugin<ITransformation>(loader, pluginName));
            break;
        default:
            break;
    }
}

void rayTracer::PluginHandler::display() const
{
    std::cout << "PLUGINS" << std::endl;
    std::cout << "#Primitives:" << std::endl;
    for (const std::pair<std::string, rayTracer::PluginHandler::Plugin<rayTracer::IPrimitive>> plugin : this->_primitivePlugins) {
        std::cout << "+--" << plugin.first << std::endl;
    }
    std::cout << "#Graphicals:" << std::endl;
    for (const std::pair<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> plugin : this->_graphicalPlugins) {
        std::cout << "+--" << plugin.first << std::endl;
    }
            std::cout << "#Transformations:" << std::endl;
            for (const std::pair<std::string, rayTracer::PluginHandler::Plugin<ITransformation>> plugin : this->_transformationPlugins) {
                std::cout << "+--" << plugin.first << std::endl;
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

const std::map<std::string, rayTracer::PluginHandler::Plugin<rayTracer::IPrimitive>> &rayTracer::PluginHandler::getPrimitivePlugins() const
{
    return this->_primitivePlugins;
}

const std::map<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> &rayTracer::PluginHandler::getGraphicalPlugins() const
{
    return this->_graphicalPlugins;
}

const std::map<std::string, rayTracer::PluginHandler::Plugin<ITransformation>> &rayTracer::PluginHandler::getTransformationPlugins() const
{
    return this->_transformationPlugins;
}
