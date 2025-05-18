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
#include "SafeQueuePopOn.hpp"
#include "SafeQueuePushOn.hpp"
#include "DynamicQueue.hpp"
#include "Scene.hpp"
#include <chrono>

namespace rayTracer {
    class RenderPool {
        public:
            RenderPool(size_t nWorkers, std::vector<std::shared_ptr<std::vector<rayTracer::Pixel>>> &baseQueue, const rayTracer::Scene &scene);
            ~RenderPool();

        private:
            const size_t _nWorkers;
            std::vector<std::thread> _workers;
            rayTracer::DynamicQueue<std::vector<rayTracer::Pixel>> _renderQueue;
    };
};

#endif /* !RENDERPOOL_HPP_ */
