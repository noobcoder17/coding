//Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST
void fix(struct node* root,int min,int max,struct node* arr[],int* index){
    if(root==NULL) return;
    fix(root->left,min,root->data-1,arr,index);
    //cout << root->data << " ";
    if(root->data<min || root->data>max){
        arr[*index] = root;
        //cout << root->data;
        *index+=1;
    }
    fix(root->right,root->data+1,max,arr,index);
}

struct node *correctBST( struct node* root ){
    struct node* arr[2];
    int index=0;
    fix(root,INT_MIN,INT_MAX,arr,&index);
    struct node* temp1 = arr[0];
    struct node* temp2 = arr[1];
    if(index>=2){
        int temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;    
    }
    return root;
}