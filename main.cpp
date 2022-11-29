#include <bits/stdc++.h>

using namespace std;

int hp, atk, cR;
float cDMG;
int Whp, Watk, WcR;
float WcDMG;

//XD

int r(int p, int k){
    int n;
    n = p + rand() % k;
    return n;
}

void postac(){
    hp = r(200, 800); atk = r(50, 100); cR = r(1, 40); cDMG = r(101, 49);
    cout<<" \nTwoja postac:\nhp:"<<hp<<" \natk: "<<atk<<" \ncR: "<<cR<<" \ncDMG: "<<cDMG/100<<endl;
}

void wrog(){
    Whp = r(200, 800); Watk = r(50, 100); WcR = r(1, 40); WcDMG = r(101, 49);
    cout<<" \nWroga postac:\nhp:"<<Whp<<" \natk: "<<Watk<<" \ncR: "<<WcR<<" \ncDMG: "<<WcDMG/100<<endl;
}


int main()
{
    srand(time(NULL));
    cout<<" Witaj, wybierz opcje:\n1. Graj\n2. Wyjdz\n";
    int wybor;
    do{
        cin>>wybor;
    }while(wybor!=1 && wybor!=2);
    switch(wybor){
    case 1:
        postac();
        wrog();
        break;
    case 2:
        cout<<"Pa Pa";
        break;
    }
    return 0;
}
