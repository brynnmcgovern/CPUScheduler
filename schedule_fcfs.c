/**
1. Brynn McGovern
   2370579
   bmcgovern@chapman.edu
   CPSC 380-01
   Assignment 4 - CPU Scheduler
2. A program to act as a simulation of first-come first-served scheduling.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "cpu.h"



struct node *temp;

Task* pickNext()
{
    return (temp->task);

}
void add(char *name, int priority, int burst){

  Task *newTask;
  newTask = (Task*)malloc(sizeof(Task));
  (*newTask).priority = priority;
  (*newTask).burst = burst;
  (*newTask).name = name;
  insert(&temp, newTask);

}


void schedule(){

  Task *taskToPick;
    while (temp != NULL) {
        taskToPick = pickNext();

        run(taskToPick, taskToPick->burst);
        delete(&temp, taskToPick);
    }
}
