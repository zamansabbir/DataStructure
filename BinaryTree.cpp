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
BTree* invertBinaryTree(BTree* root){
 if(root==NULL){
     return root;
 }
  BTree* left_dummy= invertBinaryTree(root->left);
  BTree* right_dummy= invertBinaryTree(root->right);
  root->left=right_dummy;
  root->right=left_dummy;
return root;
}

int main(){
    BTree* root=NULL;
    root=insertBTree(root,4);
    root=insertBTree(root,2);
    root=insertBTree(root,7);
    root=insertBTree(root,1);
    root=insertBTree(root,3);
    root=insertBTree(root,6);
    root=insertBTree(root,9);
    InordertraversalBTree(root);
    std::cout<<std::endl;
    LevelordertraversalBTree(root);
    std::cout<<std::endl;
    PreordertraversalBTree(root);
    std::cout<<std::endl;
    PostordertraversalBTree(root);
    std::cout<<std::endl;

    root=invertBinaryTree(root);
    std::cout<<"Reverse Tree"<<std::endl;

    LevelordertraversalBTree(root);
    std::cout<<std::endl;
    return 0;
}
