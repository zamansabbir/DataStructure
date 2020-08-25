#include <iostream>
#include<vector>
#include<climits>

int size=INT_MAX; //just a number, later initialized
int getParentIndex(int childIndex){
    return (childIndex-1)/2;
}
int getLeftChildIndex(int parentIndex){
    return 2*parentIndex+1;
}
int getRightChildIndex(int parentIndex){
    return 2*parentIndex+2;
}

bool hasParent(int index){
    return getParentIndex(index)<=0;
}
bool hasLeftChild(int index){
    return getLeftChildIndex(index)<size;
}

bool hasRightChild(int index){
    return getRightChildIndex(index)<size;
}

void swap(std::vector <int> &s,int index1,int index2){
    int temp=s[index1];
    s[index1]=s[index2];
    s[index2]=temp;

}
void heapifyDown(std::vector<int> &h,int index){
    //int index=0;
    int smallerChildIndex=0;
    while(hasLeftChild(index)){
        smallerChildIndex=getLeftChildIndex(index);
        if(hasRightChild(index)&& h[getRightChildIndex(index)]<h[getLeftChildIndex(index)]){
            smallerChildIndex=getRightChildIndex(index);
        }
        if(h[index]<h[smallerChildIndex]){
            break;
        }
        swap(h,index,smallerChildIndex); 
        index=smallerChildIndex;      
    }


}
void createMinHeap(std::vector<int> &h){
    for(int i=(h.size()/2-1);i>=0;--i){
        heapifyDown(h,i);
    }
}
int main(){
    //int a[]={12, 11, 13, 5, 6, 7};
    std::vector<int> a={12, 11, 13, 5, 6, 7};
    size=a.size();
    createMinHeap(a);
    for(auto i=a.begin();i!=a.end();++i){
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
    return 0; 
}