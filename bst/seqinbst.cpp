//Check if given sorted sub-sequence exists in binary search tree

void isSubInBSTUntil(struct NOde* root,int arr[],int n,int* count){
    if(root==NULL) return;
    isSubInBSTUntil(root->left,arr,n,count);
    if(arr[count]==root->data){
        *count++;
    }
    isSubInBSTUntil(root->right,arr,n,count);
}

bool isSubInBST(struct Node* root,int arr[],int n){
    int count = 0;
    isSubInBSTUntil(root,arr,n,&count);
    if(count==n){
        return true
    } else{
        return false
    }
    
}