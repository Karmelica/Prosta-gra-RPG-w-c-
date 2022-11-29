#include <bits/stdc++.h>

using namespace std;

int hp, atk, cR;
float cDMG;
int Whp, Watk, WcR;
float WcDMG;

int r(int p, int k)
{
    int n;
    n = p + rand() % k;
    return n;
}

vector <float> postac()
{
    vector <float> POSTAC;
    hp = r(200, 800);
    atk = r(50, 100);
    cR = r(1, 40);
    cDMG = r(101, 49);
    POSTAC.push_back(hp);
    POSTAC.push_back(atk);
    POSTAC.push_back(cR);
    POSTAC.push_back(cDMG/100);
    return POSTAC;
}

vector <float> wrog()
{
    vector <float> WROG;
    Whp = r(200, 800);
    Watk = r(50, 100);
    WcR = r(1, 40);
    WcDMG = r(101, 49);
    WROG.push_back(Whp);
    WROG.push_back(Watk);
    WROG.push_back(WcR);
    WROG.push_back(WcDMG/100);
    return WROG;
}

int main()
{
    srand(time(NULL));
    cout<<" Witaj, wybierz opcje:\n1. Graj\n2. Wyjdz\n";
    int wybor;
    do
    {
        cin>>wybor;
    }
    while(wybor!=1 && wybor!=2);
    switch(wybor)
    {
    case 1:
        cout<<" Postac | HP | ATK | CritRate | CritDMG |\n";
        cout<<" Twoja postac: ";
        for (int i=0; i<postac().size(); i++)
        {
            cout<<postac()[i]<<" ";
        }
        cout<<"\n Wrog: ";
        for (int i=0; i<wrog().size(); i++)
        {
            cout<<wrog()[i]<<" ";
        }
        break;
    case 2:
        cout<<"Pa Pa";
        break;
    }
    return 0;
}
