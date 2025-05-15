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
#include "IGraphical.hpp"
#include "ITransformation.hpp"

namespace rayTracer {
    class PluginHandler {
        public:
            template <typename T>
            class Plugin {
                public:
                    Plugin(std::shared_ptr<rayTracer::DLLoader> loader, std::string name):
                        _loader(loader),
                        _factory(this->_loader->template getInstance<rayTracer::IFactory<T>>(LOADER_INSTANCE_NAME)),
                        _name(name)
                    {
                    }

                    Plugin(const rayTracer::PluginHandler::Plugin<T> &other) noexcept:
                        _loader(other._loader),
                        _factory(other._factory),
                        _name(other._name)
                    {
                    }

                    Plugin& operator=(const rayTracer::PluginHandler::Plugin<T> &other) noexcept
                    {
                        if (this != &other) {
                            this->_loader = other._loader;
                            this->_factory = other._factory;
                            this->_name = other._name;
                        }
                        return *this;
                    }

                    ~Plugin() {};

                    const std::shared_ptr<rayTracer::IFactory<T>> &getFactory() const
                    {
                        return this->_factory;
                    }

                    const std::string &getName() const
                    {
                        return this->_name;
                    }

                private:
                    std::shared_ptr<rayTracer::DLLoader> _loader;
                    std::shared_ptr<rayTracer::IFactory<T>> _factory;
                    std::string _name;
            };

            PluginHandler();
            ~PluginHandler() = default;

            void display() const;
            template <typename T> std::shared_ptr<rayTracer::IFactory<T>> getPluginFactory(rayTracer::PluginType type, const std::string &name) const;
            const std::map<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> &getPrimitivePlugins() const;
            const std::map<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> &getGraphicalPlugins() const;
            const std::map<std::string, rayTracer::PluginHandler::Plugin<ITransformation>> &getTransformationPlugins() const;

        private:
            void cstrPlugin(const std::string &fileName, const LibLister &lister);
            std::string getPluginName(const std::string &path) const;
            std::map<std::string, rayTracer::PluginHandler::Plugin<IPrimitive>> _primitivePlugins;
            std::map<std::string, rayTracer::PluginHandler::Plugin<IGraphical>> _graphicalPlugins;
            std::map<std::string, rayTracer::PluginHandler::Plugin<ITransformation>> _transformationPlugins;
    };
};

#endif /* !PLUGINHANDLER_HPP_ */
