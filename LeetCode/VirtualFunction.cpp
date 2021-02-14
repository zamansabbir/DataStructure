#include<iostream>

struct newBase{
    public: 
        int x;
        void print(){
            std::cout<<"Printing from struct new Base "<< x <<std::endl;
        }
        void show(){
            std::cout<<"showing from struct new Base"<<std::endl;
        
        }
};
class Base{
    public: 
            virtual void print(){
                std::cout<<"Printing from base class"<<std::endl;
            }
            void show(){
                std::cout<<"Show Base class"<<std::endl;
            }
};

class Derived: public Base{
    public: 
        void print(){
            std::cout<<"Printing from Derived class"<<std::endl;
        }
        void show(){
            std::cout<<"Show derived class"<<std::endl;
        }
};
int main(){
    Base *bptr;
    Derived d;
    bptr=&d;
    bptr->print();
    bptr->show();

    newBase *ptr= new newBase();
    ptr->x=10;
    ptr->print();
}