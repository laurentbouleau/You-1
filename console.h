#pragma once

#include "Utils.h"
#include "titre.h"
#include "You.h"
#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <codecvt>

#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

class Console
{
public:
	Console(void);
	~Console();
	HANDLE hOut;
	DWORD dwMode = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	void init();
	const void PrintStringW(const std::wstring& str);
	const void PrintStringW(HANDLE hOut, const std::wstring& str);
	static void affiche_CleValeur(std::wstring cle, std::wstring valeur); // c'est beaucoup plus logique, voir ci-après
	//const void PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_, const std::wstring& sous_genre, bool sous_genre_, std::wstring& titre_T, std::wstring& titre_t);
	//const void PrintCreee_par(const std::vector<std::wstring>& creee_par, std::wstring titre_T, std::wstring titre_t, bool creee_par_);
protected:
	static /*const*/ std::wstring Text_Color;// = L"\x1b[38;2;255;0;0m"; // Ok ! Problème !
	static /*const*/ std::wstring Default_Color;// = L"\x1b[38;2;255;255;255m";
	static /*const*/ std::wstring Ponctuation_Color;// = L"\x1b[38;2;0;200;200m";
	static /*const*/ std::wstring End_Ln;/// = L"\r\n";

private:
	static HANDLE getInstance();//le code d'implémentation, c'est pour après.
	//static HANDLE inst = NULL; // ???
	/*static*/ HANDLE inst = NULL;
public:
};