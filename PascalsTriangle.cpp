#include <iostream>
#include <vector>
std::vector<std::vector<int>> generatePascalTriangle(int k){
std::vector<std::vector<int>> result;
std::vector<int> row;
for(int i=0;i<k;i++){
    row.insert(row.begin(),1);
    for (int j=1;j<row.size();j++){
        //row.push_front(1);
        row[j]=row[j]+row[j+1];
    }

    result.push_back(row);
}

return result;
}

void printPascalTriangle(std::vector<std::vector<int>> pascal){
    for(int i=0;i<pascal.size();i++){
        for(std::vector<int>::iterator it=pascal[i].begin();it<pascal[i].end();it++)
        std::cout<<*it<<" ";
        std::cout<<std::endl;
   }
}
int main(){
std::vector<std::vector<int>>v=generatePascalTriangle(5);
printPascalTriangle(v);
  return 0;
}