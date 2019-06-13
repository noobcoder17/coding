struct Info{
    int size;
    int min;
    int max;
    int ans;
    bool isLeft;
    bool isRight;
    bool isBST;
};

Info findLBST(struct Node* root){
    if(root==NULL) {
        return {0,INT_MIN,INT_MAX,0,true,true,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true,true,true};
    }
    
    Info l = findLBST(root->left);
    Info r = findLBST(root->right);
    Info result;
    
    if(l.isBST && r.isBST && root->data>l.max && root->data < r.min){
        result.min = min(l.min,min(root->data,r.min));
        result.max = min(r.max,max(root->data,l.max));
        
        result.size = (1+l.size+r.size);
        result.ans = result.size;
        result.isLeft = true;
        result.isRight = true;
        result.isBST = true;
        return result;
    }
    //result.ans = max(l.ans,r.ans);
    if(l.isBST && root->data>l.max){
        result.size = 1+l.size;
        result.min = l.min;
        result.max = root->data;
        result.ans = l.ans+1;
        result.isLeft = true;
        result.isRight = false;
    }
    
    if(r.isBST && root->data<r.min){
        result.size = 1+r.size;
        result.min = root->data;
        result.max = r.max;
        result.ans = r.ans+1;
        result.isLeft = false;
        result.isRight = true;
    }
    result.isBST = false;
    return result;
}

int largestBst(Node *root){
	//Your code here
	Info result = findLBST(root);
	return result.ans;
}