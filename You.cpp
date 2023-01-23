// You.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

// La signalétique jeunesse : SJ : https://www.csa.fr/Informer/Toutes-les-actualites/Actualites/Tuto-CSA-Tout-savoir-sur-la-signaletique-jeunesse
#include "pch.h"

#include "Utils.h"
#include "titre.h"
#include "You.h"
#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "erreur_ok.h"
#include "console.h"

#include <windows.h>
#include <cassert>
#include <iostream>
#include <numeric>
//#include <fstream>
#include <string>
#include <vector>
//#include <stdio.h>
//#include <locale>
#include <algorithm>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;

extern const vector<wstring> AZERTYUIOP;

//extern const Cinema C;
//extern const Serie S;
extern class Erreur E;
//extern class Bug B;

extern const bool afficher_Path_Exists(std::wstring& t);
extern const int Compare_Path(int rc, path p1, path p2);
extern const int Console_Lire_txt(std::wstring, int, int);
//extern void PrintStringW(HANDLE hOut, const std::wstring& str);

extern const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
extern const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur);
extern const std::wstring lire_fichierTxt(std::wstring const& nomFichier);
extern std::wstring LoadDataFromFile(std::wstring const& nomFichier, std::wstring const& tag);
extern void PrintKeyMultipleValues(const std::wstring& keyColor,
    const std::wstring& keyText,
    const std::wstring& valueColor,
    const std::vector<std::wstring>& values,
    const std::wstring& separatorKeyValues = L" : ",
    const std::wstring& separatorValuesValuesColor = L"",
    const std::wstring& separatorValuesValues = L", ");
extern void PrintKeyValue(const std::wstring& keyColor, const std::wstring& keyText, const std::wstring& valueColor, const std::wstring& valueText, const std::wstring& separator = L" : ");
extern void PrintTmp(const std::wstring& text);

struct Person
{
    // _ h __ min
    // X
    bool C_Espace1 = false; // true ou false
    wchar_t C_H = L'h'; // = L'h' : h ou H
    bool C_Espace2 = false; // true ou false
    // XX
    bool C_Espace3 = false; // true ou false
    std::wstring C_MIN = L"min"; // = L"min" : MIN ou Min ou min
    std::wstring C_T = L"\x1b[94;1m";
    std::wstring C_t = L"\x1b[38;2;255;255;255m";
    std::wstring C_W = L"\x1b[38;2;0;255;0m";
    std::wstring C_w = L"\x1b[38;2;255;255;255m";

    // min
    bool S_Espace = false; // true ou false
    std::wstring S_MIN = L"min"; // = L"min";
    std::wstring S_T = L"\x1b[38;2;0;0;255m";
    std::wstring S_t = L"\x1b[38;2;255;255;255m";
    std::wstring S_W = L"\x1b[38;2;0;255;0m";
    std::wstring S_w = L"\x1b[38;2;255;255;255m";

    // Bug
    //wstring B_T = L"\x1b[38;2;200;200;0m";
    //wstring B_t = L"\x1b[38;2;255;255;255m";
    //wstring B_W = L"\x1b[38;2;155;155;155m";
    //wstring B_w = L"\x1b[38;2;255;255;255m";

    // Erreur
    std::wstring E_T = L"\x1b[38;2;255;0;0m";
    std::wstring E_t = L"\x1b[38;2;255;255;255m";

    // Rechercher
    std::wstring R_T = L"\x1b[38;2;255;255;0m";
    std::wstring R_t = L"\x1b[38;2;255;255;255m";

    //
    std::wstring& P_T = C_T;
    std::wstring& P_t = C_t;
} P;

// // // // // //
typedef struct P_CS P_CS;// cinema, serie, cinema_VOD, cinema_DVD,
/*P_cinema, P_serie, P_cinema_VOD, P_cinema_DVD,*/
//& P_C, & P_S ;

struct P_CS
{
    std::wstring cs = L"";
    std::wstring note[6] = { L"", L"", L"", L"", L"", L"" };
    int cs_{ 0 };
}cinema, serie, cinema_VOD, cinema_DVD,
P_cinema, P_serie, P_cinema_VOD, P_cinema_DVD,
&P_cs = P_cinema, 
&P_C = cinema, &P_S = serie, &P_C_VOD = cinema_VOD, &P_C_DVD = cinema_DVD;
// // // // // //

//
extern const vector<wstring> AZERTYUIOP;
//

//extern const wchar_t* LTH;

//int iRed = GetRValue(couleur);
//int iBlue = GetBValue(couleur);
//int iGreen = GetGValue(couleur);

/*typedef struct _CONSOLE_SCREEN_BUFFER_INFOEX
{
    ULONG      cbSize;
    COORD      dwSize;
    COORD      dwCursorPosition;
    WORD       wAttributes;
    SMALL_RECT srWindow;
    COORD      dwMaximumWindowSize;
    WORD       wPopupAttributes;
    BOOL       bFullscreenSupported;
    COLORREF   ColorTable[16];*/

//extern const int Console_Lire_txt(wstring, wstring, int, int, int, int, int);
//extern const int Console_Lire_txt(wstring, int, int, int);

//extern const class E;
//_P_;

//extern Console console;

//HANDLE hOut;
//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//DWORD dwMode = 0;
//CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//int X;

/* www.developpez.net : kaitlyn

// enabling console virtual terminal support
DWORD current_console_mode = 0;
GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &current_console_mode);
SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE)
    , current_console_mode
    | ENABLE_VIRTUAL_TERMINAL_PROCESSING
    | ENABLE_PROCESSED_OUTPUT
);

// setting colors
// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
// https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
const std::string esc = "\033";
const std::string use_red_color_text = esc + "[31m";
const std::string use_green_color_text = esc + "[32m";
const std::string use_default_color_text = esc + "[0m";

namespace nw = nowide;
nw::cout << use_red_color_text << "ééééé" << use_default_color_text;
*/






// ############################################################
// #                                                          #
// # init                                                     #
// #                                                          #
// ############################################################

/*void init()
{
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    GetConsoleScreenBufferInfo(hOut, &csbiInfo);
    _wsetlocale(LC_ALL, L"fr");
    X = csbiInfo.srWindow.Right + 1;
    //
}*/

// ############################################################
// #                                                          #
// # You_txt_ok                                               #
// #                                                          #
// ############################################################

