#include <bits/stdc++.h>

using namespace std;

int r(int p, int k)
{
    int n;
    n = p + rand() % k;
    return n;
}

float atak(int atk, int chance, int multi)
{
    int szansa = r(1,100);
    if(chance>=szansa)
    {
        return atk*multi;
    }
    else
    {
        return atk;
    }
}

vector <float> staty()
{
    int hp, atk, cR;
    float cDMG;
    vector <float> STATY;
    hp = r(3000, 2000);
    atk = r(250, 150);
    cR = r(1, 40);
    cDMG = r(101, 49);
    STATY.push_back(hp);
    STATY.push_back(atk);
    STATY.push_back(cR);
    STATY.push_back(cDMG/100);
    return STATY;
}

int main()
{
//    ofstream wy;
//    wy.open("character.txt");
    srand(time(NULL));
    vector <float> P;
    vector <float> W;



    cout<<"Kliknij enter aby kontynuowac";
    getchar();



    cout<<"\n Postac | HP | ATK | CritRate | CritDMG |\n";
    cout<<" Twoja Postac: ";
    for (int i=0; i<staty().size(); i++)
    {
        P.push_back(staty()[i]);
        cout<<P[i]<<" ";
    }
    cout<<"\n Wrog: ";
    for (int i=0; i<staty().size(); i++)
    {
        W.push_back(staty()[i]);
        cout<<W[i]<<" ";
    }



    cout<<endl<<"\nKliknij enter aby kontynuowac";
    getchar();



    cout<<"     Walka!      \n";
    do
    {
        cout<<"\nHP twoje: "<<P[0]<<", HP Wroga: "<<W[0]<<endl;
        cout<<"Uderzasz za "<<atak(P[1],P[2],P[3])<<" ";
        W[0]-=atak(P[1],P[2],P[3]);
        if(W[0]<0)
        {
            cout<<"\n Wygrales ";
            break;
        }
        cout<<"Wrog uderza za "<<atak(W[1],W[2],W[3])<<endl;
        P[0]-=atak(W[1],W[2],W[3]);
        if(P[0]<0)
        {
            cout<<"\n Przegrales ";
            break;
        }
    }
    while(P[0]>0);



//    wy.close();
    return 0;
}
