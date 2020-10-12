 #include<iostream>
 #include<cmath>
 int findQuotient(long long dividend,long long divisor){
        int count=0;
        while(dividend>=divisor){
            int accum=divisor, i=1;
            while((accum<<1)<=dividend){
                i<<=1;
                accum<<=1;
            }
            dividend-=accum;
            count+=i;
        }
        return count;
    }
    int divide(int dividend, int divisor) {
        if(dividend==INT32_MIN && divisor==-1)
        return INT32_MAX;
        if(dividend==INT32_MIN && divisor==1)
        return INT32_MIN;
        
        bool negative=false;
        if((divisor<0)^(dividend<0)){
                negative=true;
        }
        long long a=dividend;
        long long b=divisor;
        int result=findQuotient(abs(a),abs (b));;
        return negative?-result:result;
    }
    int main(){
        
        std::cout<<divide(19,3)<<std::endl;
        return 0;
    }