const int You_txt_ok(void)
{
#if You_txt_ok_ == true
    std::wcout << L"const int You_txt_ok(void)" << std::endl;
#endif
//    ::P_CS cinema;
    cinema.cs = L"..\\Films.()\\";
    cinema.note[0] = L"-";
    cinema.note[1] = L"+";
    cinema.note[2] = L"++";
    cinema.note[3] = L"+++";
    cinema.note[4] = L"++++";
    cinema.note[5] = L"+++++";
//    ::P_CS serie;
    serie.cs = L"..\\Séries.[]\\";
    serie.note[0] = L"-";
    serie.note[1] = L"+";
    serie.note[2] = L"++";
    serie.note[3] = L"+++";
    serie.note[4] = L"++++";
    serie.note[5] = L"+++++";
//    ::P_CS cinema_VOD;
    cinema_VOD.cs = L"";
//    ::P_CS cinema_DVD;
    cinema_DVD.cs = L"";
    // // // // //
    //::P_CS* P_C = &cinema;
    //::P_CS* P_S = &serie;
    return 0;
}


//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//DWORD dwMode = 0;
//(HANDLE hOut, CONSOLE_SCREEN_BUFFER_INFO& csbiInfo)
void usage(std::wstring t = L"")
{
    int const y1 = 4, y2 = 8;
    int i;
    //
    std::wstring Textes;
    Textes = L"";
    //
    Textes += L"You :";
    i = Console_Lire_txt(Textes, 0, 0);
    std::wcout << L"\n";
    //
    Textes = L"azereezrttertretrtert";
    Console_Lire_txt(Textes, 0, 0);
    std::wcout << L"\n";
    //
    Textes = L"/t c {dossier}\n";
    Textes += L"/t s {dossier}";
    Console_Lire_txt(Textes, y1, y1);
    std::wcout << L"\n";

    //::Console_Lire_txt(Textes, textes, y1, y2, Y, in, out);
    //wcout << L"\n";
    Textes = L"aa bbb cccc ddddddd eee fffffff gggg hh ii jjjjjj kkkkkkkkkk ll mmmmmm nnn oooooo, pp.  qqqqqq rrrrr ss ttt uuu vvv wwwwww xxx yy ";
    Console_Lire_txt(Textes, y1, 0);
    std::wcout << L"\n";
    //
    Textes = L"/Gense gense c {dossier}";
    Console_Lire_txt(Textes, y1, 0);
    std::wcout << L"\n";
}

//#define setC 1

/*int setConsoleScreenBufferInfo(COORD dwSize)
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bakDwSize = dwSize;
    SMALL_RECT srctWindow;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
#if setC == 1
    wcout << L"qqqq Ok 1" << endl;
#endif
    // Obtenir les informations de la console
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) 
        return EXIT_FAILURE;
#if setC == 1
    wcout << L"qqqq Ok 2" << endl;
#endif

    // Adapter le buffer de la console en fonction des tailles maximales
    //dwSize.X = (dwSize.X > csbiInfo.srWindow.Right) ? dwSize.X : csbiInfo.dwSize.X;
    dwSize.X = csbiInfo.dwSize.X;

    dwSize.Y = (dwSize.Y > csbiInfo.srWindow.Bottom) ? dwSize.Y : csbiInfo.dwSize.Y;
    if (!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) 
        return EXIT_FAILURE;
#if setC == 1
    wcout << L"qqqq Ok 3" << endl;
#endif

    // Modifier la taille de la console
    dwSize = bakDwSize;
    srctWindow = csbiInfo.srWindow;
    srctWindow.Right = dwSize.X - 1;
    srctWindow.Bottom = dwSize.Y - 1;
    if (!SetConsoleWindowInfo(hConsoleOutput, TRUE, &srctWindow)) 
        return EXIT_FAILURE;

#if setC == 1
    wcout << L"qqqq Ok 4" << endl;
#endif
    // Adapter la taille du buffer de la console à sa taille (pas d'ascenseurs)
    dwSize = bakDwSize;
    if (!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) 
        return EXIT_FAILURE;
#if setC == 1
    wcout << L"qqqq Ok 5" << endl;
#endif

    return EXIT_SUCCESS;
}*/

// ############################################################
// #                                                          #
// # You                                                      #
// #                                                          #
// ############################################################

const wstring You(int c, wchar_t** v)
{
    std::wstring t = L"";
    static const basic_string <wchar_t>::size_type npos = -1;    //bool q;
#if You_ == 1
    std::wcout << L"wstring You(" << c << L", )" << std::endl;
#endif
    /*if (!(v[0][0] == L'Y' && v[0][1] == L'o' && v[0][2] == L'u' && v[0][3] == wstring::npos))
    {
        afficher_X(-1, L"Erreur ssss You()");
        return L"";
    }*/
    int i = 0;
    while (i < c)
    {
        std::wcout << L"wxcvbn i=" << i << L" v=[" << v[i] << L"]" << std::endl;
        t += v[i];
        if (i < c - 1)
            t += L" ";
        i++;
    }
    return t;
}

// ############################################################
// #                                                          #
// # You_you                                                  #
// #                                                          #
// ############################################################

const int You_you(int c, wchar_t** v)
{
    int i;
    std::wstring t;
#if You_you_ == 1
    std::wcout << L"wstring You_you(" << c << L", )" << std::endl;
#endif
    if (v[1] == L"")
    {
        //E.afficher_X(-1, v[1], L"Erreur ssss You_you()");
        return EXIT_FAILURE;
    }
    if((v[1][0] == L'/' || v[1][0] == L'-') && v[1][1] == L'G' && v[1][2] == L'e' && v[1][3] == L'n' && v[1][4] == L's' && v[1][5] == L'e')
    {
        t = You(c, v);
        if (t == L"")
            return -1;
        i = You_Genre(t);
        return EXIT_FAILURE;
    }
    /*if (
        ()
      )*/
#if You_you_ == 1
    std::wcout << L"wstring You_you(" << c << L", ) pas de aaaaaa" << std::endl;
#endif

    return EXIT_FAILURE;
}

// ############################################################
// #                                                          #
// # You_Genre                                                #
// #                                                          #
// ############################################################

