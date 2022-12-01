#include <bits/stdc++.h>

using namespace std;

struct postac
{
    float hp;
    float atk;
    float cR;
    float cDMG;
};

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

int walka(struct postac P, struct postac W)
{
    cout<<"\n     Walka!      \n";
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
    while(P.hp>0);

    cout<<endl<<"\n Kliknij enter aby kontynuowac";
    getchar();
}

void resetP(struct postac* P)
{
    P->hp = r(300, 200)+(0.5);
    P->atk = r(25, 15)+(0.5);
    P->cR = r(1, 40)+(0.3);
    P->cDMG = (r(101, 49)+(0.6))/100;
}

void lvlUP(struct postac* P, int l)
{
    cout<<"\nCo chcesz ulepszyc?\n1.HP ++\n2.ATK ++\n3.critRATE ++\n4.critDMG ++\n";
    int w;
    do
    {
        cin>>w;
    }
    while(w<1 || w>4);
    if(w==1)
    {
        P->hp += l*0.5;
        cout<<"\nHP "<<(P->hp)-(l*0.5)<<" -> "<<P->hp<<endl;
    }
    else if(w==2)
    {
        P->atk += l*0.5;
        cout<<"\nATK "<<(P->atk)-(l*0.5)<<" -> "<<P->atk<<endl;
    }
    else if(w==3)
    {
        P->cR += l*0.3;
        cout<<"\ncritRate "<<(P->cR)-(l*0.5)<<" -> "<<P->cR<<endl;
    }
    else
    {
        P->cDMG += l*0.006;
        cout<<"\ncritDMG "<<(P->cDMG)-(l*0.5)<<" -> "<<P->cDMG<<endl;
    }

    cout<<"\n Kliknij enter aby kontynuowac";
    getchar();
}

void pokaz(struct postac* A)
{
    cout<<A->hp<<" ";
    cout<<A->atk<<" ";
    cout<<A->cR<<" ";
    cout<<A->cDMG<<" ";
}

int main()
{
//    ofstream wy;
//    wy.open("character.txt");
    srand(time(NULL));

    cout<<"\n Kliknij enter aby kontynuowac";
    getchar();
    int lvl = 1;
    int rekord = 0;
    char wybor;

    postac Gracz =
    {
        r(300, 200)+(0.5),
        r(25, 15)+(0.5),
        r(1, 40)+(0.3),
        (r(101, 49)+(0.6))/100,
    };
    do
    {
        resetP(&Gracz);
        do
        {
            if(lvl%2==0)
            {
                if(lvl%5==0)
                {
                    lvlUP(&Gracz,5);
                }
                lvlUP(&Gracz,2);
            }
            postac Wrog =
            {
                r(300, 200)+(0.5*(lvl-1)),
                r(25, 15)+(0.5*(lvl-1)),
                r(1, 40)+(0.3*(lvl-1)),
                (r(101, 49)+(0.6*(lvl-1)))/100,
            };

            cout<<"\n     LVL: "<<lvl;
            cout<<"\n Postac | HP | ATK | CritRate | CritDMG |";
            cout<<"\n Twoja Postac: ";
            pokaz(&Gracz);
            cout<<"\n Wrog: ";
            pokaz(&Wrog);
            cout<<endl;


            if(walka(Gracz, Wrog)==1)
            {
                cout<<"\n     Wygrales\n     LVL UP\n";
                lvl++;
            }
            else
            {
                cout<<"\n     Przegrales\n     Gramy dalej? y/n\n";
                do
                {
                    cin>>wybor;
                }
                while(wybor!='y' && wybor!='n');
                if(rekord<lvl)
                {
                    rekord=lvl;
                }
                lvl=1;
                break;
            }
        }
        while(lvl<200);
    }
    while(wybor=='y');
    cout<<"\nNajwyzszy poziom to: "<<rekord;
//    wy.close();
    return 0;
}
