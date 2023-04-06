#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <Windows.h>
using namespace std;
void giocate(int gio[], int cru[], int &punt, int &credit, string name, string &contr) // note sopra
{
    int so = gio[0] + gio[1], sc = cru[0] + cru[1], controllo = 0, a = 0, app2 = 2, mae = 0, yu = 2;
    string pesca = "y";
    cout << name << " le tue carte sono " << gio[0] << " " << gio[1] << endl
         << "somma delle tue carte " << gio[0] + gio[1] << endl
         << "carta croupier " << cru[0] << endl;
    srand(time(0));
    do
    {
        cout << endl
             << "vuoi pescare? scrivi [y]es o [n]ot ";
        cin >> pesca;
        if (pesca == "y")
        {
            for (int i = app2; i < app2 + 1; i++)
            {
                a = rand() % 10 + 2;
                if ((so > 21) && (a == 11))
                {
                    gio[i] = 1;
                    so += gio[i];
                }
                else
                {
                    gio[i] = a;
                    so += gio[i];
                }
            }
            cout << "carte: ";
            for (int i = 0; i < app2 + 1; i++)
            {
                cout << gio[i] << " ";
            }
            cout << endl
                 << "somma delle carte=" << so;
            if (so > 21)
            {
                controllo = 10;
                if (controllo == 10)
                {
                    cout << endl
                         << name << " hai sballato!!";
                    credit -= punt;
                    pesca = "n";
                }
            }
            app2++;
        }
    } while (pesca != "n");
    if (controllo != 10)
    {
        cout << "crupier mano:";
        for (int i = 0; i < 10; i++)
        {
            if (cru[i] != 0)
            {
                cout << cru[i] << " ";
            }
        }
        cout << endl;
        while (sc <= 16)
        {
            mae = rand() % 10 + 2;
            cru[yu] = mae;
            sc += mae;
            cru[yu] = mae;
            cout << "mano crupier:";
            for (int i = 0; i < 10; i++)
            {
                if (cru[i] != 0)
                {
                    cout << cru[i] << " ";
                }
            }
            yu++;
            cout << "il crupier ha " << sc << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sc > 22)
                {
                    if (cru[i] == 11)
                    {
                        cru[i] = 1;
                    }
                }
            }
        }
        if (sc < 22)
        {
            if ((sc > so) || (sc == so))
            {
                cout << name << " hai perso!!";
                credit -= punt;
            }
            else
            {
                cout << name << " hai vinto!!";
                credit += punt;
            }
        }
        else
        {
            cout << name << " hai vinto!! il crupier ha sballato!! ";
            credit += punt;
        }
    }
    cout << endl
         << "vuoi continuare? scrivi [y]es o [n]ot ";
    cin >> contr;
    cout << endl
         << "hai " << credit << " fish" << endl;
}
int main()
{
    const int n = 10;
    int gio[n] = {10, 11, 0, 0, 0, 0, 0, 0, 0, 0}, cru[n] = {10, 10, 0, 0, 0, 0, 0, 0, 0, 0}, punt = 123, credit = 1000000;
    string name = "monfo", contr = " ";
    giocate(gio, cru, punt, credit, name, contr);
}