#include<iostream>

struct Node{
    int value;
    Node *next=NULL, *prev=NULL;
};

Node* createNode(int data){
    Node* temp=new Node();
    temp->value=data;
    return temp;
}
Node* addToList(Node* temp_head, int data){
    Node *temp=createNode(data);
    if(temp_head==NULL){
        temp_head=temp;
    }else{
        temp_head->prev=temp;
        temp->next=temp_head;
        temp_head=temp;
    }
    return temp_head;
}

void printList(Node* temp_head){
    Node *current=temp_head;
    while(current!=NULL){
        std::cout<<current->value<<" ";
        current=current->next;
    }

}

int main(){
    Node * head=NULL;
    head=addToList(head,1);
    head=addToList(head,10);
    head=addToList(head,100);
    head=addToList(head,1000);
    
    printList(head);
    return 0;
}