const int You_Genre(std::wstring t)
{
#if You_Genre_ == 1
    std::wcout << L"int You_Gense(" << t << L')' << std::endl;
#endif
    if (t.substr(0, 4) == L"you ")
    {
#if You_Genre_ == 1
        std::wcout << L"int You_Gense(" << t << L')' << std::endl;
#endif
        t = t.substr(4);
    }
    if (t.length() == 6)
    {
        //::Gense;
        std::vector <std::wstring>::iterator iter;
        std::vector <std::wstring>::const_iterator c_iter;
        std::wcout << L"Genre : " << ::Genre.size() << std::endl;
        std::size_t n = Genre.size();
        for (int i = 0; i < n; i++)
        {
            std::wcout << ::Genre[i];
            if (i < n - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                std::wcout << L", ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                std::wcout << L'.';
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
        }
        std::wcout << std::endl;
        return 0;
    }
    std::size_t pos = 0;
    std::wcout << L"(" << t << L")" << std::endl;
    //pos = strlen(pt);
    std::wstring tt = t;
    tt = tt.substr(7);
    //vector <wstring>::iterator iter;
    pos = tt.find(L" ");
    if (pos == std::wstring::npos)
    {
        std::wcout << L"zzzz" << std::endl;
        ::E.afficher_X(-1, t, L"Genre wwww pas");
        return -1;
    }
    // genre
    std::wstring genre = tt.substr(0, pos);
    std::wcout << L"aa genre=[" << genre << L"] tt=[" << tt << L"] pos=" << pos << std::endl;
    if (std::find(::Genre.begin(), ::Genre.end(), genre) != ::Genre.end())
    {
        //gense = tt;
    }
    else
    {
        ::E.afficher_X(-1, t, L"genre pas");
        return -1;
    }
    std::wcout << L"Genre : " << genre << std::endl;
    std::wcout << L"aaaaaa" << std::endl;
    tt = tt.substr(pos + 1);
    // c ou s ou cd ou cv
    pos = tt.find(L" ");
    if (pos == std::wstring::npos)
    {
        std::wcout << L"eeeeee" << std::endl;
        E.afficher_X(-1, t, L"pas !");
        return -1;
    }
    std::wstring cs = tt.substr(0, pos);
    if (cs == L"c" || cs == L"s" || cs == L"cd" || cs == L"cv")
    {
        std::wstring p_cs = cs;
        std::wcout << L"p_cs=[" << p_cs << L']' << std::endl;
    }
    else
    {
        E.afficher_X(-1, t, L"Erreur pas cs");
        return -1;
    }
    std::wcout << L"cs=[" << cs << L"]" << std::endl;
    //
    std::vector <std::wstring> G;
    return 0;
}

// ############################################################
// #                                                          #
// # You_Rechercher                                           #
// #                                                          #
// ############################################################

const int You_Rechercher(int c, wchar_t** v)
{
    std::size_t pos = 0;
    //static const basic_string <wchar_t>::size_type npos = -1;
    std::size_t npos = -1;
    std::wstring t;
#if You_Rechercher_ == 1
    std::wcout << L"const int You_Rechercher(" << c << L", ) :" << std::endl;
#endif
    std::wcout << P.R_T << L"Rechercher :" << P.R_t << std::endl;
    if (v[3][0] == L'\0')
    {
        std::wcerr << L"Erreur !!! (v[3][0] == L'\0')" << std::endl;
        E.afficher_X(-3, L"v[3][0] == L'\0' erreur !!!", L"Erreur !!!");
        return -3;
    }
    std::wstring rechercher = v[3];
    std::wstring RECHERCHER = rechercher;
    transform(RECHERCHER.begin(), RECHERCHER.end(), RECHERCHER.begin(), ::toupper);
    std::wstring r_r = RECHERCHER.substr(0, 1);
    //
    if (v[2][0] == L's' && v[2][1] == L'\0')
    {
        P_cs = P_serie;
        P.P_T = P.S_W;
        P.P_t = P.S_w;
    }
    else if (v[2][0] == L'c' && v[2][1] == L'\0')
    {
        P_cs = P_cinema;
    }
    else if (v[2][0] == L'c' && v[2][1] == L'v' && v[2][2] == L'\0')
        P_cs = P_cinema_VOD;
    else if (v[2][0] == L'c' && v[2][1] == L'd' && v[2][2] == L'\0')
        P_cs = P_cinema_DVD;
    else
    {
        std::wcerr << L"Erreur !!!" << std::endl;
        E.afficher_X(-3, L"Erreur !!!", L"Erreur !!!");
        return -3;
    }
    if (v[2][0] == L'c')
    {
        P.P_T = P.C_T;
        P.P_t = P.C_t;
    }
    //
    int i = 0;
    std::vector<std::wstring>r;
    //r.push_back(P_cs.cs + L"\\");
    r.push_back(P_cs.cs + L"\\" + r_r);
    r.push_back(P_cs.cs + L"\\-" + r_r);
    r.push_back(P_cs.cs + L"\\+\\" + r_r);
    r.push_back(P_cs.cs + L"\\++\\" + r_r);
    r.push_back(P_cs.cs + L"\\+++\\" + r_r);
    r.push_back(P_cs.cs + L"\\++++\\" + r_r);
    r.push_back(P_cs.cs + L"\\+++++\\" + r_r);
    std::vector<std::wstring>::iterator iter;
    std::wstring TT;
    std::wstring rr;
    path rrr;
    for (iter = r.begin(); iter != r.end(); iter++)
    {
        rr = *iter;
        //rrr = rr.parent_path();
        //if (rrr == rr.parent_path())
        //{
        //}

        //rr.parent_path();
        //if (rrr.parent_path() == *iter)
        //{
            //wcout << L"    " << L"eee " << rr.parent_path() << L" aaa " << endl;
        //}
        for (directory_iterator next(*iter), end; next != end; ++next)
        {
            t = next->path();
            //if(rrr.parent_path() == t)
            //    wcout << L"    " << L"zzz " << rrr.parent_path() << endl;
            //;
            //if (rrr.has_parent_path())
            //    wcout << "Parent path of " << rrr << " is " << rrr.parent_path() << endl;

            if (is_directory(t))
            {
                TT = t;
                transform(TT.begin(), TT.end(), TT.begin(), ::toupper);
                pos = TT.find(RECHERCHER);
                if (pos != std::wstring::npos)
                {
                    if (*iter != L"" && rr == *iter)
                    {
                        std::wcout << P.R_T << L">>> " << P.R_t << P.P_T << *iter << P.P_t << std::endl;
                        rr = L"";
                    }
                    std::wcout << L"    " << t << std::endl;
                    //wcout << L"    " << (wstring)t.parent_path() << endl;
                    i++;
                }
            }
        }
    }
    if (i == 0)
        std::wcout << L"    " << L"Pas de rechercher !!!" << std::endl;
#if You_Rechercher_ == 1
    std::wcout << L"const int You_Rechercher() : Ok !" << std::endl;
#endif
    return EXIT_SUCCESS;
}

/*const int You_Rechercher(wstring t)
{
#if You_Rechercher_ == 1
    wcout << L"You_Rechercher() :" << endl;
#endif
    if (!(t.substr(0, 3) == L"-R " || t.substr(0, 2) == L"/R "))
    {
        wcerr << L"Érreur !!!" << endl;
        E.afficher_X(-3, L"Érreur !!!", L"Érreur !!!");
        return -3;
    }
    wstring you = L"you";
    wstring R = L"/R";
    t = t.substr(3);
    wstring cs;
    if (t.substr(0, 2) == L"c ")
    {
        cs = L"c";
        t = t.substr(3);
    }
    else if (t.substr(0, 2) == L"s ")
    {
        cs = L"s";
        t = t.substr(3);
    }
    else if (t.substr(0, 3) == L"cv ")
    {
        cs = L"cv";
        t = t.substr(4);
    }
    else if (t.substr(0, 3) == L"cd ")
    {
        cs = L"cd";
        t = t.substr(4);
    }
    else
    {
        wcerr << L"Érreur !!!" << endl;
        E.afficher_X(-3, L"Érreur !!!", L"Érreur !!!");
        return -3;
    }
    wcout << you << L' ' << R << L' ' << cs << L' ' << t << endl;
    wstring y[4];
    y[0] = you;
    y[1] = R;
    y[2] = cs;
    y[3] = t;
    int i = You_Rechercher(4, y[4]);
#if You_Rechercher_ == 1
    wcout << L"You_Rechercher() : Ok !" << endl;
#endif
    return EXIT_SUCCESS;
}*/

// ############################################################
// #                                                          #
// # const int You_t(wstring t)                               #
// #                                                          #
// ############################################################

const int You_t(std::wstring t)
{
    //Bug B;
    std::wcout << t << std::endl;
    return EXIT_SUCCESS;
}

const int You_t(std::vector<std::wstring>&v)
{
    int i = 0;
    std::size_t pos = 0;
    static const basic_string <wchar_t>::size_type npos = -1;
    std::wstring t;
    /*if (v[3][0] == L'\0')
    {
        std::wcerr << L"    " << L"Erreur !!! (v[3][0] == L'\0')" << std::endl;
        E.afficher_X(-3, L"v[3][0] == L'\0' erreur !!!", L"Erreur !!!");
#if You_t_ == 1
        B.Ok_W(L"v[3][0] == L''\\0''");
#endif
        return EXIT_FAILURE;
    }*/
    if (v[2] == L"c")
    {
        if (v[3] != L"\0")
        {
            path c_(v[3]);
            Cinema C;
            i = C.Ok_C(P.C_Espace1, P.C_H, P.C_Espace2, P.C_Espace3, P.C_MIN, P.C_T, P.C_t, P.C_W, P.C_w);
            i = C.afficher_dossier(c_.filename());
            //for (directory_iterator next(path(P_C.cs + v[3])), end; next != end; ++next)
            for (directory_iterator next(path(cinema.cs + v[3])), end; next != end; ++next)
            {
                //wcout << L"qqqqq" << next->path() << endl;
                t = next->path();
                if (is_regular_file(t))
                {
                    pos = t.find(L".txt");
                    if (pos != std::wstring::npos)
                    {
                        pos = t.find(L"\\_");
                        if (pos != std::wstring::npos)
                            continue;
                        i = C.afficher_fichier(t, TXT_);
                        continue;
                    }
                    //pos = t.find(L".jpg");
                    //if (pos != wstring::npos)
                    //    i = C.afficher_Image(t);
                    //pos = t.find(L".png");
                    //if (pos != wstring::npos)
                    //    i = C.afficher_Image(t);
                    pos = t.find(L".jpg");
                    if (pos != std::wstring::npos)
                    {
                        i = C.afficher_fichier(t, JGP_);
                    }
                    pos = t.find(L".png");
                    if (pos != std::wstring::npos)
                    {
                        i = C.afficher_fichier(t, PNG_);
                    }
                }
            }
            //wcout << L"aaa" << endl;
            i = C.afficher();
        }
    }
    else if (v[2] == L"s")
    {
        if (v[3] != L"\0")
        {
            int j = 0;
            path s_(v[3]);
            std::wcout << L"v[3]={" << v[3] << L"}" << std::endl;
            std::wstring temps = v[3];
            pos = temps.find_last_of(L"\\");
            temps = temps.substr(pos + 1);
            std::wcout << L"ffff" << std::endl;
            P_cs = P_S;
            //j = compare_path(/*P_cs,*/ s_, temps);

            if (j == 0)
                ;
            else
            {
                std::wcerr << L"[s] erreur !!!" << std::endl;
                E.afficher_X(-3, L"s erreur !!!", L"s erreur !!!");
                return -3;

            }
            Serie S;
            i = S.Ok_S(P.S_Espace, P.S_MIN, P.S_T, P.S_t, P.S_W, P.S_w);
            i = S.afficher_dossier(s_.filename());
            //for (directory_iterator next(path(serie.cs + v[3])), end; next != end; ++next)
            //for (directory_iterator next(path(P_S.cs + v[3])), end; next != end; ++next)
            for (directory_iterator next(s_), end; next != end; ++next)
            {
                //assert(P_S->cs && "L'index ne doit pas être négatif.");
                t = next->path();
                if (is_regular_file(t))
                {
                    pos = t.find(L".txt");
                    if (pos != npos)
                    {
                        pos = t.find(L"\\_you_.txt");
                        //pos = t.find(L"\\_");
                        //pos = t.find(L"\\_");
                        if (pos != npos)
                            continue;
                        i = S.afficher_fichier(t, TXT_);
                    }
                    pos = t.find(L".jpg");
                    if (pos != std::wstring::npos)
                    {
                        i = S.afficher_fichier(t, JGP_);
                    }
                    pos = t.find(L".png");
                    if (pos != std::wstring::npos)
                    {
                        i = S.afficher_fichier(t, PNG_);
                    }
                }
                if (is_directory(t))
                {
                    //i = You_t_directory(t);
                    path ss_(t + L'\\');
                    std::wstring t2;
                    t2 = t + L'\\';
                    i = S.afficher_dossier(t2);
                    //                    for (directory_iterator next(path(t + L'\\')), end; next != end; ++next)
                    for (directory_iterator next2(ss_), end2;
                        next2 != end2;
                        ++next2)
                    {
                        //wcout << next->path() << endl;
                        t2 = next2->path();
                        if (is_regular_file(t2))
                        {
                            pos = t2.find(L".txt");
                            if (pos != std::wstring::npos)
                            {
                                //wcout << L'\t';
                                if (t2 == t + L"\\_you_.txt")
                                    continue;
                                i = S.afficher_fichier(j, t2, TXT_);
                            }
                            pos = t2.find(L".jpg");
                            if (pos != std::wstring::npos)
                            {
                                i = S.afficher_fichier(j, t2, JGP_);
                            }
                            pos = t2.find(L".png");
                            if (pos != std::wstring::npos)
                            {
                                i = S.afficher_fichier(j, t2, PNG_);
                            }
                        }
                    }
                    j++;
                }
            }
            i = S.afficher_pas_de_OK();
            i = S.afficher();
        }
    }
    else
    {
        wcout << L"hacnnnn" << endl;
    }
    return i;
}

//const int You_t_directory(std::wstring& t)
//{

//}

// ############################################################
// #                                                          #
// # wmain                                                    #
// #                                                          #
// ############################################################

int wmain(int argc, wchar_t* argv[])
{
#if wmain_ == 1
    wcout << L"int wmain(int argc, wchar_t* argv[]) :" << endl;
    //B.Ok_T(L"int wmain(int " + argc + ", wchar_t* argv[])");
#endif

    int i;
    std::vector<std::wstring> v;
    if(argc != 0)
    { 
        for (i = 0; i < argc; i++)
        {
            v.push_back(argv[i]);
            std::wcout << L"argv[" << i << L"]= {" << argv[i] << L'}' << std::endl;
        }
    }

    //
    //init();
    //::Console console;
    Console::init();
    //::B;
    ::P;
    ::E;
    //
    //P_cinema;
    //
    //int i;
    // Set output mode to handle virtual terminal sequences
    //hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    /*if (Console::hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }
    //    DWORD dwMode = 0;
    if (!GetConsoleMode(Console::hOut, &Console::dwMode))
    {
        return GetLastError();
    }
    Console::dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(Console::hOut, Console::dwMode))
    {
        return GetLastError();
    }*/

    //    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    //GetConsoleScreenBufferInfo(Console::hOut, &Console::csbiInfo);
    //_Y_ = csbiInfo.srWindow.Right + 1;
    //CONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx;
    //GetConsoleScreenBufferInfoEx(hOut, &lpConsoleScreenBufferInfoEx);
    //i = console_OK();
    //GetConsoleMode(_In_  HANDLE  hConsoleHandle, _Out_ LPDWORD lpMode);
    //HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //DWORD dwMode = 0;

    /*COORD dwSize = {100, 60};
    if (setConsoleScreenBufferInfo(dwSize))
    {	// Réglage des coordonnées
        printf("setConsoleScreenBufferInfo qqq (%ld)\n", GetLastError());
        wcout << GetLastError() << endl;
        return EXIT_FAILURE;
    }*/
    SetConsoleTitle(u8"You");	// Réglage du titre

    //dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    //CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    //GetConsoleScreenBufferInfo(hOut, &csbiInfo);
    //hOut = GetStdHandle(STD_OUTPUT_HANDLE);


    //if (ScrollByAbsoluteCoord(10))
    //    _getwch(); 
    //else 
    //    return 0;

    //if (ScrollByRelativeCoord(200))
        //_getwch();
    //else 
    //    return 0;
    //i = console_ok_((HANDLE)hOut, csbiInfo);

    //COORD dwSize = { 100, 60 };

    // Non !!! PERSON Person pas !!!
    // Oui :

//    ::C_T = ::C_T_t + ::C_T_f * 16;
//    ::C_W = ::C_W_t + ::C_W_f * 16;
    //_setmode(_fileno(stdout), _O_U16TEXT); // https://www.it-swarm-fr.com/fr/c%2B%2B/quelle-est-la-difference-entre-printf-s-printf-ls-wprintf-s-et-wprintf-ls/1048965707/
    std::wstring t;
    std::size_t pos;



    std::wcout << L"…" << std::endl;


    i = 0;
    i = You_txt(i);
    if (i == 0)
    {
        //P_C = P_cinema;
        P_S = P_serie;
#if wmain_ == 1
        std::wcout << L"\tP_S.cs=[" << P_S.cs << L']' << std::endl;
#endif
        //P_C_VOD = P_cinema_VOD;
       //P_C_DVD = P_cinema_DVD;
    }
    else
    {
        i = You_txt_ok();
    }
    i = 0;



    /*if (argc > 2)
    {
        i = get_all(argc);
    }*/
    
    if (argc != 0)
    {
        if (v[1] == L"/t" || v[1] == L"-t")
        {
            //i = You_t(argc, argv);
            i = You_t(v);
        }

    }
    else
    {
        std::wstring input = L"";
        pos = 0;
        //if(argc == 1)
        //    usage();

        while (argc == 1)
        {
            if (i == 1)
            {
                std::wcout << L"TTTTTTTTTTTTTTT" << std::endl;
            }

            if (i == 0)
            {
                // Ok
                t = L"qqqqq";
                //usage(t);
                std::wcout << L'\n' << std::endl;
                //return 0;
            }
            else if (i == 5)
            {
                //wcout << "Trouvez de ___ !" << endl;
                return 5;
            }
            else if (i == 6)
            {
                //wcout << "Trouvez de ___ !" << endl;
                return 6;
            }
            else
            {
                //usage();
                //break;
                //return 0;
            }
            //const char* str = argv[1];
            //while (str[idx] != '\0') 
            //{
            //    if ((str[idx] == '\\') && (str[idx + 1] == 'n')) 
            //{
            //        std::cout << std::endl;
            //        idx += 2;
            //    }
            //    else 
            //{
            //        std::cout << str[idx];
            //        idx++;
            //    }
            //}
            while (wcin)
            {
                std::wcout << "Ok : ";
                getline(std::wcin, input);
                std::wcout << "[" << input << "]" << std::endl;;
                if (input.substr(0, 6) == L"/Gense")
                {
                    //wcout << L"/Gense :" << endl;
                    //i = You_Gense(input);
                    //i = 0;
                    /*if (i != 0)
                    {
                        wcout.width(2);
                        wcout << E.X_i[i];
                        wcout << L" : " << E.X[i] << L" : " << E.X_W[i] << endl;
                        i++;
                    }
                    E.X_I = 0;*/
                    std::wcout << std::endl;
                }

                if (input.substr(0, 2) == L"/t" || input.substr(0, 2) == L"-t")
                {
                    std::wstring tt = L"/t";
                    std::wcout << tt << L" :" << std::endl;
                    i = You_t(input);
                }
                if (input.substr(0, 5) == L"Genre")
                {
                    std::wcout << L"Genre :" << std::endl;
                    i = You_Genre(input);
                }
                if (input.substr(0, 5) == L"usage")
                {
                    std::wcout << L"usage :" << std::endl;
                    usage();
                }
                if (input.substr(0,1) == L"/h" || input.substr(0, 2) == L"-h")
                {
                    std::wcout << L"usage :" << std::endl;
                    usage();
                }
                /*if (input.substr(0, 3) == L"-R " || input.substr(0, 2) == L"/R ")
                {
                    wcout << L"Rechercher :";
                    i = You_Rechercher(input);
                }*/
                if (input == L"x")
                {
                    int y = 0;
                    /*wstring textes =*L"cc" + P.S_W + L"azertyuiop" + P.S_w + L"vv" + P.S_W + L"qsdfghjklm" + P.S_w + L" wxc" +
                        L"aa bbb cccc ddddddd eee fffffff gggg hh ii jjjjjj kkkkkkkkkk ll mmmmmm nnn oooooo, pp.qqqqqq rrrrr ss ttt uuu vvv wwwwww xxx yy zzzzzz.AAAA BBB CC DDDDD EEEEEEEE F'GGGGG HHH II JJJJJ KKKK, LL MMMMMMM NNNN ! OOOO PP QQQQ !" +
                        L"RR S TTTTT, UU VVVV WWWWW XX YYYYYYY ZZZ ; aaaa bb ccccc(dd eeeeeeeee !) fff ggg, hhh iiiiii jjjjjjjj kk ? l'mm nnnnnnn ooo ppppppppp qqqqq rrr ss tttttt u'vvvvvv wwwww ! xx yyyyyyyy ! zzzzz. AAAA BBB CCCCCCCCCC - DD ! EEEEE FFF GGGG HHHH II JJJJ. KK LLLLLL MMM NNNNNNN OOO PPPP .QQQQQQ - RR SSSS TTTT U VVV WW XXXXXX YY ZZZ !" +
                        L"\n" +
                        L"aa bbb cccc ddddddd eee fffffff" + P.E_T + L" gggg" + P.E_t + L" hh ii jjjjjj kkkkkkkkkk ll mmmmmm. nnn oooooo, pp qqqqqq rrrrr ss ttttt uuu vv www xxx yy zzzzzz. AAAA BBB CC DDDDD EEEEEEEE F'GGGGG HHH II JJJJJ KKKK, LL MMMMMMM NNNN : OOOO PP QQQQ ! RR SS TTTTT, UU VVVV WWWWW XX YYYYYYY ZZZ ; aaaa bb ccccc (dd eeeeeeeee) fff ggg, hhh iiiiii jjjjjjjj " +
                        L"kk " + P.S_T + L'?' + P.S_t + L" ss."; */
                        //wstring textes = L"ccazertyuiopvvqsdfghjklm wxc";// +L"\n" + L"qsdfghjklm";
                    wstring const textes = L"Ashley Walters" + P.S_W + L" (" + P.S_w + L"Dushane" + P.S_W + L"), " + P.S_w +
                        L"Kane Robinson" + P.S_W + L" (" + P.S_w + L"Sully" + P.S_W + L"), " + P.S_w +
                        L"Micheal Ward" + P.S_W + L" (" + P.S_w + L"Jamie" + P.S_W + L"), " + P.S_w +
                        L"Jasmine Jobson" + P.S_W + L" (" + P.S_w + L"Jaq" + P.S_W + L"), " + P.S_w +
                        L"Shone Romulus" + P.S_W + L" (" + P.S_w + L"Dris" + P.S_W + L"), " + P.S_w +
                        L"Ashley Thomas" + P.S_W + L" (" + P.S_w + L"Jermaine" + P.S_W + L"), " + P.S_w +
                        L"Kadeem Ramsay" + P.S_W + L" (" + P.S_w + L"Kit" + P.S_W + L"), " + P.S_w +
                        L"Seraphina Beh" + P.S_W + L" (" + P.S_w + L"Farah" + P.S_W + L"), " + P.S_w +
                        L"Hope Ikpoku Jnr" + P.S_W + L" (" + P.S_w + L"Aaron" + P.S_W + L"), " + P.S_w +
                        L"Kane Robinson" + P.S_W + L" (" + P.S_w + L"Sully" + P.S_W + L"), " + P.S_w +
                        L"Micheal Ward" + P.S_W + L" (" + P.S_w + L"Jamie" + P.S_W + L"), " + P.S_w +
                        L"Jasmine Jobson" + P.S_W + L" (" + P.S_w + L"Jaq" + P.S_W + L"), " + P.S_w +
                        L"Shone Romulus" + P.S_W + L" (" + P.S_w + L"Dris" + P.S_W + L"), " + P.S_w +
                        L"Ashley Thomas" + P.S_W + L" (" + P.S_w + L"Jermaine" + P.S_W + L"), " + P.S_w +
                        L"Kadeem Ramsay" + P.S_W + L" (" + P.S_w + L"Kit" + P.S_W + L"), " + P.S_w +
                        L"Seraphina Beh" + P.S_W + L" (" + P.S_w + L"Farah" + P.S_W + L"), " + P.S_w +
                        L"Hope Ikpoku Jnr" + P.S_W + L" (" + P.S_w + L"Aaron" + P.S_W + L")" + P.S_w;

                    i = Console_Lire_txt(textes, y + 4, y);
                    E.Ok();

                }
                if (input == L"w")
                    return 0;
                if (input == L"\n")
                {
                    usage();
                    return 0;
                }
                if (input.empty())
                    continue;
            }
        }
    }
    i = 0;
    //while (i < E.X_I)
    //{
    //    wcout.width(2);
    //    wcout << E.X_i[i];
    //    wcout << L" : " << E.X[i] << L" : " << E.X_W[i] << endl;
    //   i++;
    //}

#if wmain_ == 1
    std::wcout << L"int wmain(int argc, wchar_t* argv[]) : Ok !" << std::endl;
    std::wcout << L"" << std::endl;
#endif
    return EXIT_SUCCESS;
}
/*if (argc > 1)
{
    //#if You_ == 1
    for (int j = 1; j != argc; ++j) //parcourir les arguments
    {
        if (argv[j][0] == L'-' || argv[j][0] == L'/') //si le premier caractère de l'argument est '-'...
        {//...c'est une option.
            for (wchar_t* popt = &argv[j][1]; *popt != L'\0'; ++popt) //parcourir les caractères de l'option
            {
                //int you_t;
                switch (*popt)
                {
                case L't':
                    i = You_t(argc, argv);
                    break;
                case L'R':
                    i = You_Rechercher(argc, argv);
                    break;
                case L'G':
                    i = You_you(argc, argv);
                    break;
                case L'X':
                    //string XX = u8"";
                    break;
                default: //option inconnue
                    i = -1;
                }
                return 0;
            }
        }
        else
        {//...c'est un argument
            argv[j]; //traiter cet argument
        }
    }

    //#endif
}*/

