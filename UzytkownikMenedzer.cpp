#include <iostream>
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"




using namespace std;


bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            cout<< "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;

}



int UzytkownikMenedzer:: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
    {
        return 1;
    }
    else
    {
        return (uzytkownicy.back().pobierzID() + 1);
    }
}


void UzytkownikMenedzer::rejestracjaUzytkownika()
{

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plik.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}


Uzytkownik UzytkownikMenedzer:: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawID(pobierzIdNowegoUzytkownika());

    MetodyPomocnicze metoda;

    do
    {
        cout<<"Podaj login: ";

        uzytkownik.ustawLogin(metoda.wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(metoda.wczytajLinie());

    return uzytkownik;
}


void UzytkownikMenedzer:: wypisz()
{
    for(int i =0; i<uzytkownicy.size(); i++)
    {
        cout<<uzytkownicy[i].pobierzID()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;
        cout<<endl;
    }
}


void UzytkownikMenedzer:: wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;

    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;


    plikTekstowy.open(plik.nazwaPlikuZUzytkownikami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }

    }
    plikTekstowy.close();
}



Uzytkownik UzytkownikMenedzer:: pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawID(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}



void UzytkownikMenedzer:: ustawWektorUzytkownicy(vector <Uzytkownik> dane)
{
    uzytkownicy = dane;
}
