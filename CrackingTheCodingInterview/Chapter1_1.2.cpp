/**
 * Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
five characters, including the null character.)
Example: Hello\0 reversed=olleH\0
*/
#include <iostream>
#include<string.h>

/**
 * Time complexity O(n), where n is the length of string and space complexity O(1)
*/
void reverseCString(char* s,int length){ 
    int left=0;
    int right=length-1;
    while(left<right){
        char temp=*(s+left);
        *(s+left)=*(s+right);
        *(s+right)=temp;
        left++;
        right--;
    }
}

int main (){

    char s1[]="hello";
    reverseCString(s1,strlen(s1));
        std::cout<<strlen(s1)<<std::endl;
        printf("%s\n",s1);
    return 0;
}