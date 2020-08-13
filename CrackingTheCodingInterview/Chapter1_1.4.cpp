/**
 * Write a method to decide if two strings are anagrams or not
 * Silent and Listen are anagrams
 * baiii ibiaii are anagrams
*/

#include<iostream>
#include <string>
#include<unordered_map>

/**
 * 1. Check the length of the two strings, if they are not equal. return false
2. We can populate the DataStructure: Hashmap1 as we traverse the string 1 
iiiby
(i,3)
(b,1)
(y,1)


3. While traversing string 2, 
yibii

y if hashmap1.get(y)==0 return false, if not update hashmamp1.get(y)-1	
if passes through the 2nd for loop return true			

*/

bool checkAnagrams(std::string&s1,std::string&s2){
    if(s1.length()!=s2.length()){
        return false;
    }
std::unordered_map<char,int> hashmap; 

//hashmap1[s1[0]]=1;
for(int i=0;i<s1.length();i++){
    if(hashmap.find(s1[i])!=hashmap.end()){//s[i] found 
       hashmap[s1[i]]= hashmap.at(s1[i])++;
    }else //s[i] not found
    {
      hashmap[s1[i]]=1;
    }
    
}
for (int i=0;i<s2.length();i++){
    if(hashmap.find(s2[i])==hashmap.end()){//not found
    return false;

    }else if (hashmap.at(s2[i])==0){ // if count is =0

        return false;
    }else{
        hashmap[s2[i]]=--hashmap.at(s2[i]);
       //std::cout<<--hashmap.at(s2[i])<<std::endl;
    }

}

 return true;
}

int main(){
std::string s1="silent";
std::string s2="liiten";
std::cout<<checkAnagrams(s1,s2)<<std::endl;
    return 0;
}