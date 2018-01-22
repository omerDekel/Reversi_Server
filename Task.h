//
// Created by omer on 22/01/18.
//

#ifndef UNTITLED6_TASK_H
#define UNTITLED6_TASK_H


class Task {
public:Task(void *(*func)(void *arg) , void *arg) : func(func) , arg(arg) {}
    /**
     * execute
     */
    void execute() {
        func(arg);
    }
    /**
     * distractor
     */
    virtual~Task() {}

private:
    void *(*func)(void *arg);
    void *arg;
};

#endif //UNTITLED6_TASK_H
