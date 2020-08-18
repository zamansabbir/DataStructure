/**
 * Write a method to replace all spaces in a string with ‘%20
 * 
*/

/**
 * 
Example: 
 012345678901
"S ab bir"
"S%20ab%20bir"

1. count the number of spaces 
for each space %20, if n spaces are there, then we need extrace space n*2. extend the current 
array to new_size=arraysize+n*2

 01234567891011121314
"S ab bir"
if we enter space as we traverse
for each space, we have to move rest of the characters after space everytime we find a space

If we just traverse list from the end(arraysize) to the beginning=0
S ab bir
nextupdate=new_size=arraysize+n*2
S ab bir   r
------------
new_size=new_size-1
S ab bir  ir
------------
new_size=new_size-1

S ab bir  bir
------------
new_size=new_size-1

now we find a space
if we find space, 3 characters taken, nextupdate should happen after another 3 position
new_size=new_size-3
S ab b%20bir
*/
#include<iostream>
#include<string.h>

void insertCharacters(char* s, int length){
    //count the number of spaces
    int space_count=0;
    for(int i=0;i<length;i++){
        space_count=(*(s+i)==' ')?space_count+1:space_count;
    }
    int new_length=length+2*space_count;
    //std::cout<<space_count<<std::endl;
    *(s+new_length)='\0';
    for(int i=length-1;i>=0;i--){
        if(*(s+i)==' '){
            *(s+new_length-1)='0';
            *(s+new_length-2)='2';
            *(s+new_length-3)='%';
            new_length=new_length-3;
        }else{
            *(s+new_length-1)=*(s+i);
            new_length--;
        }
        
    }
}

int main(){
    char s[]="S ab bir"; //8 char, 2 space, new_length=8+2*2
   // std::cout<<"length"<<strlen(s)<<std::endl;

   // int l=strlen(s);
   insertCharacters(s, strlen(s));
   std::cout<<s<<std::endl;
    return 0;
}