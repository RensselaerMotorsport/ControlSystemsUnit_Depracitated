#include "ThreadPool.h"
#include <stdexcept>
#include <iostream>

ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for(size_t i = 0; i < threads; ++i)
        workers.emplace_back([this] {
            for(;;) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(this->queueMutex);
                    this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); });
                    if(this->stop && this->tasks.empty())
                        return;
                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }
                task();
            }
        });
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        if(stop) throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace(task);

        if(tasks.size() > workers.size()) {
            // Warning: More tasks enqueued than available worker threads
            // std::cerr << "\033[33mWarning: More tasks enqueued than available worker threads.\033[0m" << std::endl;
        }
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker: workers)
        worker.join();
}
