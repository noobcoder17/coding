//reverse path of bst from a preticular key value using queue
void reversePath(struct Node *root,int key,queue<int>& q){
    if(root==NULL) return;
    if(root->data==key){
        q.push(root->data);
        root->data = q.front();
        q.pop();
        return;
    } else if(key<root->data){
        q.push(root->data);
        reversePath(root->left,key,q);
        root->data = q.front();
        q.pop();
        return;
    } else if(key>root->data){
        q.push(root->data);
        reversePath(root->right,key,q);
        root->data = q.front();
        q.pop();
        return;
    }
}

