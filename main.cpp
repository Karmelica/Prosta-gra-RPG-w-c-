#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(color, #);
//1 Blue                10 Light Green
//2 Green               11 Light Aqua
//3 Aqua                12 Light Red
//4 Red                 13 Light Purple
//5 Purple              14 Light Yellow
//6 Yellow              15 Bright White
//7 White
//8 Gray
//9 Light Blue
//0 Black

struct itemy
{
    int nr;
    string nazwa;
    double hp;
    double atk;
    double cR;
    double cDMG;
};

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
        cout<<endl;
        if(Atak>P.atk)
        {
            cout<<" Uderzasz ";
            SetConsoleTextAttribute(color, 6);
            cout<<"KRYTYCZNIE";
            SetConsoleTextAttribute(color, 7);
            cout<<" za ";
            SetConsoleTextAttribute(color, 4);
            cout<<Atak;
            SetConsoleTextAttribute(color, 7);
        }
        else
        {
            cout<<" Uderzasz za ";
            SetConsoleTextAttribute(color, 12);
            cout<<Atak;
            SetConsoleTextAttribute(color, 7);
        }
        W.hp-=Atak;
        cout<<"\n HP wroga: ";
        SetConsoleTextAttribute(color, 2); cout<<W.hp; SetConsoleTextAttribute(color, 7);
        if(W.hp<=0)
        {
            return 1;
            break;
        }
        Atak = atak(W.atk, W.cR, W.cDMG);
        if(Atak>W.atk)
        {
            cout<<"\n Wrog uderza ";
            SetConsoleTextAttribute(color, 6);
            cout<<"KRYTYCZNIE";
            SetConsoleTextAttribute(color, 7);
            cout<<" za ";
            SetConsoleTextAttribute(color, 4);
            cout<<Atak;
            SetConsoleTextAttribute(color, 7);
            cout<<" ";
        }
        else
        {
            cout<<"\n Wrog uderza za ";
            SetConsoleTextAttribute(color, 12);
            cout<<Atak;
            SetConsoleTextAttribute(color, 7);
            cout<<" ";
        }
        P.hp-=Atak;
        cout<<"\n HP twoje: ";
        SetConsoleTextAttribute(color, 2); cout<<P.hp; SetConsoleTextAttribute(color, 7);
        if(P.hp<=0)
        {
            return 0;
            break;
        }
        cout<<endl;
    }
    while(P.hp>0);
}

void resetP(struct postac* P)
{
    P->hp = r(300, 200);
    P->atk = r(25, 15);
    P->cR = r(1, 40);
    P->cDMG = r(101, 49);
}

void lvlUP(struct postac* P, struct postac W, int l, int w)
{
    if(w==0)
    {
        cout<<"\nLVL UP";
        cout<<"\n Co chcesz ulepszyc?\n 1.HP ++\n 2.ATK ++\n 3.critRATE ++\n 4.critDMG ++\n 5.Sugestia AI\n";
    }
    while(w<1 || w>5)
    {
        w = getch();
        w-='0';
        cout<<w;
    }
    if(w==1)
    {
        P->hp += l*5;
        cout<<"\n HP ("<<(P->hp)-(l*5)<<" -> "<<P->hp<<")\n";
    }
    else if(w==2)
    {
        P->atk += l*3;
        cout<<"\n ATK ("<<(P->atk)-(l*3)<<" -> "<<P->atk<<")\n";
    }
    else if(w==3)
    {
        P->cR += l*1;
        cout<<"\n critRate ("<<(P->cR)-(l*1)<<")% -> ("<<P->cR<<")%\n";
    }
    else if(w==4)
    {
        P->cDMG += l*0.6;
        cout<<"\n critDMG +("<<(((P->cDMG)/100)-1)*100-l*0.6<<")%ATK -> +("<<(((P->cDMG)/100)-1)*100<<")%ATK\n";
    }
    else
    {
        if(P->hp<W.hp)
        {
            lvlUP(P,W,l,1);
        }
        else if(P->atk<W.atk)
        {
            lvlUP(P,W,l,2);
        }
        else if(P->cR<W.cR)
        {
            lvlUP(P,W,l,3);
        }
        else
        {
            lvlUP(P,W,l,4);
        }
    }
}

