#pragma once


#include "Utils.h"
#include "You.h"
//#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "console.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <stdexcept>
#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
//#include <stdio.h>
//#include <locale>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

/*struct Avec2
{
	wstring Avec = L"";
	wstring Avec_role = L"";
} avec;*/
//vector<Avec2> avec;


class Console;
class Titre
{
public:
	Titre(void);
	~Titre();
	//const void afficher_Audiodescription(std::wstring& a_filename, std::wstring const& nomFichier, std::wstring& audiodescription);
protected:
private:
};

