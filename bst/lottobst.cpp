//Convert Level Order Traversal to BST
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;

    Node(int data){
        data = data;
        left = right = NULL;
    }
};

struct Node* newNode(int data){
    struct Node* node = new Node(data);
    return node;
}

struct Node* LevelOrder(struct Node* root,int data){
    if(root==NULL){
        return newNode(data);
    }
    if(data <= root->data){
        root->left = LevelOrder(root->left,data);
    }else{
        root->right = LevelOrder(root->right,data);
    }
    return root;
}

//main called functon
struct Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    // Code here
    struct Node *root = NULL;
    for(int i=0;i<n;i++){
        root = LevelOrder(root,arr[i]);
    }
	return root;
}
