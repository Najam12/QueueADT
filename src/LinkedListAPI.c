/*
 Author: Najam Rizvi
 Date: May 28th 2018
 Purpose: Demonstrate some basic testing concepts
 University of Guelph, 2018.
 CIS*2520 (DE) S18
*/

#include <stdlib.h>
#include <stdio.h>
#include "LinkedListAPI.h"

Node *initializeNode(void *data){

    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->previous = NULL;

return newnode;
}

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){

    List * listnew = malloc (sizeof(List)); 

    listnew->head = NULL;

    listnew->printData = printFunction;
    
    listnew->deleteData = deleteFunction ;
    
    listnew->compare = compareFunction;

    return listnew;
}
 


void deleteList (List *list){

    if (list == NULL){
        
        return;
    }

    while (list -> head != NULL){
       
        Node *current = list->head;
        
        list-> head = list-> head -> next;

        list -> deleteData(current -> data);

        free (current);
        
    }
    
}


void insertBack(List *list, void *toBeAdded){

    Node *newnode = initializeNode((void*)toBeAdded);

    if(list==NULL){
        
        return;
    }

    if (list-> head == NULL){
        
        list-> head = newnode;

        list -> tail = newnode;
        return;
    }

    Node * temp = list->head; 
    
    while (temp -> next != NULL){
 
        temp = temp -> next;
 
    }

    temp -> next = newnode;
    
    newnode -> previous = temp;

    list-> tail = newnode;

}

void insertFront (List *list, void* toBeAdded){

    Node *nNode = initializeNode(toBeAdded);
    
    if (list == NULL){
    
        return;
    }

    if (list->head == NULL) {
        
        list->head = nNode;
        
        list->tail = nNode;
        
        return;
    }
  
    nNode -> next = list -> head;
    
    list -> head -> previous = nNode;
    
    list -> head = nNode;

}

void *getFromFront(List *list){

    if( list == NULL|| list -> head == NULL){

        return NULL;
    }

    return list ->head->data ; 

}

void *getFromBack (List *list){

    if (list == NULL || list -> head == NULL){

        return NULL;
    }

    Node * prev = list -> head;

    Node * curr = list -> head -> next; 

    while (curr != NULL){

        prev = curr;

        curr = curr -> next;
    }

    return prev -> data;

}

int deleteDataFromList(List *list, void *toBeDeleted){
    
    if(list == NULL || list -> head == NULL ||toBeDeleted == NULL){
        
        return 0;
    }
    Node *temp = list -> head;

    while(temp != NULL){
        
        if(list->compare(temp->data,toBeDeleted)==0){
            
            if (temp == list -> head){
                list -> head = temp -> next;
                
                if(list -> head != NULL ){
                    list -> head -> previous = NULL;
                    
                }   
            }

        else if (temp == list -> tail){
                  
            if (temp -> previous != NULL){
                
                temp -> previous->next = NULL; 
            }
        }

        else {
            
            temp -> previous -> next = temp-> next;
            temp -> next -> previous = temp -> previous;
            
        }
            list -> deleteData (temp-> data);
            free (temp);
            return 0;
    }
        temp = temp->next;
    }
      
    return -1;  
}

void printForward (List *list){

    if (list == NULL){

        return;
    }

    Node *temm = list -> head;

    while (temm != NULL){

        list -> printData (temm -> data);

        temm = temm -> next;
    }
    
}


void printBackwards(List *list){

    if(list == NULL){
    
    return;

    }
    Node * temm = list -> tail;

    while(temm != NULL){

        list -> printData(temm -> data);

        temm = temm -> previous;
    }
    
}

void insertSorted(List *list, void *toBeAdded){

    
    if (list == NULL){
        return;
    }

    if (list -> head == NULL){

        insertBack(list, toBeAdded);
        return;
    }

    if (toBeAdded <= list -> head -> data){

        insertFront (list, toBeAdded);
        return;
    }

    if (toBeAdded > list -> tail -> data){

        insertBack(list, toBeAdded);
        return;
    }

    Node * temp = list -> head;
    
    while (temp != NULL){ 
        
        if (toBeAdded <= temp -> data ){
            
            Node * new = initializeNode(toBeAdded);
            
            new -> next = temp;
            
            new -> previous = temp -> previous;
            
            temp -> previous -> next = new;
            
            temp -> previous = new;
            
            return;
        }

    temp = temp -> next;

    }

}


