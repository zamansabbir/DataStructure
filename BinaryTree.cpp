#include <iostream>
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

void insertBTree(BTree* root,int data){
    BTree* newNode=createNode(data);

}
int main(){

    return 0;
}
