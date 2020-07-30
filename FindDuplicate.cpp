#include<iostream>
#include <unordered_set>
bool isThereDuplicate(int* a, int n){
    bool found=false;
    std::unordered_set<int> v;
    std::unordered_set<int>:: iterator it;
    for(int i=0;i<n;i++){
        if(v.find(a[i])==v.end())
        v.insert(a[i]);
        else{
            found=true;
            break;
        }
    }
    return found;
}

int main(){
    //int array[]={11,34,67,43,67,20,21,11,0,56};
    int array[]={11,34,67,43,20,21,0,56};
    
    std::cout<<isThereDuplicate(array,sizeof(array)/sizeof(array[0]))<<std::endl;
    return 0;
}