#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

struct postac
{
    double hp;
    double atk;
    double cR;
    double cDMG;
};

int r(int p, int k)
{
    int n;
    n = p + rand() % k;
    return n;
}

double atak(double atk, double chance, double multi)
{
    int szansa = r(1,100);
    if(chance>=szansa)
    {
        return atk*(multi/100);
    }
    else
    {
        return atk;
    }
}

int walka(struct postac P, struct postac W)
{
    cout<<"     Walka!      \n";
    int Atak;
    do
    {
        Atak = atak(P.atk, P.cR, P.cDMG);
        cout<<"\n HP twoje: "<<P.hp<<", HP Wroga: "<<W.hp<<endl;
        if(Atak>P.atk)
        {
            cout<<"Uderzasz KRYTYCZNIE za "<<Atak<<", ";
        }
        else
        {
            cout<<"Uderzasz za "<<Atak<<", ";
        }
        W.hp-=Atak;
        if(W.hp<=0)
        {
            return 1;
            break;
        }
        Atak = atak(W.atk, W.cR, W.cDMG);
        if(Atak>W.atk)
        {
            cout<<"Wrog uderza KRYTYCZNIE za "<<Atak<<endl;
        }
        else
        {
            cout<<"Wrog uderza za "<<Atak<<endl;
        }
        P.hp-=Atak;
        if(P.hp<=0)
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
    P->hp = r(300, 200);
    P->atk = r(25, 15);
    P->cR = r(1, 40);
    P->cDMG = r(101, 49);
}

void lvlUP(struct postac* P, struct postac W, int l)
{
    cout<<"\nLVL UP";
    cout<<"\n Co chcesz ulepszyc?\n 1.HP ++\n 2.ATK ++\n 3.critRATE ++\n 4.critDMG ++\n 5.Sugestia AI\n";
    int w;
    do
    {
        cin>>w;
    }
    while(w<1 || w>5);
    if(w==1)
    {
        P->hp += l*0.5;
        cout<<"\n HP ("<<(P->hp)-(l*0.5)<<" -> "<<P->hp<<")\n";
    }
    else if(w==2)
    {
        P->atk += l*0.5;
        cout<<"\n ATK ("<<(P->atk)-(l*0.5)<<" -> "<<P->atk<<")\n";
    }
    else if(w==3)
    {
        P->cR += l*0.3;
        cout<<"\n critRate ("<<(P->cR)-(l*0.3)<<")% -> ("<<P->cR<<")%\n";
    }
    else if(w==4)
    {
        P->cDMG += l*0.6;
        cout<<"\n critDMG +("<<(((P->cDMG)/100)-1)*100-l*0.6<<")%ATK -> +("<<(((P->cDMG)/100)-1)*100<<")%ATK\n";
    }
    else{

    }
}

void pokaz(struct postac* A)
{
    cout<<"\n  HP("<<A->hp<<")\n";
    cout<<"  ATK("<<A->atk<<")\n";
    cout<<"  CritRate("<<A->cR<<")%\n";
    cout<<"  CritDMG+("<<(((A->cDMG)/100)-1)*100<<")%ATK\n";
}

int main()
{
    srand(time(NULL));

    cout<<"\n Kliknij enter aby kontynuowac";
    getchar();

    int lvl = 1;
    int rekord = 0;
    char wybor;

    postac Gracz =
    {
        r(300, 200),
        r(25, 15),
        r(1, 40),
        r(101, 49),
    };
    do
    {
        do
        {
            postac Wrog =
            {
                r(300, 200)+(0.5*(lvl-1)),
                r(25, 15)+(0.5*(lvl-1)),
                r(1, 40)+(0.3*(lvl-1)),
                r(101, 49)+(0.6*(lvl-1)),
            };

            cout<<"\n     LVL: "<<lvl;
            cout<<"\n Twoja Postac: ";
            pokaz(&Gracz);
            cout<<"\n Wrog: ";
            pokaz(&Wrog);
            cout<<endl;

            if(walka(Gracz,Wrog)==1)
            {
                cout<<"\n     Wygrales\n     Next Level\n";
                if(lvl%2==0)
                {
                    lvlUP(&Gracz,Wrog,2);
                    if(lvl%5==0)
                    {
                        lvlUP(&Gracz,Wrog,5);
                    }
                }
                else if(lvl%5==0)
                {
                    lvlUP(&Gracz,Wrog,5);
                }
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
        resetP(&Gracz);
    }
    while(wybor=='y');
    cout<<"\n Najwyzszy poziom to: "<<rekord;
    return 0;
}
