#pragma once

#define vector_afficher_fichier_lire_     1
#define afficher_fichier_lire_            1

#define afficher_Path_Exists_             0

#define Console_Lire_txt_                 0
#define Console_Lire_txt_OK_              0
#define PrintStringW_                     1

//#include "Source.h"
#include "console.h"
#include "titre.h"
//#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <sstream>
//#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation


const void afficher_Audiodescription(std::wstring& a, std::wstring const& nomFichier, std::wstring& audiodescription);
const int afficher_Avec(std::wstring&, std::wstring&, std::vector<std::wstring>&, std::vector<std::wstring>&);
const void afficher_Genre(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
const void afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images);
const void afficher_Nationalite(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
const bool afficher_Min(std::wstring&);
//const int afficher_Nationalite(std::wstring&, std::wstring const&, std::vector<std::wstring>&, std::vector<std::wstring> const&);
const void afficher_Netflix_SJ(std::wstring&, const std::wstring&, std::wstring&);
const void afficher_SJ(std::wstring&, const std::wstring&, std::wstring&);
//const wstring afficher_SJ(std::wstring);
const int afficher_Sous_Genre(std::wstring&);
const int afficher_Sur(std::wstring&);
const int afficher_T123(std::wstring, std::wstring&, std::wstring&, std::wstring&);
const bool afficher_Temps(std::wstring);
const int afficher_Temps(std::wstring, std::tm&);
const void afficher_Temps(std::tm&);
const void afficher_Temps_OK(std::wstring&, bool);
const int afficher_Titre(std::wstring t, std::vector<std::wstring>& titre, bool& titre_);
const void afficher_Titre(std::wstring, std::vector<std::wstring>& titre);
const int afficher_Titre_Original(std::wstring&, std::wstring const&, std::vector<std::wstring>&, bool&);

extern const std::vector<std::wstring> Audiodescription;

//void PrintStringW(HANDLE hOut, const std::wstring& str);
static inline void rtrim(std::wstring& s);
std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);

const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur);
const std::wstring lire_fichierTxt(std::wstring const& nomFichier);
std::wstring LoadDataFromFile(std::wstring const& nomFichier, std::wstring const& tag);
void PrintKeyMultipleValues(const std::wstring& keyColor,
    const std::wstring& keyText,
    const std::wstring& valueColor,
    const std::vector<std::wstring>& values,
    const std::wstring& separatorKeyValues = L" : ",
    const std::wstring& separatorValuesValuesColor = L"",
    const std::wstring& separatorValuesValues = L", ");
void PrintKeyValue(const std::wstring& keyColor, const std::wstring& keyText, const std::wstring& valueColor, const std::wstring& valueText, const std::wstring& separator = L" : ");
void PrintTmp(const std::wstring& text);

