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

void insertCharacters(char* s){

}

int main(){

    return 0;
}