#include<iostream>
int reverseDigitsOfInteger(int N){
    int result=0;
    if(N==0)
    return result;
    
    else{
        int digit=0;
        while(N!=0){
            digit=N%10;
            result=result*10+ digit;
            N=N/10;
        }
    }
    return result;
}

int main(){
    std::cout<<reverseDigitsOfInteger(1000000045)<<std::endl;
    std::cout<<(unsigned int)-20<<std::endl;
    return 0;
}