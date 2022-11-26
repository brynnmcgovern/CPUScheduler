/**
1. Brynn McGovern
   2370579
   bmcgovern@chapman.edu
   CPSC 380-01
   Assignment 4 - CPU Scheduler
2. A program to act as a simulation of priority scheduling.
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

//compare function used in qsort()
int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;

    return 0;
}

int* sortTask()
{
    Node *temp;
    temp = head;
    static int sortedpriorities[30];
    int i = 0;
    while (temp != NULL) {
        sortedpriorities[i] = temp->task->priority;
        temp = temp->next;
        i++;
    }

    qsort(sortedpriorities, id, sizeof(int), comp);

    return sortedpriorities;
}

Task* pickNext()
{
    Node *temp = head->next;
    Task *tempTask = head->task;

    while (temp != NULL) {
        if(temp->task->priority > tempTask->priority) {
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
    //int *sortedTasks = sortTask();
    Task *taskToPick;
    while (head != NULL) {
        taskToPick = pickNext();
        // if (taskToPick == NULL)
        // {
        //     printf("Error: Can't find task to pick");
        //     break;
        // }

        run(taskToPick, taskToPick->burst);
        delete(&head, taskToPick);
    }
}
