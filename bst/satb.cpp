//sorted Array to BST
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data){
    struct Node * temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *atb(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    struct Node *root = newNode(arr[mid]);
    root->left = atb(arr,start,mid-1);
    root->right = atb(arr,mid+1,end);
    return root;
}

void preorder(struct Node *root){
    if(root==NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	int t,n,i;
	cin >> t;
	while(t--){
	    cin >> n;
	    int *arr = new int[n];
	    for(i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    struct Node *root = atb(arr,0,n-1);
	    preorder(root);
        delete arr;
        cout <<"\n";
	}
}