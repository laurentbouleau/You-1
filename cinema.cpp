#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
//#define _CRT_NONSTDC_NO_WARNINGS
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
//#pragma warning(disable : 4996)
//#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "serie.h"
#include "cinema.h"
#include "console.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
#include <string>
#include <iostream>
#include <numeric>
//#include <sstream>
//#include <ctime>
#include <codecvt>
#include <vector>
/*#include <filesystem> // C++17 standard header file name
#include <experimental/filesystem> // Header file for pre-standard implementation

using namespace std;
using namespace std::experimental::filesystem::v1;*/

extern int X;

extern class Erreur E;
//extern class Bug B;
extern class Console console;

extern const int afficher_Avec(std::wstring&, std::wstring const&, std::vector<std::wstring>&, std::vector<std::wstring>&);

extern const std::vector<std::wstring> lire_fichierTxt(std::wstring const& nomFichier, std::vector<std::wstring> separeteurs);
extern const std::vector<std::pair<std::wstring, std::wstring>>lire_paireCleValeur_depuisFichierTxt(std::wstring const& nomFichier, std::wstring separeteur);
extern const std::wstring lire_fichierTxt(std::wstring const& nomFichier);

extern const void Console_Lire_txt(std::wstring);
extern const int Console_Lire_txt(std::wstring, int, int);

extern void PrintAudiodescription(const std::wstring& ad, bool ad_, std::wstring& titre_T, std::wstring& titre_t);
extern void PrintGenres(const std::vector<std::wstring>& genres, bool genre_, const std::wstring& sous_genre, bool sous_genre_, std::wstring& titre_T, std::wstring& titre_t);
extern void PrintImages(const std::vector<std::wstring>& images, bool image_, std::wstring& titre_T, std::wstring& titre_t, int x1, int y1, int x2, int y2);
extern void PrintNationalites(const std::vector<std::wstring>& nationalites, bool nationalite_, std::wstring& titre_T, std::wstring& titre_t);

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

Cinema::Cinema()
{
	std::vector<std::wstring>Titre{};
}

