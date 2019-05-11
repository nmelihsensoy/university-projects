/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "oop_basics.cpp"
 * 
 * Write classes that follow the following requests.
 * 1- Each classes must be have 3 constructor.
 * 2- Function Overloading must be used.
 * 3- Math operations must be done with using volume so operation made class should have minimum 3 dimension.
 *         
*/
#include <iostream>
using namespace std;

class Area{
    private:
        int length;
        int width;
    public:
        //Constructors
        Area(){
            this->length = 1;
            this->width = 1;
        }
        Area(int length, int width){
            this->length = length;
            this->width = width;
        }
        Area(int length){
            this->length = length;
            this->width = 1;
        }

        //Overloaded setters and getters
        void setlength(int length){this->length = length;}
        void setlength(){this->length = 1;}

        void setwidth(int width){this->width = width;}
        void setwidth(){this->width = 1;}

        int getwidth(){return this->width;}
        int getlength(){return this->length;}

        //Virtual for overriding
        virtual int getArea(){return 0;}
};

class Volume:public Area{
    private:
        int height;
    public:
        //Constructors
        Volume(){
            this->height = 1;
        }
        Volume(int u, int g):Area(u, g){};
        Volume(int u, int g, int y):Area(u, g){
            this->height = y;
        }
        
        //Overloaded setters and getters
        void setheight(int y){this->height = y;}
        void setheight(){this->height = 1;}
        int getheight(){return this->height;}

        virtual int getVolume(){return 0;}
};

class Shape:public Volume{
    private:

    public:
        //Constructors
        Shape():Volume(1, 1, 1){};
        Shape(int u, int g, int y):Volume(u, g, y){}
        Shape(int u, int g):Volume(u, g){}

        //Overridings
        int getArea(){
            return this->getlength()*this->getwidth();
        }

        int getVolume(){
            return this->getArea()*this->getheight();
        }

        //Operator Overloadings
        int operator+(Shape &s){
            return this->getVolume()+s.getVolume();
        }

        friend ostream &operator<<(ostream &out, Shape &s){
            return out<< "Volume:" <<s.getVolume()<< " Area:"<< s.getArea() <<endl;
        }        
};

int main(){

    Shape s1(11, 20, 30), s2(6, 8, 9);
    cout<<"S1 "<<s1;
    cout<<"S2 "<<s2;

    cout<<"S1+S2 : "<<s1+s2<<endl;

    return 0;
}