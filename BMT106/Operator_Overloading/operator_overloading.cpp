/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "operator_overloading.cpp"
 * 
 * Relational operator overloading.'+' as a bigger than, '-' as a less than. 
*/
#include <iostream>
using namespace std;

class Safe{
    private:
        int lira;
        int kurus;
    public:
        Safe(){
            this->lira = 0;
            this->kurus = 0;
        }
        Safe(int l, int k){
            this->lira = l;
            this->kurus = k;
        }
        int getLira(){return this->lira;};
        int getKurus(){return this->kurus;};
        void setLira(int l){this->lira = l;};
        void setKurus(int k){this->kurus = k;};

        //Bigger than
        bool operator+(Safe &k){ 
            if(this->lira > k.getLira()){
                return true;
            }

            if((this->kurus > k.getKurus()) and (this->lira == k.getLira()))
                return true;

            return false;
        }

        //Less than
        bool operator-(Safe &k){
            if((this->lira == k.getLira()) and (this->kurus == k.getKurus()))
                return true;

            return false;
        }
        
        //Output operator
        friend ostream & operator<<(ostream &out, Safe &k){
            return out<<k.getLira()<<"."<<k.getKurus()<<"₺";
        }
};

int main(){

    Safe S1(5, 20), S2;
    
    S2.setLira(10);
    S2.setKurus(60);

    if(S1 + S2){
        cout<<S1<<" > "<<S2<<endl;
        cout<<"great"<<endl;
    }else if(S1-S2){
        cout<<S1<<" = "<<S2<<endl;
        cout<<"equal"<<endl;
    }else{
        cout<<S1<<" < "<<S2<<endl;
        cout<<"less"<<endl;
    }
    return 0;
}