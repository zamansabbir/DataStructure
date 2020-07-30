#include<iostream>
#include <vector>
void findContinuity(std::vector<std::vector<char>> &a,int i,int j){
    if(i<0||i>=a.size()||j<0||j>=a[0].size()||a[i][j]=='0')
    return ;

    a[i][j]='0';
    findContinuity(a,i-1,j); //top
    findContinuity(a, i+1,j); //bottom
    findContinuity(a,i,j-1); //left
    findContinuity(a,i,j+1); // right

}
int findIsland(std::vector<std::vector<char>> &a){
    int count=0;
   for(int i=0;i<a.size();i++){
       for(int j=0;j<a[i].size();j++){
           if(a[i][j]=='1'){
               count++;
               findContinuity(a,i,j);
           }
      }
       
    }
    return count;
}



int main(){
    std::vector<std::vector<char>> array={
        {'1','1','1','1','0'},
        {'0','0','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
   // std::cout<<sizeof(array)/sizeof(array[0])<<std::endl;
   int i= findIsland(array);
   std::cout<<"Number of island found: "<< i<<std::endl;
    return 0;
}