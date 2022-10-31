#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int data;
    struct Node* next;
};
void addatend(struct Node**, int);
void printlist(struct Node*);
struct Node* mergesort(struct Node*, struct Node*);
int main()
{
    struct Node* head1 = NULL;
    int n;
    char ch[20];
    char check[20] = "e";
    while(1)
    {
        scanf("%s",ch);
        if(strcmp(ch, check) == 0)
            break;
        else
            n = atoi(ch);
            addatend(&head1, n);
    }
    
    struct Node* head2 = NULL;
    while(1)
    {
        scanf("%s",ch);
        if(strcmp(ch, check) == 0)
            break;
        else
            n = atoi(ch);
            addatend(&head2, n);
    }
    
    struct Node *head = NULL;
    head = mergesort(head1, head2);
    printlist(head);

    return 0;
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
void printlist(struct Node *ptr)
{
    while(ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct Node* mergesort(struct Node *h1, struct Node *h2)
{
    struct Node *head = NULL;
    struct Node *cur = NULL;
    if(h1 == NULL && h2 != NULL)
    {
        head = h2;
        return(head);
    }
    if(h1 != NULL && h2 == NULL)
    {
        head = h1;
        return(head);
    }
    if(h1 == NULL && h2 == NULL)
    {
        return(NULL);
    }
    if(h1 != NULL && h2 != NULL)
    {
        if(h1->data <= h2->data)
        {
            head = h1;
            h1 = h1->next;
            cur = head;
        }   
        else
        {
            head = h2;
            h2 = h2->next;
            cur = head;
        }
    }

    while(h1 != NULL || h2 != NULL)
    {
        if(h1 != NULL && h2 != NULL)
        {
            if(h1->data <= h2->data)
            {
                cur->next = h1;
                h1 = h1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
                cur = cur->next;
            }
        }
        else
        {
            if(h1 == NULL)
            {
                cur->next = h2;
                break;
            }
            if(h2 == NULL)
            {
                cur->next = h1;
                break;
            }
        }
        /*if(h1 == NULL && h2 != NULL)
        {
            cur->next = h2;
            break;
        }
        if(h1 != NULL && h2 == NULL)
        {
            cur->next = h1;
            break;
        }
        if(h1 == NULL && h2 == NULL)
        {
            break;
        }*/
        
        
    }
    return(head);
}