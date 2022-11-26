#ifndef SCHEDULERS_FCFS_H
#define SCHEDULERS_FCFS_H

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list
void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();
//iterate through nodes of list according to process
//pass type of scheduler to function

//check to see how list node holds information; cout list node

#endif
