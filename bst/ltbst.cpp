// C++ implementation to check if the given array 
// can represent Level Order Traversal of Binary 
// Search Tree 
#include <bits/stdc++.h> 
using namespace std; 

struct NodeDetails { 
	int data; 
	int min, max; 
}; 

bool levelOrderIsOfBST(int arr[], int n) { 
	if(n==1 || n==0){
	    return true;
	}
	
	queue<struct NodeDetails> q;
	int i=0;
	struct NodeDetails newNode;
	newNode.data = arr[i];
	newNode.min = 0;
	newNode.max = INT_MAX;
	q.push(newNode);
	
	while(i!=n && !q.empty()){
	    struct NodeDetails* temp = q.top();
	    q.pop();
	    if(i<n && arr[i] > temp.min && arr[i]<temp.data-1){
	        struct NodeDetails newNode;
        	newNode.data = arr[i];
        	newNode.min = temp.min;
        	newNode.max = temp.max-1;
        	q.push(newNode);
        	i++;
	    }
	    if(i<n && arr[i]>temp.data-1 && temp.max > arr[i]){
	        struct NodeDetails newNode;
        	newNode.data = arr[i];
        	newNode.min = temp.data-1;
        	newNode.max = temp.max;
        	q.push(newNode);
        	i++;
	    }
	}
	
	if(i!=n) return false;
	return true;
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};	 
	int n = sizeof(arr) / sizeof(arr[0]);	 
	if (levelOrderIsOfBST(arr, n)) 
		cout << "Yes"; 
	else
		cout << "No";		 
	return 0;	 
} 