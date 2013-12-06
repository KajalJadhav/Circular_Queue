#include <stdbool.h>
typedef struct {
        int capacity;
        int size;
        int front;
        int rear;
        void *elements;
}Queue;

typedef char String[256];

Queue* create(int maxElements,int elementSize);
int enqueue(Queue *q,void* element);
void* dequeue(Queue *q);
void* front(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);