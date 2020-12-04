#include<iostream>

  struct ListNode {
      int val;
      ListNode *next;
  
  };

ListNode* createNode(int x){
    ListNode *temp=new ListNode();
    temp->val=x;
    temp->next=NULL;
    return temp;
}
ListNode* createList(int *a, int l){
    ListNode * head=NULL;
    ListNode *temp=createNode(*(a+0));
    head=temp;
    for(int i=1;i<l;i++){
        temp->next=createNode(*(a+i));
        temp=temp->next;
    }
    return head;
}

void printNode(ListNode *h){
    while(h){
        std::cout<< h->val<< " ";
        h=h->next;
    }
    std::cout<<std::endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    ListNode *currentL1=l1,*currentL2=l2,*temp=NULL,*current=NULL;
    ListNode* head=current;
    while(currentL1!=NULL || currentL2!=NULL){
        if(currentL1->val<=currentL2->val){
             
            temp=createNode(currentL1->val);
            //take care of head for the first time
           /* if(currentL1==l1 & currentL2==l2){
               // head=temp;
               temp=createNode(currentL1->val);
            }else{
                temp->next=createNode(currentL1->val);
            } */
            currentL1=currentL1->next;

        }else
        {
             temp=createNode(currentL2->val);
           /*  //take care of head for the first time
            if(currentL1==l1 & currentL2==l2){
          //      head=temp;
                temp=createNode(currentL2->val);
            }else{
                temp->next=createNode(currentL2->val);
            } */
            //temp=temp->next;
            currentL2=currentL2->next;
        }
        current=temp;
        current=current->next;
    }
    //temp=NULL;
    return head;
}

int main(){
    int a[3]={1,2,4};
    int b[3]={1,3,4};
    ListNode* head1=createList(a,3);
    ListNode* head2=createList(b,3);
    printNode(head1);
    printNode(head2);
    ListNode *head=mergeTwoLists(head1,head2);
    printNode(head);
    return 0;
}