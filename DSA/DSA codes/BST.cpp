#include <bits/stdc++.h>
using namespace std;
struct BSTnode
{
    int val;
    BSTnode *left;
    BSTnode *right;
};
BSTnode* newNode(int data)
{
    BSTnode *temp = new BSTnode;
    temp->val = data;
    temp->left = temp->right = nullptr;
    return temp;
}
void insert(BSTnode *root, int data)
{
    if(root->left == nullptr && root->right == nullptr)
    {
        BSTnode *newnode = newNode(data);
        if(data <= root->val)
            root->left = newnode;
        else
            root->right = newnode;
        return;
    }
    if(data <= root->val)
        insert(root->left, data);
    else
        insert(root->right, data);
}
void inorder(BSTnode *root)
{
    if(root == nullptr)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
bool search(BSTnode *root, int data)
{
    if(root == nullptr)
        return false;
    if(root->val == data)
        return true;
    if(data < root->val)
        return search(root->left, data);
    else
        return search(root->right, data);
}
int main()
{
    BSTnode *root = newNode(1);
    root->left = newNode(-3);
    root->right = newNode(4);
    inorder(root);
    cout<<endl;
    cout<<search(root, -2)<<endl;
    insert(root, -2);
    inorder(root);
    cout<<endl;
    cout<<search(root, -2)<<endl;
    return 0;
}