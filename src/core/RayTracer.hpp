#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "Ray.hpp"
#include "DLLoader.hpp"
#include "PluginHandler.hpp"
#include "Parser.hpp"
#include "Scene.hpp"
#include "Pixel.hpp"
#include "External.hpp"

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
            std::pair<size_t, size_t>getImageResolution() const;

        private:
            std::string _outputFilePath;
            std::shared_ptr<IGraphical> _graphical;
            rayTracer::PluginHandler _pluginHandler;
            rayTracer::Parser _parser;
            Scene _scene;
            std::vector<std::vector<Pixel>> _image;
            std::string _confPath;
        };
}

#endif /* !RAYTRACER_HPP_ */