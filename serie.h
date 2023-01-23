#pragma once

// serie
#define Serie_afficher_dossier_          1
#define Serie_afficher_fichier_          1
#define Serie_afficher_fichier_2_        1
#define Serie_afficher_AD_               0
//#define Serie_afficher_Avec_             0
#define Serie_afficher_Avec_2_           1
#define Serie_afficher_Chaine_           1
#define Serie_afficher_Chaine_1_         1
#define Serie_afficher_Creee_par_        1       
#define Serie_afficher_Date_             1
#define Serie_afficher_Diffusee_         0
#define Serie_afficher_En_relation_avec_ 0
#define Serie_afficher_Image_            0
#define Serie_afficher_Image_1_          0
#define Serie_afficher_Note_             1
#define Serie_afficher_t123_temps_       0
#define Serie_afficher_Titre_            1
#define Serie_afficher_Titre_1_          0       
#define Serie_afficher_Titre_2_          0
#define Serie_afficher_Titre_3_          0
#define Serie_afficher_Titre_min_        0
#define Serie_afficher_Titre_Original_   0

#define Serie_afficher_X_x_              0

#define Serie_afficher_pas_de_OK_        1
#define Serie_afficher_OK_               1
#define Serie_afficher_OK_Note_          0
#define Serie_afficher_OK_Temps_         0
//#define Serie_afficher_Temps_OK_

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "cinema.h"
#include "console.h"
#//include "series.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
//#include <xstring>
#include <string>
//#include <algorithm>
#include <vector>
#include <iostream>
//#include <sstream>
//#include <ctime>
//#include <corecrt_wstring.h>
#include <codecvt>
#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

//extern Avec2 avec;

extern class Erreur E;

extern const std::vector<std::wstring> Genre;
extern const std::vector<std::wstring> Sur;
extern const std::vector<std::wstring> Sous_Genre;
extern const std::vector<std::wstring> Nationalite;

class Titre;
//class Console;
class Serie
{
	friend class Titre;
public:
	Serie(void);
	~Serie();

	const int afficher_dossier(std::wstring const& t);
	const int afficher_fichier(std::wstring const& t, int const& _T_);
	const int afficher_fichier(int I, std::wstring const& t, int const& _T_);
	const int afficher_Avec_2(int I, std::wstring& a, std::wstring const& nomFichier);
	void afficher_Chaine(std::wstring&, std::wstring const&, std::wstring&) const;
	void afficher_Creee_par(std::wstring&, std::wstring const&, std::vector<std::wstring>&) const;
	const int afficher_Date(std::wstring d);
	const int afficher_Diffusee(int& I, std::wstring const& d);
	void afficher_En_relation_avec(std::wstring& e, std::wstring const& nomFichier, std::vector<std::wstring>&e_r_a) const;
	const int afficher_Note(std::wstring&, std::wstring const&, int&, bool&);
	const int afficher_t123_temps(std::vector<std::wstring>&, std::wstring&, std::wstring&, std::wstring&);
	const int afficher_Titre(std::wstring& t, std::wstring const& _TnomFichier);

	const int afficher_pas_de_OK() const;
	const int afficher(void);
	const int Ok_S(bool S_Espace, std::wstring S_MIN, std::wstring S_T, std::wstring S_t, std::wstring S_W, std::wstring S_w);

protected:
	//std::wstring ad;// = L"";
	//bool ad_ = true;

private:
	const int afficher_Titre_2(int I, std::wstring t, std::wstring nomFichier);
	const int afficher_Titre_3(int I, std::wstring t, std::wstring nomFichier);
	const int afficher_X_x(int I, int J, std::wstring const& nomFichier, std::wstring& t);

	const std::wstring afficher_OK_Note();
	const int afficher_OK_T(std::vector <std::wstring>&, std::wstring&, int y0, int y1, int y2);
	const std::wstring afficher_OK_Temps(std::wstring& v, std::wstring& S, std::wstring& s);
	const std::wstring afficher_OK_Temps(std::tm& t, std::wstring &S, std::wstring &s);

	const void PrintChaine();
	const void PrintCreee_par();
	const void PrintEn_relation_avec();

	std::wstring Ok = L"";
	std::wstring Titre__;// = L"";

	bool S_Espace; // = false ou true;
	std::wstring S_MIN; // = L"min";
	std::wstring keyColor;
	std::wstring valuesColor;
	std::wstring keyColor2;
	std::wstring valueColor2;

	std::vector<std::wstring> Titre{};
	std::vector<std::wstring> Titre_Original{};
	std::wstring chaine{};
	std::tm Temps{ 0 };
	std::vector<std::wstring> genre;
	std::vector<std::wstring> creee_par;
	std::vector<std::wstring> Avec;
	std::vector<std::wstring> Avec_role;
	//int Avec_i = 0;
	std::vector<std::wstring> nationalite;
	std::wstring sur = L"";
	std::wstring sous_genre{};
	std::wstring netflix_sj;
	std::wstring sj = L"";
	
	std::wstring audiodescription = L"";
	
	std::vector<std::wstring> en_relation_avec;
	float Note = 0.0;
	std::vector<std::wstring> image;

	bool Titre_ = false;
	bool Titre_Original_ = false;
	bool Date_ = false, Temps_ = false;
	
	bool affichage_audiodescription_actif = true;
	bool affichage_chaine_actif = true;
	bool affichage_creee_par_actif = true;
	bool affichage_en_relation_avec_actif = true;
	bool affichage_image_actif = true;
	bool affichage_genres_actif = true;
	bool affichage_nationalite_actif = true;
	bool affichage_sous_genre_actif = false;

	bool Avec_ = false;
	bool sur_ = false;
	bool netflix_ = false;
	bool netflix_sj_ = true;
	bool sj_ = true;


	bool Note_ = false;
	bool Date_Diffusee_a_partir_de_[_X2_] = { true };
	bool X_ = false;

	std::wstring Titre_1 = L"";
	bool Titre_1_ = false;

	std::tm Date_X[_X2_][_X_ * 4][_x_] = { 0 };
	std::tm Date_Diffusee_a_partir_de[_X2_] = { 0 };

	std::wstring D[_X2_] = { L"" };
	std::wstring D_Titre[_X2_] = { L"" };
	std::vector<std::wstring> D_titre[_X2_];// = { L"" };
	std::vector<std::wstring> D_t[_X2_][_X_ * 4];// = { L"" };
	//wstring D_s[_X2_][_X_ * 4] = { L"" };
	std::vector<std::wstring> D_Avec_role[_X2_];// = { L"" };
	std::wstring d_chaine[_X2_] = { L"" };
	std::vector<std::wstring> d_image[_X2_];
	int D_Note[_X2_] = { -1 };
	
	int D_I = { 0 };
	int D_J[_X2_] = { 0 };
	int D_K[_X2_][_X_ * 4] = { -1 };
	//wchar_t D_K_[_X2_][_X_ * 4] = { L' ' };
	bool D_K_[_X2_][_X_ * 4] = { false };
	int D_K_d[_X2_][_X_ * 4] = { 0 };

	//bool D_Netflix[_X2_] = { false };
	bool D_DVD[_X2_] = { false };
	bool d_chaine_[_X2_] = { true };
	bool d_affichage_image_actif[_X2_] = { true };
	bool D_Note_[_X2_] = { true };
	bool D_Titre_[_X2_] = { false };

	std::vector<Episode>;
};

// ######################################################################################################################################################
// ######################################################################################################################################################
// ######################################################################################################################################################
// ######################################################################################################################################################
// ######################################################################################################################################################

class Episode
{
	std::wstring m_episode;
};

