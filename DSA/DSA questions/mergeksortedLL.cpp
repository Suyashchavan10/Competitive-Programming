/*You are given an array of k linked-lists lists,
 each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.*/
#include<bits/stdc++.h>
using namespace std;
/*struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = l1->val <= l2->val? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++)
            head = merge2Lists(head, lists[i]);
        
        return head;
    }
};*/
/* Takes two lists sorted in increasing order, and merge
   their nodes together to make one big sorted list. Below
   function takes O(n) extra space for recursive calls,
    */
struct Node {
    int data;
    Node* next;
};
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}
 
// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node* mergeKLists(Node* arr[], int last)
{
    // repeat until only one list is left
    while (last != 0) {
        int i = 0, j = last;
 
        // (i, j) forms a pair
        while (i < j) {
            // merge List i with List j and store
            // merged list in List i
            arr[i] = SortedMerge(arr[i], arr[j]);
 
            // consider next pair
            i++, j--;
 
            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }
 
    return arr[0];
}