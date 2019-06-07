//BST to min heap
#include<bits/stdc++.h>
using namespace std;

struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
struct Node* newNode(int data) { 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

int sizeofBST(struct Node *root){
    if(root==NULL) return 0;
    return sizeofBST(root->left) + sizeofBST(root->right) + 1;
}

void storeVal(struct Node* root,int arr[],int *index){
    if(root==NULL) return;
    storeVal(root->left,arr,index);
    arr[*index] = root->data;
    (*index)++;
    storeVal(root->right,arr,index);
}

void putLevelWise(struct Node *root,int arr[]){
    int index = 0;
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty()){
        struct Node *now = q.front();
        q.pop();
        now->data = arr[index];
        index++;
        if(now->left!=NULL) q.push(now->left);
        if(now->right!=NULL) q.push(now->right);
    }
}

void BSTToMinHeap(struct Node *root){
    int n = sizeofBST(root);
    int *arr = new int[n];
    int index = 0;
    storeVal(root,arr,&index);
    sort(arr,arr+n);
    putLevelWise(root,arr);
}

void printLevelOrder(Node *root) { 
    if (root == NULL)  return; 
  
    queue<Node *> q; 
    q.push(root); 
    while (!q.empty()) 
    { 
        int nodeCount = q.size(); 
        while (nodeCount > 0) 
        { 
            Node *node = q.front(); 
            cout << node->data << " "; 
            q.pop(); 
            if (node->left) 
                q.push(node->left); 
            if (node->right) 
                q.push(node->right); 
            nodeCount--; 
        } 
        cout << endl; 
    } 
} 

int main() {
  
    Node* root = newNode(8); 
    root->left = newNode(4); 
    root->right = newNode(12); 
    root->right->left = newNode(10); 
    root->right->right = newNode(14); 
    root->left->left = newNode(2); 
    root->left->right = newNode(6); 
  
    BSTToMinHeap(root); 
    printLevelOrder(root); 
    return 0;  
}