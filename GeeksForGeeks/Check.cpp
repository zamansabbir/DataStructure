#include<iostream>


int main(){

int x=0x01;
char *a=(char*)(&x);
if(*a==1){
    std::cout<<"Litt endian";

}else std::cout<<"Big Endian";
return 0;
}