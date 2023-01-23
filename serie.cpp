//#pragma warning(disable : 4834)
#include "pch.h"

// Audio : Français [VO]
// Sous-titres : Français [CC]

#include "Utils.h"
#include "titre.h"
#include "You.h"
//#include "you_txt.h"
#include "cinema.h"
#include "serie.h"
#include "console.h"
#include "erreur_ok.h"

#include <windows.h>
#include <cassert>
//#include <xstring>
#include <string>
//#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
//#include <sstream>
//#include <ctime>
//#include <corecrt_wstring.h>
#include <codecvt>

//extern int X;

extern class Erreur E;
//extern class Bug B;
//extern class Console console;

//extern const class Titre;

//extern tm;
//extern const int afficher_AD(std::wstring& a, std::wstring& ad, std::wstring const& nomFichier);

//extern int Titre::afficher_AD(std::wstring& a, std::wstring& ad, std::wstring const& nomFichier);

extern const int afficher_Avec(std::wstring&, std::wstring const&, std::vector<std::wstring>&, std::vector<std::wstring>&);

extern const void afficher_Audiodescription(std::wstring& a, std::wstring const& nomFichier, std::wstring& audiodescription);
extern const void afficher_Genre(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);
extern const void afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images);
extern const void afficher_Nationalite(std::wstring&, std::wstring const&, std::vector<std::wstring>&, const std::vector<std::wstring>&);

extern const void afficher_SJ(std::wstring&, const std::wstring&, std::wstring&);
extern const int afficher_T123(std::wstring t, std::wstring& t1, std::wstring& t2, std::wstring& t3);
extern const int afficher_Temps(std::wstring, tm&);
extern const bool afficher_Temps(std::wstring);
extern const void afficher_Temps(std::tm&);
extern const void afficher_Temps_OK(std::wstring&, bool);
extern const std::vector<std::wstring> afficher_Titre_Original(std::wstring, std::wstring);

extern const void Console_Lire_txt(std::wstring);
extern const int Console_Lire_txt(std::wstring, int, int);

extern std::wstring replace_all(std::wstring subject, const std::wstring& search, const std::wstring& replace);

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

extern const std::vector<std::wstring> AD;
//extern const wchar_t X;

//extern wstring utf8_to_wstring(string& str);
//extern const Titre titre;// C_S;
//const class Titre;

Serie::Serie()
{
    std::vector<std::wstring>Titre{};
}

