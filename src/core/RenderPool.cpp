/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** RenderPool
*/

#include "RenderPool.hpp"

void render(rayTracer::DynamicQueue<std::vector<rayTracer::Pixel>> &renderQueue, const rayTracer::Scene &scene)
{
    std::shared_ptr<std::vector<rayTracer::Pixel>> toRender = renderQueue.pop();

    while (toRender) {
        for (size_t i = 0; i < toRender->size(); i++)
            toRender->at(i).simulateRays(scene);
        toRender = renderQueue.pop();
    }
}

rayTracer::RenderPool::RenderPool(size_t nWorkers,
    std::vector<std::shared_ptr<std::vector<rayTracer::Pixel>>> &baseQueue, const rayTracer::Scene &scene):
    _nWorkers(nWorkers),
    _renderQueue(baseQueue)
{
    this->_workers.resize(this->_nWorkers);
    for (size_t i = 0; i < this->_nWorkers; i++)
        this->_workers.emplace_back(render, std::ref(this->_renderQueue), scene);
}

rayTracer::RenderPool::~RenderPool()
{
    for (std::thread &worker : _workers) {
        if (worker.joinable())
            worker.join();
    }
}
