#include<iostream>
using namespace  std;
const int n=4;

void rotateArray90DegreeClockWise(int a[][n]){

    //transpose the array-2D
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
    //Mirror the array
    for(int i=0;i<n;i++){
        for(int j=n-1;j>n/2;j--){
            int temp=a[i][n-1-j];
            a[i][n-1-j]=a[i][j];
            a[i][j]=temp;
        }
    }
}


void rotateArray90DegreeAntiClockWise(int a[][n]){

    //transpose the array-2D
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
    //Mirror the array
    
    for(int j=0;j<n;j++){
        for(int i=0;i<n/2;i++){
            int temp=a[i][j];
            a[i][j]=a[n-1-i][j];
            a[n-1-i][j]=temp;
        }
    }
}


void displayArray(int a[][n]){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<a[i][j]<<" ";
        }
        std:cout<<std::endl;
    }

}
int main (){
    int a[n][n]={ {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}};
            //rotateArray90DegreeClockWise(a);
            rotateArray90DegreeAntiClockWise(a);
            displayArray(a);
    return 0;
}