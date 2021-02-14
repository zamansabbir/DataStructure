#include<iostream>
#include<vector>
#include<algorithm>
int main(){

       std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) {​​​​​ return n < x }​​​​​), c.end());
    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){​​​​​ std::cout << i }​​​​​);
    std::cout << '\n';
    auto func1 = [](int i = 6) {​​​​​ return i + 4 }​​​​​;
    std::cout << "func1: " << func1() << '\n';

}