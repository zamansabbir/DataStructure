#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string reverseVowels(string s) {
        unordered_set<char> vowels({'A','E','I','O','U','a','e','i','o','u'});
        int left=0, right=s.length()-1;
        char temp;
        while(left<right){
            while((vowels.find(s.at(left))==vowels.end())&& left<right){
                left++;
            }

            while((vowels.find(s.at(right))==vowels.end())&& right>left){
                right--;
            }
            
            if((vowels.find(s.at(left))!=vowels.end())& (vowels.find(s.at(right))!=vowels.end())){
                temp=s.at(left);
                s.at(left)=s.at(right);
                s.at(right)=temp;
            }
            left++;
            right--;
        }
      
    return s;
}

int main(){

cout<<reverseVowels("xyz");
    return 0;
}