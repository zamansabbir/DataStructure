#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> output;
    if(intervals.size()<=1){
        return output;
    }
    
   // output.push_back(intervals[0]);
    vector<int> current_interval=intervals[0];
    output.push_back(current_interval);
    for(vector<int> i: intervals){
        if(current_interval[1]>=i[0]){
            current_interval[1]=current_interval[1]>i[1]?current_interval[1]:i[1];
            output[output.size()-1][1]=current_interval[1];
        }else{
            current_interval=i;
            output.push_back(i);
        }

    }
    return output;
 }
bool compareFunction(vector<int> i, vector<int> j){
    return i[0]<j[0];
}

int main(){
    vector<vector<int>> i={{1,3},{2,6},{15,18},{8,10}};
    sort(i.begin(),i.end(),compareFunction); // N*log(N) with N is the number of ele
    vector<vector<int>> output=merge(i);
 

    return 0;
}