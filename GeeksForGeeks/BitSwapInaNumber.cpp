/**
 * Given a number x and two positions (from the right side) in the binary representation 
 * of x, write a function that swaps n bits at given two positions and returns the result.
 * It is also given that the two sets of bits do not overlap.

 *  Let p1 and p2 be the two given positions.
 * 
 * Input:
x = 47 (00101111)
p1 = 1 (Start from the second bit from the right side)
p2 = 5 (Start from the 6th bit from the right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from the right side) are 
swapped with 3 bits starting from 6th position (from the right side) 
*/

/**First part
 * 00101111
 * 11100000---n 1's after p2
 * 11111111
 * 00011111 : 1<<(p2+1)=>100000 then subtracting 1 from it=100000-1=00011111
 * mask1=11111111-((1<<(p2+1))-1)=11100000 first thing
 * 
 * a=x&11100000=00100000
 * if we shift a to right (p2-p1)=4 space,00000010 
 * 
 * 1. max=~0=11111111;
 * 2. mask_a=max-((1<<(p2+1))-1)
 * 3.temp=x&mask_a
 * 4.t1=x&(~mask_a)
 * 5. a=temp>>(p2-p1)
 * 
 * Second part=
 * 00101111
 * 00001110           111 110
 * 1<<(p1+3)=>10000 if we subtract 1 from it, 10000-1=01111-1=01110
 * 
 * 6. mask_b=(1<<(p1+3))-2= 01110
 * 7. temp=x&mask_b
 * 8. t2=t1&(~mask_b)
 * 9. b=temp<<(p2-p1)=>00001110<<(4)=>11100000
 * 
 * 10. final_mask_= a|b
 * 00000010
 * 11100000
 * 11100010
 * final_mask=11100010
 * t2=00000001
 *11. final_number=t2|final_mask=
 * 00000001
 * 11100010
 * 11100011
 * not done yet, we need the bits to be swapped as 0's
*/
#include<iostream>
#include<bitset>
int BitSwapInNumbers(int x, int p1,int p2, int n){
    //int max=~0;
    int mask_a=(~0)-((1<<(p2))-1);
    int temp=x&mask_a;
    int t1=x&(~mask_a);
    int a=temp>>(p2-p1);

    int mask_b=(1<<(p1+n))-2;
    temp=x&mask_b;
    int t2=t1&(~mask_b);

    int b=temp<<(p2-p1);
    int final_mask= a|b;

    return (t2|final_mask);
}

int main(){
    int x=28;
    //std::bitset<32> y(x)
    std::cout<<std::bitset<32>(x)<<std::endl;
    int y=BitSwapInNumbers(x,0,3,2);
    std::cout<<std::bitset<32>(y)<<std::endl;

}