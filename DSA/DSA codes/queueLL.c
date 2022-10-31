#include<stdio.h>
#include<stdlib.h>

struct QNode
{
    int key;
    struct QNode *next;
};
struct Queue
{
    struct QNode *front, *rear;
};
struct QNode* newnode(int);
struct Queue* createQ();
void enqueue(struct Queue*, int);
void dequeue(struct Queue*);

int main()
{
    struct Queue *q = createQ();
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    printf("Queue front is %d \n", q->front->key);
    printf("Queue rear is %d \n", q->rear->key);
    return 0;
}
struct QNode* newnode(int n)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = n;
    temp->next = NULL;
    return temp;
}
struct Queue* createQ()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue *q, int n)
{
    struct QNode *temp = newnode(n);
    if(q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void dequeue(struct Queue *q)
{
    if(q->front == NULL)
        return;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
}