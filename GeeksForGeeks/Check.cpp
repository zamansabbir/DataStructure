#include<iostream>
#include<list>
#include<string>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int maxItems=3;
struct DataInfo{
        string key;
        int value;
        int priority;
        int expireTime;
};
struct comparator_expiry {
    bool operator()(list<DataInfo*>* p1, list<DataInfo*>* p2)
    {
        DataInfo* a=(*p1).front();
        DataInfo*b=(*p2).front();
        return (a->expireTime)>(b->expireTime);
    }
};

struct comparator_priority{
    bool operator()(list<DataInfo*> *p1, list<DataInfo*> *p2){
        DataInfo* a=(*p1).front();
        DataInfo*b=(*p2).front();
        return (a->priority)>(b->priority);
    }
};
unordered_map<int, list<DataInfo*>*> map_expiry;
priority_queue<list<DataInfo*>*,vector<list<DataInfo*>*>,comparator_expiry> minheap_expiry;
//It is a structure to contain necessary node information with key, value, priority and expireTime

//data structure for priority and LRU
unordered_map<int, list<DataInfo*>*> map_priority; // to map priority (key) with reference to group of same priority DataInfo Node
priority_queue<list<DataInfo*>*,vector<list<DataInfo*>*>,comparator_priority> minheap_priority;

DataInfo* createDataInfo(string key,int priority, int value, int expireTime){
    DataInfo* temp=new DataInfo();
    temp->key=key;
    temp->priority=priority;
    temp->value=value;
    temp->expireTime=expireTime;
    return temp;
}


void addInExpiry(DataInfo* t){
    //list<DataInfo*> *temp;
    if(map_expiry.find(t->expireTime)==map_expiry.end()){
        
        map_expiry[t->expireTime]=new list<DataInfo*>();
        
        map_expiry[t->expireTime]->push_back(t);
        minheap_expiry.push(map_expiry[t->expireTime]);
    }else{
        map_expiry[t->expireTime]->push_back(t);
    }
        
   
}

void maintainLRU(DataInfo* t,list<DataInfo*>* l ){
    /* if((*l).size()==maxItems){
        DataInfo* temp_data=(*l).back();
        (*l).pop_back();
        //1. remove cache_map key: string key=temp_data->key 
        
        //2. remove min_heap expiry list: use temp_data to delete from list of min_heap_expiry, get the 
            //list from map_expiry and use delete with temp_data pointer
       list<DataInfo*>* temp_list1=map_expiry[t->expireTime];
       (*temp_list1).remove(temp_data);               
    } */
    (*l).push_front(t);
}
void addInPriority(DataInfo* t){
    if(map_priority.find(t->priority)==map_priority.end()){
        map_priority[t->priority]=new list<DataInfo*>();
        map_priority[t->priority]->push_back(t);
        minheap_priority.push(map_priority[t->priority]);
    }else{
        //make arrangement for LRU simultaneously
        maintainLRU(t,map_priority[t->priority]);
    }
}

void printList(list<DataInfo*>* temp){
    list<DataInfo*> t=*temp;
    for(list<DataInfo*> ::iterator it=(*temp).begin();it!=(*temp).end();++it){
        cout<<(*it)->key<<" "<<(*it)->priority<<" "<<(*it)->value<<" "<<(*it)->expireTime<<endl;
    }
}
int main(){
   
    //DataInfo* temp=createDataInfo("A",1,3,100);
    //DataInfo* createDataInfo(string key,int priority, int value, int expireTime)
    addInPriority(createDataInfo("A",1,3,100));
    addInExpiry(createDataInfo("A",1,3,100));
    addInPriority(createDataInfo("B",1,3,101));
    addInExpiry(createDataInfo("B",1,3,101));
    
    addInPriority(createDataInfo("C",2,3,100));
    addInExpiry(createDataInfo("C",2,3,100));
    
    addInPriority(createDataInfo("D",2,3,105));
    addInExpiry(createDataInfo("D",2,3,105));

    addInPriority(createDataInfo("D",4,3,105));
    addInExpiry(createDataInfo("D",4,3,105));

    printList(minheap_priority.top());
    minheap_priority.pop();
    printList(minheap_priority.top());
  //  minheap_expiry.pop();
 //   printList(minheap_expiry.top());
    
    return 0;
}