void itemek(vector <itemy> A, struct postac* P, int n = r(1,5))
{
    cout<<"\n Wylosowales item: "<<A[n].nazwa;
    if (A[n].hp>0)
    {
        P->hp+=A[n].hp;
        cout<<"\n HP ("<<(P->hp)-(A[n].hp)<<" -> "<<P->hp<<")\n";
    }
    if (A[n].atk>0)
    {
        P->atk+=A[n].atk;
        cout<<"\n ATK ("<<(P->atk)-(A[n].atk)<<" -> "<<P->atk<<")\n";
    }
    if (A[n].cR>0)
    {
        P->cR+=A[n].cR;
        cout<<"\n critRate ("<<(P->cR)-(A[n].cR)<<")% -> ("<<P->cR<<")%\n";
    }
    if (A[n].cDMG>0)
    {
        P->cDMG+=A[n].cDMG;
        cout<<"\n critDMG +("<<(((P->cDMG)/100)-1)*100-(A[n].cDMG)<<")%ATK -> +("<<(((P->cDMG)/100)-1)*100<<")%ATK\n";
    }
}

void pokaz(struct postac* A)
{
    cout<<"\n  HP("<<A->hp<<")\n";
    cout<<"  ATK("<<A->atk<<")\n";
    cout<<"  CritRate("<<A->cR<<")%\n";
    cout<<"  CritDMG +("<<(((A->cDMG)/100)-1)*100<<")%ATK\n";
}

void pokazI(vector <itemy> A, int n)
{
    cout<<" "<<A[n].nazwa<<" ";
    if (A[n].hp>0)
    {
        cout<<" HP+"<<A[n].hp<<" ";
    }
    if (A[n].atk>0)
    {
        cout<<" ATK+"<<A[n].atk<<" ";
    }
    if (A[n].cR>0)
    {
        cout<<" critRate+"<<A[n].cR<<" ";
    }
    if (A[n].cDMG>0)
    {
        cout<<" critDMG+"<<A[n].cDMG<<" ";
    }
    cout<<endl;
}

int main()
{
    srand(time(NULL));

    double a = 1;
    int lvl = 1;
    int aut = 0;
    int rekord = 0;
    char wybor;

    postac Gracz =
    {
        r(300, 200),
        r(25, 15),
        r(1, 40),
        r(101, 49),
    };

    vector <itemy> nrI =
    {
        {0},
        {1, "helm", 0, 0, 0, 8},
        {2, "galoty", 25, 15, 2, 4},
        {3, "buty", 0, 0, 4, 0},
        {4, "sztylet", 0, 30, 0, 0},
        {5, "jablko", 50, 0, 0, 0},
    };

    do
    {
        cout<<" Wybierz poziom trudnosci:\n 1.Super Latwy\n 2.Latwy\n 3.Normalny\n 4.Niemozliwy ";
        int t;
        do
        {
            t = getch();
            t-='0';
            cout<<t;
        }
        while(t>4 || t<1);
        switch(t)
        {
        case 1:
            a=0.5;
            break;
        case 2:
            a=0.75;

            break;
        case 3:
            a=1;

            break;
        case 4:
            a=1.5;
            break;
        }
        cout<<" Tryb auto? y/n ";
        char wy;
        do
        {
            wy = getch();
            cout<<wy;
        }
        while(wy!='y' && wy!='n');
        if (wy=='y')
        {
            aut = 5;
        }
        do
        {
            postac Wrog =
            {
                r(300*a, 200*a)+(2*(lvl-1)),
                r(25*a, 15*a)+(1*(lvl-1)),
                r(1, 40)+(0.5*(lvl-1)),
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
                cout<<"\n     Wygrales\n\n     Next Level\n";
                if(lvl%2==0)
                {
                    lvlUP(&Gracz,Wrog,2,aut);
                }
                if(lvl%5==0)
                {
                    lvlUP(&Gracz,Wrog,5,aut);
                }
                if(lvl%10==0){
                    itemek(nrI, &Gracz);
                }

//                cout<<"\n Kliknij cokolwiek aby kontynuowac\n";
//                getch();
                lvl++;
            }
            else
            {
                cout<<"\n     Przegrales na poziomie "<<lvl<<"\n     Gramy dalej? t/n\n";
                do
                {
                    wybor = getch();
                    if(wybor!='t' && wybor!='n')
                    {
                        cout<<" WYBIERZ t LUB n! ";
                    }
                    cout<<wybor;
                }
                while(wybor!='t' && wybor!='n');
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
    while(wybor=='t');
    if (lvl==200)
    {
        cout<<" !!LVL 200 WYGRALES AUUUU!! ";
    }
    else
    {
        cout<<"\n Najwyzszy poziom to: "<<rekord;
    }
    return 0;
}

/*cout<<"\nKliknij cokolwiek aby kontynuowac\n";
getch();*/
