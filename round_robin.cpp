#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define P_NORMAL 5
#define P_HIGH 1
#define P_LOW 10
#define Quantum INT_MAX  
int  PID=1, CLOCK =0,  TotalProcessExecuted=0;
float TotalwaitingTime=1.0;

typedef struct a{
    int pid,priority, lastseen;
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
     newprocess->lastseen=-1;
     //link setup
     if(q->head==0){
        q->head=q->tail =newprocess;
     }
     else{
        q->tail->next=newprocess;
        newprocess-> prev=q->tail;
        q->tail = newprocess;
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
 void re_addPCB(Queue *q, PCB r)
 {
     PCB *p =(PCB *)malloc(sizeof(PCB));
     p->pid = r.pid;
     p->priority = r.priority;
     p->burstTime = r.burstTime;
     p->arrivalTime = r.arrivalTime;
     p->waitingTime = r.waitingTime;
     p->turnArTime = r.turnArTime;
     p->lastseen = r.lastseen;

     p->next = p->prev= 0;
     if(q->head==0){
        q->head=q->tail = p;

     }
     else{
        q->tail->next= p;
        p->prev= q->tail;
        q->tail=p;

     }
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
         TotalProcessExecuted++;
     }
 }
  void executeprocessRR(Queue *rq)
 {
     while(!rq->head==0)
     {
         PCB r = deQueue(rq);
         printf("\n\nprocess %d is being processed", r.pid);

         if(r.lastseen==-1){
            r.waitingTime = CLOCK- r.arrivalTime;
         }else{
         r.waitingTime = CLOCK - r.lastseen;
         }
         //r.waitingTime=waiting;
         TotalwaitingTime+=r.waitingTime;

         if(r.burstTime<=Quantum){
            CLOCK+=r.burstTime;
            TotalProcessExecuted++;
            printf("\n process- completed #%d\n",r.pid);
         }
         else{
            CLOCK+=Quantum;
            r.burstTime = r.burstTime - Quantum;
            r.lastseen = CLOCK;
            re_addPCB(rq,r);
         }


         printf("\n waiting time for processed %d is %d", r.pid,r.waitingTime);
         printf("\nAfter Time Slice slice/quantum completion, Clock=%d", CLOCK);

     }

 }
 main(){
 Queue *readyQ=(Queue *)malloc(sizeof(Queue));
 readyQ->head=readyQ->tail=0;
 insertprocess(readyQ, 10, P_NORMAL);
 insertprocess(readyQ, 5, P_NORMAL);
 insertprocess(readyQ, 20, P_NORMAL);
 printQueue(readyQ);
 //deQueue(readyQ);
 //printQueue(readyQ);
 executeprocessRR(readyQ);
 printf("\n\nAverage WaitingTime = %f",(float)(TotalwaitingTime/TotalProcessExecuted));
 }


