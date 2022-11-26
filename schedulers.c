
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedulers.h"
#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedule_fcfs.h"
#include "schedule_rr.h"

struct node* temp = NULL;
void add(char *name, int priority, int burst){

  Task *newTask;
  newTask = (Task*)malloc(sizeof(Task));
  (*newTask).priority = priority;
  (*newTask).burst = burst;
  (*newTask).name = name;
  //assign parameters to task members
  insert(&temp, newTask);

  //add to list
}


void schedule(char* scheduleName){
  char* fcfsName = "fcfs";
  char* sjfName = "sjf";
  char* rrName = "rr";
  char* priorityName = "priority";
  //create objects for each scheduler
  if(strcmp(scheduleName, fcfsName) == 0){
    GetNodeData(temp);
    findavgTime();
  }
  else if(strcmp(scheduleName, sjfName) == 0){
    //do something
  }
  else if(strcmp(scheduleName, rrName) == 0){
    //do something
  }

  else if(strcmp(scheduleName, priorityName) == 0){
    //do something
  }

  else{
    //print error
  }
}

/**
int main(){

  add("file", 0, 1);
  add("butt", 3, 5);
  add("work", 8, 11);
  traverse(temp);
  schedule("fcfs");



}*/
