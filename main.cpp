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
//    ofstream wy;
//    wy.open("character.txt");
    srand(time(NULL));
    vector <float> POSTAC;
    vector <float> WROG;
    cout<<"Kliknij enter aby kontynuowac";
    getchar();
    cout<<"\n Postac | HP | ATK | CritRate | CritDMG |\n";
    cout<<" Twoja postac: ";
    for (int i=0; i<postac().size(); i++)
    {
        POSTAC.push_back(postac()[i]);
        cout<<POSTAC[i]<<" ";
    }
    cout<<"\n Wrog: ";
    for (int i=0; i<wrog().size(); i++)
    {
        WROG.push_back(wrog()[i]);
        cout<<WROG[i]<<" ";
    }
    cout<<endl<<"\nKliknij enter aby kontynuowac";
    getchar();

    cout<<"     Walka!\n";
    do{
        cout<<"HP twoje: "<<POSTAC[0]<<" HP wroga: "<<WROG[0]<<endl;
        WROG[0]-=POSTAC[1];
        if(WROG[0]<0){
            cout<<"\n Wygrales ";
            break;
        }
        POSTAC[0]-=WROG[1];
        if(POSTAC[0]<0){
            cout<<"\n Przegrales ";
            break;
        }
    }while(POSTAC[0]>0);
    cout<<endl<<"\nKliknij enter aby kontynuowac";
    getchar();
//    wy.close();
    return 0;
}
