#include <bits/stdc++.h>

using namespace std;

int r(int p, int k)
{
    int n;
    n = p + rand() % k;
    return n;
}

float atak(float atk, float chance, float multi)
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

//vector <float> stat(int lvl)
//{
//    int hp, atk, cR;
//    float cDMG;
//    vector <float> S;
//    hp = r(300, 200);
//    atk = r(25, 15);
//    cR = r(1, 40);
//    cDMG = r(101, 49);
//    S.push_back(hp+(0.5*lvl));
//    S.push_back(atk+(0.5*lvl));
//    S.push_back(cR+(0.3*lvl));
//    S.push_back(cDMG/100+(0.6*lvl));
//    return S;
//}

int walka(struct postac* P, struct postac* W)
{
    cout<<"     Walka!      \n";
    do
    {
        cout<<"\nHP twoje: "<<P.hp<<", HP Wroga: "<<W.hp<<endl;
        cout<<"Uderzasz za "<<atak(P.atk,P.cR,P.cDMG)<<" ";
        W.hp-=atak(P.atk,P.cR,P.cDMG);
        if(W.hp<0)
        {
            return 1;
            break;
        }
        cout<<"Wrog uderza za "<<atak(W.atk,W.cR,W.cDMG)<<endl;
        P.hp-=atak(W.atk,W.cR,W.cDMG);
        if(P.hp<0)
        {
            return 0;
            break;
        }
    }
    while(P[0]>0);



    cout<<endl<<"\n Kliknij enter aby kontynuowac";
    getchar();
}

struct postac
{
    float hp;
    float atk;
    float cR;
    float cDMG;
};

void pokaz(struct postac A)
{
    cout<<A.hp<<" ";
    cout<<A.atk<<" ";
    cout<<A.cR<<" ";
    cout<<A.cDMG<<" ";
}


int main()
{
//    ofstream wy;
//    wy.open("character.txt");
    srand(time(NULL));
    vector <float> P;
    vector <float> W;

    cout<<"\n Kliknij enter aby kontynuowac";
    getchar();

    int lvl = 200;
    postac Gracz =
    {
        r(300, 200)+(0.5*lvl),
        r(25, 15)+(0.5*lvl),
        r(1, 40)+(0.3*lvl),
        (r(101, 49)+(0.6*lvl))/100,
    };

    postac Wrog =
    {
        r(300, 200)+(0.5*lvl),
        r(25, 15)+(0.5*lvl),
        r(1, 40)+(0.3*lvl),
        (r(101, 49)+(0.6*lvl))/100,
    };

    cout<<"\n Postac | HP | ATK | CritRate | CritDMG |";
    cout<<"\n Twoja Postac: ";
    pokaz(Gracz);
    cout<<"\n Wrog: ";
    pokaz(Wrog);
//    for (int i=0; i<stat(lvl).size(); i++)
//    {
//        P.push_back(stat(lvl)[i]);
//        cout<<P[i]<<" | ";
//    }
//    for (int i=0; i<stat(lvl).size(); i++)
//    {
//        W.push_back(stat(lvl)[i]);
//        cout<<W[i]<<" | ";
//    }

    cout<<"\n Kliknij enter aby kontynuowac";
    getchar();

    if(walka(Gracz, Wrog)==1)
    {
        cout<<"\n Wygrales";
    }
    else
    {
        cout<<"\n Przegrales";
    }
//    wy.close();
    return 0;
}