Serie::~Serie()
{
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_dossier                                                                                                                                   #
// # const int Serie::afficher_dossier(wstring const& t)                                                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_dossier(std::wstring const& t)
{
    if (Titre_ == false)
    {
        int i = 0;
        int tm_year = 0, tm_mon = 0, tm_mday = 0;
        std::wstring date = L"";
        std::wstring t2;
        std::size_t idx, idx2 = 0;
        idx = t.find(L".[", 0);
        t2 = t.substr(0, idx);
        i = ::afficher_Titre(t2, Titre, Titre_);
        Titre__ = t2;
        idx = t.find_last_of(L"[");
        idx2 = t.find_last_of(L"]");
        if (idx2 - idx - 1 == 0)
            return -1;
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
                E.afficher_X(-1, L"Pas de Sur={" + t2 + L"} !!!", L"Érreur (" + t2 + L") !!!");
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
            i = afficher_Date(t2);
        }
        idx = t.find(L"].");
        if (idx != std::wstring::npos)
        { // Sous_Genre
            idx += 2;
            sous_genre = t.substr(idx);
            //wstring sous_genre = L"";
            i = afficher_Sous_Genre(sous_genre);
            affichage_sous_genre_actif = true;
        }
        D_I = 0;
    }
    else
    {
        std::size_t pos;
        pos = t.length();
        pos--;
        std::wstring t2 = t.substr(0, pos);
        pos = t2.find_last_of(L"\\");
        t2 = t2.substr(++pos);
        D[D_I] = t;
        //
        if (
            (t2[4] == L'-' && t2[7] == L'-' /*&& pos == 11*/  /* && t[11] == wstring::npos*/)
            ||
            (t2[4] == std::wstring::npos)
            ||
            t2 == L"Nouveau dossier"
            )
            // XXXX-XX-XX ou xxxx ou "Nouveau dossier"
        {
            int i = afficher_Diffusee(D_I, t2);
            if (Date_Diffusee_a_partir_de_[D_I] == true)
            {
                //return 0;
            }
        }
        else
        {
            E.afficher_X(-1, t2, t + L" erreur !!!");
            return EXIT_FAILURE;
        }
        //D_J[_X2_]
        //wcout << L"*****" << endl;
        D_J[D_I] = 0;
        D_I++;
    }
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_fichier                                                                                                                                   #
// # const int Serie::afficher_fichier(std::wstring const& nomFichier, int const& nomImage = TXT_)                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_fichier(std::wstring const& nomFichier, int const& nomImage = TXT_)
{	
    int i = 0;
    std::size_t pos;
    std::vector <wstring>::iterator iter;
    //::S_Nationalite;
    pos = nomFichier.find_last_of(L"\\");
    if (Ok == L"")
        Ok = nomFichier.substr(0, pos);
    pos++;
    std::wstring t = nomFichier.substr(pos);
    //if((t == (Titre__ + L".txt")) /* || L"Titre.txt"*/)
    //{
    //    wcout << L"rrrr" << endl;
    //    i = afficher_Titre(t, _T);
        /*if (t == L"Titre.txt")
        {
            wcout << L"www t={" << t << L"} : ok !" << endl;
            Ok = t;
        }*/
        //i ::
//#if Serie_afficher_1_ == 1
        //wcout << B_T << L"const int Serie::afficher(1)() : Ok !" << B_t << endl;
//        B.Ok_T(L"const int Serie::afficher() : Ok !");
//#endif
//        return EXIT_SUCCESS;
//    }
 //   else 
    if (nomImage == TXT_)
    {
        if (std::isdigit(t[0]))
        {
            /*          0 1 2 3 4 5 6 7 8 9                   */
            if (int j = std::stoi(t, 0))
            {
                std::wstring t_ = std::to_wstring(j);
                if (t == t_)
                {
                    return EXIT_SUCCESS;
                }
            }
            // Temps
            if (std::isdigit(t[0]) && Temps_ == false)
            {
                i = /*::*/afficher_Temps(t, Temps);
                if (i == -1)
                    goto ok;
                if (Temps_ == false)
                {
                    if (Temps.tm_min > 60 && Temps.tm_min < 120 && Temps.tm_hour == 0)
                    {
                        ::afficher_Temps(Temps);
                    }
                    Temps_ = true;
                    return EXIT_SUCCESS;
                }
            }
        }
        else
        /*          A B C D E F G  H I J K L M N O P Q R S T U V W Y Z            */
        {
            // AD
            if (t == L"AD.txt")
            {
                afficher_Audiodescription(t, nomFichier, audiodescription);
                return EXIT_SUCCESS;
            }
            // Avec
            if (L"Avec.txt" == t && Avec_ == false)
            {
                i = ::afficher_Avec(t, nomFichier, Avec, Avec_role);
                if (i == -1)
                {
                    E.afficher_X(-1, nomFichier, t + L"Avec={} : Erreur !!!");
                    return EXIT_FAILURE;
                }
                //Avec_ = 1;
                if (Avec_ == false)
                {
                    Avec_ = true;
                    return EXIT_SUCCESS;
                }
            }
            // Netflix
            if (t == L"Netflix.txt")
            {
                afficher_Netflix_SJ(t, nomFichier, netflix_sj);
                return EXIT_SUCCESS;
            }
            // Chaîne d'origine
            if (t == L"Chaîne d'origine.txt")
            {
                afficher_Chaine(t, nomFichier, chaine);
                return EXIT_SUCCESS;
            }
            // Créée par
            if (L"Créée par.txt" == t)
            {
                afficher_Creee_par(t, nomFichier, creee_par);
                return EXIT_SUCCESS;
            }
            // En relation avec
            if (L"En relation avec.txt" == t)
            {
                afficher_En_relation_avec(t, nomFichier, en_relation_avec);
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
#if Cinema_afficher_fichier_ == 1
                B.Ok_W(L"netflix={" + netflix_sj + L'}');
                B.Ok_T(L"const int Cinema::afficher_fichier() : Ok !");
#endif
                return EXIT_SUCCESS;
            }
            // SJ
            if (t == L"SJ.txt")
            {
                afficher_SJ(t, nomFichier, sj);
                return EXIT_SUCCESS;
            }
            // Titre
            if ((L"Titre.txt" == t)
                && Titre_ == true)
            {
                i = afficher_Titre(t, nomFichier);
                {
                    Ok = t;
                    return EXIT_SUCCESS;
                }
            }
            // Titre original
            if ((L"Titre original.txt" == t || L"Titre original - " == t.substr(0, 17))
                && Titre_Original_ == false)
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
        //i = afficher_Image(nomFichier, image);
        //afficher_Image(const std::wstring& nomFichier, std::vector<std::wstring>& images);




        ::afficher_Image(nomFichier, image);



        return EXIT_SUCCESS;
    }
    else
    {
    std::wcout << L"qqq qqq qqq" << std::endl;
        return EXIT_FAILURE;
    }
ok:
    if (t == L"Note.txt")
    {
        E.afficher_X(-2, nomFichier, L"Erreur !!!", L"Note.txt ---> XXXX-XX-XX !");
    }
    else
    {
        std::wcout << L"sss sss sss" << std::endl;
        E.afficher_X(-1, nomFichier, L"Erreur {" + t + L"} !!!");
    }
    //	wcout << L"qqqqqqqqqqq" << endl;
    return EXIT_FAILURE;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_fichie                                                                                                                                    #
// # const int Serie::afficher_fichier(int I, wstring const& _T, int const& _T_ = _TXT_)                                                                #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_fichier(int I, std::wstring const& nomFichier, int const& nomImage = TXT_)
{
    int i = 0;
    std::size_t pos;
    pos = nomFichier.find_last_of(L"\\");
    pos++;
    std::wstring t = nomFichier.substr(pos);
    pos = t.length();
    std::wstring filename = t;
    t = t.substr(0, pos - 4);
    pos = pos - 4;
    //wcout << L"bbbbbbb [" << t << L']' << endl;
    if (!(std::isdigit(t[0])))
    {
        // Avec
        if (filename == L"Avec.txt")
        {
            i = afficher_Avec_2(I, filename, nomFichier);
            return i;
        }
        // Chaîne d'origine -
        if (filename == L"Chaîne d'origine.txt")
        {
            //afficher_chaine(I, filename, nomFichier, D_Chaine[I]);
            afficher_Chaine(filename, nomFichier, d_chaine[I]);
            return EXIT_SUCCESS;
        }
        // DVD
        if (filename == L"DVD.txt")
        {
            D_DVD[I] = true;
            return EXIT_SUCCESS;
        }
        // Netflix
        /*if (t == L"Netflix")
        {
#if Serie_afficher_2_ == 1
            wcout << L"    " << L"Netflix ok" << endl;
#endif
            D_Netflix[I] = true;
#if Serie_afficher_2_ == 1
            wcout << B_T << L"const int Serie::afficher(" << I << L", " << _T << L", " << _T_ << L") : Ok !" << B_t << endl;
#endif
            return 0;
        }*/
        // Note
        if (filename == L"Note.txt" && D_Note_[I] == false)
        {
            i = afficher_Note(t, nomFichier, D_Note[I], D_Note_[I]);
            if (i == -1)
            {
                E.afficher_X(-1, L"Erreur", L"Note : " + t + L" !");
                if (Note_ == false)
                    return EXIT_FAILURE;
            }
            D_Note_[I] = true;
            return EXIT_SUCCESS;
        }
        // Titre
        if (filename == L"Titre.txt")
        {
            i = afficher_Titre_3(I, filename, nomFichier);
            if (i == -1)
            {
                E.afficher_X(-1, L"Erreur", L"Titre : " + filename + L" !");
                return EXIT_FAILURE;
            }
            D_Titre_[I] = true;
            return EXIT_SUCCESS;
        }
        // Image
        if (nomImage == JGP_ || nomImage == PNG_)
        {
            //d_image[I]
            //i = afficher_Image(I, nomFichier);
            ::afficher_Image(nomFichier, d_image[I]);

            return EXIT_SUCCESS;
        }
        // Erreur !
        if (t != L"")
        {
            E.afficher_X(-1, nomFichier, L'{' + t + L".txt} !!!");
            return EXIT_FAILURE;
        }
    }
    else
    {
        //
        if (
            (t[0] == L'1' || t[0] == L'2' || t[0] == L'3' || t[0] == L'4' || t[0] == L'5' || t[0] == L'6' || t[0] == L'7' || t[0] == L'8' || t[0] == L'9')
            && t[1] == L'x'
            )
        {
            t = t.substr(2);
            //#if Series_afficher_2_ == 1
            //		wcout << L"j=[" << 1 << L"] t=[" << t << L"]" << endl;
            //#endif
            i = afficher_X_x(I, D_J[I], nomFichier, t);
            if (i == 0)
            {
                D_J[I]++;
                return EXIT_SUCCESS;
            }
            else
            {
                E.afficher_X(-1, nomFichier, L'[' + t + L".txt] !!!");
                return EXIT_FAILURE;
            }
        }
        if (
            (t[0] == L'1' || t[0] == L'2' || t[0] == L'3' || t[0] == L'4' || t[0] == L'5' || t[0] == L'6' || t[0] == L'7' || t[0] == L'8' || t[0] == L'9')
            &&
            (std::isdigit(t[1]))
            && t[2] == L'x'
            )
        {
            t = t.substr(3);
            i = afficher_X_x(I, D_J[I], nomFichier, t);
            if (i == 0)
            {
                D_J[I]++;
                return EXIT_SUCCESS;
            }
            else
            {
                E.afficher_X(-1, nomFichier, L'[' + t + L".txt] !!!");
                return EXIT_FAILURE;
            }
        }
        if (int j = std::stoi(t, 0))
        {
            //wstring t2 
            std::wstring t_ = std::to_wstring(j);
            if (t == t_)
            {
                i = afficher_Titre_2(I, t, nomFichier);
                //afficher_X(0, _T, t + L" ok !" + t2);
                return EXIT_SUCCESS;
            }
            else
            {
                E.afficher_X(-1, nomFichier, L'[' + t + L".txt] !!!");
                return EXIT_FAILURE;
            }
        }
    }
    // Image
    if (t != L"" && filename != L"")
    {
        if(t != L"")
            E.afficher_X(-1, nomFichier, L"{" + t + L"} !!!");
        if (t != L"")
            E.afficher_X(-1, nomFichier, L"{" + filename + L" (filename)} !!!");
        return EXIT_FAILURE;
    }
    //afficher_X(-1, _T, t + L" !!!");
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Avec_2                                                                                                                                    #
// # const int Serie::afficher_Avec_2(int I, wstring a, wstring _T)                                                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Avec_2(int I, std::wstring& filename, std::wstring const& nomFichier)
{
    if (filename != L"Avec.txt")
    {
        E.afficher_X(1, nomFichier, filename);
        return EXIT_FAILURE;
    }
    //wstring p = ::afficher_fichier_lire(a, _T);
    std::wstring p;
    try
    {
        p = lire_fichierTxt(nomFichier);
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }

    if (!p.empty())
    {
        p = p + L"\n";
        std::size_t pos;
        while (pos = p.find(L"\n"))
        {
            if (p[0] != p.length())
            {
                D_Avec_role[I].push_back(p.substr(0, pos));
                p = p.substr(pos + 1);
            }
            else
                break;
        }
#if Serie_afficher_Avec_2_ == 1
        //wcout << L"Avec_role[" << I << L"]=(";
        std::wstring wstr = L"Avec_role[" + std::to_wstring(I) + L"]={";
        std::vector <std::wstring>::iterator iter;
        int i;
        for (iter = D_Avec_role[I].begin(), i = 0; iter != D_Avec_role[I].end(); iter++, i++)
        {
            //wcout << *iter;
            wstr += *iter;
            if (i != D_Avec_role[I].size() - 1)
                //wcout << L", ";
                wstr += L", ";
        }
        //wcout << L')' << endl;
#endif
    }
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_Chaine                                                                                                                                    #
// # const void Serie::afficher_chaine(std::wstring c_filename, std::wstring const& nomFichier, std::wstring& chaine) const                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Serie::afficher_Chaine(std::wstring& c_filename, std::wstring const& nomFichier, std::wstring& chaine) const
{ // Chaîne
    assert((c_filename == createdBy_filename) && L"Erreur !!! Chaîne d'origine... !");
    chaine = lire_fichierTxt(nomFichier);
    assert((chaine.size() != 0));
}


// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Creee_par                                                                                                                                          #
// # void Serie::afficher_Creee_par(std::wstring& c_filename, std::wstring const& nomFichier, std::vector<std::wstring>&c_p) const                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Serie::afficher_Creee_par(std::wstring& c_filename, std::wstring const& nomFichier, std::vector<std::wstring>& c_p) const
{
    assert((c_filename == createdBy_filename) && L"Erreur !!! Créée par... !");
    c_p = lire_fichierTxt(nomFichier, { L"\n", L", " });
    assert((c_p.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Date                                                                                                                                               #
// # const int Serie::afficher_Date(wstring d)                                                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Date(std::wstring d)
{ // Date(s)
    if (Date_ == true)
    {
        return EXIT_FAILURE;
    }
    std::wstring s_ = L"";
    std::size_t idx = 0;
    int year;
    std::wstring d_[_X_];
    int i = 0;
    while (d.length() != 0)
    {
        //year = 0;
        //idx = 0;
        if (
            //(d[0] == L'0' || d[0] == L'1' || d[0] == L'2' || d[0] == L'3' || d[0] == L'4' || d[0] == L'5' || d[0] == L'5' || d[0] == L'6' || d[0] == L'7' || d[0] == L'8' || d[0] == L'9') &&
            std::isdigit(d[0]) &&
            //(d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3' || d[1] == L'4' || d[1] == L'5' || d[1] == L'5' || d[1] == L'6' || d[1] == L'7' || d[1] == L'8' || d[1] == L'9') &&
            std::isdigit(d[1]) &&
            //(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
            isdigit(d[2]) &&
            //(d[3] == L'0' || d[3] == L'1' || d[3] == L'2' || d[3] == L'3' || d[3] == L'4' || d[3] == L'5' || d[3] == L'5' || d[3] == L'6' || d[3] == L'7' || d[3] == L'8' || d[3] == L'9')
            std::isdigit(d[3])
            )
        {
            d_[i] = d.substr(0, 4);
            year = std::stoi(d_[i], &idx, 10);
            i++;
            d = d.substr(4);
            //continue;
        }
        if (d[0] == L'-')
        {
            d = d.substr(1);
            //continue;
            /*if (d[0] == L' ')
            {
                wcout << endl;
            }*/
        }
        if (d[0] == L' ')
        {
            d = d.substr(1);
            //break;
        }
    }
    //wcout << L"]" << endl;
    int j = i;
#if Serie_afficher_Date_ == 1
    //wcout << L"Date=[";
    std::wstring wstr = L"Date={";
    for (i = 0; i < j; i++)
    {
        //wcout << d_[i];
        wstr += d_[i];
        if (i != j - 1)
            //wcout << L' ';
            wstr += L' ';
    }
    //wcout << L"]" << endl;
#endif
    Date_ = true;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Diffusee                                                                                                                                           #
// # const int Serie::afficher_Diffusee(int I, wstring d)                                                                                               #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Diffusee(int& I, std::wstring const& d)
{
    if (d == L"")
    {
        return EXIT_SUCCESS;
    }
    if (
        (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
        std::isdigit(d[1]) &&
        std::isdigit(d[2]) &&
        std::isdigit(d[3]))
    {
        goto stop;
    }
    E.afficher_X(-1, L"", d);
    return EXIT_FAILURE;
stop:
    int year = 0, mon = 0, mday = 0;
    // %d/%m/%Y
    std::tm D = { 0 };
    // year
    std::wstring x = d.substr(0, 4);
    year = std::stoi(x);
    if (
        (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
        //(d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3' || d[1] == L'4' || d[1] == L'5' || d[1] == L'5' || d[1] == L'6' || d[1] == L'7' || d[1] == L'8' || d[1] == L'9') &&
        //(d[2] == L'0' || d[2] == L'1' || d[2] == L'2' || d[2] == L'3' || d[2] == L'4' || d[2] == L'5' || d[2] == L'5' || d[2] == L'6' || d[2] == L'7' || d[2] == L'8' || d[2] == L'9') &&
        //(d[3] == L'0' || d[3] == L'1' || d[3] == L'2' || d[3] == L'3' || d[3] == L'4' || d[3] == L'5' || d[3] == L'5' || d[3] == L'6' || d[3] == L'7' || d[3] == L'8' || d[3] == L'9')
        std::isdigit(d[1]) &&
        std::isdigit(d[2]) &&
        std::isdigit(d[3])
        )
    {
        x = d.substr(0, 4);
        year = std::stoi(d);
        if (year <= 1900 || year >= 3001)
        { // Erreur year
            return EXIT_FAILURE;
        }
    }
    else
    {
        return EXIT_FAILURE;
    }
    if (
        (d[5] == L'0' || d[5] == L'1') &&
        //(d[6] == L'0' || d[6] == L'1' || d[6] == L'2' || d[6] == L'3' || d[6] == L'4' || d[6] == L'5' || d[6] == L'6' || d[6] == L'7' || d[6] == L'8' || d[6] == L'9')
        std::isdigit(d[6])
        )
    {
        x = d.substr(5, 2);
        mon = std::stoi(x);
        if (mon <= 0 || mon >= 13)
        { // Erreur mon
            return EXIT_FAILURE;
        }
    }
    if (
        (d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
        //(d[9] == L'0' || d[9] == L'1' || d[9] == L'2' || d[9] == L'3' || d[9] == L'4' || d[9] == L'5' || d[9] == L'6' || d[9] == L'7' || d[9] == L'8' || d[9] == L'9')
        std::isdigit(d[9])
        )
    {
        x = d.substr(8, 2);
        mday = std::stoi(x);
        if (mday <= 0 || mday >= 32)
        { // Erreur mday
            return EXIT_FAILURE;
        }
    }
    D.tm_year = year - 1900;
    D.tm_mon = mon - 1;
    D.tm_mday = mday;
    Date_Diffusee_a_partir_de[I] = D;
    Date_Diffusee_a_partir_de_[I] = true;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # En relation avec                                                                                                                                   #
// # const int Serie::afficher_En_relation_avec(std::wstring& e_filename, std::wstring const& nomFichier, std::vector<std::wstring>&e_r_a) const        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

void Serie::afficher_En_relation_avec(std::wstring& e_filename, std::wstring const& nomFichier, std::vector<std::wstring>&e_r_a) const
{
    assert((e_filename == createdBy_filename) && L"Erreur !!! En relation avec... !");
    e_r_a = lire_fichierTxt(nomFichier, { L"\n", L", " });
    assert((en_relation_avec.size() != 0));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Note                                                                                                                                               #
// # const int Serie::afficher_Note(wstring n, wstring _T, int& note, bool& note_)                                                                      #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Note(std::wstring& n_filename, std::wstring const& nomFichier, int& note, bool& note_)
{ // 0...100 ou -100
    assert((n_filename == createdBy_filename) && L"Erreur !!! Note... !");
    std::wstring n = lire_fichierTxt(nomFichier);
    std::size_t pos = n.length();
    if (n == L"")
    {
        note = -100;
        return EXIT_SUCCESS;
    }
    if (pos != 1 && pos != 3)
    {
        E.afficher_X(-1, n, L"Pas de [a-z] et/ou [0-9] et/ou etc…");
        return EXIT_FAILURE;
    }
    if (!iswdigit(n[0]))
    {
        E.afficher_X(-1, n, L"Pas de [a-z] et/ou etc…");
        return EXIT_FAILURE;
    }
    if (!(n[0] == L'0' || n[0] == L'1' || n[0] == L'2' || n[0] == L'3' || n[0] == L'4' || n[0] == L'5'))
    {
        E.afficher_X(-1, n, L"Pas de [0-5]");
        return EXIT_FAILURE;
    }
    if (pos == 1)
    {
        note = 20 * std::stoi(n);
    }
    else
    {
        if ((n[1] == L',' || n[1] == L'.') && iswdigit(n[2]) && pos == 3)
        {
            n[1] = L',';
            float f = std::stof(n, 0);
            // Ok !!!
            //note = (int)floor(f * 20.0);
            //note = (int)floor(f * 20);
            //note = static_cast<int>(f * 20.0f);
            note = static_cast<int>(f * 20.0f);
        }
        else
        {
            E.afficher_X(-1, n, L"Pas de…");
        }
    }
    note_ = true;
    if (Note_ == false)
        Note_ = true;
    return EXIT_SUCCESS;
}

const std::wstring Serie::afficherNote()
{
    double note = std::accumulate(m_episode.begin(), m_episode.end(), 0.0) / m_episode.size();
    PrintTmp(std::to_wstring(note));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # t123 temps                                                                                                                                         #
// # const int Serie::afficher_t123_temps(vector<wstring>& t, wstring& p, wstring& tt, wstring& _T)                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_t123_temps(std::vector<std::wstring>& t, std::wstring& p, std::wstring& tt, std::wstring& nomFichier)
{
    if (p == L"")
    {
        if(tt != L"")
            t.push_back(tt);  // tt
        else
            t.push_back(L"");  // tt={}
        t.push_back(L""); // t1
        t.push_back(L""); // t2
        t.push_back(L""); // t3
        t.push_back(L""); // temps
        t.push_back(L""); // p
        return EXIT_SUCCESS;
    }
    std::size_t pos = 0;
    std::wstring t1, t2, t3, temps;
    t1 = t2 = t3 = temps = L"";
    std::wstring v;
    bool t123_ = false, temps_ = false;
    p += L'\n';
    //
    pos = p.find(L'\n');
    v = p.substr(0, pos);
    //
    //wcout << L"v={" << v << L'}' << endl;
    //
    temps_ = afficher_Temps(v);
    if (temps_ == false)
    {
        int i = afficher_T123(v, t1, t2 = L"", t3 = L"");
        if (i == -1)
            E.afficher_X(0, L"t123_ == false", L"érreur (" + tt + L") !!!");
        else
        {
            p = p.substr(pos + 1);
            pos = p.find(L'\n');
            v = p.substr(0, pos);
            temps_ = ::afficher_Temps(v);
            if (temps_ == false)
            {
                E.afficher_X(0, L"temps={false}", L"érreur (" + tt + L") !!!");
            }
            else
            {
                temps = v;
                p = p.substr(pos + 1);
            }
        }
    }
    else
    {
        int i = afficher_T123(tt, t1, t2 = L"", t3 = L"");
        temps_ = afficher_Temps(v);
        if (temps_ == false)
        {
            E.afficher_X(0, L"temps=", L"érreur (" + v + L") !!!");
        }
        else
        {
            temps = v;
            p = p.substr(pos + 1);
        }       
    }
    //
    if (tt == L"" && t1 != L"")
    {
        tt = t1 + t2 + t3;
        std::wcout << L"tt == t1" << std::endl;
    }
    pos = p.length();
    p = p.substr(0, p.length() - 1);
    t.push_back(tt);
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);
    t.push_back(temps);
    t.push_back(p);
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Titre                                                                                                                                              #
// # const int Serie::afficher_Titre(wstring t, wstring _T)                                                                                             #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Titre(std::wstring& t, std::wstring const& nomFichier)
{ // Titre_1
    //if (Titre_1_ == true)
    //    return 0;

    //wstring t_
    if (Titre.begin() == Titre.end())
    {
#if Serie_afficher_Titre_ == 1
        //int i;
        //wcout << L"    " << B_W << L"const int Serie::afficher_Titre(" << t << L", " << _T << L") : erreur !!!" << B_w << endl;
        //wstring wstr;
        //wstr = B_W;
        //wstr += L"const int Serie::afficher_Titre(";
        //i = ::Console_Lire_txt(t + L", " + _T + L") :" + B_w, 0, 0, Y);
#endif
        E.afficher_X(-1, t, L"Titre.begin() == Titre.end()");
        return EXIT_FAILURE;
    }
    //Titre_1 = ::afficher_fichier_lire(t, _T);
    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.
        Titre_1 = lire_fichierTxt(nomFichier);
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (runtime_error const& exception)
    {
        // On affiche la cause de l'exception.
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    Titre_1 += L'\n';
    //
    std::vector<std::wstring> titre;
    std::wstring wstr = L"";
    std::size_t pos = 0;
    pos = Titre_1.find(L'\n');
    int y = 0;
    while (pos != std::wstring::npos)
    {
        //wcout << L"y=" << y << L" titre[" << y << L"] = [" << Titre_1.substr(0, pos) << L']' << endl;
        titre.push_back(Titre_1.substr(0, pos));
        Titre_1 = Titre_1.substr(pos + 1);
        pos = Titre_1.find(L'\n');
        y++;
    }
    // Titre[0] + Titre[1] + Titre[2]
    if (Titre_ == true && (Titre[1] == L" : " || Titre[1] == L": " || Titre[1] == L"/" || Titre[1] == L""))
    {
        //wcout << L"iiiiii" << endl;
        if (titre[0] == (Titre[0] + Titre[1] + Titre[2] + L"\n"))
        {
            bool titre_ = false;
            //wcout << L"xxxxxxx" << endl;
            pos = titre[0].find(L" : ");
            if (pos != wstring::npos && titre_ == false)
            {
                Titre[0] = titre[0].substr(0, pos);
                Titre[1] = L" : ";
                Titre[2] = t.substr(pos + 3, t.length());
                titre_ = true;
            }
            pos = titre[0].find(L": ");
            if (pos != wstring::npos && titre_ == false)
            {
                Titre[0] = titre[0].substr(0, pos);
                Titre[1] = L": ";
                Titre[2] = t.substr(pos + 2, t.length());
                titre_ = true;
            }
            pos = titre[0].find(L"/");
            if (pos != wstring::npos && titre_ == false)
            {
                Titre[0] = titre[0].substr(0, pos);
                Titre[1] = L": ";
                Titre[2] = t.substr(pos + 1, t.length());
                titre_ = true;
            }
            else
            {
                Titre[0] = titre[0];
                Titre[1] = L"";
                Titre[2] = L"";
                titre_ = true;
            }
            if (titre_ == false)
            {
                E.afficher_X(-1, t, L"Titre_={false} !!!");
                return EXIT_FAILURE;
            }
        }
    }
    else
    {
        E.afficher_X(-1, nomFichier, t);
        return EXIT_FAILURE;
    }
    //
    //wcout << L"ooooooo" << endl;
    if (y == 1)
    {
        //wcout << L"    " << B_W << L"const int Series::afficher_Titre(" << t << L", " << _T << L") : érreur !!!" << B_w << endl;
        E.afficher_X(-1, nomFichier, t);
        return EXIT_FAILURE;
    }
    //
    bool titre_, min_;
    titre_ = min_ = false;
    int i = 0;
    if (titre_ == false && min_ == false && i == 0)
    {
        //wcout << L"azertyuiop" << endl;
        min_ = ::afficher_Temps(titre[0]);
        if (min_ == false)
        {
            min_ = ::afficher_Temps(titre[1]);
            if (min_ == false)
                Titre.push_back(L""); // _h_min
            else
            {
                ::afficher_Titre(titre[0], Titre);
                //i = ::afficher_Titre(wstring t, vector<wstring>&titre, bool& titre_);
                titre_ = true;
                Titre.push_back(titre[1]);
                min_ = ::afficher_Temps(titre[1]);
                if (min_ == false)
                {
                    E.afficher_X(-1, titre[1], titre[1] + L" erreur (" + titre[1] + L") !!!");
                    return -1;
                }
                pos = titre[1].find(L' ');
                while (pos == wstring::npos)
                {
                    titre[1] = titre[1].substr(0, pos - 1) + titre[1].substr(pos + 1);
                    pos++;
                }
                //Temps.tm_hour = stoi(titre[1]);
                //Temps.tm_min = stoi(titre[1].substr(2));
                Temps.tm_min = std::stoi(titre[1]);
                //wcout << L"eee" << endl;
                if (Temps_ == false)
                    Temps_ = true;
                titre.erase(titre.begin());
                titre.erase(titre.begin());
                //wcout << L"aaa y=" << titre.size() << endl;
            }
        }
        else
        {
            //wcout << L"qsdfghjklm" << endl;
            Titre.push_back(titre[0]);
            //Temps.tm_hour = stoi(titre[0]);
            //Temps.tm_min = stoi(titre[0].substr(2));
            Temps.tm_min = stoi(titre[0]);
            if (Temps_ == false)
                Temps_ = true;
            titre.erase(titre.begin());
            min_ = true;
        }
    }
    else
    {
        Titre.push_back(L""); // _min
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

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Titre                                                                                                                                              #
// # const int Serie::afficher_Titre_2(int I, wstring t, wstring _T)                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Titre_2(int I, std::wstring t, std::wstring nomFichier)
{
    D_titre[I].push_back(t);
    //std::wstring t2 = ::afficher_fichier_lire(t, _T);
    std::wstring t2;
    try
    {
        t2 = lire_fichierTxt(nomFichier);
    }
    catch (runtime_error const& exception)
    {
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    if (t2 == L"")
        ;
    else
    {
        std::size_t pos = 0;
        if (t2[0] == L'[')
        {
            pos = t2.find(L']');
            D_titre[I].push_back(t2.substr(1, pos - 1));
            t2 = t2.substr(pos + 1);
            while (t2[0] == L'\n' || t2[0] == L'\t' || t2[0] == L' ')
                t2 = t2.substr(1);
        }
        D_titre[I].push_back(t2);
    }
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Titre                                                                                                                                              #
// # const int Serie::afficher_Titre_3(int I, wstring t, wstring _T)                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_Titre_3(int I, std::wstring filename, std::wstring nomFichier)
{
    //D_Titre[I] = afficher_fichier_lire(t, nomFichier);
    D_Titre[I] = lire_fichierTxt(nomFichier);
    if (D_Titre[I] == L"")
    {
        E.afficher_X(0, nomFichier, filename);
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_X_x                                                                                                                                       #
// # const int Serie::afficher_X_x(int I, int J, wstring _T, wstring d)                                                                                 #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_X_x(int I, int J, std::wstring const& nomFichier, std::wstring& d)
{
    ///wcout << L'[' << d << L']' << endl;
    std::size_t pos = 0;
    pos = d.find(L'.');
    D_K_d[I][J] = std::stoi(d, &pos);
    //assert(d.substr(pos + 1) == L"");
    d = d.substr(pos + 1);
    bool texte_ = true;
    std::wstring tt = L"";
    if (texte_ == true &&
        (d[0] == L'1' || d[0] == L'2' || d[0] == L'3') &&
        (std::isdigit(d[1])) &&
        (std::isdigit(d[2])) &&
        (std::isdigit(d[3])) &&
        (d[4] == L'-') &&
        (d[5] == L'0' || d[5] == L'1') &&
        (std::isdigit(d[6])) &&
        (d[7] == L'-') &&
        (d[8] == L'0' || d[8] == L'1' || d[8] == L'2' || d[8] == L'3') &&
        (std::isdigit(d[9])) /* &&
        (d[10] == wstring::npos || d[10] == L'_')*/
        )
    {
        texte_ = false;
        //wcout << L"texte_ = false" << endl;
    }
    if (texte_ == true)
    {
        pos = d.find(L'.');
        tt = d.substr(0, pos);
        pos = d.find(L'.');
        d = d.substr(pos + 1);

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
            // ???
            /* &&
            (d[10] == wstring::npos || d[10] == L'_')*/
            )
        {
        }
        else
        {
            E.afficher_X(-1, nomFichier, L"Erreur de date !");
            return EXIT_FAILURE;
        }
    }
    //wcout << L"tt={" << tt << L"}, d={" << d << L"}" << endl;
    //wstring p = ::afficher_fichier_lire(_T, _T);
    std::wstring p;
    try
    {
        // Dans le try, on est assuré que toute exception levée
        // pourra être traitée dans le bloc catch situé après.
        p = lire_fichierTxt(nomFichier);
    }
    // Notez qu'une exception s'attrape par référence constante.
    catch (runtime_error const& exception)
    {
        // On affiche la cause de l'exception.
        std::wcout << L"Erreur : " << exception.what() << std::endl;
    }
    std::vector<std::wstring> titre;
    std::wstring titre_ = nomFichier;
    if (texte_ == false)
    {
        pos = p.find(L'\n');
        tt = p.substr(0, pos);
        //wcout << L"bbb texte_ = false, pp={" << tt << L"}" << endl;        pos = d.find(L'.');
    }
    //
    int i = afficher_t123_temps(titre, p, tt, titre_); // titre[6] = 7
    //wcout << L"www d={" << d << L"}" << endl;
    //
    if (i == -1)
    {
        E.afficher_X(-1, nomFichier, titre_);
        return EXIT_FAILURE;
    }
    D_t[I][J] = titre;
    //
    int year[_x_] = { 0 }, month[_x_] = { 0 }, day[_x_] = { 0 };
    std::wstring d2 = L"";
    int w = 0;
    int j = 0, k = 0;
    int K = 0;
    while (
        d[0] != std::wstring::npos &&
        !(d[0] == L'_' && (pos = d.length()) == 1) &&
        !(d[0] == L'_' && d[1] == L' ' && (pos = d.length()) > 2) &&
        !(d[0] == L' ')
        )
    {
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
            year[i] = stoi(d2, &pos);
            if (year[i] <= 1900 || year[i] >= 3001)
            { // Erreur
                E.afficher_X(i, nomFichier, L"year[" + std::to_wstring(i) +L"] = " + std::to_wstring(year[i]) + L" erreur (1) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(4);
            d = d.substr(1);
            d2 = d.substr(0, 2);
            month[j] = std::stoi(d2, &pos);
            if (month[j] <= 0 || month[j] >= 13)
            { // Erreur
                E.afficher_X(i, nomFichier, L"month[" + std::to_wstring(j) + L"] = " + std::to_wstring(month[j]) + L" erreur (1) !!!");
                return -1;
            }
            d = d.substr(2);
            d = d.substr(1);
            d2 = d.substr(0, 2);
            day[k] = std::stoi(d2, &pos);
            if (day[k] <= 0 || day[k] >= 32)
            { // Erreur
                E.afficher_X(i, nomFichier, L"day[" + std::to_wstring(k) + L"] = " + std::to_wstring(day[k]) + L" erreur (1) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
            Date_X[I][J][K].tm_year = year[i] - 1900;
            Date_X[I][J][K].tm_mon = month[j] - 1;
            Date_X[I][J][K].tm_mday = day[k];
            K++;
            if ((pos = d.length()) == 0)
                goto stop;
        }
        // month[j] + day[k]
        if (
            d[0] == L'_' &&
            (d[1] == L'0' || d[1] == L'1') &&
            (std::isdigit(d[2])) &&
            d[3] == L'-' &&
            (d[4] == L'0' || d[4] == L'1' || d[4] == L'2' || d[4] == L'3') &&
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
                E.afficher_X(i, nomFichier, L"month[" + std::to_wstring(j)+L"] = " + std::to_wstring(month[j]) + L" erreur (2) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
            d = d.substr(1);
            d2 = d.substr(0, 2);
            day[k] = std::stoi(d2, &pos);
            if (day[k] <= 0 || day[k] >= 32)
            { // Erreur
                E.afficher_X(i, nomFichier, L"day[" + std::to_wstring(k) + L"] = " + std::to_wstring(day[k]) + L" erreur (2) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
            Date_X[I][J][K].tm_year = year[i] - 1900;
            Date_X[I][J][K].tm_mon = month[j] - 1;
            Date_X[I][J][K].tm_mday = day[k];
            K++;
            if ((pos = d.length()) == 0)
                goto stop;
        }
        // '_'
        if (
            d[0] == L'_' &&
            (d[1] == L'1' || d[1] == L'2' || d[1] == L'3') &&
            (std::isdigit(d[2])) &&
            (std::isdigit(d[3])) &&
            (std::isdigit(d[4]))
            )
        {
            i++;
            j = 0;
            k = 0;
            d = d.substr(1);
            continue;
        }
        // day[k]
        if (
            d[0] == L'_' &&
            (d[1] == L'0' || d[1] == L'1' || d[1] == L'2' || d[1] == L'3') &&
            (std::isdigit(d[2]))
            )
        {
            k++;
            d = d.substr(1);
            d2 = d.substr(0, 2);
            day[k] = stoi(d2, &pos);
            if (day[k] <= 0 || day[k] >= 32)
            { // Erreur
                E.afficher_X(-1, nomFichier, L"day[" + std::to_wstring(k)+L"] = " + std::to_wstring(day[k]) + L" erreur (3) !!!");
                return EXIT_FAILURE;
            }
            d = d.substr(2);
            Date_X[I][J][K].tm_year = year[i] - 1900;
            Date_X[I][J][K].tm_mon = month[j] - 1;
            Date_X[I][J][K].tm_mday = day[k];
            K++;
            if ((pos = d.length()) == 0)
                goto stop;
        }
    }
    // Ok !
stop:
    if (d[0] == L'_')
    {
        D_K_[I][J] = true;
        d = d.substr(1);
    }
    if (d[0] == L' ')
    {
        d = d.substr(1);
        D_t[I][J].push_back(d);
    }
    else
        D_t[I][J].push_back(L"");
    wchar_t date_string[15];
#if Serie_afficher_X_x_ == 1
    //wcout << L"    " << L"(";
    std::wstring wstr = L"{";
    for (i = 0; i < K; i++)
    {
        wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][J][i]);
        //wcout << date_string;
        wstr += date_string;
        if (i < K - 1 )
            //wcout << L' ';
            wstr += L' ';
    }
    if (D_K_[I][J] == true)
        wstr += L"(_)";
#else
    for (i = 0; i < K; i++)
        wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][J][i]);
#endif
    D_K[I][J] = i;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # pas de OK                                                                                                                                          #
// # const int Serie::afficher_pas_de_OK()                                                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_pas_de_OK() const
{
    int i;
    if (!affichage_genres_actif)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de genne !!!");
    }
    if (!affichage_nationalite_actif)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de Nationalité !!!");
    }
    // Note
    /*if (Note_ == false)
    {
        E.afficher_X(-1, L"Attention !", L"Érreur de Note !!!");
#if Serie_afficher_pas_de_OK_ == 1
        B.Ok_W(L"Attention : Érreur de Note !!!");
#endif
    }*/
    bool j;
    j = false;
    for (i = 0; i < D_I ; i++)
    {
        if (D_Note[i] != -1)
        {
            j = true;
            break;
        }
    }
    if (j == false)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de Note !!!");
    }
    // Titre
    if (!Titre_)
    {
        E.afficher_X(-1, L"Attention !", L"Erreur de Titre !!!");
    }
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher                                                                                                                                           #
// # const int Serie::afficher()                                                                                                                        #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher()
{ // OK !
    int i = 0, j, x = 4, I;
    std::vector <std::wstring>::iterator iter;
    std::size_t pos = 0;
    std::wstring wstr;
    std::wstring Textes;
    wchar_t date_string[22] = L"";
    //
#if Serie_afficher_OK_ == 1
    Console_Lire_txt(L"---------- ");
    if (Ok != L"Titre.txt")
        //B.Ok_W(L'{' + Ok + L'}');
        ;
    else
    {
        std::wcout << L"    " << keyColor << L'{' << valuesColor << Titre[0];
        if (Titre[1] != L"")
        {
            std::wcout << keyColor2 << Titre[1] << valueColor2;
            std::wcout << Titre[2];
        }
        std::wcout << keyColor << L'}' << valuesColor << std::endl;
    }
#endif
    Console_Lire_txt(L"---------- ");
    // Titre
    //bool titre_ = false;
    if (Titre_ != true)
    {
        E.afficher_X(-1, L"Series::afficher_OK()", L"Erreur !!!");
        return EXIT_FAILURE;
    }
    Textes = keyColor + L"Titre : " + valuesColor + Titre[0];
    if (Titre[2] != L"")
        Textes += keyColor + Titre[1] + valuesColor + Titre[2];
     // Sur
    if (sur_ == true)
        Textes += keyColor + L" (" + valuesColor + sur + keyColor + L')' + valuesColor;
    // La signalétique jeunesse
    if (sj_ == true && sj.length() != 0)
        Textes += keyColor + L" (" + valuesColor + sj+ keyColor + L')' + valuesColor;
    // Netflix SJ
    if (netflix_sj_ == true && netflix_sj.length() != 0)
        Textes += (keyColor + L" [" + valuesColor + netflix_sj + keyColor + L']' + valuesColor);
    // Temps
    if (Temps_ == true)
    {
        Textes += L' ';
        wstr = afficher_OK_Temps(Temps, keyColor, valuesColor);
        Textes += wstr;
    }
    // Note
    if (Note_ == true)
    {
        wstr = afficher_OK_Note();
        Textes += wstr;
    }
    else if (Date_Diffusee_a_partir_de_[0] == true)
        Textes += L' ' + keyColor + L'(' + valuesColor + L"Pas de note !!!" + keyColor + L')' + valuesColor;
    else
    {
        Textes += L' ' + keyColor + L'(' + valuesColor + L"pas de note !!!" + keyColor + L')' + valuesColor;
        E.afficher_X(-1, L"Erreur !!!", L"Pas de note !");
    }
    //
    i = Console_Lire_txt(Textes, 0, 8);
    // Titre original
    if (Titre_Original_ == true)
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
    // Chaîne
    PrintChaine();
    // Audiodescription
    PrintAudiodescription(audiodescription, affichage_audiodescription_actif, keyColor, valuesColor);
    // Genre
    PrintGenres(genre, affichage_genres_actif, sous_genre, affichage_sous_genre_actif, keyColor, valuesColor);
    // Créée par
    PrintCreee_par();
    //PrintCreee_par(creee_par, S_T, S_t, creee_par_);
    // Avec
    if (Avec_ == true)
    {
        Textes = keyColor + L"Avec : " + valuesColor;
        std::wstring& avec = Avec.back();
        for (iter = Avec.begin(), j = 0; iter != Avec.end(); iter++, j++)
        {
            Textes += *iter;
            if (j == 2)
                break;
            if (*iter != Avec.back())
                Textes += keyColor + L", " + valuesColor;
        }
        i = Console_Lire_txt(Textes, 0, 7);
    }
    // En relation avec
    PrintEn_relation_avec();
    // Nationalité(s)
    PrintNationalites(nationalite, affichage_nationalite_actif, keyColor, valuesColor);
    // Image
    PrintImages(image, affichage_image_actif, keyColor, valuesColor, 0, 0, 0, 0);
    // Netflix ?
    if (sur_ == false)
        i = Console_Lire_txt(keyColor + L"Netflix : " + valuesColor + L"Oui" + keyColor + L" !" + valuesColor, 0, 10);
    //
    Console_Lire_txt(L"---------- ");
    // 
    if (Titre.size() == 5/*titre_ == true*/)
    { // Titre = 4
        //iter = Titre.begin();
        //iter += 3;
        i = Console_Lire_txt(Titre[4], 4, 0);
        Console_Lire_txt(L"---------- ");
    }
    // Avec et Avec_role
    if (Avec_ == true && Avec_role.size() != 0)
    {
        i = Console_Lire_txt(keyColor + L"Avec :" + valuesColor, 0, 0);
        Textes = L"";
        std::wstring& avec = Avec.back();
        for (j = 0; j < Avec.size(); j++)
        {
            if (Avec[j] == avec && avec == L"…" && Avec_role[j] == L"")
            {
                Textes += avec;
                break;
            }
            if (Avec[j] != L"" && Avec_role[j] != L"")
                Textes += Avec[j] + L" " + keyColor2 + L"(" + valueColor2 + Avec_role[j] + keyColor2 + L")" + valueColor2;
            else if (Avec[j] == L"")
                Textes += keyColor2 + L"(" + valueColor2 + Avec_role[j] + keyColor2 + L")" + valueColor2;
            else
                Textes += Avec[j];
            if (Avec[j] != avec)
                Textes += keyColor + L", " + valuesColor;
            else
                Textes += keyColor + L'.' + valuesColor;
        }
        i = Console_Lire_txt(Textes, 4, 0);
        Console_Lire_txt(L"---------- ");
    }
    //
    I = 0;
    while (I < D_I)
    {
        Textes = L"";
        if (Date_Diffusee_a_partir_de_[I] == true)
        {
            wcsftime(date_string, 15, L"%d/%m/%Y", &Date_Diffusee_a_partir_de[I]);
            wstr = date_string;
            Textes += wstr.substr(0, 2) + keyColor2 + L'/' + valueColor2 + wstr.substr(3, 2) + keyColor2 + L'/' + valueColor2 + wstr.substr(6, 4);
        }
        else
        {
            break;
        }
        if (D_titre[I].begin() == D_titre[I].end())
        {
            wstr = L"D_titre[]";
            E.afficher_X(-1, wstr, L"Erreur !!!");
            //break;
            continue;
        }
        iter = D_titre[I].begin();
        wstr = *iter;
        if (D_Titre_[I] == true)
        {
            Textes += keyColor2 + L" : " + valueColor2 + keyColor + D_Titre[I] + valuesColor;
        }
        iter++;
        Textes += keyColor2 + L" : " + valueColor2;
        if (D_titre[I].size() == 2)
            Textes += *iter;
        else if (D_titre[I].size() == 3)
        {
            Textes += *iter;
            iter++;
            Textes += *iter;
        }
        if (D_titre[I].size() == 1)
            Textes += keyColor2 + L'(' + valueColor2;
        else
            Textes += keyColor2 + L" (" + valueColor2;
        Textes += wstr + keyColor2 + L')' + valueColor2;
        /*if (D_Titre_[I] == true)
        {
            wcout << L" : " << S_W << D_Titre[I] << S_w;// << L" (" << S_w
        }*/
        i = Console_Lire_txt(Textes, 0, x);
        //
        std::size_t k;
        for (j = 0; j < D_J[I]; j++)
        {
            wchar_t b[3];
            wstr = std::to_wstring(I + 1);
            Textes = wstr + keyColor2 + L'x' + valueColor2;
            int c = 1;
            if (D_J[I] >= 100)
            {
                swprintf_s(b, 3, L"%.3d", D_K_d[I][j]);
                c = 3;
            }
            else if (D_J[I] >= 10)
            {
                swprintf_s(b, 3, L"%.2d", D_K_d[I][j]);
                c = 2;
            }
            else
                swprintf_s(b, 3, L"%d", D_K_d[I][j]);
            wstr = b;
            Textes += wstr + keyColor2 + L" : " + valueColor2;
            if (D_K[I][j] > 0)
            {
                wstr = L"";
                pos = 0;
                std::wstring m[10] = {L""};
                for (k = 0; k < D_K[I][j]; k++)
                {
                    wcsftime(date_string, 15, L"%d/%m/%Y", &Date_X[I][j][k]);
                    std::wstring wstr2 = date_string;
                    m[k] = wstr2.substr(0, 2) + keyColor2 + L'/' + valueColor2 + wstr2.substr(3, 2) + keyColor2 + L'/' + valueColor2 + wstr2.substr(6, 4);
                }
                std::wstring n = m[0];
                int o = 0, p = 0;
                for (k = 1; k < D_K[I][j]; k++)
                {
                    if (n == m[k])
                    {
                        m[k] = L'(' + std::to_wstring(o + 2) + L')';
                        if (m[k - 1] == n && o == 0)
                            m[k - 1] += L" (1)";
                        o++;
                    }
                    else
                    {
                        n = m[k];
                        o = 0;
                    }
                }
                k = 1;
                p = 0;
                o = D_K[I][j];
                while (k < o)
                {
                    if (m[k][2] == L')')
                    {
                        m[p] += m[k];
                        m[k].clear();
                    }
                    else
                        p++;
                    k++;
                }
                k = 0;
                p = 0;
                std::wstring q[10] = { L"" };
                while (k < o)
                {
                    if (m[k] != L"")
                    {
                        q[p] = m[k];
                        p++;
                    }
                    k++;
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
                    wstr = replace_all(wstr, L" et ", keyColor2 + L" et " + valueColor2);
                if(pos = wstr.find(L")("))
                    wstr = replace_all(wstr, L")(", keyColor2 + L")(" + valueColor2);
                if (pos = wstr.find(L"("))
                    wstr = replace_all(wstr, L"(", keyColor2 + L"(" + valueColor2);
                if (pos = wstr.find(L")"))
                    wstr = replace_all(wstr, L")", keyColor2 + L")" + valueColor2);
                if (pos = wstr.find(L", "))
                    wstr = replace_all(wstr, L", ", keyColor2 + L", " + valueColor2);
                //if (pos = wstr.find(L" : "))
                //    wstr = replace_all(wstr, L" : ", S_W + L" : " + S_w);
                Textes += wstr;
            }
            // D_K_[I][j]
            //if (D_K_[I][j] == L'_')
            if(D_K_[I][j] == true)
                Textes += keyColor2 + L'(' + valueColor2 + L'_' + keyColor2 + L')' + valueColor2;
            iter = D_t[I][j].begin();
            if (D_t[I][j].size() == 7)
                i = afficher_OK_T(D_t[I][j], Textes, x, x + c + 5, x + c + 5);
            else
            {
                E.afficher_X(-1, L"", L"Erreur D_t[][] !!!");
                return -1;
            }
        }
        // Netflix
        //if (D_Netflix[I] == true)
        //{
        //    wstr = L"Netflix";
        //    i = Console_Lire_txt(S_W + L'(' + S_w + wstr + S_W + L')' + S_w, y, y, Y);
        //}
        // DVD
        if (D_DVD[I] == true)
        {
            wstr = L"DVD";
            i = Console_Lire_txt(keyColor2 + L'(' + valueColor2 + wstr + keyColor2 + L')' + valueColor2, x, x);
        }
        // Note
        //if (D_Note_[0] == false && Date_Diffusee_a_partir_de_[0] == true)
        //    i = Console_Lire_txt(S_W + L"Pas de note !!!" + S_w, y, y);
        // Note
        if (D_Note_[0] == false && Date_Diffusee_a_partir_de_[0] == true)
            i = Console_Lire_txt(keyColor2 + L"Pas de note !!!" + valueColor2, x, x);
        /*else*/ if (D_Note_[I] == true)
        {
            if (D_Note[I] == -100)
                i = Console_Lire_txt(keyColor2 + L'(' + valueColor2 + L"Pas de note !" + keyColor2 + L')' + valueColor2, x, x);
            else
            {
                Textes = keyColor2 + L"Note : " + valueColor2;
                if (D_Note[I] == 0 || D_Note[I] == 20 || D_Note[I] == 40 || D_Note[I] == 60 || D_Note[I] == 80 || D_Note[I] == 100)
                    Textes += std::to_wstring((D_Note[I] / 20));
                else
                {
                    wstr = std::to_wstring((float)D_Note[I] / 20);
                    wstr = wstr[0] + keyColor2 + wstr[1] + valueColor2 + wstr[2];
                    Textes += wstr;
                }
                Textes += keyColor2 + L"/5" + valueColor2;
                i = Console_Lire_txt(Textes, x, x);
            }
        }
        // Avec
        if (D_Avec_role[I].size() != 0)
        {
            Textes = keyColor2 + L"Avec : " + valueColor2;
            for (iter = D_Avec_role[I].begin(); iter != D_Avec_role[I].end(); iter++)
            {
                wstr = *iter;
                pos = wstr.find(L" : ");
                if (pos != 0)
                    Textes += wstr.substr(0, pos) + keyColor2 + L" (" + valueColor2 + wstr.substr(pos + 3);
                else if (pos == wstring::npos)
                    Textes += *iter;
                else
                    Textes += keyColor2 + L" (" + valueColor2 + wstr.substr(2);
                if (*iter != D_Avec_role[I].back())
                {
                    if (pos == std::wstring::npos)
                        Textes += keyColor2 + L", " + valueColor2;
                    else
                        Textes += keyColor2 + L"), " + valueColor2;
                }
                else
                {
                    if (pos == std::wstring::npos)
                        Textes += keyColor2 + L'.' + valueColor2;
                    else
                        Textes += keyColor2 + L")." + valueColor2;
                }
            }
            i = Console_Lire_txt(Textes, x, x + 7);
        }
        // Chaîne
        if (d_chaine[I] != L"" && d_chaine_[I] == true)
            i = Console_Lire_txt(keyColor2 + L"Chaîne d'origine : " + valueColor2 + d_chaine[I], x, x + 9);
        // Image
        PrintImages(d_image[I], d_affichage_image_actif[I], keyColor2, valueColor2, 4, 0, 8, 1);
        Console_Lire_txt(L"---------- ");
        // I
        I++;
    }

    // ???
    i = E.Ok();// ???

    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # OK Note                                                                                                                                            #
// # const wstring Serie::afficher_OK_Note()                                                                                                            #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Serie::afficher_OK_Note()
{
    int i, j = 0;
    // ???
    int k = 0;
    //
    std::wstring t;
    float somme = 0, moyenne = 0;
    int pas_de_moyenne = 0, pas_de_note = 0;
    int n = 0;
    if (D_I == 0)
    {
        t = L' ' + keyColor + L'(' + valuesColor + L"pas de note !" + keyColor + L')' + valuesColor;
        return t;
    }
    else
    {
        for (i = 0; i < D_I; i++)
        {
            if (D_Note[i] == -1)
            {
                std::wcout << L"pas_de_note" << std::endl;
                pas_de_note += 1;
                continue;
            }
            else if (D_Note[i] == -100)
            {
                pas_de_moyenne += 1;
                continue;
            }
            else
            {
                somme += D_Note[i];
                j++;
                k++;
            }
        }
    }
    //
    if (pas_de_note == D_I /*+ 1*/ && somme == 0)
        t = L"";
    else if (pas_de_moyenne <= 1 && somme == 0)
    {
        t = L' ' + keyColor + L'(' + valuesColor + L"pas de note !" + keyColor + L')' + valuesColor;
    }
    else
    {
        std::wstring wstr;
        if (j == 2)
        {
            // ????
            Note = somme;
            //std::wcout << L"aaa Note=" << Note << std::endl;
        }
        else
        {
            //j -= 1;
            //j--;
            Note = somme / (k);
        }
        wstr = std::to_wstring(static_cast<float>(Note / 20));
        if (wstr[2] == L'0' && wstr[3] == L'0')
            wstr = wstr[0];
        else if (wstr[3] == L'0')
            wstr = wstr[0] + keyColor + wstr[1] + valuesColor + wstr[2];
        else
            wstr = wstr[0] + keyColor + wstr[1] + valuesColor + wstr[2] + wstr[3];
        t = L' ' + wstr + keyColor + L"/5" + valuesColor;
    }
    return t;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # OK T                                                                                                                                               #
// # const int Serie::afficher_OK_T(vector <wstring>& I, wstring& Textes, int x0, int x1, int x2)                                                       #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::afficher_OK_T(std::vector <std::wstring>& I, std::wstring& Textes, int x0, int x1, int x2)
{
    //vector <wstring>::iterator iter;
    std::wstring w_p, w_t1, w_t2, w_t3, w_temps, w_P, w_s;
    int i;
    //iter = I.begin();
    w_p = I[0];
    w_t1 = I[1];
    w_t2 = I[2];
    w_t3 = I[3];
    w_temps = I[4];
    w_P = I[5];
    w_s = I[6];
    if (w_p == L"" && w_t1 == L"" && w_t2 == L"" && w_t3 == L"" && w_temps == L"" && w_P == L"")
    {
        if (w_s != L"")
            Textes += keyColor2 + L" (" + valueColor2 + w_s + keyColor2 + L')' + valueColor2;
        i = Console_Lire_txt(Textes, x0, x2);
    }
    else if (w_p != L"" && w_t1 == L"" && w_t2 == L"" && w_t3 == L"" && w_temps == L"" && w_P == L"")
    {
        Textes += L" : " + w_p;
        if (w_s != L"")
            Textes += keyColor2 + L" (" + valueColor2 + w_s + keyColor2 + L')' + valueColor2;
        i = Console_Lire_txt(Textes, x0, x2);
    }
    else
    {
        //if (!(w_p == L"" || w_t1 == L""))
        //    ;
        if (w_p != L"" && w_t1 == L"" && w_t2 == L"" && w_t3 == L"")
            Textes += keyColor2 + L" : " + valueColor2 + w_p;
        if (w_p != L"" && w_t1 != L"" && w_t2 == L"" && w_t3 == L"")
            Textes += keyColor2 + L" : " + valueColor2 + w_t1;
        else if (w_p != L"" && w_t1 != L"" && w_t3 != L"")
        {
            Textes += keyColor2 + L" : " + valueColor2 + w_t1;
            bool w_t2_ = false;
            if (w_t2 == L" : " && w_t2_ == false)
            {
                Textes += keyColor2 + L" : " + valueColor2;
                w_t2_ = true;
            }
            else if (w_t2 == L": " && w_t2_ == false)
            {
                Textes += keyColor2 + L": " + valueColor2;
                w_t2_ = true;
            }
            else if (w_t2 == L"/" && w_t2_ == false)
            {
                Textes += keyColor2 + L'/' + valueColor2;
                w_t2_ = true;
            }
            else
            {
                E.afficher_X(-1, L"", L"Erreur D_t[][] !!!");
                return -1;
            }
            if (w_t2_ == true)
                Textes += w_t3;
        }
        if (w_s != L"")
            Textes += keyColor2 + L" (" + valueColor2 + w_s + keyColor2 + L')' + valueColor2;
        if (w_temps != L"")
        {
            //size_t pos = w_temps.length();
            //Textes += S_W + L" (" + S_w;
            //i = 0;
            //pos = pos - 3;
            //while (i < pos)
            //{
            //    Textes += w_temps[i];
            //    i++;
            //}
            //Textes += w_temps[pos];
            //Textes += w_temps[pos + 1];
            //Textes += w_temps[pos + 2];
            //Textes += S_W + L')' + S_w;
            // 
            // 
            Textes += keyColor2 + L" (" + valueColor2 + afficher_OK_Temps(w_temps, keyColor2, valueColor2) + keyColor2 + L')' + valueColor2;
        }
        i = Console_Lire_txt(Textes, x0, x2);
        i = Console_Lire_txt(w_P, x1, x2);
    }
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_OK_Temps                                                                                                                                  #
// # const wstring Serie::afficher_OK_Temps(wstring& t, wstring& S, wstring& s)                                                                         #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Serie::afficher_OK_Temps(std::wstring& t, std::wstring& S, std::wstring& s)
{ // min
#if Serie_afficher_OK_Temps_ == 1
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(" << t << L", " << S << L", " << s << L") :" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps(" + t + L", " + S + L", " + s + L") :");
#endif
    std::wstring wstr = std::to_wstring(std::stoi(t));
    if (S_Espace == true)
        wstr += L' ';
    wstr += S + S_MIN + s;
#if Serie_afficher_OK_Temps_ == 1
    //wcout << L"    " << L"wstr=[" << wstr << L']' << endl;
    B.Ok_W(L"wstr=[" + wstr + L']');
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(" << t << L", " << S << L", " << s << L") : Ok !" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps() : Ok !");
#endif
    return wstr;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # afficher_OK_Temps                                                                                                                                  #
// # const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s)                                                                              #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const std::wstring Serie::afficher_OK_Temps(std::tm &t, std::wstring &S, std::wstring &s)
{ // min
#if Serie_afficher_OK_Temps_ == 1
    // Attention !!!
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s) :" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s) :");
#endif
    int m = t.tm_hour * 1 + t.tm_min;
    std::wstring wstr = to_wstring(m);
    if (S_Espace == true)
        wstr += L' ';
    wstr += S + S_MIN + s;
#if Serie_afficher_OK_Temps_ == 1
    // Attention !!!
    B.Ok_W(L"wstr=[" + wstr + L']');
    //wcout << B_T << L"const wstring Serie::afficher_OK_Temps(tm &t, wstring &S, wstring &s) : Ok !" << B_t << endl;
    B.Ok_T(L"const wstring Serie::afficher_OK_Temps() : Ok !");
#endif
    return wstr;
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # Ok S                                                     #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const int Serie::Ok_S(bool P_S_Espace, std::wstring P_S_MIN, std::wstring P_S_T, std::wstring P_S_t, std::wstring P_S_W, std::wstring P_S_w)
{
    S_Espace = P_S_Espace; // = false ou true;
    S_MIN = P_S_MIN; // = L"min";
    keyColor = P_S_T;
    valuesColor = P_S_t;
    keyColor2 = P_S_W;
    valueColor2 = P_S_w;
    return EXIT_SUCCESS;
}

// ######################################################################################################################################################
// ######################################################################################################################################################

Serie::setNote(std::wstring note)
{
    std::wstring m_note_str = std::to_wstring(20 * std::stoi(n));
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintChaine                                                                                                                                        #
// # const void Serie::PrintChaine()                                                                                                                    #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintChaine()
{
    if (affichage_chaine_actif && chaine.size() > 0)
    {
        std::wstring chaine_str = keyColor + L"Chaîne d'origine : " + valuesColor + chaine + L"\r\n";
        Console::PrintStringW(Console::hOut, chaine_str);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintCreee_par                                                                                                                                     #
// # const void Serie::PrintCreee_par()                                                                                                                 #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintCreee_par()
{
    if (affichage_creee_par_actif == true && creee_par.size() > 0)
    {
        std::wstring creee_par_str = keyColor + L"Créée" + ((creee_par.size() > 1) ? L"s" : L"") + L" par : " + valuesColor;
        bool first = true;
        for (auto&& c : creee_par)
        {
            if (!first)
            {
                creee_par_str += keyColor + L", " + valuesColor;
            }
            creee_par_str += c;
            first = false;
        }
        creee_par_str += L"\r\n";

        Console::PrintStringW(Console::hOut, creee_par_str);
    }
}

// ######################################################################################################################################################
// #                                                                                                                                                    #
// # PrintEn_relation_avec                                                                                                                              #
// # const void Serie::PrintEn_relation_avec()                                                                                                          #
// #                                                                                                                                                    #
// ######################################################################################################################################################

const void Serie::PrintEn_relation_avec()
{
    if (affichage_en_relation_avec_actif && en_relation_avec.size() > 0)
    {
        std::wstring en_relation_avec_str = keyColor + L"En relation avec : " + valuesColor;
        bool first = true;
        for (auto&& e : en_relation_avec)
        {
            if (!first)
            {
                en_relation_avec_str += keyColor + L", " + valuesColor;
            }
            en_relation_avec_str += e;
            first = false;
        }
        en_relation_avec_str += L"\r\n";

        Console::PrintStringW(Console::hOut, en_relation_avec_str);
    }
}

// ######################################################################################################################################################
// ######################################################################################################################################################
// ######################################################################################################################################################
// ######################################################################################################################################################
// ######################################################################################################################################################

Episode::Episode()
{
}

Episode::~Episode()
{
}
