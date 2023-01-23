#include "pch.h"

#include "console.h"
#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <string>
//#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
//#include <sstream>
//#include <ctime>
#include <codecvt>

#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;

//extern Titre;
//extern const Cinema C;
//extern const Serie S;
extern class Erreur E;
//extern class Bug B;

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

Console::Console()
{
    Text_Color = L"\x1b[38;2;255;0;0m"; // Ok ! Problème !
    Default_Color = L"\x1b[38;2;255;255;255m";
    Ponctuation_Color = L"\x1b[38;2;0;200;200m";
    End_Ln = L"\r\n";
}

Console::~Console()
{
}

void Console::init()
{
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    GetConsoleScreenBufferInfo(hOut, &csbiInfo);
    _wsetlocale(LC_ALL, L"fr-FR");
    //X = csbiInfo.srWindow.Right + 1;
    //
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }
    //    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

    //    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(hOut, &csbiInfo);
}

const void Console::PrintStringW(const std::wstring& str)
{
    DWORD dwMode = 0;

    BOOL res = WriteFile(
        hOut,
        &str[0],
        (DWORD)(str.size() * sizeof(wchar_t)),
        &dwMode,
        NULL);
    assert(res == TRUE);
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintStringW                                                                                                                                       #
// # const void Console::PrintStringW(HANDLE hOut, const std::wstring& str)                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Console::PrintStringW(HANDLE hOut, const std::wstring& str)
{
    DWORD dwMode = 0;

    BOOL res = WriteFile(
        hOut,
        &str[0],
        (DWORD)(str.size() * sizeof(wchar_t)),
        &dwMode,
        NULL);
    assert(res == TRUE);
}


static HANDLE getInstance()
//le code d'implémentation, c'est pour après.
{
    return;
}

void Console::affiche_CleValeur(std::wstring cle, std::wstring valeur)
{
    PrintStringW(getInstance(), Text_Color + cle + Default_Color + L" : " + Text_Color + valeur + Default_Color + End_Ln);
    return;
}
