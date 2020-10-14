#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string pstring){
    int i=0, l=pstring.length();
    bool isP=true;
    while(i<(l/2)){
        if(pstring[i]==pstring[l-1-i])
        ++i;
        else {
            isP=false;
            break;
        }
    }
    return isP;
}
string longestPalindrome(string s){

    string result=s.substr(0,1);

    for(int size=s.length()-1;size>0;size--){
        for(int i=0;i<(s.length()-size);i++){
            if(isPalindrome(s.substr(i,size+1))){
                result=s.substr(i,size+1);
                return result;
            }
        }
    }

    return result;
}

int main(){
    cout<<longestPalindrome("forgeeksskeegfor");
    return 0;
}