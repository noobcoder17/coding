void inorder(struct Node* root,int* prev,bool* isbst){
    if(root==NULL) return;
    
    inorder(root->left,prev,isbst);
    if(root->data<*prev){
        *isbst = false;
    } else {
        *prev = root->data;
    } 
    inorder(root->right,prev,isbst);
}


bool isBST(Node* root) {
    // Your code here
    bool isbst = true;
    int prev=INT_MIN;
    inorder(root,&prev,&isbst);
    return isbst;
}