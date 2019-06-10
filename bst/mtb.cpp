//merge two bst
//print two bst in sorted order
// iterative inorder traversal
void inorder(struct Node *root)  
{  
    if (root != NULL)  
    {  
        inorder(root->left);  
        cout<<root->data<<" ";  
        inorder(root->right);  
    }  
} 

void merge(Node *root1, Node *root2)
{
   //Your code here
   stack<struct Node*> s1;
   stack<struct Node*> s2;
   
   
   struct Node* current1 = root1;
   struct Node* current2 = root2;
   
   while(current1!=NULL || current2!=NULL || !s1.empty() || !s2.empty()){
       if(current1!=NULL || current2!=NULL){
           if(current1!=NULL){
               s1.push(current1);
               current1 = current1->left;
           }
           if(current2!=NULL){
               s2.push(current2);
               current2 = current2->left;
           }
       } else {
           if(s1.empty()){
              while(!s2.empty()){
                  current2 = s2.top();
                  s2.pop();
                  current2->left = NULL;
                  inorder(current2);
              } 
              return;
           }
           if(s2.empty()){
              while(!s1.empty()){
                  current1 = s1.top();
                  s1.pop();
                  current1->left = NULL;
                  inorder(current1);
              } 
              return;
           }
           
           current1 = s1.top();
           s1.pop();
           current2 = s2.top();
           s2.pop();
           
           if(current1->data<current2->data){
               cout << current1->data << " ";
               current1 = current1->right;
               s2.push(current2);
               current2=NULL;
           } else{
               cout << current2->data << " ";
               current2 = current2->right;
               s1.push(current1);
               current1=NULL;
           }
       }
   }
   cout << "\n";
}