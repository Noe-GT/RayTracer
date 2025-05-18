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
            DynamicQueue(std::vector<std::shared_ptr<T>> &queue):
                _accessIndex(0),
                _done(0)
            {
                for (std::shared_ptr<T> &elem : queue)
                    this->_queue.push_back(elem);
            }

            const std::shared_ptr<T> pop() {
                std::lock_guard<std::mutex> lock(_mutex);
                if (!_queue.empty() && this->_accessIndex < this->_queue.size()) {
                    this->_accessIndex++;
                    return this->_queue[this->_accessIndex - 1];
                } else {
                    return nullptr;
                }
            }

            void incDone() {
                std::lock_guard<std::mutex> lock(_mutex);
                this->_done++;
            }

            size_t getDone() const {
                return this->_done;
            }

            void reset() {
                this->_accessIndex = 0;
                this->_done = 0;
            }

            size_t size() const {
                return this->_queue.size();
            }

            size_t getAccessIndex() const {
                return this->_accessIndex;
            }

            std::shared_ptr<const T> peak(size_t index) const {
                if (index < _queue.size()) {
                    return std::const_pointer_cast<const T>(this->_queue[index]);
                } else {
                    return nullptr;
                }
            }

        private:
            size_t _accessIndex;
            size_t _done;
            std::mutex _mutex;
            std::vector<std::shared_ptr<T>> _queue;
    };
};

#endif /* !_DYNAMIC_QUEUE_HPP */