// ############################################################
// #                                                          #
// # compare_path                                             #
// #                                                          #
// ############################################################

const int compare_path(path& t, std::wstring& t2)
{
    int i;
    i = Compare_Path(t.compare(P_cs.cs + t2), t, P_cs.cs + t2);
    if (i == 0)
    {
#if compare_path_ == 1
        std::wcout << L"compare_path(" << t << L", " << t2 << L") : Ok (1) !" << std::endl;
        //B.Ok_W(L"compare_path(" + path(t) + L", " + t2 + L") : Ok (1) !");
#endif
        return EXIT_SUCCESS;
    }
    for (i = 0; i < 6; i++)
    {
        int j = Compare_Path(t.compare(P_cs.note[i] + L'\\' + t2), t, P_cs.cs + L'\\' + t2);
        if (j == 0)
        {
#if compare_path_ == 1
            std::wcout << L"compare_path(" << t << L", " << t2 << L") : Ok (2) !" << std::endl;
#endif
            return EXIT_SUCCESS;
        }
        std::vector <std::wstring>::const_iterator iter;
        std::wstring wstr;
        for (iter = ::AZERTYUIOP.begin(); iter != ::AZERTYUIOP.end(); iter++)
        {
            wstr = P_cs.note[i] + L'\\' + *iter;// +t2;
            if (afficher_Path_Exists(wstr) == false)
                continue;
            wstr += L'\\' + t2;
            j = Compare_Path(t.compare(wstr), t, wstr);
            if (j == 0)
            {
#if compare_path_ == 1
                //wcout << L"compare_path(" << t << L", " << t2 << L") : Ok(3) !" << endl;
#endif
                return EXIT_SUCCESS;
            }
        }
    }
#if compare_path_ == 1
    //wcout << L"compare_path( , " << t2 << L") : Érreur !!!" << endl;
#endif
    return EXIT_FAILURE;
}


