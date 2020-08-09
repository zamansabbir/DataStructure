/**
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
method to set all bits between i and j in N equal to M (e.g., M becomes a substring of
N located at i and starting at j). 
Example 
Input: N = 10000000000, M = 10101, i = 2, j = 6
             9876543210
Output: N = 10001010100
_______________________
*/
#include <iostream>
#include<bitset>
/**
 * Concept is We can left shift m to i times and 'OR' n with shifted m. Problem is not bits
 * in n are 0's. We need to make sure those bits 0's then we can simply 'OR' with m.
 * We have to create a mask with zeros in between i to jth position
 * 
 * if we have all 1's, dummy=1111 1111 (8 bits) considering
 * we want 0's in between 3-5: 1100 0111
 * left= 1111 1111 
 *       0011 1000 
 * ----------------
 * (-)   1100 0111 mask
 * 
 * left=1100 0000
 * 
 * 1111 1111 ->dummy
 * 0011 1111    0100 0000 -1 =1 0011 1111= 1<<(j+1)-1 gives j+1 setbits in least significant part 
 * dummy-((1<<j+1)-1)
 *
 * 
 * right 0000 0111 : 1<<3=1000 and subtracting 1 from it we get 0111 
 * right= (1<<i)-1
 * 
 * 
*/
int setBitsBetweenIandJ(int m, int n, int i, int j){
    int dummy=~0; //32 1's
    int left=dummy-((1<<j+1)-1); //1's beyond jth
    int right=(1<<i)-1; 
    int mask=left|right;
    return ((n&mask)|(m<<i));

}

int main(){
    int x=setBitsBetweenIandJ(21,1024,2,6);

    std::bitset<32> y(x);
    std::cout<<y<<std::endl;
    return 0;
}