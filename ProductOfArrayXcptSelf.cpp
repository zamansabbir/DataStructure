#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums){
    vector<int> result;
    vector<int> left_side;
    vector<int> right_side;
    int old=1;
    for(vector<int>::iterator it=nums.begin();it!=nums.end();++it){
        if(it==nums.begin()){
            left_side.push_back(old);
            //old=*it;
        }else{
            old=old* (*(it-1));
            left_side.push_back(old);
        }
    }
    old=1;
    for(vector<int>::reverse_iterator it=nums.rbegin();it!=nums.rend();++it){
        if(it==nums.rbegin()){
            right_side.push_back(old);
            //old=*it;
        }else{
            old=old* (*(it-1));
            right_side.push_back(old);
        }
    }
    vector<int>::reverse_iterator iter=right_side.rbegin();
    for(vector<int>::iterator it=left_side.begin();it!=left_side.end();++it){
        result.push_back((*it) *(*iter));
        iter++;
    }
    return result;
}
int main(){
    vector<int> input={1,2,3,4,30};
    productExceptSelf(input);
    return 0;
}