/**
1. Brynn McGovern
   2370579
   bmcgovern@chapman.edu
   CPSC 380-01
   Assignment 4 - CPU Scheduler
2. A program to act as a simulation of shortest job first scheduling.
*/

#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

typedef struct node Node;
Node *taskList;
Node *head;
int id = 0;

Task* pickNext()
{
    Node *temp = head->next;;
    Task *tempTask = head->task;

    while (temp != NULL) {
        if(temp->task->burst < tempTask->burst) {
            tempTask = temp->task;
        }
        temp = temp->next;
    }

    return tempTask;
}

// add a task to the list
void add(char *name, int priority, int burst)
{
    Task *newTask = (Task*) malloc(sizeof(Task));
    newTask->tid = id;
    newTask->name = name;
    newTask->priority = priority;
    newTask->burst = burst;

    insert(&head, newTask);
    id++;
}

void schedule()
{
    Task *taskToPick;
    while (head != NULL) {
        taskToPick = pickNext();

        run(taskToPick, taskToPick->burst);
        delete(&head, taskToPick);
    }
}
