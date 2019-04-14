
#include <iostream>

/*
 new data->5->2->1->NULL
*/

typedef struct node{
int data;
struct node* next;
struct node* oldmax;
} stak;

stak* head=NULL;
stak* maxStack=NULL;
void pushStack(int data){
    stak* new_node=(stak*) malloc(sizeof(stak));

    if(maxStack==NULL){
         maxStack=(stak*) malloc(sizeof(stak));
         maxStack->data=data;

    }
    new_node->data=data;
    new_node->next=head;
    head=new_node;
    if(data>maxStack->data){
        new_node->oldmax=maxStack;
        maxStack=new_node;
    }
}

int popStack(){

    if(head!=NULL){
        int r=head->data;
        maxStack=head->oldmax;
        head=head->next;
        return r;
    }
    std::cout<<"Stack is empty"<<std::endl;
    return 0;
}

void displayStack(){
    stak* ptr;
    ptr=head;
    while(ptr!=NULL){
    std::cout<<ptr->data<<" ";
    ptr=ptr->next;
    }
    std::cout<<std::endl;
}
int main(){
    std::cout<<"Popping "<< popStack()<<std::endl;
    pushStack(5);
    pushStack(1);
    pushStack(54);
    pushStack(2);
    pushStack(56);

    displayStack();
    std::cout<<"Maxium in Stack= "<<maxStack->data<<std::endl;
    std::cout<<"Popping "<< popStack()<<std::endl;
    displayStack();
    std::cout<<"Maxium in Stack= "<<maxStack->data<<std::endl;

return 0;
}
