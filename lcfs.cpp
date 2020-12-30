#include <stdio.h>
#include <stdlib.h>

#define P_NORMAL 5
#define P_HIGH 1
#define P_LOW 10
int  PID=1, CLOCK =0, TotalProcessExecuted=0;
float TotalwaitingTime=0.0;;

typedef struct a{
    int pid,priority;
    int burstTime,arrivalTime,waitingTime,turnArTime;
    struct a *next, *prev;
}PCB;

typedef struct{
    PCB *head, *tail;

 }Queue;

 void printQueue(Queue *q){
     PCB *pn = q->head;
     printf("\n\n PID\t CPUburstTime\t ArrivalTime\t waitingTime\t NodeLocation\n");
     while(pn!=0){
     printf("%d\t %8d\t %8d \t%8d \t@%d \n", pn->pid, pn->burstTime, pn->arrivalTime, pn->waitingTime,&pn);
     pn = pn->next; //Update
     }
 }
 void insertprocess(Queue *q, int burst, int priority)
 {
     PCB *newprocess =(PCB *)malloc(sizeof(PCB));
     newprocess->next = newprocess->prev = 0;//Reset Value
     //set values
     newprocess->pid=(PID++);
     newprocess->arrivalTime =CLOCK;
     newprocess->burstTime =burst;
     newprocess->priority = priority;
     newprocess->waitingTime=-1;
     newprocess->turnArTime =-1;
     if(q->head==0){
        q->head=q->tail =newprocess;
     }
     else{
        //q->tail->next=newprocess;
        //newprocess-> prev=q->tail;
        //q->tail = newprocess;

        newprocess->next=q->head;
        newprocess->prev=0;
        q->head=newprocess;
     }

 }

 PCB deQueue(Queue *list){
     PCB t;
     t.pid=0;
     if(list->head==0){
        printf("\n Queue is empty!\n");
        return t;
 }
 t = *list->head;
 list->head = list->head->next;
 return t;
 }
 void executeprocess(Queue *rq)
 {
     while(!rq->head==0)
     {
         PCB r = deQueue(rq);
         printf("\n\nprocess %d is being processed", r.pid);
         r.waitingTime= CLOCK-r.arrivalTime;
         TotalwaitingTime+=r.waitingTime;
         CLOCK+= r.burstTime;
         printf("\n waiting time for processed %d is %d", r.pid,r.waitingTime);
         printf("\nAfter Completion, Clock=%d", CLOCK);
        // printf("\n%f\t%d",TotalwaitingTime,TotalProcessExecuted);
         TotalProcessExecuted++;
     }
 }
 main(){
 Queue *readyQ=(Queue *)malloc(sizeof(Queue));
 readyQ->head=readyQ->tail=0;
 insertprocess(readyQ, 10, P_NORMAL);
 insertprocess(readyQ, 5, P_NORMAL);
 insertprocess(readyQ, 20, P_NORMAL);
 printQueue(readyQ);
 executeprocess(readyQ);

 printf("\n\nAverage WaitingTime of Priority Scheduling Algorithm = %f",(float)(TotalwaitingTime/TotalProcessExecuted));



 }


