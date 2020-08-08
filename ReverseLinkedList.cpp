#include <iostream>
struct Node{
    int value;
    Node* next=NULL;
};

Node* insertToNode(Node* head, int data){
    Node* temp=new Node();
    temp->value=data;
    Node* current=head;
    if(head==NULL){
        head=temp;
    }else{
    while(current->next){
        current=current->next;
    }
    current->next=temp;
    }
    return head;
}

void traverseForwardlist(Node * head){
    Node* current=head;
    while(current){
        std::cout<<current->value<<" ";
        current=current->next;
    }
     std::cout<<std::endl;

}


Node* reverseForwardList(Node* head){
    Node* prev=NULL;
    if(head){
        
        while(head){
            Node* temp_next=head->next;
            head->next=prev;
            prev=head;
            head=temp_next;
            
        }
    }
    return prev;
}
int main(){
    Node* head=NULL;
    for(int i=0;i<20;i+=2){
       head=insertToNode(head,i);
    }
    traverseForwardlist(head);
    head=reverseForwardList(head);
    traverseForwardlist(head);
    return 0;
}