#ifndef SCHEDULERS_FCFS_H
#define SCHEDULERS_FCFS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list
void add(char *name, int priority, int burst);
Task* pickNext();

// invoke the scheduler
void schedule();


#endif