Cinema::~Cinema()
{
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_dossier                                                                                                                                   #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher_dossier(std::wstring const& t)
{
#if Cinema_afficher_dossier_ == true
	B.Ok_T(L"const int Cinema::afficher_dossier(" + t + L") :");
#endif
	int i = 0;
	std::wstring t2;
	std::size_t idx, idx2 = 0;
	idx = t.find(L".(", 0);
	t2 = t.substr(0, idx);
	i = ::afficher_Titre(t2, Titre, Titre_);
	idx = t.find_last_of(L"(");
	idx2 = t.find_last_of(L")");
	if (idx2 - idx - 1 == 0)
		return EXIT_FAILURE;
	idx2--;
	if (!(t.at(idx2) == L' ' || t.at(idx2) == L'-' ||
		t.at(idx2) == L'0' || t.at(idx2) == L'1' || t.at(idx2) == L'2' || t.at(idx2) == L'3' || t.at(idx2) == L'4' ||
		t.at(idx2) == L'5' || t.at(idx2) == L'6' || t.at(idx2) == L'7' || t.at(idx2) == L'8' || t.at(idx2) == L'9'))
	{ // Sur
		std::size_t idx3;
		idx3 = t.find_first_of(L" ", idx);
		idx3++;
		t2 = t.substr(idx3, idx2 - idx3 + 1);
		i = afficher_Sur(t2);
		if (sur == t2)
		{
			E.afficher_X(-1, L"Sur !", L"Érreur (" + t2 + L") !!!");
			return EXIT_FAILURE;
		}
		else
		{
			sur = t2;
			sur_ = true;
		}
		idx2 = idx3 - 2;
	}
	idx++;
	if (t.at(idx2) == L' ' || t.at(idx2) == L'-' ||
		t.at(idx2) == L'0' || t.at(idx2) == L'1' || t.at(idx2) == L'2' || t.at(idx2) == L'3' || t.at(idx2) == L'4' ||
		t.at(idx2) == L'5' || t.at(idx2) == L'6' || t.at(idx2) == L'7' || t.at(idx2) == L'8' || t.at(idx2) == L'9')
	{ // Date
		t2 = t.substr(idx, idx2 - idx + 1);
		i = afficher_Date(t2, t);
	}
	else
		return i;
	idx = t.find(L").");
	if (idx != std::wstring::npos)
	{ // Sous_Genre
		idx = idx + 2;
		sous_genre = t.substr(idx);
		//wstring sous_genre = L"";
		i = afficher_Sous_Genre(sous_genre);
		affichage_sous_genre_actif = true;
	}
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_fichier                                                                                                                                   #
// # const int Cinema::afficher_fichier(wstring const& _T, int const& _T_ = _TXT_)                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher_fichier(std::wstring const& nomFichier, int const& nomImage = TXT_)
{
	int i = 0;
	std::size_t pos;
	pos = nomFichier.find_last_of(L"\\");
	if (Ok == L"")
		Ok = nomFichier.substr(0, pos);
	pos++;
	std::wstring t = nomFichier.substr(pos);
	if (nomImage == TXT_)
	{
		if (std::isdigit(t[0]))
		{
			/*          0 1 2 3 4 5 6 7 8 9                   */
			// Date
			if ((t[0] == L'1' || t[0] == L'2' || t[0] == L'3'))
			{
				if (int j = std::stoi(t, 0) /*&& (t[4] == L'-' || t[4] == L'_')*/)
				{
					i = afficher_Date_1(t, nomFichier);
					return i;
				}
			}
			// Temps
			if (std::isdigit(t[0]) && !Temps_)
			{
				i = afficher_Temps(t, Temps);
				if (i == -1)
				{
					E.afficher_X(-1, t, L"Erreur {" + t + L"} !!!");
					return EXIT_FAILURE;
				}
				if (!Temps_)
				{
					Temps_ = true;
					return EXIT_SUCCESS;
				}
			}
		}
		/*          A B C D E F G H I J K L M N O P Q R S T U V W Y Z            */
		else
		{
			// AD : Audiodescription
			if (t == L"AD.txt")
			{
				afficher_Audiodescription(t, nomFichier, audiodescription);
				return EXIT_SUCCESS;
			}
			// Avec
			if (L"Avec.txt" == t && !Avec_ )
			{
				i = afficher_Avec(t, nomFichier, Avec, Avec_role);
				if (i == -1)
				{
					E.afficher_X(-1, t, L"Erreur {" + t + L"} !!!");
					return EXIT_FAILURE;
				}
				if (!Avec_)
				{
					Avec_ = true;
					return EXIT_SUCCESS;
				}
			}
			// Date de reprise
			if (t == L"Date de reprise.txt"/*Date_de_reprise_ == false*/ && &nomFichier)
			{
				//i = afficher_Date(t, nomFichier);
				afficher_Date_de_reprise(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Date de sortie
			if (Date_de_sortie_ == false && &nomFichier)
			{
				i = afficher_Date(t, nomFichier);
				if (Date_de_sortie_ == true && &nomFichier)
				{
					return EXIT_SUCCESS;
				}
			}
			// De
			if (t == L"De.txt")
			{
				afficher_De(t, nomFichier, de);
				return EXIT_SUCCESS;
			}
			// Distributeur
			if (t == L"Distributeur.txt")
			{
				afficher_Distributeur(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Genre
			if (t == L"Genre.txt")
			{
				afficher_Genre(t, nomFichier, genre, ::Genre);
				return EXIT_SUCCESS;
			}
			// Nationalité
			if (t == L"Nationalité.txt")
			{
				afficher_Nationalite(t, nomFichier, nationalite, ::Nationalite);
				return EXIT_SUCCESS;
			}
			// Netflix
			if (t == L"Netflix.txt")
			{
				afficher_Netflix_SJ(t, nomFichier, netflix_sj);
				return EXIT_SUCCESS;
			}
			// Note
			if (t == L"Note.txt")
			{
				afficher_Note(t, nomFichier);
				return EXIT_SUCCESS;
			}
			// Par
			if (t == L"Par.txt")
			{
				afficher_Par(t, nomFichier, par);
				return EXIT_SUCCESS;
			}
			// SJ
			if (t == L"SJ.txt")
			{
				afficher_SJ(t, nomFichier, sj);
				return EXIT_SUCCESS;
			}
			// Soundtrack
			if (t == L"Soundtrack.txt")
			{
				afficher_Soundtrack();
				return EXIT_SUCCESS;
			}
			// Titre
			if (L"Titre.txt" == t)
			{
				i = afficher_Titre(t, nomFichier);
				{
					Ok = t;
					return EXIT_SUCCESS;
				}
			}
			// Titre original
			if (L"Titre original.txt" == t)
			{
				i = afficher_Titre_Original(t, nomFichier, Titre_Original, Titre_Original_);
				{
					return EXIT_SUCCESS;
				}
			}
			// www.nautiljon.com
			if (t == L"www.nautiljon.com.txt")
			{
				return EXIT_SUCCESS;
			}
		}
	}
	else if (nomImage == JGP_ || nomImage == PNG_)
	{
		afficher_Image(nomFichier, image);
		return EXIT_SUCCESS;
	}
	else
	{
		E.afficher_X(-1, t, t + L" erreur (" + t + L") !!!");
		return EXIT_FAILURE;
	}
	E.afficher_X(-1, t, t + L" erreur (" + t + L") !!!");
	return EXIT_FAILURE;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Date                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher_Date(std::wstring& d, const std::wstring& nomFichier)
{ // Date
#if Cinema_afficher_Date_ == 1
	//wcout << B_T << L"const int Cinema::afficher_Date(" << d << L", " << _T << L") :" << B_t << endl;
	B.Ok_T(L"const int Cinema::afficher_Date(" + d + L", " + nomFichier + L") :");
#endif
	if (d == L"")
	{
#if Cinema_afficher_Date_
		B.Ok_W(L"date={}");
		B.Ok_T(L"const int Cinema::afficher_Date() : Ok !)");
#endif
		return EXIT_SUCCESS;
	}
	std::tm D;
	std::wstring d_;
	std::size_t pos = d.length();
	int i = 0;
	if (pos == 10 && &nomFichier)
		goto stop;
	if ((pos == 27 + 4) && &nomFichier)
	{
		d_ = d.substr(0, 17);
		if (d_ == L"Date de sortie - ")
		{
			d = d.substr(17);
			pos = d.length();
			d = d.substr(0, pos - 4);
			i = 1;
#if Cinema_afficher_Date_de_sortie_ == 1
			B.Ok_W(L"Date_de_sortie==" + d + L"==");
#endif
			goto stop;
		}
#if Cinema_afficher_Date_de_sortie_ == 1
		//wcout << B_T << L"const int Cinema::afficher_Date(" << d << L", " << _T << L") : Erreur !!!" << B_t << endl;
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
	/*else if ((pos == 28 + 4) && &nomFichier)
	{
		d_ = d.substr(0, 18);
		if (d_ == L"Date de reprise - ")
		{
			d = d.substr(18);
			pos = d.length();
			d = d.substr(0, pos - 4);
			i = 2;
#if Cinema_afficher_Date_de_reprise_ == 1
			B.Ok_W(L"Date_de_reprise==" + d + L"==");
#endif
			goto stop;
		}
		E.afficher_X(-1, nomFichier, d);
#if Cinema_afficher_Date_de_sortie_ == 1
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}*/
	else
	{
#if Cinema_afficher_Date_de_sortie_ == 1
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
stop:	//nYear, nMonth, nJour, nheure, nMin, nSec
	int year = 0, mon = 0, mday = 0;
	pos = 0;
	if (
		(d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
		(d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3' || d[1] == L'4' || d[1] == L'5' || d[1] == L'5' || d[1] == L'6' || d[1] == L'7' || d[1] == L'8' || d[1] == L'9') &&
		(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
		(d[3] == L'0' || d[3] == L'1' || d[3] == L'2' || d[3] == L'3' || d[3] == L'4' || d[3] == L'5' || d[3] == L'5' || d[3] == L'6' || d[3] == L'7' || d[3] == L'8' || d[3] == L'9')
		)
	{
		d_ = d.substr(0, 4);
		year = std::stoi(d, &pos);
		if (year <= 1900 || year >= 3001)
		{ // Erreur year
#if Cinema_afficher_Date_ == 1
			//wcerr << L"    " << L"year=" << year << endl;
			B.Ok_W(L"year=" + to_wstring(year));
#endif
			return EXIT_FAILURE;
		}
	}
	else
	{
#if Cinema_afficher_Date_ == 1
		//wcout << L"year=???" << endl;
		B.Ok_W(L"year=???");
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
	pos = d.find(L"-", 4);
	if (pos == std::wstring::npos)
	{
#if Cinema_afficher_Date_ == 1
		B.Ok_W(L"year=" + std::to_wstring(year));
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
	d_ = d.substr(5, 2);
	mon = std::stoi(d_, &pos);
	if (mon <= 0 || mon >= 13)
	{ // Erreur mon
#if Cinema_afficher_Date_ == 1
		B.Ok_W(L"mon=" + std::to_wstring(mon));
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
	if (pos == std::wstring::npos)
	{
		return 0;
	}
	d_ = d.substr(8, 2);
	mday = std::stoi(d_, &pos);
	if (mday <= 0 || mday >= 32)
	{ // Erreur mday
#if Cinema_afficher_Date_ == 1
		B.Ok_W(L"mday=" + std::to_wstring(mday));
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
	D.tm_year = year - 1900;
	D.tm_mon = mon - 1;
	D.tm_mday = mday;
#if Cinema_afficher_Date_ == 1
	std::wcerr << L"    " << D.tm_year << L"/" << D.tm_mon << L"/" << D.tm_mday << L"]" << std::endl;
#endif
	if (i == 0)
	{
		Date = D;
		Date_ = true;
	}
	else if (i == 1)
	{
		Date_de_sortie = D;
		Date_de_sortie_ = true;
	}
	else if (i == 2)
	{
		Date_de_reprise = D;
		Date_de_reprise_ = true;
	}
	else
	{
#if Cinema_afficher_Date_ == 1
		B.Ok_W(L"qqqqq");
		B.Ok_T(L"const int Cinema::afficher_Date() : Erreur !!!");
#endif
		return EXIT_FAILURE;
	}
#if Cinema_afficher_Date_ == 1
	B.Ok_T(L"const int Cinema::afficher_Date) : Ok !");
#endif
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_                                                                                                                             #
// # const int Cinema::afficher_(std::wstring& d_filename, std::wstring const& nomFichier)                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Cinema::afficher_Date_de_reprise(std::wstring& d_filename, std::wstring const& nomFichier)
{ // Distributeur
	std::wcout << L"Date_de_reprise" << std::endl;
	assert((d_filename == createdBy_filename) && L"Erreur !!! Date de reprise... !");
	std::wstring date = lire_fichierTxt(nomFichier);
	assert((date.size() != 0));

	std::tm D;
	int year = 0, mon = 0, mday = 0;
	std::size_t pos = 0;
	std::wstring d_;
	if (
		(date[0] == L'1' || date[0] == L'2' || date[0] == L'3') &&
		(std::isdigit(date[1])) &&
		(std::isdigit(date[2])) &&
		(std::isdigit(date[3]))
		)
	{
		d_ = date.substr(0, 4);
		year = std::stoi(date, &pos);
		if (year <= 1900 || year >= 3001)
		{ // Erreur year
			return;
		}
	}
	else
	{
		return;
	}
	pos = date.find(L"-", 4);
	if (pos == std::wstring::npos)
	{
		return;
	}
	d_ = date.substr(5, 2);
	mon = std::stoi(d_, &pos);
	if (mon <= 0 || mon >= 13)
	{ // Erreur mon
		return;
	}
	if (pos == std::wstring::npos)
	{
		return;
	}
	d_ = date.substr(8, 2);
	mday = std::stoi(d_, &pos);
	if (mday <= 0 || mday >= 32)
	{ // Erreur mday
		return;
	}
	D.tm_year = year - 1900;
	D.tm_mon = mon - 1;
	D.tm_mday = mday;

	std::wcout << L"\n\ndate=" << D.tm_year + 1900 << L'-' << D.tm_mon + 1 << L'-' << D.tm_mday << L"\n\n" << std::endl;
	//Date_de_reprise = D;
	date_de_reprise = D;

}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_De                                                                                                                                        #
// # void Cinema::afficher_De(std::wstring& d_filename, std::wstring const& nomFichier, std::vector<std::wstring>&de) const                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Cinema::afficher_De(std::wstring& d_filename, std::wstring const& nomFichier, std::vector<std::wstring>&de) const
{
	assert((d_filename == createdBy_filename) && L"Erreur !!! De... !");
	de = lire_fichierTxt(nomFichier, { L"\n", L", " });
	assert((de.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Distributeur                                                                                                                              #
// # const int Cinema::afficher_Distributeur(std::wstring& d_filename, std::wstring const& nomFichier)                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Cinema::afficher_Distributeur(std::wstring& d_filename, std::wstring const& nomFichier)
{ // Distributeur
	assert((d_filename == createdBy_filename) && L"Erreur !!! Distributeur... !");
	distributeur = lire_fichierTxt(nomFichier);
	assert((distributeur.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Par                                                                                                                                       #
// # void Cinema::afficher_Par(std::wstring& p_filename, std::wstring const& nomFichier, std::vector<std::wstring>& par) const                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Cinema::afficher_Par(std::wstring& p_filename, std::wstring const& nomFichier, std::vector<std::wstring>& par) const
{
	assert((p_filename == createdBy_filename) && L"Erreur !!! Par... !");
	par = lire_fichierTxt(nomFichier, { L"\n", L", " });
	assert((par.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Note                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Cinema::afficher_Note(std::wstring& n_filename, std::wstring const& nomFichier)
{ // 0...100 ou -100
    std::wstring n = lire_fichierTxt(nomFichier);
	std::size_t pos = n.length();
	if (n == L"")
	{
		note = -100;
		return;
	}
	if (pos != 1 && pos != 3)
	{
		E.afficher_X(-1, n, L"Pas de [a-z] et/ou [0-9] et/ou etc…");
		return;
	}
	if (!iswdigit(n[0]))
	{
		E.afficher_X(-1, n, L"Pas de [a-z] et/ou etc…");
		return;
	}
	if (!(n[0] == L'0' || n[0] == L'1' || n[0] == L'2' || n[0] == L'3' || n[0] == L'4' || n[0] == L'5'))
	{
		E.afficher_X(-1, n, L"Pas de [0-5]");
		return;
	}
	if (pos == 1)
		note = 20 * std::stoi(n);
	else
	{
		if ((n[1] == L',' || n[1] == L'.') && iswdigit(n[2]) && pos == 3)
		{
			n[1] = L',';
			float f = std::stof(n);
			// Ok !!!
			note = static_cast<int>(f * 20.0f);
		}
		else
		{
			E.afficher_X(-1, n, L"Pas de…");
			return;
		}
	}
	return;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Soundtrack                                                                                                                                         #
// # const int afficher_Soundtrack(wstring s, wstring _T)                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################

/*const int Cinema::afficher_Soundtrack(std::wstring& s, std::wstring const& nomFichier)
{
#if Cinema_afficher_Soundtrack_ == 1
	B.Ok_T(L"const int afficher_Soundtrack(" + s + L", " + nomFichier + L") :");
#endif
	std::size_t pos, pos2;
	pos = s.length();
	std::vector <wstring>::iterator iter, iter2;
	if (s == L"Soundtrack.txt")
	{
		try
		{
			s = lire_fichierTxt(nomFichier);
		}
		catch (runtime_error const& exception)
		{
			std::wcout << L"Erreur : " << exception.what() << std::endl;
		}
		if (!s.empty())
		{
			//if (pos = s.find(L", "))
			//	a = replace_all(a, L", ", L"\n");
			s += L"\n";
			while (pos = s.find(L"\n"))
			{
				if (s[0] != s.length())
				{
					pos2 = s.find(L" : ");
                    if (pos > pos2)
						// Soundtrack et Soundtrack_role
					{
						if (std::find(Soundtrack.begin(), Soundtrack.end(), s.substr(0, pos2)) != Soundtrack.end())
						{
							B.Ok_W(L"Soundtrack={" + s.substr(0, pos2) + L"}, Soundtrack_role={" + s.substr(pos2 + 3, pos - (pos2 + 3)) + L'}');
							Soundtrack.push_back(s.substr(0, pos2));
							Soundtrack_role.push_back(s.substr(pos2 + 3, pos - (pos2 + 3)));
							//G.push_back(g.substr(0, pos));
							//g = g.substr(pos + 1);
						}
						else
						{
							B.Ok_T(L"const int afficher_Soundtrack() : Attention !!!");
							return EXIT_FAILURE;
						}
					}
					else
					{
						// Rrrrrrrr !!! Pas de solution
						B.Ok_W(L"Soundtrack={" + s.substr(0, pos - 1) + L"}");
						return EXIT_FAILURE;
					}
					//
					s = s.substr(pos + 1);
				}
				else
					break;
			}
#if Cinema_afficher_Soundtrack_ == 1
			B.Ok_W(L"-- -- -- -- --");
			std::wstring wstr = L"Soundtrack et Soundtrack_role={";
			std::wstring& soundtrack = Soundtrack.back();
			for (int i = 0; i < Soundtrack.size(); i++)
			{
				wstr += Soundtrack[i] + L' ';
				wstr += L'(' + Soundtrack_role[i] + L')';
				if (Soundtrack[i] != soundtrack)
					wstr += L", ";
				else
					wstr += L'.';
			}
			B.Ok_W(wstr + L'}');
#endif
		}
		else
		{
#if Cinema_afficher_Soundtrack_ == 1
			B.Ok_W(L"Soundtrack={} nomFichier");
#endif
			return EXIT_SUCCESS;
		}
	}
	else
	{
#if Cinema_afficher_Soundtrack_ == 1
		B.Ok_W(L"Soundtrack={}, Pas de repons !!!");
#endif
		E.afficher_X(-1, L"Soundtrack={}", L"Pas de reponse !!!");
		return EXIT_FAILURE;
	}
#if Cinema_afficher_Soundtrack_ == 1
	B.Ok_T(L"const int afficher_Soundtrack() : Ok !");
#endif
	Soundtrack_ = true;
	return EXIT_SUCCESS;
}*/

// const int /*pas de valeur de retour car exceptions en C++ suffise => void*/
// Cinema::afficher_Soundtrack(
/*std::wstring& s, ce paramètre ne sert à rien sauf envoyer une erreur si c'est pas égale à "Soundtrack.txt" donc on dégage et on utilise une valeur en dur, qu'on rendra paramétrable plus tard, après refactoring*/
/*std::wstring const& nomFichier fait doublon avec le paramètre "s", on dégage)*/

void Cinema::afficher_Soundtrack()
{

	// utiliser les fonctions plus générique ("de plus bas niveau") pour avoir un code simple pour les fonction de plus "haut" niveau
	// Il y a peut-être un peu de customisation pour gérer les "rôles" mais rien d'insurmontable
	std::vector<std::pair<std::wstring, std::wstring>> clevaleurs = lire_paireCleValeur_depuisFichierTxt(L"Soundtrack.txt", L" : ");

	//Console::PrintStringW(Console::Ponctuation_Color + L"Soundtrack :" +  console.End_Ln + L"\r\n");
	Console::PrintStringW(L"Soundtrack :" + L"\r\n");

	for (const auto& [cle, valeur] : clevaleurs) {
		Console::affiche_CleValeur(L"\t" + cle, valeur);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Titre                                                                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher_Titre(std::wstring& t, std::wstring const& nomFichier)
{ // Titre_1
	if (Titre_1_)
		return EXIT_SUCCESS;
	wchar_t const* t_ = nomFichier.c_str();
	FILE* fichier = NULL;
	if ((fichier = _wfopen(t_, L"r")) == NULL) // C4996
	{ // Note: fopen is deprecated; consider using fopen_s instead
		E.afficher_X(-1, nomFichier, t_);
		return -1;
	}
	char phrase[255] = { u8"" };
	string titre_1 = u8"";
	while (!feof(fichier))
	{
		if (!(fgets(phrase, 255, fichier) == NULL))
			titre_1 += phrase;
	}
	fclose(fichier);
	wstring_convert<codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
	Titre_1 = convert.from_bytes(titre_1);
	Titre_1 += L'\n';
	std::vector<wstring> titre;
	std::wstring wstr = L"";
	std::size_t pos = 0;
	pos = Titre_1.find(L'\n');
	int y = 0;
	while (pos != std::wstring::npos)
	{
		titre.push_back(Titre_1.substr(0, pos));
		Titre_1 = Titre_1.substr(pos + 1);
		pos = Titre_1.find(L'\n');
		y++;
	}
	if (y == 1)
	{
		E.afficher_X(-1, nomFichier, t_);
		return EXIT_FAILURE;
	}
	//
	bool titre_, h_min_;
	titre_ = h_min_ = false;
	int i = 0;
	if (!titre_ && !h_min_ && i == 0)
	{
		h_min_ = ::afficher_Temps(titre[0]);
		if (!h_min_)
		{
			h_min_ = ::afficher_Temps(titre[1]);
			if (!h_min_)
				Titre.push_back(L""); // _h_min
			else
			{
				::afficher_Titre(titre[0], Titre);
				titre_ = true;
				Titre.push_back(titre[1]);
				h_min_ = ::afficher_Temps(titre[1]);
				if (!h_min_)
				{
					E.afficher_X(-1, titre[1], titre[1] + L" érreur (" + titre[1] + L") !!!");
					return EXIT_FAILURE;
				}
				pos = Titre[1].find(L' ');
				while (pos == std::wstring::npos)
				{
					titre[1] = titre[1].substr(0, pos - 1) + titre[1].substr(pos + 1);
					pos++;
				}
				Temps.tm_hour = std::stoi(titre[1]);
				Temps.tm_min = std::stoi(titre[1].substr(2));
				if (!Temps_)
					Temps_ = true;
				titre.erase(titre.begin());
				titre.erase(titre.begin());
				//wcout << L"aaa y=" << titre.size() << endl;
			}
		}
		else
		{
			Titre.push_back(titre[0]);
			Temps.tm_hour = stoi(titre[0]);
			Temps.tm_min = stoi(titre[0].substr(2));
			if (!Temps_)
				Temps_ = true;
			titre.erase(titre.begin());
			h_min_ = true;
		}
	}
	else
	{
		Titre.push_back(L""); // _h_min
	}
	for (int j = 0; j < y; j++)
	{
		//wcout << L"j=" << j << L" wstr=[" << wstr << L']' << endl;
		wstr += titre[j] + L'\n';
	}
	Titre.push_back(wstr);
	Titre_1_ = true;
	return EXIT_SUCCESS;
}

/////////////////
// //////////////


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Date_1                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher_Date_1(std::wstring& d, std::wstring const& nomFichier)
{
#if Cinema_afficher_Date_1_ == 1
	//wcout << B_T << L"const int Cinema::afficher_Date_1(" << d << L", " << nomFichier << L") :" << B_t << endl;
#endif
	if (d == L"")
	{
#if Cinema_afficher_Date_1_ == 1
		std::wcerr << L"    " << L"date=[???]" << std::endl;
		E.afficher_X(-1, nomFichier, L"Date=[???] erreur !!!");
#endif
		return -1;
	}
	std::size_t pos;
	pos = d.length();
	d = d.substr(0, pos - 4);



	std::wcout << L"aaaa" << std::endl;
	if (d[1] == L'h' && d[5] == L'm' && d[6] == L'i' && d[7] == L'n')
	{
		std::wcout << L"aaaaa" << std::endl;
		int i = ::afficher_Temps(d, Temps);
		if (i == -1)
			return -1;
		if (!Temps_)
		{
			Temps_ = true;
#if Cinema_afficher_Date_1_ == 1
			std::wcout << L"    " << L"Temps=[" << d << L"]" << std::endl;
#endif
			return 0;
		}
		return i;
	}
	std::wcout << L"bbbbb" << std::endl;



	if (pos < 10)
	{
#if Cinema_afficher_Date_1_ == 1
		std::wcerr << L"    " << L"Date={" << d << L"} erreur !!!" << std::endl;
#endif
		E.afficher_X(-1, nomFichier, L"Date={" + d + L"} erreur !!!");
		return -1;
	}
	int year[_X_] = { 0 }, month[_X_] = { 0 }, day[_X_] = { 0 };
	std::wstring d2 = L"";
	int w = 0;
	int i = 0, j = 0, k = 0;
	int J = 0;
	//int I = D_I;
#if Cinema_afficher_Date_1_ == 1
	std::wcout << L"    " << L"Date=[" << d << L"]" << std::endl;
#endif
	while (
		d[0] != std::wstring::npos &&
		!(d[0] == L'_' && (pos = d.length()) == 1) &&
		!(d[0] == L'_' && d[1] == L' ' && (pos = d.length()) > 2) &&
		!(d[0] == L' ')
		)
	{
		// year[i] + month[j] + day[k]
		if (
			(d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
			(std::isdigit(d[1])) &&
			(std::isdigit(d[2])) &&
			(std::isdigit(d[3])) &&
			(d[4] == L'-') &&
			(d[5] == L'0' || d[5] == L'1') &&
			(std::isdigit(d[6])) &&
			(d[7] == L'-') &&
			(d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
			(std::isdigit(d[9]))
			)
		{
			d2 = d.substr(0, 4);
			year[i] = std::stoi(d2, &pos);
			if (year[i] <= 1900 || year[i] >= 3001)
			{ // Erreur
#if Cinema_afficher_Date_1_ == 1
				std::wcerr << L"year[" << i << L"]=" << year[i] << L" erreur (1) !!!" << std::endl;
#endif
				E.afficher_X(i, nomFichier, L"year[" + std::to_wstring(i) + L"] = " + std::to_wstring(year[i]) + L" erreur (1) !!!");
				return -1;
			}
			d = d.substr(4);
			d = d.substr(1);
			d2 = d.substr(0, 2);
			month[j] = std::stoi(d2, &pos);
			if (month[j] <= 0 || month[j] >= 13)
			{ // Erreur
#if Cinema_afficher_Date_1_ == 1
				std::wcerr << L"    " << L"month[" << j << L"]=" << month[j] << L" erreur (1) !!!" << std::endl;
#endif
				E.afficher_X(i, nomFichier, L"month[" + std::to_wstring(j) + L"] = " + std::to_wstring(month[j]) + L" erreur (1) !!!");
				return -1;
			}
			d = d.substr(2);
			d = d.substr(1);
			d2 = d.substr(0, 2);
			day[k] = std::stoi(d2, &pos);
			if (day[k] <= 0 || day[k] >= 32)
			{ // Erreur
#if Cinema_afficher_Date_1_ == 1
				std::wcerr << L"    " << L"day[" << k << L"]=" << day[k] << L" erreur (1) !!!" << std::endl;
#endif
				E.afficher_X(i, nomFichier, L"day[" + std::to_wstring(k) + L"] = " + std::to_wstring(day[k]) + L" erreur (1) !!!");
				return -1;
			}
			d = d.substr(2);
			Date_1[D_I][J].tm_year = year[i] - 1900;
			Date_1[D_I][J].tm_mon = month[j] - 1;
			Date_1[D_I][J].tm_mday = day[k];
			J++;
			if ((pos = d.length()) == 0)
				goto stop;
			continue;
		}
		// month[j] + day[k]
		if (
			d[0] == L'_' &&
			(d[1] == L'0' || d[1] == L'1') &&
			//(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
			(std::isdigit(d[2])) &&
			d[3] == L'-' &&
			(d[4] == L'0' || d[4] == L'1' || d[4] == L'2' || d[4] == L'3') &&
			//(d[5] == L'0' || d[5] == L'1' || d[5] == L'2' || d[5] == L'3' || d[5] == L'4' || d[5] == L'5' || d[5] == L'6' || d[5] == L'7' || d[5] == L'8' || d[5] == L'9')
			(std::isdigit(d[5]))
			)
		{
			j++;
			k = 0;
			d = d.substr(1);
			d2 = d.substr(0, 2);
			month[j] = stoi(d2, &pos);
			if (month[j] <= 0 || month[j] >= 13)
			{ // Erreur
#if Cinema_afficher_Date_1_ == 1
				std::wcerr << L"    " << L"month[" << j << L"]=" << month[j] << L" erreur (2) !!!" << std::endl;
#endif
				E.afficher_X(i, nomFichier, L"month[" + std::to_wstring(j) + L"] = " + std::to_wstring(month[j]) + L" erreur (2) !!!");
				return -1;
			}
			d = d.substr(2);
			d = d.substr(1);
			d2 = d.substr(0, 2);
			day[k] = stoi(d2, &pos);
			if (day[k] <= 0 || day[k] >= 32)
			{ // Erreur
#if Cinema_afficher_Date_1_ == 1
				std::wcerr << L"    " << L"day[" << k << L"]=" << day[k] << L" erreur (2) !!!" << std::endl;
#endif
				std::wstring x = L"day[";
				x = x + (wchar_t)(k)+L"] = " + (wchar_t)(day[k]) + L" erreur (2) !!!";
				E.afficher_X(i, nomFichier, x);
				return -1;
			}
			d = d.substr(2);
			Date_1[D_I][J].tm_year = year[i] - 1900;
			Date_1[D_I][J].tm_mon = month[j] - 1;
			Date_1[D_I][J].tm_mday = day[k];
			J++;
			if ((pos = d.length()) == 0)
				goto stop;
			continue;
		}
		// '_'
		if (
			d[0] == L'_' &&
			(d[1] == L'1' || d[1] == L'2' || d[1] == L'3') &&
			//(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
			(std::isdigit(d[2])) &&
			//(d[3] == L'0' || d[3] == L'1' || d[3] == L'2' || d[3] == L'3' || d[3] == L'4' || d[3] == L'5' || d[3] == L'5' || d[3] == L'6' || d[3] == L'7' || d[3] == L'8' || d[3] == L'9') &&
			(std::isdigit(d[3])) &&
			//(d[4] == L'0' || d[4] == L'1' || d[4] == L'2' || d[4] == L'3' || d[4] == L'4' || d[4] == L'5' || d[4] == L'5' || d[4] == L'6' || d[4] == L'7' || d[4] == L'8' || d[4] == L'9')
			(std::isdigit(d[4]))
			)
		{
			i++;
			j = 0;
			k = 0;
			d = d.substr(1);
#if Cinema_afficher_Date_1_ == 1
			std::wcout << L"    " << L"Date !!!" << std::endl;
#endif
			continue;
		}
		// day[k]
		if (
			d[0] == L'_' &&
			(d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3') &&
			//(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9')
			(std::isdigit(d[2]))
			)
		{
			k++;
			d = d.substr(1);
			d2 = d.substr(0, 2);
			day[k] = stoi(d2, &pos);
			if (day[k] <= 0 || day[k] >= 32)
			{ // Erreur
#if Cinema_afficher_Date_1_ == 1
				std::wcerr << L"    " << L"day[" << k << L"]=" << day[k] << L" erreur (3) !!!" << std::endl;
#endif
				E.afficher_X(1, nomFichier, L"day[" + std::to_wstring(k) + L"] = " + std::to_wstring(day[k]) + L" erreur (3) !!!");
				return -1;
			}
			d = d.substr(2);
#if Cinema_afficher_Date_1_ == 1
			std::wcout << L"    " << L"day[" << k << L"]=" << day[k] << std::endl;
#endif
			Date_1[D_I][J].tm_year = year[i] - 1900;
			Date_1[D_I][J].tm_mon = month[j] - 1;
			Date_1[D_I][J].tm_mday = day[k];
			J++;
			if ((pos = d.length()) == 0)
				goto stop;
			//d = d.substr(1);
			continue;
		}
	}
	//afficher_X(0, _T, L"Cinema::afficher_Date_1() !!!");
	// Ok !
stop:
	if (d[0] == L'_')
	{
		//D_1_[D_I] = L'_';
		D_1_[D_I] = true;
		d = d.substr(1);
	}
	if (d[0] == L' ')
	{
		d = d.substr(1);
		Date_1_t[D_I] = d;
	}
	wchar_t date_string[15];
	D_J[D_I] = J - 1;
#if Cinema_afficher_Date_1_ == 1
	std::wcout << L"    " << L'(';
	for (i = 0; i < J; i++)
	{
		wcsftime(date_string, 15, L"%d/%m/%Y", &Date_1[D_I][i]);
		std::wcout << date_string;
		if (i < J - 1)
			std::wcout << L", ";
	}
	//if (D_1_[D_I] == L'_')
	if (D_1_[D_I] == true)
		std::wcout << L"(_)";
	if (w == 1)
		std::wcout << L' ' << Date_1_t[D_I];
	std::wcout << L')' << std::endl;
#else
	for (i = 0; i < J; i++)
		wcsftime(date_string, 15, L"%d/%m/%Y", &Date_1[D_I][i]);
#endif
#if Cinema_afficher_Date_1_ == 1
	std::wcout << L"    " << L"D_J[" << D_I << L"]=[" << J - 1 << L"]" << std::endl;
#endif
	D_I++;
#if Cinema_afficher_Date_1_ == 1
	//wcout << B_T << L"const int Cinema::afficher_Date_1() : Ok !" << B_t << endl;
#endif
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # pas de OK                                                                                                                                          #
// # const int Cinema::afficher_pas_de_OK()                                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher_pas_de_OK() const
{
#if Cinema_afficher_pas_de_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_pas_de_OK() :");
#endif
	if (!affichage_genres_actif)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Genre !!!");
#if Cinema_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Genre !!!");
#endif
	}
	if (!affichage_nationalite_actif)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Nationalité !!!");
#if Cinema_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Nationalité !!!");
#endif
	}
	// Note
	if (!note_)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Note !!!");
#if Cinema_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Note !!!");
#endif
	}
	// Titre
	if (!Titre_)
	{
		E.afficher_X(-1, L"Attention !", L"Erreur de Titre !!!");
#if Cinema_afficher_pas_de_OK_ == 1
		B.Ok_W(L"Attention : Erreur de Titre !!!");
#endif
	}
#if Cinema_afficher_pas_de_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_pas_de_OK() : Ok !");
#endif
	return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher                                                                                                                                           #
// # const int Cinema::afficher()                                                                                                                       #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::afficher()
{ // OK !
#if Cinema_afficher_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_OK() :");
#endif
	int i = 0, j, I;
	std::vector <wstring>::iterator iter;
	std::size_t pos = 0;
	std::wstring wstr;
	std::wstring Textes;
	wchar_t date_string[22];
	//
#if Cinema_afficher_OK_ == 1
	Console_Lire_txt(L"---------- ");
	if (Ok != L"Titre.txt")
		std::wcout << L"    " << C_T << L'{' << C_t << Ok << C_T << L'}' << C_t << std::endl;
	else
	{
		std::wcout << L"    " << C_T << L'{' << C_t << Titre[0];
		if (Titre[1] != L"")
		{
			std::wcout << C_T << Titre[1] << C_t;
			std::wcout << Titre[2];
		}
		std::wcout << C_T << L'}' << C_t << std::endl;
	}
#endif
	Console_Lire_txt(L"---------- ");
	if (Ok == L"")
	{
		if (E.Ok())
			Console_Lire_txt(L"---------- ");
		return -1;
	}
	// Titre
	bool titre_ = false;
	Textes = keyColor + L"Titre : " + valuesColor + Titre[0];
	if (Titre[2] != L"")
		Textes += keyColor + Titre[1] + valuesColor + Titre[2];
	if (Date_)
	{
		wcsftime(date_string, 15, L"%d/%m/%Y", &Date);
		wstr = date_string;
		Textes += L' ' + wstr.substr(0, 2) + keyColor + L'/' + valuesColor + wstr.substr(3, 2) + keyColor + L'/' + valuesColor + wstr.substr(6, 4);
	}
	// Sur
	if (sur_ )
		Textes += keyColor + L" (" + valuesColor + sur + keyColor + L')' + valuesColor;
	// En salle
	else
		Textes += keyColor + L" (" + valuesColor + L"en salle" + keyColor + L')' + valuesColor;
	// La signalétique jeunesse
	if (sj_ && sj.length() != 0)
		Textes += keyColor + L" (" + valuesColor + sj + keyColor + L')' + valuesColor;
	// Netflix SJ
	if (netflix_sj_ || netflix_sj.length() != 0)
		Textes += keyColor + L" [" + valuesColor + netflix_sj + keyColor + L']' + valuesColor;
	// Temps
	if (Temps_)
	{
		Textes += L' ';
		if (Temps.tm_hour != 0)
		{
			wstr = afficher_Temps_OK();
			Textes += wstr;
		}
	}
	// Note
	if (note_)
	{
		if (note == -100)
			Textes += L' ' + keyColor + L'(' + valuesColor + L"pas de note !" + keyColor + L')' + valuesColor;
		else
		{
			if (note == 0 || note == 20 || note == 40 || note == 60 || note == 80 || note == 100)
				Textes += L' ' + std::to_wstring((int)note / 20.0f);
			else
			{
				wstr = std::to_wstring(static_cast<float>(note / 20.0f));
				wstr = wstr[0] + keyColor + wstr[1] + valuesColor + wstr[2];
				Textes += L' ' + wstr;
			}
			Textes += keyColor + L"/5" + valuesColor;
		}
		Textes += std::to_wstring(note);
	}
	else
	{
		Textes += L' ' + keyColor + L'(' + valuesColor + L"pas de note !" + keyColor + L')' + valuesColor;
	}
	i = Console_Lire_txt(Textes, 0, 8);
	// Distributeur
	PrintDistributeur();
	// Date de reprise
	if (affichage_date_de_reprise_actif == false)
	{
		wcsftime(date_string, 18, L"%d/%m/%Y", &date_de_reprise);
		wstr = date_string;
		i = Console_Lire_txt(keyColor + L"Date de reprise : " + valuesColor + wstr.substr(0, 2) + keyColor + L'/' + valuesColor + wstr.substr(3, 2) + keyColor + L'/' + valuesColor + wstr.substr(6, 4), 0, 19);
	}
	//PrintDate_de_reprise(date_de_reprise, affichage_date_de_reprise_actif);
	
	// Date de sortie
	if (Date_de_sortie_ != 0)
	{
		wcsftime(date_string, 14, L"%d/%m/%Y", &Date_de_sortie);
		wstr = date_string;
		i = Console_Lire_txt(keyColor + L"Date de sortie : " + valuesColor + wstr.substr(0, 2) + keyColor + L'/' + valuesColor + wstr.substr(3, 2) + keyColor + L'/' + valuesColor + wstr.substr(6, 4), 0, 18);
	}
	// Titre original
	if (Titre_Original_)
	{
		//Titre_Original.begin();
		Textes = keyColor + L"Titre original : " + valuesColor + Titre_Original[0];
		if (Titre_Original[2] != L"")
		{
			Textes += keyColor + Titre_Original[1] + valuesColor;
			Textes += Titre_Original[2];
		}
		i = Console_Lire_txt(Textes, 0, 17);
	}
	// Audiodescription
	PrintAudiodescription(audiodescription, affichage_audiodescription_actif, keyColor, valuesColor);
	// Genre
	PrintGenres(genre, affichage_genres_actif, sous_genre, affichage_sous_genre_actif, keyColor, valuesColor);
	// De
	PrintDe();
	// Par
	PrintPar();
	// Avec
	if (Avec_)
	{
		Textes = keyColor + L"Avec : " + valuesColor;
		i = 0;
		for (iter = Avec.begin(); iter != Avec.end(); iter++)
		{
			Textes += *iter;
			if (i == 2)
				break;
			if (i < Avec.size() - 1)
				Textes += keyColor + L", " + valuesColor;
			i++;
		}
		i = Console_Lire_txt(Textes, 0, 7);
	}
	/*if (Avec_ == true)
	{
		Textes = C_T + L"Avec : " + C_t;
		j = 0;
		for (iter = Avec.begin(); iter != Avec.end(); iter++)
		{
			Textes += *iter;
			//if ((i > (2)) || *iter == L"…")
			//    break;
			if (j < Avec.size() - 1)
				Textes += C_T + L", " + C_t;
			j++;
		}
		i = Console_Lire_txt(Textes, 0, 7);
	}*/
	// Nationalité(s)
	PrintNationalites(nationalite, affichage_nationalite_actif, keyColor, valuesColor);
	// Image
	PrintImages(image, affichage_image_actif, keyColor, valuesColor, 0, 0, 0, 0);
	// Netflix ?
	if (sur_)
	{
		i = 0;
		wstr = L"";
		while (i < D_I)
		{
			if (Date_1_t[i].substr(0, 6) == L"Netflix")
			{
				netflix_ = true;
				break;
			}
			if (Date_1_t[i] != L"")
			{
				wstr = Date_1_t[i];
			}
			i++;
		}
		if (netflix_  || wstr == L"")
			i = Console_Lire_txt(keyColor + L"Netflix : " + valuesColor + L"Oui " + keyColor + L'!' + valuesColor, 0, 0);
	}
	//
	Console_Lire_txt(L"---------- ");
	if (Titre.size() == 5)
	{ // Titre[4]
		i = Console_Lire_txt(Titre[4], 4, 0);
		Console_Lire_txt(L"---------- ");
	}
	// Date_1
	I = 0;
	//wstr = L"";
//			size_t pos = 0;
//			int j;
	while (I < D_I)
	{
		Textes = L"";
		if (D_J[I] == 0)
		{
			wcsftime(date_string, 15, L"%d/%m/%Y", &Date_1[I][0]);
			wstr = date_string;
			Textes += L' ' + wstr.substr(0, 2) + keyColor2 + L'/' + valuesColor2 + wstr.substr(3, 2) + keyColor2 + L'/' + valuesColor2 + wstr.substr(6, 4);
			if (D_1_[I] == true)
				Textes += keyColor2 + L'(' + valuesColor2 + L'_' + keyColor2 + L')' + valuesColor2;
			if (Date_1_t[I] != L"")
				Textes += keyColor2 + L" : " + valuesColor2 + Date_1_t[I];
			j = Console_Lire_txt(Textes, 4, 4);
		}
		else if (D_J[I] > 0)
		{
			wstr = L"";
			pos = 0;
			std::wstring m[10] = { L"" };
			for (j = 0; j < D_J[I] + 1; j++)
			{
				wcsftime(date_string, 15, L"%d/%m/%Y", &Date_1[I][j]);
				std::wstring wstr2 = date_string;
				m[j] = wstr2.substr(0, 2) + keyColor2 + L'/' + valuesColor2 + wstr2.substr(3, 2) + keyColor2 + L'/' + valuesColor2 + wstr2.substr(6, 4);
			}
			std::wstring n = m[0];
			int o = 0, p = 0;
			for (j = 1; j < D_J[I] + 1; j++)
			{
				if (n == m[j])
				{
					m[j] = L'(' + std::to_wstring(o + 2) + L')';
					if (m[j - 1] == n && o == 0)
						m[j - 1] += L" (1)";
					o++;
				}
				else
				{
					n = m[j];
					o = 0;
				}
			}
			j = 1;
			p = 0;
			o = D_J[I] + 1;
			while (j < o)
			{
				if (m[j][2] == L')')
				{
					m[p] += m[j];
					m[j].clear();
				}
				else
					p++;
				j++;
			}
			j = 0;
			p = 0;
			std::wstring q[10] = { L"" };
			while (j < o)
			{
				if (m[j] != L"")
				{
					q[p] = m[j];
					p++;
				}
				j++;
			}
			o = p;
			p = 0;
			while (p < o)
			{
				pos = q[p].find_last_of(L")(");
				if (pos != std::wstring::npos)
				{
					q[p] = q[p].substr(0, pos - 2) + L" et " + q[p].substr(pos - 2);
					wstr += q[p];
				}
				else
					wstr += q[p];
				if (p < o - 2)
					wstr += L", ";
				else if (p < o - 1)
				{
					if (pos != std::wstring::npos)
					{
						wstr += L", ";
						pos = 0;
					}
					else
						wstr += L" et ";
				}
				p++;
			}
			if (pos = wstr.find(L" et "))
				wstr = replace_all(wstr, L" et ", keyColor2 + L" et " + valuesColor2);
			if (pos = wstr.find(L")("))
				wstr = replace_all(wstr, L")(", keyColor2 + L")(" + valuesColor2);
			if (pos = wstr.find(L"("))
				wstr = replace_all(wstr, L"(", keyColor2 + L"(" + valuesColor2);
			if (pos = wstr.find(L")"))
				wstr = replace_all(wstr, L")", keyColor2 + L")" + valuesColor2);
			if (pos = wstr.find(L", "))
				wstr = replace_all(wstr, L", ", keyColor2 + L", " + valuesColor2);
			Textes += wstr;
			if (Date_1_t[I] != L"")
				Textes += keyColor2 + L" : 111" + valuesColor2 + Date_1_t[I];
			i = Console_Lire_txt(Textes, 4, 8);
		}
		else
		{
			E.afficher_X(-1, L"D_I()", L"Cinema::afficher_OK() D_J erreur !!!");
			return -1;
		}
		I++;
	}
	if(I != 0)
        Console_Lire_txt(L"---------- ");
	// Avec et Avec_role
	if (Avec_ /* && Avec_role.size() != 0*/)
	{
		i = Console_Lire_txt(keyColor + L"Avec :" + valuesColor, 0, 0);
		Textes = L"";
		/*for (iter = Avec_role.begin(); iter != Avec_role.end(); iter++)
		{
			wstr = *iter;
			pos = wstr.find(L" : ");
			if (pos != 0)
				Textes += wstr.substr(0, pos) + C_W + L" (" + C_w + wstr.substr(pos + 3);
			else if (pos == wstring::npos)
				Textes += *iter;
			else
				Textes += C_W + L" (" + C_w + wstr.substr(2);
			if (*iter != Avec_role.back())
			{
				if (pos == wstring::npos)
					Textes += C_W + L", " + C_w;
				else
					Textes += C_W + L"), " + C_w;
			}
			else
			{
				if (pos == wstring::npos)
					Textes += C_T + L'.' + C_t;
				else
					Textes += C_W + L')' + C_w + C_T + L'.' + C_t;
			}
		}*/

		std::wstring& avec = Avec.back();
		//if (avec == L"…")
		//    Z = Avec.size() - 1;
		//else
		//    Z = Avec.size();


		for (j = 0; j < Avec.size(); j++)
		{
			if (Avec[j] == avec && (avec == L"…" || avec == L"..." || avec == L".") && Avec_role[j] == L"")
			{
				Textes += avec;
				break;
			}
			if(Avec[j] != L"" && Avec_role[j] != L"")
				Textes += Avec[j] + L' ' + keyColor2 + L'(' + valuesColor2 + Avec_role[j] + keyColor2 + L')' + valuesColor2;
			else if (Avec[j] == L"")
				Textes += keyColor2 + L'(' + valuesColor2 + Avec_role[j] + keyColor2 + L')' + valuesColor2;
			else
				Textes += Avec[j];
			if (Avec[j] != Avec.back())
				Textes += keyColor + L", " + valuesColor;
			else
				Textes += keyColor + L'.' + valuesColor;
		}


		i = Console_Lire_txt(Textes, 4, 0);
	}
	// Soundtrack et Soundtrack_role
	/*if (Soundtrack_ && Soundtrack.size() != 0)
	{
		i = Console_Lire_txt(keyColor + L"Soundtrack :" + valuesColor, 0, 0); // Oui, je sais !
		wstr = L"";
		wstr = Soundtrack[0];
		std::wcout << L'{' << wstr << L'}' << std::endl;
		std::wcout << L"Length=" << wstr.length() << std::endl;
		std::size_t kk = 0;
		pos = 0;
		for (iter = Soundtrack.begin(); iter != Soundtrack.end(); iter++);
		{
			std::wcout << L"qqqq" << std::endl;
			wstr = *iter;
			//wcout << L"qqqq 2" << endl;
			//wcout << L"wstr={" << wstr << L'}' << endl;
			//wcout << L"qqqq 3" << endl;
			//kk = (*iter).length();
			//wcout << L"kk=" << kk << endl;
			//wcout << L"qqqq 4" << endl;
			//if (kk > pos)
			//{
			//	pos = kk;
			//	wcout << L"Soundtrack={" << *iter << L'}' << L"pos=" << pos << endl;
			//}
		}
		std::wcout << L"pos=" << pos << std::endl;
	    Textes = L"";
		wstr = L"";
		for (i = 0; i < Soundtrack.size(); i++)
		{
			Textes += keyColor2 + Soundtrack[i] + L" : " + valuesColor2;
			wstr = L' ' * (int)(pos - Soundtrack[i].length());
			//if (wstr == L"")
			//	;
			//else
			//    Textes += wstr;
			Textes += Soundtrack_role[i] + L'\n';
		}
		i = Console_Lire_txt(Textes, 4, 0);
	}*/
	PrintSoundtracks(soundtraks);
	if(Avec_ /*|| Soundtrack_*/)
	    Console_Lire_txt(L"---------- ");
	//

    // ???
	i = E.Ok();


#if Cinema_afficher_OK_ == 1
	B.Ok_T(L"const int Cinema::afficher_OK() : Ok !");
#endif
	return EXIT_SUCCESS;
}

/*		pos = 0;
		for (iter = Soundtrack.begin(); iter != Soundtrack.end(); iter++)
		{
			wstr = *iter;
			if (wstr.length() > pos)
				pos = wstr.length();
		}
*/

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Temps_OK                                                                                                                                  #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const wstring Cinema::afficher_Temps_OK()
{ // h:mm
#if Cinema_afficher_Temps_OK_ == 1
#endif
	wchar_t date_string[22];
	wcsftime(date_string, 20, L"%H:%M", &Temps);
	std::wstring t = date_string;
	std::size_t pos = t.find(L':');
	std::wstring h = t.substr(1, pos - 1);
	std::wstring m = t.substr(pos + 1);
	std::wstring wstr = h;
	if (C_Espace1)
		wstr += L' ';
	wstr += keyColor + C_H + valuesColor;
	if (C_Espace2)
		wstr += L' ';
	wstr += m;
	if (C_Espace3)
		wstr += L' ';
	if (C_MIN != L"")
		wstr += keyColor + C_MIN + valuesColor;
#if Cinema_afficher_Temps_OK_ == 1
#endif
	return wstr;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// #                                                                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Cinema::Ok_C(bool P_C_Espace1, wchar_t P_C_H, bool P_C_Espace2, bool P_C_Espace3, std::wstring P_C_MIN, std::wstring P_C_T, std::wstring P_C_t, std::wstring P_C_W, std::wstring P_C_w)
{
	C_Espace1 = P_C_Espace1;
	C_H = P_C_H;
	C_Espace2 = P_C_Espace2;
	C_Espace3 = P_C_Espace3;
	C_MIN = P_C_MIN;
	keyColor = P_C_T;
	valuesColor = P_C_t;
	keyColor2 = P_C_W;
	valuesColor2 = P_C_w;
	return 0;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintPrintDate_de_reprise                                                                                                                          #
// # const void Cinema::PrintDistributeur()                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################
	/*if (affichage_date_de_reprise_actif == true)
	{
		wcsftime(date_string, 18, L"%d/%m/%Y", &date_de_reprise);
		wstr = date_string;
		i = Console_Lire_txt(keyColor + L"Date de reprise : " + valuesColor + wstr.substr(0, 2) + keyColor + L'/' + valuesColor + wstr.substr(3, 2) + keyColor + L'/' + valuesColor + wstr.substr(6, 4), 0, 19);
	}*/

const void Cinema::PrintDate_de_reprise(const std::tm& date_de_reprise, bool affichage_date_de_reprise_actif)
{
	if (affichage_date_de_reprise_actif && date_de_reprise.tm_year !=0)
	{
		wchar_t date_string[22];
		wcsftime(date_string, 18, L"%d/%m/%Y", &Date_de_reprise);
		std::wstring wstr = date_string;
		//std::wstring date_str;// = date_string;
		std::wstring date_str = keyColor + L"Date de reprise : " + valuesColor + wstr.substr(0, 2) + keyColor + L'/' + valuesColor + wstr.substr(3, 2) + keyColor + L'/' + valuesColor + wstr.substr(6, 4);
		int i = Console_Lire_txt(date_str, 0, 19);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDe                                                                                                                                            #
// # const void Cinema::PrintDe()                                                                                                                       #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Cinema::PrintDe()
{
	if (affichage_de_actif && de.size() > 0)
	{
		std::wstring de_str = keyColor + L"De" + ((de.size() > 1) ? L"s" : L"") + L" : " + valuesColor;
		bool first = true;
		for (auto&& d : de)
		{
			if (!first)
			{
				de_str += keyColor + L", " + valuesColor;
			}
			de_str += d;
			first = false;
		}
		de_str += L"\r\n";

		Console::PrintStringW(Console::hOut, de_str);
		//int i = Console_Lire_txt(de_str, 0, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintDistributeur                                                                                                                                  #
// # const void Cinema::PrintDistributeur()                                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Cinema::PrintDistributeur()
{
	if (affichage_distributeur_actif && distributeur.size() > 0)
	{
		std::wstring distributeur_str = keyColor + L"Distributeur : " + valuesColor + distributeur + L"\r\n";
		Console::PrintStringW(Console::hOut, distributeur_str);
		//int i = Console_Lire_txt(distributeur_str, 0, 0);
	}
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintPar                                                                                                                                           #
// # const void Cinema::PrintPar()                                                                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Cinema::PrintPar()
{
	if (affichage_par_actif && par.size() > 0)
	{
		std::wstring par_str = keyColor + L"Par : " + valuesColor;
		bool first = true;
		for (auto&& p : par)
		{
			if (!first)
			{
				par_str += keyColor + L", " + valuesColor;
			}
			par_str += p;
			first = false;
		}
		par_str += L"\r\n";

		Console::PrintStringW(Console::hOut, par_str);
		//int i = Console_Lire_txt(par_str, 0, 0);
	}
}


void Cinema::PrintSoundtracks(const std::vector<std::pair<std::wstring, std::wstring>>& soundtraks)
{
	// à l'arrache, faudrait dégager ces C_x à la con et utiliser des noms de constante CORRECTES
	if (affichage_soundtraks_actif && soundtraks.size() > 0)
	{
		Console::PrintStringW(Console::hOut, keyColor + L"Soundtrack :" + valuesColor + L"\r\n");
		// Soundtrack
		for (auto&& [role, nom] : soundtraks)
		{
			Console::PrintStringW(Console::hOut, keyColor2 + role + L" : " + valuesColor2, 4); //Utilisation d'une version de PrintStringW où l'on ne spécifie que le décalage en x et les C_G/C_g pour "green" (t=>turquoise ? , w=>White?)
			Console::PrintStringW(Console::hOut, nom + L"\r\n");
		}
	}
}