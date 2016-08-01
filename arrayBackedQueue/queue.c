
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Maximum number of elements in Queue
#define MAX_ARRAY 5

typedef unsigned int uint;
typedef enum { false, true } bool;


// method headers.
void newQueue(int* queue);
void printQueue(int* queue); 
bool enQueue(int* queue, int element);
int deQueue(int* queue);

static int elementCount;


// test routines
int main(int argc, char* argv[]) {
    int q [MAX_ARRAY];
    int sleepLoopCount = 30;
    const int sleepDelay = 3;
    newQueue(q);
    printQueue(q);

/*
    deQueue(q);

    enQueue(q, 7);
    printQueue(q);
    enQueue(q, 4);
    printQueue(q);

    printf("Dequeued value is %d\n", deQueue(q));
    printQueue(q);

*/
    srand(time(NULL));

    while(sleepLoopCount-- > 0) {
        int r = rand() % 20;
        if (elementCount == MAX_ARRAY) {
            printf("discarding %d\n", deQueue(q));
        }
        printf("Adding %d to queue.\n\t%d total elements\n",r, elementCount);
        enQueue(q,r);
        printQueue(q);
        sleep(sleepDelay);
    }
    
}



/****************************
 * Queue routines
 ****************************/

// initialize the queue, so all elements are pre-set to zero.
void newQueue(int* queue) {
    int i = MAX_ARRAY;
    elementCount = 0;
    for(; i >= 0; i--) {
        queue[i] = 0;
    }
}


// print all elements in the queue.
void printQueue(int* queue) {
    int i = 0;

    printf("----------\n");
    for(; i < MAX_ARRAY; i++) {
        printf("q[%2d]\t%d\n", i, queue[i]);
    }
    printf("----------\n");
}


// add an element to the end of the queue
bool enQueue(int* queue, int element) {
    bool added = false;
    if(elementCount < MAX_ARRAY) {
        // still room to add element
        queue[elementCount++] = element;   
        if (queue[elementCount - 1] == element) {
            added = true;
        }
    }
    return added;
}


// take the first element in the queue
int deQueue(int* queue) {
    int returnValue = queue[0];
    if (elementCount == 0) {
        printf("no elements in queue\n");
        return 0;
    }
    int i = 1;
    for(; i < MAX_ARRAY; i++) {
        queue[i-1] = queue[i];
    }
    elementCount--;
    return returnValue;
}



