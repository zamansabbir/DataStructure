 #include<iostream>
 #include<array>
 
 struct ListNode{
     int value;
     ListNode *next;
 };
 ListNode* getNode(int data){
     ListNode *temp= new ListNode();
     temp->value=data;
     temp->next=NULL;
     return temp;
 }

 ListNode* createLinkedList(){
     std::array<int,4> myArray={1,2,3,4};
     ListNode * head= getNode(myArray[0]);
     ListNode* prev=head, *temp;
     for (int i=1;i<myArray.size();i++){
         temp=getNode(myArray[i]);
         prev->next=temp;
         prev=temp;
     }
        
     return head;
 }

  ListNode* swapPairs(ListNode* head){
      ListNode *current=head,*temp,*oldTemp;
        if(!head){
            return head;
        }
        if(head && head->next){
            head=head->next;
        }
        
        while(current && current->next){
            oldTemp=current;
            temp=current->next->next;
            //ListNode *tempX=current->next;
            current->next->next=current;
            current->next=temp;
            current=temp;
            //delete tempX;
            if(current && current->next){
                oldTemp->next=current->next;
            }
        }

      return head;
  }

int main(){
    ListNode *head=createLinkedList();
    head=swapPairs(head);
    return 0;
}