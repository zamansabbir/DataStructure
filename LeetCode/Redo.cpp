#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
#include<list>



using namespace std;

volatile int timer=0; // a global timer value to represent timer for code, originally

// a timer.sleep() was supposed to be used.

//It is a structure to contain necessary node information with key, value, priority and expireTime
struct DataInfo{
        string key;
        int value;
        int priority;
        int expireTime;
};
//custom compartor function for the generating min-heap for expire time

struct comparator_expiry {
    bool operator()(list<DataInfo*>* p1, list<DataInfo*>* p2)
    {
        DataInfo* a=(*p1).front();
        DataInfo*b=(*p2).front();
        if((*p1).size()==0) return false;
        if((*p1).size()!=0 && (*p2).size()==0) return true;
        return (a->expireTime)>(b->expireTime);
    }
};

//custom compartor function for the generating min-heap for priority value
struct comparator_priority{
    bool operator()(list<DataInfo*> *p1, list<DataInfo*> *p2){
        DataInfo* a=(*p1).front();
        DataInfo*b=(*p2).front();
       // if(a==NULL & b==NULL) return false;
       if((*p1).size()==0) return false;
       if((*p1).size()!=0 && (*p2).size()==0) return true;
        return (a->priority)>(b->priority);
    }
};

struct PriorityExpiryCache{
    int maxItems;
    unordered_map<string, DataInfo*> cache_map; //it contains key vs value pair and gives constant access and remove   
    
    unordered_map<int, list<DataInfo*>*> map_priority; // to map priority (key) with reference to group of same priority DataInfo Node
    priority_queue<list<DataInfo*>*,vector<list<DataInfo*>*>,comparator_priority> minheap_priority;

    unordered_map<int, list<DataInfo*>*> map_expiry; // to map expiry (key) with reference to group of same expire DataInfo node

    priority_queue<list<DataInfo*>*,vector<list<DataInfo*>*>,comparator_expiry> minheap_expiry;
//It is a structure to contain necessary node information with key, value, priority and expireTime

};
vector<string> keys(PriorityExpiryCache* cache){
    vector<string> k;
    cout<<"[";
    for(unordered_map<string,DataInfo*>::iterator it=cache->cache_map.begin();it!=cache->cache_map.end();++it){
        k.push_back(it->first);
        cout<<it->first<<", ";
    }
    cout<<"]"<<endl;
    return k;
}

DataInfo* createDataInfo(string key,int priority, int value, int expireTime){
    DataInfo* temp=new DataInfo();
    temp->key=key;
    temp->priority=priority;
    temp->value=value;
    temp->expireTime=expireTime;
    return temp;
}
void addInExpiry(PriorityExpiryCache* cache,DataInfo* t){
    //list<DataInfo*> *temp;
    if(cache->map_expiry.find(t->expireTime)==cache->map_expiry.end()){
        
        cache->map_expiry[t->expireTime]=new list<DataInfo*>();
        
        cache->map_expiry[t->expireTime]->push_back(t);
        cache->minheap_expiry.push(cache->map_expiry[t->expireTime]);
    }else{
        cache->map_expiry[t->expireTime]->push_back(t);
    }          
}

void maintainLRU(DataInfo* t,list<DataInfo*>* l ){ 
    (*l).remove(t);
    (*l).push_front(t);
}
void addInPriority(PriorityExpiryCache* cache,DataInfo* t){
    if(cache->map_priority.find(t->priority)==cache->map_priority.end()){
        cache->map_priority[t->priority]=new list<DataInfo*>();
        cache->map_priority[t->priority]->push_back(t);
        cache->minheap_priority.push(cache->map_priority[t->priority]);
    }else{
        //make arrangement for LRU simultaneously
        maintainLRU(t,cache->map_priority[t->priority]);
    }
}




///re-written
bool removeFromExpiryHeap_new(PriorityExpiryCache* cache,int temp_timer){
    if(!cache->minheap_expiry.empty()){
     list<DataInfo*>* top_list_reference=cache->minheap_expiry.top();
     if((* top_list_reference).empty()){
         cache->minheap_expiry.pop();
         top_list_reference=cache->minheap_expiry.top();
     }
        int preserve_temp_expire_timer=(* top_list_reference).front()->expireTime;
        int temp_expire_time=preserve_temp_expire_timer;
        while(temp_expire_time<=temp_timer){
            cache->minheap_expiry.pop(); //removed from the heap
            cache->map_expiry.erase(temp_expire_time); // removed from the map_expiry
            while(!(*top_list_reference).empty()){
                // remove from map_priority
					 	int key_priority=(*top_list_reference).front()->priority;
					 	list<DataInfo*>* priority_list_referece=cache->map_priority[key_priority];
					 	DataInfo* temp_node_reference=cache->cache_map[(*top_list_reference).front()->key];
					 	(*priority_list_referece).remove(temp_node_reference);
					 	if((*priority_list_referece).empty()){
					 		cache->map_priority.erase(key_priority);
					 	}
					 	// remove from 
						//Final removing from the PECcache
					 	cache->cache_map.erase((*top_list_reference).front()->key);
					 	(*top_list_reference).pop_front();	

                
            }
           // keys(cache);
            top_list_reference=cache->minheap_expiry.top();
            temp_expire_time=(* top_list_reference).front()->expireTime;
        }
        return preserve_temp_expire_timer<=temp_timer?true:false;
     }
     return false;
}







