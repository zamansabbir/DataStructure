#include<iostream>

//Time complexity O(N)
//Space Complexity O(1)
int reverseBitsInNumber(unsigned int number){
    int reverse=0;
    int n_bits=sizeof(number)*8; // number of bits in the data
    for(int i=0;i<n_bits;i++){
        reverse|=((number&1)<<(n_bits-1-i));
        number=(number>>1);
        std::cout<<reverse<<" ";
        
    }
    return reverse;
}

int main(){
    unsigned int originalNumber=1; //

    unsigned int reversed=reverseBitsInNumber(originalNumber); //
    std::cout<<std::endl<<"Reversed number:"<<reversed<<std::endl;
    return 0;
}