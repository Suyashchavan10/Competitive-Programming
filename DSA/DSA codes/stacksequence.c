#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node* next;
};
void addatend(struct Node**, int);
bool stackseq(struct Node*);

int main()
{
    struct Node* head = NULL;
    int i,n;
    char ch[20];
    char check[20] = "e";
    while(1)
    {
        scanf("%s",ch);
        if(strcmp(ch, check) == 0)
            break;
        else
            n = atoi(ch);
            addatend(&head, n);
    }
    if(stackseq(head))
        printf("True");
    else
        printf("False");
}
void addatend(struct Node **ptr, int i)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *ptr;
    temp->data = i;
    temp->next = NULL;
    if(*ptr == NULL)
    {
        *ptr = temp;
        return;
    }
    while(last->next)
        last = last->next;

    last->next = temp;
}
bool stackseq(struct Node *head)
{
    struct Node *start = head, *cur = head;
    bool check = true;
    if(cur && cur->next)
    {
        while(cur->next)
        {
            if(cur->data < cur->next->data)
            {
                if(cur->next->data > start->data)
                {
                    start = cur->next;
                    cur = cur->next;
                }
                else
                {
                    check = false;
                    break;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
    }
    return check;
}