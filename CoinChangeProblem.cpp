/**
 * given the coins 1 cent, 5 cents, and 10 cents with N = 10 cents, what are the total 
 * number of permutations of the coins you can arrange to obtain 10 cents.
 * Coins=[1,2,5] and N=10
 * 
*/
#include <iostream>
#include <vector>

int findTheNumberOfWaysToMakeTheAmount(std::vector<int>& coins,int target){
    std::vector<int> dp (target+1,0);
    dp[0]=1;
    /** find the obejctive function. dp[i] is going to be the number ways to make the 
    target amount where is the current amount.Whatever coin from the coin array I am going 
    to use, I need to check how many ways are there for the rest of the amount, so the 
    objective function is going to be dp[i]=dp[i]+dp[current amount-current coin]
    */


   for(int i=0;i<coins.size();i++){
       for(int j=0;j<=target;j++){
           //I can't use any coin greater the i
           if(coins[i]<=j){
               dp[j]+=dp[j-coins[i]];
           }
       }
   }
   return dp[target];
}

int main(){
    std::vector<int> coins={1,2,3};
    int amount=4;
    int numberOfWays=findTheNumberOfWaysToMakeTheAmount(coins,amount);
    std::cout<<"There are "<<numberOfWays<<" ways to make "<<amount<<std::endl;
    return 0;
}