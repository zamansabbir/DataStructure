/**
 * write code to remove the duplicate characters in a string without using any additional buffer. 
Note: One or two additional variables are fine. An extra copy of the array is not
*/

/**
 * 
 * Using a C-style string and using two pointers 
*/
#include<iostream>
#include<string.h>
#include<unordered_set>


/**Without using any buffer, inplace removal, but time complexity is O(N^2)*/
void removeDuplicates(char* s,int n){
    int last_not_updated_reference=1;
    
    for(int i=1;i<n;i++){ 
         bool found=false;
        for(int j=0;j<last_not_updated_reference;j++){
            if(*(s+i)==*(s+j)){
            found=true;
            break;
            }
            
        }
        if(!found){
                    *(s+last_not_updated_reference)=*(s+i);
                    ++last_not_updated_reference; 
            }
    }
    *(s+last_not_updated_reference)='\0';

}
/*improving time complexity O(N) using hashmpap (array) space complexity O(1), assuming 8 bit ASCII*/
void removeDuplicates2(char* s,int n){
    int hash_map[256]={0};
    int last_not_updated_reference=0;
    for(int i=0;i<n;i++){
        if(hash_map[*(s+i)]==0){
            hash_map[*(s+i)]++;
            *(s+last_not_updated_reference)=*(s+i);
            ++last_not_updated_reference;
        }
    }

     *(s+last_not_updated_reference)='\0';
}


/**Using STL unordered_set, access time O(1), saves space complextiy, maximum size would be size of unique, 
 * last implementation utilizes 256*sizeof(int), rarely used completely
*/

void removeDuplicates3(char* s,int n){
    std::unordered_set<char> unique_char;
    int last_not_updated_reference=0;

    for(int i=0;i<n;i++){//0 1 2 3 4 5
        if(unique_char.find(*(s+i))==unique_char.end()){
            unique_char.insert(*(s+i));//S a b i r
            *(s+last_not_updated_reference)=*(s+i);//Sabir
            last_not_updated_reference++;//1 2 3 4 5
        }
    }
    *(s+last_not_updated_reference)='\0';
}
int main (){

    char s[]="abbiSr";
    removeDuplicates3(s,strlen(s));
    printf("%s\n",s);
    return 0;
}