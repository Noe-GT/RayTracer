/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** safeQueue
*/

#ifndef _SAFE_QUEUE_HPP
#define _SAFE_QUEUE_HPP

#include <thread>
#include <mutex>
#include <queue>

namespace rayTracer {
    template<class T>
    class SafeQueue {
        public:
            SafeQueue() {}
            SafeQueue(const std::queue<T> &queue):
                _queue(queue)
            {}

            void push(const T& val) {
                std::lock_guard<std::mutex> lock(_mutex);
                _queue.push(val);
            }

            bool pop(T& val) {
                std::lock_guard<std::mutex> lock(_mutex);
                if (!_queue.empty()) {
                    val = _queue.front();
                    _queue.pop();
                    return true;
                } else {
                    return false;
                }
            }

        protected:
            std::mutex _mutex;
            std::queue<T> _queue;
    };
};

#endif /* !_SAFE_QUEUE_HPP */
