#include <iostream>
int main(){
    int a=0x0001;
    char* b=(char*)&a;
    //int littleEndian=b
    std::cout<<(*b?"little endian":"Big Endian")<<std::endl;
        return 0;

}