/*void usage(wstring t = L"")
{
    int i = 0, y1, y2;
    int in = 9, out = 15;
    //::_Y_ = csbiInfo.srWindow.Right + 1;
    //Y = ::_Y_;
    y1 = 4;
    y2 = 4;
    //
    wstring Textes, textes;
    Textes = textes = L"";
    //
    Textes += L"You :";
    textes += L"¬¬¬ ¬";
    ::Console_Lire_txt(Textes, textes, 0, 0, _Y_, in, out);
    wcout << L"\n";
    //
    Textes = L"azereezrttertretrtert";
    textes = L"azereezrttertretrtert";
    ::Console_Lire_txt(Textes, textes, 0, 0, _Y_, in, out);
    wcout << L"\n";
    //
    Textes = L"/t c {dossier}\n";
    textes = L"¬¬ ¬ {dossier}\n";
    Textes += L"/t s {dossier}";
    textes += L"¬¬ ¬ {dossier}";
    ::Console_Lire_txt(Textes, textes, y1, y1, _Y_, in, out);
    wcout << L"\n";

    //::Console_Lire_txt(Textes, textes, y1, y2, Y, in, out);
    //wcout << L"\n";
    Textes = L"aa bbb cccc ddddddd eee fffffff gggg hh ii jjjjjj kkkkkkkkkk ll mmmmmm nnn oooooo, pp.  qqqqqq rrrrr ss ttt uuu vvv wwwwww xxx yy ";
    textes = L"aa bbb cccc ddddddd eee fffffff gggg hh ii jjjjjj kkkkkkkkkk ll mmmmmm nnn oooooo, pp.  qqqqqq rrrrr ss ttt uuu vvv wwwwww xxx yy ";
        //L"zzzzzz.AAAA BBB CC DDDDD EEEEEEEE F'GGGGG HHH II JJJJJ KKKK, LL MMMMMMM NNNN « OOOO PP QQQQ »." +
        //L"RR S TTTTT, UU VVVV WWWWW XX YYYYYYY ZZZ; aaaa bb ccccc(dd eeeeeeeee !) fff ggg, hhh iiiiii jjjjjjjj " +
        //L"kk ? l'mm nnnnnnn ooo ppppppppp qqqqq rrr ss tttttt u'vvvvvv wwwww xx yyyyyyyy zzzzz.AAAA BBB CCCCCCCCCC - DD !EEEEE FFF GGGG HHHH " +
        //L"II JJJJ.KK LLLLLL MMM NNNNNNN OOO PPPP.QQQQQQ - RR « SSSS TTTT U » VVV WW XXXXXX YY ZZZ." +
        //L"\n" +
        //L"aa bbb cccc ddddddd eee fffffff gggg hh ii jjjjjj kkkkkkkkkk ll mmmmmm.nnn oooooo, pp qqqqqq rrrrr ss ttttt uuu " +
        //L"vv www xxx yy zzzzzz.AAAA BBB CC DDDDD EEEEEEEE F'GGGGG HHH II JJJJJ KKKK, LL MMMMMMM NNNN « OOOO PP QQQQ ». RR SS TTTTT, UU VVVV WWWWW XX YYYYYYY " +
        //L"ZZZ; aaaa bb ccccc(dd eeeeeeeee) fff ggg, hhh iiiiii jjjjjjjj kk ?";
        ;
    ::Console_Lire_txt(Textes, textes, y1, 0, _Y_, in, out);
    wcout << L"\n";
    //
    Textes = L"/Gense gense c {dossier}";
    textes = L"¬¬¬¬¬¬ gense ¬ {dossier}";
    ::Console_Lire_txt(Textes, textes, y1, 0, _Y_, in, out);
    wcout << L"\n";
}*/



