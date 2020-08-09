/**
 * Implement an algorithm to determine if a string has all unique characters
*/

#include <iostream>
#include<string>
#include<unordered_set>

/**
 * Time complexity determineUnique(std::string &s) is O(N)
 * and space complexity O(N) 
*/
bool determineUnique(std::string &s){
    if(s.empty())
    return true;
    std::unordered_set <char> set;
    for(int i=0;i<s.length();i++){
        if(set.find(s[i])!=set.end()){
            return false;
        }
        set.insert(s[i]);
    }
    return true;
}
/**
 * Time complexity determineUnique1(std::string &s) is O(N^2), two nested for loops
 * and space complexity O(1) 
*/

bool determineUnique2(std::string &s){
    if(s.empty())
    return true;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            if(s[i]==s[j]){
                return false;
            }
        }
    }
    return true;
}

bool determineUnique3(std::string &s){
    int unique=0; //unique can act as a flag;assuming only smaller case alphabet (a-z),
    // 26 bits 
    if(s.empty())
    return true;
    for(int i=0;i<s.length();i++){
        int val=(s[i]-'a');
        if((unique&(1<<val))>0)
        return false;
        unique|=(1<<val);
    }
    return true;
}

int main(){
    std::string s="abcd";
    std::cout<<determineUnique3(s)<<std::endl;
    return 0;
}