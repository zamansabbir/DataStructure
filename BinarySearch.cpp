#include<iostream>

bool binarySearch(int* arr,int start, int end, int x){
    if(start>end){
        return false;
    }
    if(end<start){
        return false;
    }
    int middle=(start+end)/2;
    if(arr[middle]==x){
        return true;
    }else if(x>arr[middle]){
       return binarySearch(arr,middle+1,end,x);
    }else{
        return binarySearch(arr,start,middle-1,x);
    }
}

bool findNumber(int* arr,int n,int x){
    bool found=binarySearch(arr,0,n,x);
    return found;
}

int main(){
    int array[]={1,2,3,4,5,6,7,8,9,11,15,17,90,200,350};
    bool found=false;
    found=findNumber(array,sizeof(array)/sizeof(array[0]),301);
    std::cout<<found<<std::endl;
    return 0;
}