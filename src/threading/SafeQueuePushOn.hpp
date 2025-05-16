/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** safeQueuePushOn
*/

#ifndef _SAFE_QUEUE_PUSHON_HPP
#define _SAFE_QUEUE_PUSHON_HPP

#include "SafeQueue.hpp"

namespace rayTracer {
    template<class T>
    class SafeQueuePushOn : public rayTracer::SafeQueue<T> {
        public:
            SafeQueuePushOn() {}
            SafeQueuePushOn(const std::queue<T> &queue):
                rayTracer::SafeQueue<T>(queue)
            {}

            const std::queue<T> &getQueue() const {
                return this->_queue;
            }

            bool pop() = delete;
    };
};

#endif /* !_SAFE_QUEUE_PUSHON_HPP */
