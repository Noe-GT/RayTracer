/*
** EPITECH PROJECT, 2025
** rayTracer
** File description:
** RenderPool
*/

#ifndef RENDERPOOL_HPP_
#define RENDERPOOL_HPP_

#include <thread>
#include "External.hpp"
#include "Pixel.hpp"
#include "DynamicQueue.hpp"
#include "Scene.hpp"
#include <chrono>

namespace rayTracer {
    class RenderPool {
        public:
            RenderPool(size_t nWorkers, std::vector<std::shared_ptr<std::vector<rayTracer::Pixel>>> &baseQueue);
            ~RenderPool();

            void render(const rayTracer::Scene &scene, const std::shared_ptr<IGraphical> &graphical);

        private:
            void displayRender(const std::shared_ptr<IGraphical> &graphical) const;

            size_t _nWorkers;
            std::list<std::thread> _workers;
            rayTracer::DynamicQueue<std::vector<rayTracer::Pixel>> _renderQueue;
    };
};

#endif /* !RENDERPOOL_HPP_ */
