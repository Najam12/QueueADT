/*
 Author: Najam Rizvi
 Date: May 28th 2018
 Purpose: Demonstrate some basic testing concepts
 University of Guelph, 2018.
 CIS*2520 (DE) S18
*/

#include <stdlib.h>
#include <stdio.h>
#include "queueADT.h"
#include "LinkedListAPI.h"

void *createQueue(void(*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int(*compareFunction)(const void *first,const void *second)){

	Queue * queue = malloc(sizeof(Queue));

	queue -> thelist = initializeList(printFunction, deleteFunction, compareFunction);
   
	queue -> Front = queue -> thelist -> head;

	queue -> Rear = queue -> thelist -> tail;

	return queue;

}

void enQueue (Queue* queue, void *add){

	insertBack(queue -> thelist, add);

	queue -> Front = queue -> thelist -> tail;
	
	queue -> Front = queue -> thelist -> head;

	queue -> count ++;
}

void deQueue(Queue *queue){

	if(queue == NULL){

		return;
	}

	void * intial;

	intial = getFromFront(queue -> thelist);

	deleteDataFromList(queue -> thelist, intial);

	queue -> count --;

}

void destroy(Queue * queue){

	deleteList(queue -> thelist);

	free (queue);

}


