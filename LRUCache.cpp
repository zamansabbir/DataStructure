#include<iostream>
#include<list>
#include<unordered_map>
#include<utility>
using namespace std;
class LRUCache {
//list<int> dq; // cache
list<pair<int, int>> dq;

unordered_map <int,list<pair<int, int>>::iterator> map; // helps me to find the cache faster
int cache_capacity;
public:

    LRUCache(int capacity) {
        this->cache_capacity=capacity;
    }
    
    int get(int key) {
        //not found
        if(map.find(key)==map.end()){
            return -1;
        }else{
            pair<int, int> value=*map[key];
            //dq.erase(map[key]);
            dq.erase(map[key]);
            //pair<int,int> p(key,value);
            dq.push_front(value);
            map[key]=dq.begin();
            return value.second;
        }
    }
    
    void put(int key, int value) {
          // not found:
        if(map.find(key)==map.end()){
            if(dq.size()==cache_capacity){
                pair<int, int> temp_key=dq.back();

                dq.pop_back();
                map.erase(temp_key.first);
            }
        } else{
            //found, erase from back
            dq.erase(map[key]);
            map.erase(key);
            
        }  

        //both cases, move to front of dq and add referenec to the map
        dq.push_front(make_pair(key,value));
        map[key]=dq.begin();
       
       


       // dq.push_front()
    }
};


int main(){

    LRUCache lRUCache(2);
    //LRUCache lRUCache = new LRUCache(2);
    int value=0;
    lRUCache.put(2, 1); // cache is {1=1}
    lRUCache.put(1, 1);
    value=lRUCache.get(2); // cache is {1=1, 2=2}
    lRUCache.put(4,1);    // return 1
    //lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    value=lRUCache.get(1);    // returns -1 (not found)
    //lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    //lRUCache.get(1);    // return -1 (not found)
   value= lRUCache.get(2);    // return 3
    //lRUCache.get(4);    // return 4
    return 0;
}