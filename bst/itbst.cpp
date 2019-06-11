//Inorder Traversal and BST

#include <bits/stdc++.h>
using namespace std;

void itbst(int arr[],int n){
    int i;
    for(i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
    return;
}

int main() {
	//code
	int t,n,i;
	cin >> t;
	while(t--){
	    cin >> n;
	    int *arr = new int[n];
	    for(i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    itbst(arr,n);
	}
	return 0;
}