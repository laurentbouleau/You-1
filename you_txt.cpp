
#include "pch.h"

#include "Utils.h"
#include "titre.h"
#include "You.h"
#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "erreur_ok.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale>

extern int X;

extern /*const */class Erreur E;
extern /*const*/ class Bug B;


extern const bool afficher_Path_Exists(std::wstring&);
extern const std::wstring lire_fichierTxt(std::wstring const& t);
extern std::wstring you_substr(std::wstring);
extern std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);
extern const int Console_Lire_txt(std::wstring, int, int);

// // // // // // // // // //
struct P_CS
{
    std::wstring cs = L"";
    std::wstring note[6] = { L"", L"", L"", L"", L"", L"" };
    int cs_{ 0 };
};
extern struct P_CS P_cinema, P_serie, P_cinema_VOD, P_cinema_DVD, &P_cs;
// // // // // // // // // //

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt                                                                                                                                            #
// # const int You_txt(int v)                                                                                                                           #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt(int& v)
{
    switch (v)
    {
    case 0:
        You_txt_OK();
        break;
    default:
        break;
    }
    return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt_cs                                                                                                                                         #
// # const int You_txt_cs(wstring& t, wstring& p1)                                                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt_cs(std::wstring& t, std::wstring& p1)
{
    int v;
    std::wstring p2, p3, p4;
    p4 = p1;
    size_t pos = 0;
    if (p1 == L"<Cinéma>")
    {
        p2 = L"</Cinéma>";
        p3 = L"Cinéma=";
    }
    else if (p1 == L"<Série>")
    {
        p2 = L"</Série>";
        p3 = L"Série=";
    }
    else if (p1 == L"<Cinéma VOD>")
    {
        p2 = L"</Cinéma VOD>";
        p3 = L"Cinéma-VOD=";
    }
    else if(p1 == L"<Cinéma DVD>")
    {
        p2 = L"</Cinéma DVD>";
        p3 = L"Cinéma-DVD=";
    }
    else
    {
#if You_txt_cs_ == 1
        Console_Lire_txt(L"Impossible de pas (" + p1 + L") !", 4, 4);
#endif
        //wcerr << L"Impossible pas de note (" << cs << L") !" << endl;
        E.afficher_X(-3, L"Impossible de pas (" + p1 + L") !", L"Érreur (" + p1 + L") !!!");
        return -3;
    }
    pos = t.find(L'\n');
    t = t.substr(pos + 1);    
    while (t != L"")
    {
        pos = t.find(L'\n');
        p1 = t.substr(0, pos);
        p1 = you_substr(p1);
        if (p1 == p2)
            // </Cinéma> ou </Serie> ou </Cinéma VOD> ou </Cinéma DVD>
        {
#if You_txt_cs_ == 1
            //wcout << L'{' << p2 << L'}' << endl;
            Console_Lire_txt(L'{' + p2 + L'}', 4, 4);
#endif
            //t = t.substr(pos + 1);
            p2 = L"";
            return 0;
        }
        else if (p1.substr(0, 7) == L"Cinéma=" || p1.substr(0, 6) == L"Série=" || p1.substr(0, 11) == L"Cinéma-VOD=" || p1.substr(0, 11) == L"Cinéma-DVD=")
            // Cinéma= ou Série= ou Cinéma-VOD ou Cinéma-DVD
        {
            size_t pos2 = 0;
            pos2 = p1.find(L"=");
            P_cs.cs = p1.substr(pos2 + 1);
#if You_txt_cs_ == 1
            //wcout << L'{' << p1.substr(0, pos2 + 1) << L'[' << P_cs.cs << L"]}" << endl;
            Console_Lire_txt(L'{' + p1.substr(0, pos2 + 1) + L'[' + P_cs.cs + L"]}", 4, 4);
#endif
            p3 = L"";
            t = t.substr(pos + 1);
            //wcout << L">> continue;" << endl;
            continue;
        }
        else if (p1.substr(0, 5) == L"Note[" && p1.substr(6, 2) == L"]=")// p1[6] == L']' && p1[7] == L'=')
            // Note[0-5]=
        {
            v = stoi(p1.substr(5, 1));
            if(v >= 0 && v <= 5)
            { 
                P_cs.note[v] = p1.substr(8);
#if You_txt_cs_ == 1
                //wcout << L"{Note[" << v << L"]=[" << P_cs.note[v] << L"]}" << endl;
                Console_Lire_txt(L"{Note[" + to_wstring(v) + L"]=[" + P_cs.note[v] + L"]}", 4, 4);
#endif
                t = t.substr(pos + 1);
                continue;
            }
            else
            {
#if You_txt_cs_ == 1
                B.Ok_W(L"Impossible pas de note (0-5) !");
                B.Ok_T(L"const int You_txt_cs() : Attention !!!");
#endif
                E.afficher_X(-5, L"Impossible pas de note (0-5) !", L"Érreur (" + p1 + L") !!!");
                return -5;
            }
        }
        else
        {
            if (p1[0] == L' ' || p1[0] == '\t')
            {
                E.afficher_X(-3, L"Impossible " + p4 + L" ou \"Note[0-5]=\", pas de ' ' ou '\t' !", L"Érreur (" + p1 + L") !!!");
                return -3;
            }
            //wcerr << L"Impossible (</Cinéma>) (2) !" << endl;
            //E.afficher_X(-3, L"Impossible (</Cinéma>) (2) !", L"Érreur (" + p1 + L") !!!");
            //return -3;
        }
        t = t.substr(pos + 1);
    }
    return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt_is_directory                                                                                                                               #
// # const int You_txt_is_directory(wstring& t)                                                                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt_is_directory(std::wstring& t)
{
    if(afficher_Path_Exists(P_cs.cs) == false)
    {
        E.afficher_X(-8, t + L" pas de " + P_cs.cs + L" !", L"Erreur !!!");
        return -8;
    }

    if (is_directory(P_cs.cs))
    {
        int i;
        for (i = 0; i < 6; i++)
        {
#if You_txt_is_directory_ == 1
            Console_Lire_txt(L"{Note[" + std::to_wstring(i) + L"]=[" + P_cs.note[i] + L"] !}", 4, 4);
#endif
            if (P_cs.note[i] == L"")
                continue;
            else
            {
                //path canonical(const std::filesystem::path & p);
                
                /*std::filesystem::path fpath{"fname"};
                if (std::error_code ec{}; !std::filesystem::exists(fpath, ec)) {
                    std::cerr << "File system returned the following for \"" << fpath.string() << "\":\nError: " << ec.value() << "\nMessage: " << ec.message();
                }*/
                path p{ P_cs.note[i] };
                //if (error_code ec{}; !/*filesystem::*/exists(p, ec))
                if (error_code ec{}; experimental::filesystem::v1::exists(p, ec))
                {
                    wcout << L"iiiii" << endl;
                    //wcerr << L"File system returned the following for \"" << p.wstring() << L"\":\nError: " << ec.value() << L"\nMessage: " << ec.message() << endl;
                    E.afficher_X(-6, L"Le système de fichiers a renvoyé ce qui suit pour [" + p.wstring() + L']' + L" {" + P_cs.cs + L'}', L"Erreur !!!");
                    exit(6);
                }

                if (is_directory(P_cs.note[i]))
                {
                    continue;
                }
                if (is_directory(P_cs.cs + P_cs.note[i]))
                {
                    P_cs.note[i] = P_cs.cs + P_cs.note[i];
                    continue;
                }
                if (is_directory(P_cs.cs + L'\\' + P_cs.note[i]))
                {
                    P_cs.note[i] = P_cs.cs + L'\\' + P_cs.note[i];
                    continue;
                }
                /*if (is_directory(P_cs.cs + L'\\' + P_cs.note[i]))
                {
                    P_cs.note[i] = P_cs.cs + L'\\' + P_cs.note[i];
                    continue;
                }*/
                else
                {
                    E.afficher_X(-6, t + L" pas de Note[" + to_wstring(i) + L"]=[" + P_cs.note[i] + L']', L"Erreur !!!");
                    return -6;
                }
            }

        }
    }
    else
    {
        //wcerr.width(4);
        //wcerr << t << L" pas de " << P_cs.cs << L" ! Érreur !!!" << endl;
#if You_txt_is_directory_ == 1
        Console_Lire_txt(t + L" pas de " + P_cs.cs + L" ! Érreur !!!", 4, 4);
#endif
        E.afficher_X(-6, t + L" pas de " + P_cs.cs + L" !", L"Érreur !!!");
        return -6;
    }
    return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # You_txt_OK                                                                                                                                         #
// # const int You_txt_OK()                                                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int You_txt_OK()
{
    const wchar_t* p{ L"../" };
    path filePath(p);

    filePath /= L"you.txt";
    wstring t;
    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.
        t = lire_fichierTxt(L"you.txt");
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (runtime_error const& exception)
    {
        // On affiche la cause de l'exception.
        wcout << L"Erreur : " << exception.what() << endl;
    }
    //#if You_txt_OK_ == 1
//    wcout << L"t={" << endl;
//    wcout << t << endl;
 //   wcout << L'}' << endl;
//#endif
    t += L'\n';
    size_t pos = 0;
    int i{ 0 }, j{ 0 };
    std::wstring t1 = L"", temps = L"";
    while (t != L"")
    {
        pos = t.find(L'\n');
        t1 = t.substr(0, pos);
        t1 = you_substr(t1);
        if (t1 == L"")
        {
            i = 0;
            t = t.substr(pos + 1);
            continue;
        }

        if (t1 == L"<Cinéma>" || t1 == L"<Série>" || t1 == L"<Cinéma DVD>" || t1 == L"<Cinéma VOD>")
        {
            if (t1 == L"<Cinéma>")
                P_cs = P_cinema;
            else if (t1 == L"<Série>")
                P_cs = P_serie;
            else if (t1 == L"<Cinéma VOD>")
                P_cs = P_cinema_VOD;
            else if(t1 == L"<Cinéma DVD>")
                P_cs = P_cinema_DVD;
            else
            {
                E.afficher_X(-6, L"!!!", t1 + L" érreur [" + t1 + L"] !!!");
                return -6;
            }
            //
            P_cs.cs_++;
            //
            if (P_cs.cs_ > 1)
            {
                E.afficher_X(-5, L"Trouvez de " + t1 + L" !", t1 + L" érreur [" + P_cs.cs + + L"] !!!");
                return -5;
            }
            i = -1;
            temps = t1;
            j = You_txt_cs(t, temps);//, 1);
            if (j != 0)
            {
                E.afficher_X(-7, L"Impossible pas de hhhhhhhhh !!!", t1 + L" érreur (" + t1 + L") !!!");
                return j;
            }
            //i = You_txt_is_directory(temps);
            i = You_txt_is_directory(t1);
            if (i != 0)
            {
                E.afficher_X(-7, L"Impossible pas de " + t1 + L" !!!", t1 + L" érreur (" + t1 + L") !!!");
                return -7;
            }
            if (j == 0 && t1 == L"<Cinéma>")
                P_cinema = P_cs;
            else if (j == 0 && t1 == L"<Série>")
                P_serie = P_cs;
            else if (j == 0 && t1 == L"<Cinéma VOD>")
                 P_cinema_VOD = P_cs;
            else if (j == 0 && t1 == L"<Cinéma DVD>")
                P_cinema_DVD = P_cs;
            else
            {
                //
                E.afficher_X(-7, L"Impossible pas de qqqqqq !!!", t1 + L" érreur (" + t1 + L") !!!");
                return -7;
            }
            P_cs.cs_ = 0;
            i = 0;
        }
        else
        {
            /*i = -5;
            wcerr << L"Impossible pas de phrase !" << endl;
            E.afficher_X(-5, L"Impossible pas de phrase !", L"Érreur (" + t1 + L") !!!");
            return i;*/
        }
        //
        t = t.substr(pos + 1);
    }
#if You_txt_OK_ == 1
    if (P_cinema.cs != L"")
    {
        std::wcout << L"    " << L"Cinéma = [" << P_cinema.cs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_cinema.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_cinema.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_cinema.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_cinema.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_cinema.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_cinema.note[5] << L"]."
            << std::endl;
    }
    if (P_serie.cs != L"")
    {
        std::wcout << L"    " << L"Série=[" << P_serie.cs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_serie.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_serie.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_serie.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_serie.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_serie.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_serie.note[5] << L"]."
            << std::endl;
    }
    if (P_cinema_VOD.cs != L"")
    {
        std::wcout << L"    " << L"Cinéma VOD=[" << P_cinema_VOD.cs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_cinema_VOD.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_cinema_VOD.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_cinema_VOD.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_cinema_VOD.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_cinema_VOD.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_cinema_VOD.note[5] << L"]."
            << std::endl;
    }
    if (P_cinema_DVD.cs != L"")
    {
        std::wcout << L"    " << L"Cinéma DVD=[" << P_cinema_DVD.cs << L"]" << std::endl;
        std::wcout << L"\t";
        std::wcout << L"note[" << 0 << L"]=[" << P_cinema_DVD.note[0] << L"], "
            << L"note[" << 1 << L"]=[" << P_cinema_DVD.note[1] << L"], "
            << L"note[" << 2 << L"]=[" << P_cinema_DVD.note[2] << L"], "
            << L"note[" << 3 << L"]=[" << P_cinema_DVD.note[3] << L"], "
            << L"note[" << 4 << L"]=[" << P_cinema_DVD.note[4] << L"], "
            << L"note[" << 5 << L"]=[" << P_cinema_DVD.note[5] << L"]."
            << std::endl;
    }
#endif
    return 0;
}
