#include "circular_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Queue* create(int maxElements,int elementSize){
    Queue *q;
    q = (Queue*)malloc(sizeof(Queue));
    q->elements = calloc(maxElements,elementSize);
    q->capacity = maxElements;
    q->size = elementSize;
    q->front = 0;
    q->rear = -1;
    return q;
}

int isFull(Queue* q){
    if(q->capacity-1 == q->rear && q->front == 0)
            return true;
    return false;
}
int isEmpty(Queue* q){
    if(q->rear == -1)
            return true;
    return false;
}
int enqueue(Queue *q,void* element){
    int length = q->front;
    if(q->front > 0 && q->front <= length)
            q -> rear = -1;
    if(isFull(q))
    	return 1;
    else {
      	void* address;
        q->size++;
        q->rear++;
        address = q->elements+(q->rear*q->size);
            memmove(address,element, q->size);
        return 0;
    }
}
void* dequeue(Queue* queue){
    if(isEmpty(queue)) return NULL;        
    queue->front++;
    return queue->elements;
}
void* front(Queue *q){
    if(q->rear == -1)
        return NULL;
    return &q->front;
}