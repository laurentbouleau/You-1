#pragma once
#include "pch.h"

#define Erreur_afficher_X_                1
#define Erreur_Ok_                        1

#include "Utils.h"
#include "titre.h"
#include "you.h"
//#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
//#include "Erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
//#include <stdio.h>
//#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;

class Erreur
{
public:
	Erreur(void);
	~Erreur();
	/*const */void afficher_X(int i, std::wstring xx, std::wstring t);
	/*const */void afficher_X(int i, std::wstring xx, std::wstring t, std::wstring w);
	/*const */int Ok(void);
	/*const */int Erreur_Ok(bool);

private:
	int OK = 0; // 8;
	bool OK_ = false;
	const std::wstring E_T = L"\x1b[38;2;255;0;0m";
	const std::wstring E_t = L"\x1b[38;2;255;255;255m";
	const std::wstring E_W = L"\x1b[38;2;0;200;200m";
	const std::wstring E_w = L"\x1b[38;2;255;255;255m";
	const int x1 = 0;
	const int x2 = 4;
	const int x3 = 4;
	const int x4 = 8;

	std::vector<int> X_i;
	std::vector<std::wstring> X_X;
	std::vector<std::wstring> X_T;
	std::vector<std::wstring> X_W;
	std::size_t X_I = -1;

	int I = 0;
	std::vector<int> XX_i = { 0 };
	std::vector<std::wstring> XX_X;
	std::vector<std::wstring> XX_T;
	std::vector<std::wstring> XX_W;
	std::size_t XX_I = -1;
};

