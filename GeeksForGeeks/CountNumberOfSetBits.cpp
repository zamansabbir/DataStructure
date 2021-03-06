#include <iostream>

//Iterative solution
int countSetBits(unsigned int x){
    //int count=x&1;
    int count=0;
    while(x>0){
        count+=(x&1);
        x=x>>1;
    }
    return count;
}
//Recursive Solution
int counSetBitsRecursive(unsigned int x){
    if(x==0)
    return 0;
    return (x&1)+counSetBitsRecursive(x>>1);
}

int countSetBitR(unsigned int x){
    if(x==0)
    return 0;
    return (x&1)? 1+countSetBitR(x>>1):countSetBitR(x>>1);

}
int coutSetBitOptimized(unsigned int x){
    if(x==0)
    return 0;
    return 1+countSetBitR(x&(x-1));

}
int main(){
    unsigned int x=(2);//00101111
    std::cout<<countSetBits(x)<<std::endl;
    std::cout<<counSetBitsRecursive(x)<<std::endl;
    std::cout<<countSetBitR(x)<<std::endl;
    std::cout<<coutSetBitOptimized(x)<<std::endl;
    return 0;
}