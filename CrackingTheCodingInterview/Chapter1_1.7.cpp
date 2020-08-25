#include<iostream>
void printMatrix(int array[][4]){
    /**
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        for(int j=0;j<sizeof(a[0])/sizeof(int);j++){
            std::cout<<a[i][j]<<" "<<std::endl;
        }
        std::cout<<std::endl;
    }
    **/
       std::cout<<sizeof(array)/sizeof(*array)<<std::endl;

   
}

int main(){
    int array[][4]={{1,2,3,4},{0,2,5,9},{3,4,5,0}};
   // std::cout<<sizeof(array)/sizeof(array[0])<<std::endl;
    printMatrix(array);
    return 0;
}