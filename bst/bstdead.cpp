//Check whether BST contains Dead End
bool isDeadUntil(struct Node* root,int min,int max){
    if(!root) return false;
    if(min==max) return true;
    return isDeadUntil(root->left,min,root->data-1) || isDeadUntil(root->right,root->data+1,max);  
}
bool isDeadEnd(Node *root){
    //Your code here
    return isDeadUntil(root,1,INT_MAX);
}