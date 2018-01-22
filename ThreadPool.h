//
// Created by omer on 22/01/18.
//

#ifndef UNTITLED6_THREADPOOL_H
#define UNTITLED6_THREADPOOL_H

#include"Task.h"
#include<queue>
#include<pthread.h>
using namespace std;
class ThreadPool {
public:
    /**
     * consractor
     * @param threadsNum the threadsNum
     */
    ThreadPool(int threadsNum);
    /**
     * adding task
     * @param task the task
     */
    void addTask(Task *task);
    /**
     * terminate the treads
     */
    void terminate();
    /**
     * distractor
     */
    virtual~ThreadPool();
private:
    queue<Task *> tasksQueue;
    pthread_t * threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);

};
#endif //UNTITLED6_THREADPOOL_H
