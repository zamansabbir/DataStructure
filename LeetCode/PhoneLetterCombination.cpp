#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

std::unordered_map <char, std::string> phone={
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};

void backTrack(std::string current, std::string digits, int index,std::vector<std::string> &output){
    if(index==digits.length()){

        output.push_back(current);
        return;
    }
    std::string letters=phone[digits[index]];
    for(int i=0;i<letters.length();i++){
        backTrack(current+letters[i],digits,index+1,output);
    }

}
std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> output;
        backTrack("",digits,0,output);
        return output;

    }
int main(){
    std::string digits="234";
    std::vector<std::string> output=letterCombinations(digits);

    return 0;
}