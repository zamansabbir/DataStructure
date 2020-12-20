#include<iostream>
#include<climits>
using namespace std;
struct d{int a; char b;double c; };

 bool isPalindrome(int x) {
        if(x<0) return false;
        int temp=x, digit,newNumber=0;
      
         while(temp){
                digit=temp%10;
                if(newNumber>=INT32_MAX/10 && (temp%10)>0 )
                return false;
                newNumber=newNumber*10+digit;
                temp=temp/10;
          }

          return newNumber==x? true: false;
   
    }

    bool checkPalindrome(int x){
        if(x<0 || (x!=0 &&(x%10==0))) return false;
        int revertedNumber=0;
        while(x>revertedNumber){
            revertedNumber=revertedNumber*10+(x%10);
            x=x/10;
        }
        return x==revertedNumber || x==revertedNumber/10;
    }

int findGreater(int a, int b){
    return ((a-b)>>31)&1?b:a;
}
int main(){
    //std::cout<<isPalindrome(12321);
    //std::cout<<checkPalindrome(12321);
    std::cout<<findGreater(50,49);
        return 0;

}
