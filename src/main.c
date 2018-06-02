
#include <stdio.h>
#include <stdlib.h>
#include <queueADT.h>
#include <LinkedListAPI.h>
#include <test.h>
#include <queueADT.c>

void delete(void * toBeDeleted){

    
 free(toBeDeleted);
    
}
int comp(const void *a, const void *b){
    
 int * first = (int*)a;
 int * second = (int*)b;
 return (*first) - (*second);
}
void print(void * toBePrinted)
{
    
 int * a = (int*)toBePrinted;
 printf("%d ", *a);
 return;
    
}

int main(int argc ,char * argv[]){

	Queue * queue = createQueue(&print, &delete, &comp);	

	int * number = NULL;

	if(queue == NULL){
		return 1;
	}

	for(int i = 0; i < 4; i++){
 		
 		number = malloc(sizeof(int));
 		*number = i;

 		enQueue (queue , number);
		
 	}

 	printForward(queue -> thelist);

 	printf("\nTesting remove element from front\n");
 	
 	deQueue(queue);

 	printForward(queue -> thelist);

	printf("\nTesting destroy the queue function\n");

 	destroy(queue);


 	FILE * ptr;

	ptr = fopen ("input.txt", "r"); 	

	/*while ((ch= fgetc(ptr)) != -1){

		printf("%c",ch );
	int ch;
	} 

	 
	Creating 4 queues

	*/

	void * add;

	Queue * North = createQueue(&print, &delete, &comp);	

		enQueue (Queue -> Car, add);

	Queue * South = createQueue(&print, &delete, &comp);	

	Queue * East = createQueue(&print, &delete, &comp);	

	Queue * West = createQueue(&print, &delete, &comp);	

}

