/*
* @file queueADT.h
* @arthur Najam Rizvi
* @date May 28th 2018
* @brief File containing the function definitions of a queues 
*/

#ifndef _Queue_API_
#define _Queue_API_

#include <stdio.h>
#include <stdlib.h>
#include <LinkedListAPI.h>

typedef struct Quenode{
	
	void * data;
	struct Qnode * next;
	struct Qnode * previous;

}Qnode;

typedef struct QueueHead{
    List * thelist;
    int count;
    Qnode *Front;
    Qnode *Rear;
} Queue; 


void *createQueue(void(*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int(*compareFunction)(const void *first,const void *second));

void enQueue (Queue *queue, void *add);

void deQueue(Queue *queue);

void destroy(Queue * queue); 

#endif 