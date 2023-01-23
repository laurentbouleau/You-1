#include "pch.h"

#include "Utils.h"
//#include "erreur_ok.h
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "cinema.h"
#include "serie.h"

#include <windows.h>
#include <cassert>
#include <iostream>
//#include <xstring>
#include <iomanip>
#include <string>
#include <vector>
//#include <sstream>
//#include <conio.h>
//#include <ctype.h>

extern int X;

Erreur E;
//extern const struct Person;// P;
extern const void Console_Lire_txt(std::wstring lire);
extern const int Console_Lire_txt(std::wstring, int, int);

Erreur::Erreur()
{
}

Erreur::~Erreur()
{
}

void Erreur::afficher_X(int i, std::wstring x, std::wstring t) //const{}
{
#if Erreur_afficher_X_ == 1
    //wcerr << E_T << L"void Erreur::afficher_X(" << i << L", " << x << L", " << t << L") :" << E_t << endl;
    int j = Console_Lire_txt(E_T + L"void Erreur::afficher_X(" + E_t + std::to_wstring(i) + E_T + L", " + E_t + x + E_T + L", " + E_t + t + E_T + L") :" + E_t, x1, x2);
#endif
    X_i.push_back(i);
    X_X.push_back(x);
    X_T.push_back(t);
    X_W.push_back(L"");
    //
    X_I++;
#if Erreur_afficher_X_ == 1
    //wcerr << E_T << L"void Erreur::afficher_X() : Ok !" << E_t << endl;
    j = Console_Lire_txt(E_W + x + E_w + E_T + L" : " + E_t + E_W + t + E_w, x3, x4);
    j = Console_Lire_txt(E_T + L"void Erreur::afficher_X() : Ok !" + E_t, x1, x2);
#endif
    return;
}

void Erreur::afficher_X(int i, std::wstring x, std::wstring t, std::wstring w) //const{}
{
#if Erreur_afficher_X_ == 1
    //wcerr << E_T << L"void Erreur::afficher_X(" << i << L", " << x << L", " << t << L", " << w << L") :" << E_t << endl;
    int j = Console_Lire_txt(E_T + L"void Erreur::afficher_X(" + std::to_wstring(i) + L", " + x + L", " + t + L"\n" + w + L") :" + E_t, x1, x2);
    j = Console_Lire_txt(E_T + L"void Erreur::afficher_X(" + E_t + std::to_wstring(i) + E_T + L", " + E_t + x + E_T + L", " + E_t + t + E_T + L", " + E_t + w + E_T + L") :" + E_t, x1, x2);
#endif
    X_i.push_back(i);
    X_X.push_back(x);
    X_T.push_back(t);
    X_W.push_back(w);
    //
    X_I++;
    //if (Ok_ == false)
    //   Ok_ = true;
#if Erreur_afficher_X_ == 1
    //wcerr << E_T << L"void Erreur::afficher_X() : Ok !" << E_t << endl;
    j = Console_Lire_txt(E_W + x + E_w + E_T + L" : " + E_t + E_W + t + E_w, x3, x4);
    j = Console_Lire_txt(E_W + w + E_w, x3, x4);
    j = Console_Lire_txt(E_T + L"void Erreur::afficher_X() : Ok !" + E_t, x1, x2);
#endif
    return;
}

int Erreur::Ok()
{
    int j;
#if Erreur_Ok_ == 1
    if (X_I != -1)
        j = Console_Lire_txt(E_T + L"int Erreur::Ok() :" + E_t, x1, x2);
#endif
    std::wstring wstr;
    std::vector<int>::iterator iter_X_i;
    std::vector<std::wstring>::iterator iter_X, iter_T, iter_W;
    int x;
    int i = 0;
    for (iter_X_i = X_i.begin(), iter_X = X_X.begin(), iter_T = X_T.begin(), iter_W = X_W.begin(); i++, iter_X_i != X_i.end(); iter_X_i++, iter_X++, iter_T++, iter_W++)
    {
        //wstr = L"";
        if (*iter_X_i <= OK)
        {
            if (*iter_X_i >= 0)
                //wcerr.width(8);
                x = x1 + 1;
            else
                //wcerr.width(7);
                x = x1;
            wstr = E_T + to_wstring(*iter_X_i) + L" : " + E_t + *iter_X + E_T + L" : " + E_t + *iter_T;
            j = Console_Lire_txt(wstr, x, x2);
            if (*iter_W != L"")
            {

                j = Console_Lire_txt(*iter_W, x3, x4);

            }
        }
        XX_i.push_back(*iter_X_i);
        XX_X.push_back(*iter_X);
        XX_T.push_back(*iter_T);
        XX_W.push_back(*iter_W);
    }
#if Erreur_Ok_ == 1
    if (X_I != -1)
        //wcerr << E_T << L"Erreur::Ok() : Fin !" << E_t << endl;
        j = Console_Lire_txt(E_T + L"int Erreur::Ok() : Ok !" + E_t, x1, x2);
#endif
    if (X_I != -1)
        Console_Lire_txt(L"---------- ");
    X_i.clear();
    X_X.clear();
    X_T.clear();
    X_W.clear();
    X_I = -1;
    return OK;
}


/*const */int Erreur::Erreur_Ok(bool e = false)
{
    if (e == true)
    {
        I = 0;
        return 0;
    }
    int i = 0;
    while (i < I)
    {
        std::wcerr
            << E_T << XX_i[i] << L" : " << E_t
            << XX_X[i]
            << E_T << L" : " << E_t
            << XX_T[i]
            << std::endl;
        if (XX_W[i] != L"")
            std::wcerr << XX_W[i] << std::endl;
        i++;
    }
    return I;
}