void removeFromPriorityHeapnew(PriorityExpiryCache* cache){
    if(!cache->minheap_priority.empty()){
        // Get the list of node with sampe priorities
        list<DataInfo*>* temp_list_reference=cache->minheap_priority.top();
        while((*temp_list_reference).empty()){
            cache->minheap_priority.pop();
            if(cache->minheap_priority.empty()) return;
            temp_list_reference=cache->minheap_priority.top();
        }
        //// remove from the minheap_expiry and map-expiry
         int expiry_key=(*temp_list_reference).back()->expireTime;
         string key=(*temp_list_reference).back()->key;
         int priority_key=(*temp_list_reference).back()->priority;
         list<DataInfo*>* temp_pointer_list_of_minheap_expiry=cache->map_expiry[expiry_key];
         
         DataInfo* location_delete=cache->cache_map[key];
         (*temp_pointer_list_of_minheap_expiry).remove(location_delete);
         if((*temp_pointer_list_of_minheap_expiry).empty()){
         	cache->map_expiry.erase(expiry_key);
         }
         
         /// map-priority, minheap-priority and cache-map
         (*temp_list_reference).pop_back(); //removes the least recent element
         if((*temp_list_reference).empty()){
         	cache->map_priority.erase(priority_key);
         	cache->minheap_priority.pop();
         }
         cache->cache_map.erase(key);
         
         
        
    }
}

PriorityExpiryCache* NewCache(int maxItems){
    PriorityExpiryCache* temp= new PriorityExpiryCache();
    temp->maxItems=maxItems;
    return temp;
}

int get(PriorityExpiryCache* cache,string key){
    // not found
    if(cache->cache_map.find(key)==cache->cache_map.end()){
        cout<<"Not found in the cache";
        return -1;
    }else{ //found
        //void maintainLRU(DataInfo* t,list<DataInfo*>* l ) cache->map_priority[t->priority]
        DataInfo* temp_data=cache->cache_map[key];
        maintainLRU(temp_data,cache->map_priority[temp_data->priority]);
        cout<<"Key:"<<cache->cache_map[key]->key<<" Value:"<<cache->cache_map[key]->value<<" Priority:"<<cache->cache_map[key]->priority<<" Expire Time:"<<cache->cache_map[key]->expireTime<<endl;
        return cache->cache_map[key]->value;
    }  
    
}
void evictItems(PriorityExpiryCache* cache){
    //Find if the items are expired, remove them
        // check timer value, check the first item from minheap_expiry is expired
        //remove them 
        if(removeFromExpiryHeap_new(cache,timer)){
            return;
        }else{// if not expired,check the lowest priority from minheap_priority
              /// if more than one candidate, delete from LRU 
              removeFromPriorityHeapnew(cache);

        }
            
            
}
void set(PriorityExpiryCache* cache,string key, int value, int priority, int expireTime){
    // if key is not found in the cache map
    if(cache->cache_map.find(key)==cache->cache_map.end()){
        int check_size=cache->cache_map.size();
        if(check_size>=cache->maxItems){
            // need to remove items based expiryTime, then priority and then LRU
            evictItems(cache);
            // insert
        }
        // did not reach the limit
    }else{   // if found delete from the cache-map and free the datainfo space, later will be added
            //update the LRU and expireTime priority queue
            //DataInfo* t=cache->cache_map[key];
            //delete t;
            cache->cache_map.erase(key);
    }
  

    //both case, create the dataInfo node and store in map 

    DataInfo* temp=createDataInfo(key,priority, value, expireTime);
    cache->cache_map[key]=temp;
    //updating min-heap of expire time

    addInExpiry(cache,temp);
    //updateing min-heap of priority and LRU 
    addInPriority(cache,temp);
}

//resize Priority Cache
void SetMaxItems(PriorityExpiryCache* cache,int newSize){
    if(newSize>=cache->maxItems){
        cache->maxItems=newSize;
        return;
    }else{
        if(newSize<=0){
            cout<<"PEC size can not be zero or negative";
            return;
        }
        while(cache->maxItems>newSize){
            evictItems(cache);
            cache->maxItems=cache->cache_map.size();
            
        }
      //  cache->maxItems=newSize;

    }
}

void setTimer(int time_value){
    timer=time_value;
}

int main(){
    PriorityExpiryCache* c=NewCache(5);
    set(c,"A",1,5,100);
    set(c,"B",2,15,3);
    set(c,"C",3,5,10);
    set(c,"D",4,1,15);
    set(c,"E",5,5,150);
    get(c,"C");
    keys(c);
    setTimer(5);
    SetMaxItems(c,4);
    keys(c);
    //SetMaxItems(c,3);
    //keys(c);
    SetMaxItems(c,2);
    keys(c);
    SetMaxItems(c,1);
    keys(c);
    SetMaxItems(c,2);
    set(c,"F",5,5,150);
    keys(c);
    SetMaxItems(c,3);
    set(c,"G",50,5,155);
    keys(c);
    return 0;
}
