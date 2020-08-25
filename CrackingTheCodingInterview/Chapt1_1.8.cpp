#include<iostream>
#include<string>
bool isRotation(std::string s1,std::string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    std::string s=s1+s1;

    //std::cout<<<<std::endl;
    return (s.find(s2)!=std::string::npos)?true:false;
}

int main(){
    std::string s1="waterbottle", s2="b" ;
    std::cout<<isRotation(s1,s2)<<std::endl;
    return 0;
}