/*const int console_OK()
{
    //GetConsoleMode(_In_  HANDLE  hConsoleHandle, _Out_ LPDWORD lpMode);
    //HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //DWORD dwMode = 0;

    COORD dwSize = { 100, 60 };
    if (setConsoleScreenBufferInfo(dwSize))
    {	// Réglage des coordonnées
        printf("setConsoleScreenBufferInfo qqq (%ld)\n", GetLastError());
        wcout << GetLastError() << endl;
        return EXIT_FAILURE;
    }
    SetConsoleTitle(L"You");	// Réglage du titre

    return 0;
}*/

/*
int S_T_t = 9, S_T_f = 0, S_W_t = 10, S_W_f = 0;
int S_T, S_W;
int S_t_t = 15, S_t_f = 0, S_w_t = 15, S_w_f = 0;
int S_t, S_w;
*/


/*const void afficher_X(int i, wstring t, wstring w)
{
    X[X_I] = t;
    X_i[X_I] = i;
    X_W[X_I] = w;
    wcerr
        << X_in << i << L" : " << X_out
        << t
        << X_in << L" : " << X_out
        << w
        << endl;
    X_I++;
}*/

/*int qqqqq()
{
    HANDLE hStdout;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    SMALL_RECT srctScrollRect, srctClipRect;
    CHAR_INFO chiFill;
    COORD coordDest;
    int i;

    printf("\nPrinting 20 lines for reference. ");
    printf("Notice that line 6 is discarded during scrolling.\n");
    for (i = 0; i <= 20; i++)
        printf("%d\n", i);

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hStdout == INVALID_HANDLE_VALUE)
    {
        printf("GetStdHandle failed with %d\n", GetLastError());
        return 1;
    }

    // Get the screen buffer size.

    if (!GetConsoleScreenBufferInfo(hStdout, &csbiInfo))
    {
        printf("GetConsoleScreenBufferInfo failed %d\n", GetLastError());
        return 1;
    }

    // The scrolling rectangle is the bottom 15 rows of the
    // screen buffer.

    srctScrollRect.Top = csbiInfo.dwSize.Y - 16;
    srctScrollRect.Bottom = csbiInfo.dwSize.Y - 1;
    srctScrollRect.Left = 0;
    srctScrollRect.Right = csbiInfo.dwSize.X - 1;

    // The destination for the scroll rectangle is one row up.

    coordDest.X = 0;
    coordDest.Y = csbiInfo.dwSize.Y - 17;

    // The clipping rectangle is the same as the scrolling rectangle.
    // The destination row is left unchanged.

    srctClipRect = srctScrollRect;

    // Fill the bottom row with green blanks.

    chiFill.Attributes = BACKGROUND_GREEN | FOREGROUND_RED;
    chiFill.Char.AsciiChar = (char)'A';

    // Scroll up one line.

    if (!ScrollConsoleScreenBuffer(
        hStdout,         // screen buffer handle
        &srctScrollRect, // scrolling rectangle
        &srctClipRect,   // clipping rectangle
        coordDest,       // top left destination cell
        &chiFill))       // fill character and color
    {
        printf("ScrollConsoleScreenBuffer failed %d\n", GetLastError());
        return 1;
    }
    return 0;
}*/

