#include<iostream>
#include <climits>
#include <cstdlib>

/*
Algorithm Complexity Time=O(n*n)
*/
void findPair(int b[],int m, int sum){
    int diff=INT_MAX,res_i=0,res_j=0;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
                if(abs(b[i]+b[j]-sum)<=diff){
                    diff=abs(b[i]+b[j]-sum);
                    res_i=i;
                    res_j=j;
                }
        }
    }
    std::cout<<b[res_i]<<" "<<b[res_j]<<std::endl;
}
int main(){
    int a[]={10, 22, 28, 29, 30, 40};
    int n=sizeof(a)/sizeof(a[0]);
    findPair(a,n,54);
    return 0;

}
