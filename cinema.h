#pragma once

#include "Utils.h"
#include "titre.h"
#include "You.h"
#include "you_txt.h"
#include "serie.h"
#include "console.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <string>
#include <iostream>
//#include <sstream>
//#include <ctime>
#include <codecvt>
#include <vector>

#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

extern class Erreur E;

extern const std::vector<std::wstring> Genre;
extern const std::vector<std::wstring> Sous_Genre;
extern const std::vector<std::wstring> Sur;
extern const std::vector<std::wstring> Nationalite;
extern const std::vector<std::wstring> Soundtrack;

class Titre;
//class Console;
class Cinema
{
	friend class Titre;
public:
	Cinema(void);
	~Cinema();

	const int afficher_dossier(std::wstring const& t);
	const int afficher_fichier(std::wstring const& t, int const& _T_);
	const int afficher_Date(std::wstring& d, const std::wstring& nomFichier);
	const void afficher_Date_de_reprise(std::wstring& d_filename, std::wstring const& nomFichier);
	void afficher_De(std::wstring& d, std::wstring const& nomFichier, std::vector<std::wstring>& de) const;
	const void afficher_Distributeur(std::wstring&, std::wstring const&);
	void afficher_Par(std::wstring& p, const std::wstring& nomFichier, std::vector<std::wstring>&par) const;
	const void afficher_Note(std::wstring&, std::wstring const&);
	//const int afficher_Soundtrack(std::wstring& s, std::wstring const& nomFichier);
	void afficher_Soundtrack();
	const int afficher_Titre(std::wstring& t, std::wstring const& nomFichier);
	const int afficher_pas_de_OK() const;
	const int afficher(void);
	const int Ok_C(bool C_Espace1, wchar_t C_H, bool C_Espace2, bool C_Espace3, std::wstring  C_MIN, std::wstring C_T, std::wstring C_t, std::wstring C_W, std::wstring C_w);

protected:
	//std::wstring ad = L"";
	//bool ad_ = false;

private:
	const int afficher_Date_1(std::wstring& d, std::wstring const& nomFichier);
	const wstring afficher_Temps_OK();

	const void PrintDate_de_reprise(const std::tm& date_de_reprise, bool affichage_date_de_reprise_actif);
	const void PrintDe();
	const void PrintDistributeur();
	const void PrintPar();
	void PrintSoundtracks(const std::vector<std::pair<std::wstring, std::wstring>>& soundtraks);
	std::wstring Ok = L"";
	std::wstring Titre__;

	bool C_Espace1;
	wchar_t C_H;
	bool C_Espace2;
	bool C_Espace3;
	std::wstring C_MIN;
	std::wstring keyColor;
	std::wstring valuesColor;
	std::wstring keyColor2;
	std::wstring valuesColor2;

	std::wstring audiodescription;
	std::vector<std::wstring> Avec;
	std::vector<std::wstring> Avec_role;
	//std::wstring Chaine;
	std::vector<std::wstring> de;
	std::tm Date{ 0 }, Date_de_reprise{ 0 }, Date_de_sortie{ 0 }, Temps{ 0 };

	std::tm date_de_reprise{ 0 };

	std::wstring distributeur;
	std::vector<std::wstring> image;
	std::vector<std::wstring> genre{};
	std::vector<std::wstring> par;
	std::vector<std::wstring> nationalite;
	std::wstring netflix_sj;
	int note;
	std::wstring sj;
	//std::vector<std::wstring> Soundtrack, Soundtrack_role;
	std::vector<std::pair<std::wstring, std::wstring>> soundtrack;
	std::wstring sous_genre;
	std::wstring sur;
	std::vector<std::wstring> Titre{};
	std::vector<std::wstring> Titre_Original{};

	bool Avec_ = false;
	//bool Chaine_ = 0;
	bool Date_ = false, Date_de_reprise_ = false, Date_de_sortie_ = false, Temps_ = false;
	//bool distributeur_ = true;

	bool affichage_audiodescription_actif = true;
	// Attention !!!
	bool affichage_date_de_reprise_actif = true;
	// Ok !
	bool affichage_de_actif = true;// false;
	bool affichage_distributeur_actif = true;
	bool affichage_image_actif = true;
	bool affichage_genres_actif = true;
	bool affichage_nationalite_actif = true;
	bool affichage_par_actif = true;// false;
	bool affichage_soundtraks_actif = true;
	bool affichage_sous_genre_actif = true;

	bool netflix_ = true;
	bool netflix_sj_ = true;
	bool note_ = true;
	bool sur_ = false;
	bool sj_ = true;
	bool Titre_ = false;
	bool Titre_Original_ = false;

	std::wstring Titre_1 = L"";
	bool Titre_1_ = false;

	std::tm Date_1[_X_][_X_];
	std::wstring Date_1_t[_X_];

	std::wstring D[_X_];
	std::wstring D_t[_X_][_X_] = { L"" };
	int D_I = 0;
	int D_J[_X_] = { -1 };
	bool D_1_[_X_] = { false };
	std::wstring X[_X_];
	std::wstring X_T[_X_];
};

