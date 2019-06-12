//Brothers From Different Roots
//pair with given sum
int findNoNodes(struct Node* root){
    if(root==NULL) return 0;
    return findNoNodes(root->left) + findNoNodes(root->right) + 1;
}

void storeInorder(struct Node* root,int arr[],int* index){
    if(root==NULL) return;
    storeInorder(root->left,arr,index);
    arr[*index] = root->data;
    *index+=1;
    storeInorder(root->right,arr,index);
}
int countPairs(Node* root1, Node* root2, int x){
    // Code here
    int size1,size2,itrLeft,itrRight,sum;
	size1 = findNoNodes(root1);
	int *arr1 = new int[size1];
	int index1=0;
	storeInorder(root1,arr1,&index1);
	size2 = findNoNodes(root2);
	int index2=0;
	int *arr2 = new int[size2];
	storeInorder(root2,arr2,&index2);
	itrLeft = 0;
	itrRight = size2-1;
	int count = 0;
	while(itrLeft<=size1-1 && itrRight>=0){
	    sum = arr1[itrLeft] + arr2[itrRight];
	    //cout << "Sum:" << sum << "\n";
	    if(sum>x){
	      itrRight-=1;  
	    } else if(sum<x){
	        itrLeft+=1;
	    } else if(sum==x){
	        count+=1;
	        itrLeft+=1;
	        itrRight-=1;
	    }
	}
	return count;
}