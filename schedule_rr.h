#ifndef SCHEDULE_RR_H
#define SCHEDULE_RR_H

void add(char *name, int priority, int burst);

// invoke the scheduler
void schedule();
Task* pickNext();

#endif
