#include <iostream>
#include <queue>
struct BTree{
    int data;
    BTree* left;
    BTree* right;
};

BTree* createNode(int data){
     BTree* temp=new BTree();
     temp->data=data;
     temp->left=temp->right=NULL;
     return temp;
}

BTree* insertBTree(BTree* root,int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    struct BTree* temp;
    std::queue <BTree*> q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left=createNode(data);
            break;
        }else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right=createNode(data);
            break;
        }else{
            q.push(temp->right);
        }
    }
    return root;
}

void traversalBTreeInorder(BTree* root){
    if(root==NULL){
        return;
    }
    traversalBTreeInorder(root->left);
    std::cout<<root->data<<" ";
    traversalBTreeInorder(root->right);
    
}
void traversalBTreePreorder(BTree* root){

}

int main(){
    BTree* root=NULL;
    root=insertBTree(root,5);
    root=insertBTree(root,10);
    root=insertBTree(root,15);
    root=insertBTree(root,8);
    root=insertBTree(root,7);
    root=insertBTree(root,20);
    root=insertBTree(root,21);
    traversalBTreeInorder(root);
    return 0;
}
