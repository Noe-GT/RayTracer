/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** safeQueuePopOn
*/

#ifndef _SAFE_QUEUE_POPON_HPP
#define _SAFE_QUEUE_POPON_HPP

#include "SafeQueue.hpp"

namespace rayTracer {
    template<class T>
    class SafeQueuePopOn : public rayTracer::SafeQueue<T> {
        public:
            SafeQueuePopOn() {}
            SafeQueuePopOn(const std::queue<T> &queue):
                rayTracer::SafeQueue<T>(queue)
            {}

            void setQueue(const std::queue<T> &queue)
            {
                this->_queue = queue;
            }

            void push(const T& val) = delete;
    };
};

#endif /* !_SAFE_QUEUE_POPON_HPP */
