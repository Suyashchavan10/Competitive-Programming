#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
struct Node
{
    int data;
    struct Node* next;
};
void printlist(struct Node*);
void addatbeg(struct Node**, int);
void addatend(struct Node**, int);
void addafter(struct Node*, int);
void printrevlist(struct Node*);
void delatbeg(struct Node**);
void delatend(struct Node**);
void reverse(struct Node**);
int lenglist(struct Node*);
void delkey(struct Node**, int);
bool search(struct Node*, int);
void sortlist(struct Node*);
bool checkcycle(struct Node*);
int cyclelength(struct Node*);
int nthnode(struct Node*, int);
void addatind(struct Node**, int, int);

int main()
{
    //linked list creation according to user input.
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
    //linked list creation manually.
    //struct Node* head = NULL;
    //struct Node* second = NULL;
    //struct Node* third = NULL;

    //head = (struct Node*)malloc(sizeof(struct Node));
    //second = (struct Node*)malloc(sizeof(struct Node));
    //third = (struct Node*)malloc(sizeof(struct Node));

    //head->data = 1;
    //scanf("%d",&(head->data));
    //head->next = second;
    //second->data = 2;
    //scanf("%d",&(second->data));
    //second->next = third;
    //third->data = 3;
    //scanf("%d",&(third->data));
    //third->next = NULL;

    
    printlist(head);
    //sortlist(head);
    addatind(&head, 2, 3);
    printlist(head);
    /*addatbeg(&head, 0);
    printlist(head);
    addatend(&head, 4);
    printlist(head);
    printrevlist(head);
    printf("\n");
    delatbeg(&head);
    printlist(head);
    delatend(&head);
    printlist(head);
    reverse(&head);
    printlist(head);
    printf("%d",lenglist(head));*/
    return 0;
    
}
//linked list traversal and printing resp. values.
void printlist(struct Node *ptr)
{
    while(ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
//inserting new node at the beginning. **ptr == passing head of LL by reference.
void addatbeg(struct Node **ptr, int i)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = i;
    temp->next = *ptr;
    *ptr = temp;
}
//inserting new node at the end.
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
//inserting new node after a given node. *ptr == prev node.
void addafter(struct Node *ptr, int i)
{
    if(ptr == NULL)
    {
        printf("Previous node can't be NULL");
        return;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = i;
    temp->next = ptr->next;
    ptr->next = temp;
}
//printing given LL in reverse manner. ptr==head of LL.
void printrevlist(struct Node *ptr)
{
    if(ptr == NULL)
        return; 
    printrevlist(ptr->next);
    printf("%d ", ptr->data);
}
//deleting the first head node.
void delatbeg(struct Node **ptr)
{
    struct Node *temp = *ptr;
    if(*ptr)
    {
        *ptr = (*ptr)->next;
        free(temp);
    }
}
//deleting the last node.
void delatend(struct Node **ptr)
{
    struct Node *last = *ptr;
    if(last)
    {
        if(last->next)
        {
            while(last->next->next)
            last = last->next;
            free(last->next);
            last->next = NULL;
        }
        else
            last = NULL;
    }
}
//reversing a given LL. *ptr== head pointer.
void reverse(struct Node **ptr)
{
    struct Node *prev = NULL;
    struct Node *current = *ptr;
    struct Node *next = NULL;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ptr = prev;
}
//counting the length of LL can be done simply by doing count++ until current = NULL. where current starts from head of LL.
//we can count the length of LL recursively.
int lenglist(struct Node *ptr)
{
    int count=0;
    struct Node *temp = ptr;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return(count);
}
//delete the first occurence of the given key in LL.
void delkey(struct Node **ptr, int k)
{
    struct Node *temp = *ptr, *prev;
    if(temp != NULL && temp->data == k)
    {
        *ptr = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != k)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
//searching a given key in LL.
bool search(struct Node *h, int n)
{
    struct Node *cur = h;
    while(cur)
    {
        if(cur->data == n)
            return true;
        cur = cur->next;
    }
    return false;
}
//sorting a LL according to non-dcreasing order of data by using selection sort.
void sortlist(struct Node *cur)
{
    struct Node *trav = NULL;
    int t;
    if(cur)
    {
        if(cur->next)
        {
            while(cur->next)
            {
                trav = cur->next;
                while(trav)
                {
                    if(cur->data > trav->data)
                    {
                        t = cur->data;
                        cur->data = trav->data;
                        trav->data = t;
                    }
                    trav = trav->next;
                }
                cur = cur->next;
            }
        }
    }
}    
//checking the presence of cycle in LL by using Floyd's cycle detection algorithm.
bool checkcycle(struct Node *h)
{
    struct Node *slow = h, *fast = h;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}
//counting total number of nodes in a cycle in a LL.
int cyclelength(struct Node *h)
{
    struct Node *slow = h, *fast = h, *temp = NULL;
    int leng = 1;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            temp = slow;
            while(temp->next != slow)
            {
                leng++;
                temp = temp->next;
            }
            return leng;
        }
    }
    return 0;
}
//finding a data at given node index from starting.
//we can similarly find data at nth node from end by first counting length of LL and then ind = leng-n+1;
//we can use 2 pointers as main_ptr and ref_ptr. ref_ptr = main_ptr + n. travel untill ref_ptr->next != NULL.
int nthnode(struct Node *h, int ind)
{
    struct Node *cur = h;
    int count = 0;
    while(cur)
    {
        if(count == ind)
            return(cur->data);
        count++;
        cur = cur->next;
    }
    assert(0);
}
//to find middle node, we can use 2 pointers as slowptr(x) and fastptr(2x). when fastptr or fastptr->next == NULL, mid = slowptr.
void addatind(struct Node **h, int ind, int num)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *trav = *h;
    temp->data = num;
    temp->next = NULL;
    int t = 1;
    if(ind == 0)
    {
        temp->next = *h;
        *h = temp;
    }
    else
    {
        while(t != ind)
        {
            trav = trav->next;
            t++;
        }
        temp->next = trav->next;
        trav->next = temp;
    }
}


