/*int qsdfg()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        //return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        //return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        //return GetLastError();
    }

    // Try some Set Graphics Rendition (SGR) terminal escape sequences
    wprintf(L"\x1b[31mThis text has a red foreground using SGR.31.\r\n");
    wprintf(L"\x1b[1mThis text has a bright (bold) red foreground using SGR.1 to affect the previous color setting.\r\n");
    wprintf(L"\x1b[mThis text has returned to default colors using SGR.0 implicitly.\r\n");
    wprintf(L"\x1b[34;46mThis text shows the foreground and background change at the same time.\r\n");
    wprintf(L"\x1b[0mThis text has returned to default colors using SGR.0 explicitly.\r\n");
    wprintf(L"\x1b[31;32;33;34;35;36;101;102;103;104;105;106;107mThis text attempts to apply many colors in the same command. Note the colors are applied from left to right so only the right-most option of foreground cyan (SGR.36) and background bright white (SGR.107) is effective.\r\n");
    wprintf(L"\x1b[39mThis text has restored the foreground color only.\r\n");
    wprintf(L"\x1b[49mThis text has restored the background color only.\r\n");

    //
    FILE* fichier = NULL;
    if ((fichier = _wfopen(L"e:\\Séries.[]\\Wxcvbn.[2021 Netflix].Manga\\Avec.txt", L"r")) == NULL) // C4996
    //if ((fichier = fopen(u8"e:\\Séries.[]\\Wxcvbn.[2021 Netflix].Manga\\Avec.txt", u8"r, ccs=UTF-8")) == NULL) // C4996
    { // Note: fopen is deprecated; consider using fopen_s instead
        cout << "aaaa" << endl;
        return -1;
    }
    wcout << L"bbbb" << endl;
    string p = u8"";
    char phrase[254] = { u8"" };
    while (!feof(fichier))
    {
        cout << "hhhhh" << endl;
        if (fgets(phrase, 254, fichier) == NULL)
            break;
        else
            p += phrase;
    }
    fclose(fichier);
    cout << p << endl;
    cout << "ccc" << endl;
    return 0;

}*/

