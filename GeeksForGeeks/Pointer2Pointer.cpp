#include<iostream>

int global_var=42;

void changePointervalue(int **pp){
    *pp=&global_var;
}

int main(){
    int var=23;
    int *ptr_to_var=&var;
    std::cout<<"Passing Pointer to function"<<std::endl;
    std::cout<<"Before:"<<*ptr_to_var<<std::endl;
    changePointervalue(&ptr_to_var);
    std::cout<<"After:"<<*ptr_to_var<<std::endl;
    
    return 0;
}