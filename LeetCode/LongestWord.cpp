#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<unordered_set>
using namespace std;
string longestWord(vector<string> &words){
    string result="";
    sort(words.begin(),words.end());
    unordered_set <string> check;
    for(string &s:words){
        if(s.length()==1||check.find(s.substr(0,s.length()-1))!=check.end()){
        if(s.length()>result.length())
        result=s;
        check.insert(s);;
        }
    }
    return result;
}
int main(){
    vector<string> w={"a","banana","app","appl","ap","apply","apple"};
   cout<< longestWord(w)<<endl;

  
    return 0;
}