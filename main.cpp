#include <bits/stdc++.h>

using namespace std;

int r(int p, int k)
{
    int n;
    n = p + rand() % k;
    return n;
}

bool los(int chance){
    int szansa = r(1,chance);
    if(){};

}

vector <float> staty()
{
    int hp, atk, cR;
    float cDMG;
    vector <float> STATY;
    hp = r(300, 200);
    atk = r(25, 15);
    cR = r(1, 40);
    cDMG = r(101, 49);
    STATY.push_back(hp);
    STATY.push_back(atk);
    STATY.push_back(cR);
    STATY.push_back(cDMG/100);
    return STATY;
}

//vector <float> wrog()
//{
//    vector <float> WROG;
//    Whp = r(200, 800);
//    Watk = r(50, 100);
//    WcR = r(1, 40);
//    WcDMG = r(101, 49);
//    WROG.push_back(Whp);
//    WROG.push_back(Watk);
//    WROG.push_back(WcR);
//    WROG.push_back(WcDMG/100);
//    return WROG;
//}

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
    for (int i=0; i<staty().size(); i++)
    {
        POSTAC.push_back(staty()[i]);
        cout<<POSTAC[i]<<" ";
    }
    cout<<"\n Wrog: ";
    for (int i=0; i<staty().size(); i++)
    {
        WROG.push_back(staty()[i]);
        cout<<WROG[i]<<" ";
    }



    cout<<endl<<"\nKliknij enter aby kontynuowac";
    getchar();



    cout<<"     Walka!      \n";
    do{
        cout<<"HP twoje: "<<POSTAC[0]<<" HP wroga: "<<WROG[0]<<endl;
        WROG[0]-=POSTAC[1]*POSTAC[3];
        cout<<"Uderzasz za "<<POSTAC[1]*POSTAC[3]<<" ";
        if(WROG[0]<0){
            cout<<"\n Wygrales ";
            break;
        }
        POSTAC[0]-=WROG[1]*WROG[3];
        cout<<"Wrog uderza za "<<WROG[1]*WROG[3]<<endl;
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
