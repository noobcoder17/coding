//kth smallest element
void find(struct Node* root,int k,int* count,int* data){
    if(root==NULL){
        return;
    }
    find(root->left,k,count,data);
    *count+=1;
    if(*count==k){
        *data =  root->data;
    }
    find(root->right,k,count,data);
}
int KthSmallestElement(Node *root, int k){
    int count = 0;
    int data;
    struct Node* temp=NULL;
    find(root,k,&count,&data);
    return data;
}