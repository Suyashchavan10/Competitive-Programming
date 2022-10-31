#include<bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
};
 
//Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* Given a binary tree, print its nodes according to the "bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    cout << node->data << " ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left subtree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

// Iterative method to find height, level of Binary Tree
void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

/* Compute the "maxDepth" of a tree -- the number of nodes along the longest path
from the root node down to the farthest leaf node.*/
int maxDepth(Node* root) 
{
    if(root == NULL)
        return 0;
    int depl = maxDepth(root->left);
    int depr = maxDepth(root->right);
    return max(depl, depr)+1;
}

int minDepth(Node* root) 
{
    if(root == NULL)
        return 0;
    int depl = minDepth(root->left);
    int depr = minDepth(root->right);
    int minm = min(depl, depr);
    int maxm = max(depl, depr);
    if(minm > 0)
        return minm+1;
    else
        return maxm+1;
}

// Iterative function to do Preorder traversal of the tree using stacks.
void preorderIterative(Node* root)
{
    if (root == NULL)
        return;
 
    stack<Node*> st;
 
    // start from root node (set current node to root node)
    Node* curr = root;
 
    // run till stack is not empty or current is not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist and keep pushing right into the stack.
        while (curr != NULL) {
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
 
        // We reach here when curr is NULL, so We take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

/* Iterative function for inorder tree traversal */
void inorderIterative(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on the stack before traversing the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its left subtree. Now, it's right subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}
/* Function to find index of value in arr[start...end].The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

/* Recursive function to construct binary of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking for cases where inorder and preorder do not form a tree */
Node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    // Pick current node from Preorder traversal using preIndex and increment preIndex
    Node* tNode = newNode(pre[preIndex++]);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);
 
    /* Using index in Inorder traversal, construct left and right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}
//recursive approach.
bool isSameTreeR(Node* p, Node* q) 
{
    if(p == NULL || q == NULL)
    {
        if(p == q)
            return true;
        else
            return false;
    }
    bool bool1 = isSameTreeR(p->left, q->left);
    bool bool2 = isSameTreeR(p->right, q->right);
    return (p->data==q->data && bool1 && bool2);
}
void checking1(vector<int> &v1, Node* p)
    {
        if(p == NULL)
        {
            v1.push_back(0);

            return;
        }
        v1.push_back(p->data);
        checking1(v1, p->left);
        checking1(v1, p->right);
    }
    void checking2(vector<int> &v2, Node* q)
    {
        if(q == NULL)
        {
            v2.push_back(0);
            return;
        }
        v2.push_back(q->data);
        checking2(v2, q->left);
        checking2(v2, q->right);
    }
    bool isSameTree(Node* p, Node* q) {
        vector<int> v1;
        vector<int> v2;
        checking1(v1,p);
        checking2(v2,q);
        return v1==v2;
        
    }
//checking 2 trees are mirror images of each other or not.
bool isMirror(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    //For two trees to be mirror images, the following three conditions must be true :
	// 1.) Their root node's key must be same
	// 2.) left subtree of left tree and right subtree of right tree have to be mirror images
	// 3.) right subtree of left tree and left subtree of right tree have to be mirror images
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    return false;
}
bool isSymmetric(Node* root)
    {
        return isMirror(root, root);
    }

Node *buildTree2(int in[], int post[], int n)
{
 
  // Create Stack of type Node*
  stack<Node*> st;
 
  // Create Set of type Node*
  set<Node*> s;
 
  // Initialise postIndex with n - 1
  int postIndex = n - 1;
 
  // Initialise root with NULL
  Node* root = NULL;
 
  for (int p = n - 1, i = n - 1; p>=0 ;) 
  {
 
    // Initialise node with NULL
    Node* node = NULL;
     
    // Run do-while loop
    do
    {
 
      // Initialise node with
      // new Node(post[p]);
      node = newNode(post[p]);
 
      // Check is root is
      // equal to NULL
      if (root == NULL)
      {
        root = node;
      }
       
      // If size of set
      // is greater than 0
      if (st.size() > 0) 
      {
         
        // If st.top() is present in the
        // set s
        if (s.find(st.top()) != s.end())
        {
          s.erase(st.top());
          st.top()->left = node;
          st.pop();
        }
        else
        {
          st.top()->right = node;
        }
      }
       
      st.push(node);
       
    } while (post[p--] != in[i] && p >=0);
 
    node = NULL;
     
    // If the stack is not empty and
    // st.top()->data is equal to in[i]
    while (st.size() > 0 && i>=0 && 
           st.top()->data == in[i]) 
    {
      node = st.top();
       
      // Pop elements from stack
      st.pop();
      i--;
    }
     
    // if node not equal to NULL
    if (node != NULL) 
    {
      s.insert(node);
      st.push(node);
    }
  }
   
  // Return root
  return root;
 
}
vector<int> postOrderIterative(struct Node* root)
{
    vector<int> postOrderList;
    // Check for empty tree
    if (root == NULL)
        return postOrderList;
    stack<Node*> S;
    S.push(root);
    Node* prev = NULL;
    while (!S.empty()) {
        auto current = S.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == NULL || prev->left == current
            || prev->right == current) {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        }
 
        else if (current->left == prev) {
            if (current->right)
                S.push(current->right);
            else {
                S.pop();
                postOrderList.push_back(current->data);
            }
 
            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->right == prev) {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    //cout << "\nPreorder traversal of binary tree is \n";
    //printPreorder(root);
 
    //cout << "\nInorder traversal of binary tree is \n";
    //printInorder(root);
 
    //cout << "\nPostorder traversal of binary tree is \n";
    //printPostorder(root);

    //cout << "Level Order traversal of binary tree is \n";
    //printLevelOrder(root);

    //cout << "Height of tree is " << maxDepth(root);

    //preorderIterative(root);

    /*char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    Node* treeRoot = buildTree(in, pre, 0, len - 1);
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(treeRoot);*/

    inorderIterative(root);
    return 0;
}