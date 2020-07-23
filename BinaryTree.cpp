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

void InordertraversalBTree(BTree* root){
    if(root==NULL){
        return;
    }
    InordertraversalBTree(root->left);
    std::cout<<root->data<<" ";
    InordertraversalBTree(root->right);
    
}
void PreordertraversalBTree(BTree* root){
    if(root==NULL){
        return;
    }
    std::cout<<root->data<<" ";
    PreordertraversalBTree(root->left);
    PreordertraversalBTree(root->right);
}

void PostordertraversalBTree(BTree* root){
    if(root==NULL){
        return;
    }
   
    PostordertraversalBTree(root->left);
    PostordertraversalBTree(root->right);
     std::cout<<root->data<<" ";
}

//Level Order or Breadth first Traversal
void LevelordertraversalBTree(BTree* root){
    if(root==NULL){
        return;
    }
    std::queue<BTree*> q;
    q.push(root);
    while(!q.empty()){
        BTree* temp=q.front();
        std::cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        q.pop();
    }
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
    InordertraversalBTree(root);
    std::cout<<std::endl;
    LevelordertraversalBTree(root);
    std::cout<<std::endl;
    PreordertraversalBTree(root);
    std::cout<<std::endl;
    PostordertraversalBTree(root);
    return 0;
}
