#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e9+7;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
Node* convertBST(Node* root) 
{
    if(root!=NULL)
    {
        convertBST(root->right);
        root->data=root->data+sum;
        sum=root->data;
        convertBST(root->left);
    }        
    return root;   
}
int main()
{
    
    return 0;
}

/*
https://leetcode.com/problems/convert-bst-to-greater-tree/
*/