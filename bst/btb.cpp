//Binary Tree to Binary Search Tree Conversion
#include<bits/stdc++.h>
using namespace std;
// The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
};
/*Your code here*/
int countNodes(struct Node *root){
    if(root==NULL) {
        return 0;   
    }
    return countNodes(root->left) + countNodes(root->right) +1;
}

void storeVal(struct Node* root,int arr[],int *index){
    if(root==NULL) return;
    storeVal(root->left,arr,index);
    arr[*index] = root->data;
    (*index)++;
    storeVal(root->right,arr,index);
}

void putVal(struct Node* root,int arr[],int *index){
    if(root==NULL) return;
    putVal(root->left,arr,index);
    root->data = arr[*index] ;
    (*index)++;
    putVal(root->right,arr,index);
}

//main call function
struct Node *binaryTreeToBST (struct Node *root) {
    int n = countNodes(root);
    int *arr = new int[n];
    int index=0;
    storeVal(root,arr,&index);
    sort(arr,arr+n);
    index = 0;
    putVal(root,arr,&index);
    return root;
}