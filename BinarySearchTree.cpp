#include<iostream>
struct BSTNode{
    int data;
    BSTNode *left, *right;
};

BSTNode* createBSTNode(int value){
    BSTNode *temp=new BSTNode();
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
BSTNode* insertNodeInBST(BSTNode *root,int value){
    
    if(root==NULL){
        BSTNode *temp=createBSTNode(value);
        root=temp;
        return root;
    }
    // if value is smalller than the current root data, then go left
    if(value<root->data){
        //BSTNode *temp=createBSTNode(value);
        root->left=insertNodeInBST(root->left,value);
    }
       // if value is greater than the current root data, then go right
    if(value>root->data){
        //BSTNode *temp=createBSTNode(value);
        root->right=insertNodeInBST(root->right,value);
    }

    return root;
}
BSTNode* searchBST(){
    
}

BSTNode* deleteBSTNode(int value){

}

void inOrderTraversal(BSTNode* root){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left);
    std::cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int main(){
    BSTNode* root=NULL;
    root=insertNodeInBST(root,12);
    root=insertNodeInBST(root,5);
    root=insertNodeInBST(root,15);
    root=insertNodeInBST(root,3);
    root=insertNodeInBST(root,7);
    root=insertNodeInBST(root,13);
    root=insertNodeInBST(root,17);
    root=insertNodeInBST(root,1);
    root=insertNodeInBST(root,9);
    inOrderTraversal(root);

}