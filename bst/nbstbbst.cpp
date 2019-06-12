//Normal BST to Balanced BST
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

struct Node* buildTree(int arr[],int min,int max){
    int mid = (min+max)/2;
    struct Node* node = newNode(arr[mid]);
    if(min<max){
        node->left = buildTree(arr,min,mid-1);
        node->right = buildTree(arr,mid+1,max);
    }
    return node;
}

Node* buildBalancedTree(Node* root) {
	// Code here
	int size,i;
	size = findNoNodes(root);
	int *arr = new int[size];
	int index = 0;
	storeInorder(root,arr,&index);
	struct Node* temp = NULL;
	temp = buildTree(arr,0,size-1);
	return temp;
}