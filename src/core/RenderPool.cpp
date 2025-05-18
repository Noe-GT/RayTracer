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
        renderQueue.incDone();
        toRender = renderQueue.pop();
    }
}

void rayTracer::RenderPool::displayRender(const std::shared_ptr<IGraphical> &graphical) const {
    std::vector<std::vector<math::Color>> dispVector;
    size_t yIndex = 0;

    if (graphical->isActive()) {
        if (graphical->doDisplay()) {
            while (yIndex < this->_renderQueue.getDone()) {
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

rayTracer::RenderPool::RenderPool(size_t nWorkers, std::vector<std::shared_ptr<std::vector<rayTracer::Pixel>>> &baseQueue):
    _nWorkers(nWorkers),
    _renderQueue(baseQueue)
{
}

rayTracer::RenderPool::~RenderPool()
{
    for (std::thread &worker : _workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

void rayTracer::RenderPool::render(const rayTracer::Scene &scene, const std::shared_ptr<IGraphical> &graphical)
{
    for (size_t i = 0; i < this->_nWorkers; i++)
        this->_workers.emplace_back(workerRender, std::ref(this->_renderQueue), scene);
    while (this->_renderQueue.getDone() != this->_renderQueue.size()) {
        if (graphical)
            this->displayRender(graphical);
    }
    std::cout << "Rendering done." << std::endl;
    if (graphical) {
        this->displayRender(graphical);
        graphical->idle();
    }
}
