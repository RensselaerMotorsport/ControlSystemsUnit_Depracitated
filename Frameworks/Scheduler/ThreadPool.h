/*
 * -----------------------------------------------------------------
 *  _______ _                        _   _____            _
 * |__   __| |                      | | |  __ \          | |
 *    | |  | |__  _ __ ___  __ _  __| | | |__) |__   ___ | |
 *    | |  | '_ \| '__/ _ \/ _` |/ _` | |  ___/ _ \ / _ \| |
 *    | |  | | | | | |  __/ (_| | (_| | | |  | (_) | (_) | |
 *    |_|  |_| |_|_|  \___|\__,_|\__,_| |_|   \___/ \___/|_|
 *
 * ------------------------------------------------------------------
 *
 * Class Function: The ThreadPool class manages a pool of threads that can
 *                 be utilized to execute tasks in parallel. It maintains a
 *                 queue of tasks and distributes them among a specified
 *                 number of worker threads, allowing for concurrent
 *                 execution of tasks and more efficient use of system
 *                 resources in a multithreaded environment.
 *
 * Member Variables:
 * - workers: A vector of worker threads that execute tasks.
 * - tasks: A queue of tasks to be executed by the worker threads.
 * - queueMutex: A mutex to ensure thread-safe access to the task queue.
 * - condition: A condition variable used to notify worker threads of
 *              available tasks.
 * - stop: A boolean flag indicating whether the thread pool is stopping.
 *
 * Member functions:
 * - Constructor: Initializes the thread pool and creates worker threads.
 * - Destructor: Ensures all threads finish and cleans up resources.
 * - enqueue: Adds a task to the task queue to be executed by a worker thread.
 *
 */
#ifndef RENNSMOTORSPORT_THREADPOOL_H
#define RENNSMOTORSPORT_THREADPOOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
public:
    ThreadPool(size_t threads);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

#endif // THREADPOOL_H