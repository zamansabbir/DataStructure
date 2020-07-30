#include <iostream>
#include<string>
using namespace std;
int convertToInteger(string s){
    int result=0;
    for(int i=0;i<s.length();i++){
      //  std::cout<<s[i]<<" ";
        if((s[i]-'0')>=0 && (s[i]-'0')<=9){
            
            result=(s[i]-'0')+result*10;
        }
    }
    return result;
}
int main(){
    string d="a1b2";
    int x=convertToInteger(d);
    std::cout<<x<<std::endl;
    return 0;
}