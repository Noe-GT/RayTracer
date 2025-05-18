/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** RenderPool
*/

#include "RenderPool.hpp"

void workerRender(rayTracer::DynamicQueue<std::vector<rayTracer::Pixel>> &renderQueue, const rayTracer::Scene &scene)
{
    std::shared_ptr<std::vector<rayTracer::Pixel>> toRender = renderQueue.pop();

    while (toRender) {
        for (size_t i = 0; i < toRender->size(); i++)
            toRender->at(i).simulateRays(scene);
        toRender = renderQueue.pop();
    }
}

void rayTracer::RenderPool::displayRender(const std::shared_ptr<IGraphical> &graphical) const {
    std::vector<std::vector<math::Color>> dispVector;
    size_t yIndex = 0;

    while (graphical->isActive()) {
        if (graphical->doDisplay()) {
            while (yIndex < (this->_renderQueue.getAccessIndex() - this->_nWorkers)) {
                std::shared_ptr<const std::vector<rayTracer::Pixel>> vect = this->_renderQueue.peak(yIndex);
                dispVector.emplace_back();
                for (size_t x = 0; x < vect->size(); x++)
                    dispVector.back().push_back(vect->at(x).getColor());
                yIndex++;
            }
            graphical->display(dispVector);
        }
    }
}

rayTracer::RenderPool::RenderPool(size_t nWorkers, std::vector<std::shared_ptr<std::vector<rayTracer::Pixel>>> &baseQueue,
    const rayTracer::Scene &scene, const std::shared_ptr<IGraphical> &graphical):
    _nWorkers(nWorkers),
    _renderQueue(baseQueue)
{
    for (size_t i = 0; i < this->_nWorkers; i++)
        this->_workers.emplace_back(workerRender, std::ref(this->_renderQueue), scene);
    if (graphical)
        this->displayRender(graphical);
}

rayTracer::RenderPool::~RenderPool()
{
    for (std::thread &worker : _workers) {
        if (worker.joinable())
            worker.join();
    }
}
