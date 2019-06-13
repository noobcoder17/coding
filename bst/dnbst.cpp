//Delete nodes greater than k

struct Node* deleteAll(struct Node* root,int key){
    if(root==NULL) return NULL;
    root->left = deleteAll(root->left,key);
    root->right = deleteAll(root->right,key);
    
    if(root->data>key){
        struct Node* lchild = root->left;
        delete root;
        return lchild;
    }
    return root;
}
Node* deleteNode(Node* root, int key){
    //Your code here
    struct Node* temp = deleteAll(root,key-1);
    return temp;
}