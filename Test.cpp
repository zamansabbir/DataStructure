#include<iostream>
#include<vector>
using namespace std;

int findPosition(vector<int>& nums, int target,int left, int right){
    if(left>right)
        return -1;

    int mid=left+(right-left)/2;
    if(nums[mid]==target)
        return mid;
    if(target>nums[mid])
        return findPosition(nums, target,mid+1,right);
    else
        return findPosition(nums, target,left,mid-1);
}



vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> position={-1,-1};
    if(nums.size()==0)
    return position;
    int firstPosition=findPosition(nums,target,0,nums.size());
    cout<<firstPosition<<endl;
    if(firstPosition!=-1){
        position.at(0)=firstPosition;
        if(firstPosition==nums.size()-1) { position.at(1)=firstPosition; return position;}
        if(firstPosition+1<nums.size()&& nums.at(firstPosition+1)!=target)
            position.at(1)=firstPosition;
        for(int i=firstPosition+1; i<nums.size() && nums[i]==target;i++){
            position.at(1)=i;
            }
    }
  
    
    return position;

 }
int main(){
    vector<int> nums={2,2}; //{5,7,7,8,8,10,11}
    vector<int> position=searchRange(nums,3);
    for(auto it=position.begin();it!=position.end();++it)
    cout<<*it<<" ";
    
return 0;
}