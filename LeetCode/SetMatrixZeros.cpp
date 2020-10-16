#include<iostream>
#include <vector>
#include<utility>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        
    vector<pair<int, int>> zeros;
    //O(n)
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
           if(matrix[i][j]==0)
           zeros.push_back(make_pair(i,j));
        }
        
    }
    for(pair<int,int> s:zeros){
           for(int col=0;col<matrix[0].size();col++){
               matrix[s.first][col]=0;
           }
           for(int row=0;row<matrix.size();row++){
               matrix[row][s.second]=0;
           }
        }
}

int main(){
    vector<vector<int>> m={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(m);
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            cout<<m[i][j]<<"";
        }
        cout<<endl;
    }

}