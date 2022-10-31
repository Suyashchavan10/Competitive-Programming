#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct StackNode
{
    int data;
    struct StackNode *next;
};
struct StackNode* newnode(int);
int isempty(struct StackNode*);
void push(struct StackNode**, int);
int pop(struct StackNode**);
int top(struct StackNode*);

int main()
{
    struct StackNode *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printf("%d is popped from stack \n", pop(&head));
    printf("Top element is %d", top(head));
    return 0;
}

struct StackNode* newnode(int n)
{
    struct StackNode *new = (struct StackNode*)malloc(sizeof(struct StackNode));
    new->data = n;
    new->next = NULL;
    return new;
}

int isempty(struct StackNode *h)
{
    if(h != NULL)
        return 0;
    else
        return 1;
}
void push(struct StackNode **h, int n)
{
    struct StackNode *new = newnode(n);
    new->next = *h;
    *h = new;
    printf("%d is pushed to the stack \n", n);
}
int pop(struct StackNode **h)
{
    //if(isempty(*h))
    //    printf("Stack is empty");
    //    return INT_MIN;
    struct StackNode *temp = *h;
    *h = (*h)->next;
    int popdata = temp->data;
    free(temp);
    return(popdata);
}
int top(struct StackNode *h)
{
    //if(isempty(h))
    //    printf("Stack is empty");
    //    return INT_MIN;
    return(h->data);
}
