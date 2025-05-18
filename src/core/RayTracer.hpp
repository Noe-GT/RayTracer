#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "Ray.hpp"
#include "DLLoader.hpp"
#include "PluginHandler.hpp"
#include "Parser.hpp"
#include "Scene.hpp"
#include "Pixel.hpp"
#include "External.hpp"
#include "RenderPool.hpp"

namespace rayTracer {
    class RayTracer {
        public:
            RayTracer(std::string configFilePath);
            ~RayTracer();
            void render();
            void out();
            Scene &getScene();
            void setGraphical(std::shared_ptr<IGraphical> graphical);
            void setImage(const std::pair<size_t, size_t> &resolution);
            void setOutputFilePath(const std::string &outputFilePath);
            void setRayDefinition(size_t rayDefinition);
            void setShowRender(bool showRender);
            void setWorkers(size_t workers);
            std::pair<size_t, size_t>getImageResolution() const;

        private:
            size_t _rayDefinition;
            unsigned int _workers;
            std::string _outputFilePath;
            bool _showRender;
            std::shared_ptr<IGraphical> _graphical;
            rayTracer::PluginHandler _pluginHandler;
            rayTracer::Parser _parser;
            Scene _scene;
            std::vector<std::shared_ptr<std::vector<Pixel>>> _image;
            std::string _confPath;
    };
}

#endif /* !RAYTRACER_HPP_ */