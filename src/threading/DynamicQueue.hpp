/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DynamicQueue
*/

#ifndef _DYNAMIC_QUEUE_HPP
#define _DYNAMIC_QUEUE_HPP

#include <thread>
#include <mutex>
#include <queue>

namespace rayTracer {
    template<class T>
    class DynamicQueue {
        public:
            DynamicQueue(std::vector<T> &queue):
                _accessIndex(0),
                _queue(queue)
            {}

            void push(const T& val) {
                std::lock_guard<std::mutex> lock(_mutex);
                this->_queue.push_back(val);
            }

            std::unique_ptr<T> pop() {
                std::lock_guard<std::mutex> lock(_mutex);
                if (!_queue.empty() && this->_accessIndex < this->_queue.size()) {
                    this->_accessIndex++;
                    return std::make_unique<T>(this->_queue[this->_accessIndex - 1]);
                } else {
                    return nullptr;
                }
            }

            // bool set(const T& val, size_t index) {
            //     std::lock_guard<std::mutex> lock(_mutex);
            //     if (!_queue.empty() && index < this->_queue.size()) {
            //         this->_queue[index] = val;
            //         return true;
            //     } else {
            //         return false;
            //     }
            // }

        protected:
            size_t _accessIndex;
            std::mutex _mutex;
            std::vector<T> &_queue;
    };
};

#endif /* !_DYNAMIC_QUEUE_HPP */
