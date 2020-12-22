#include <iostream>
#include <vector>
#ifndef  UZYTKOWNIKMENEDZER_H

#define UZYTKOWNIKMENEDZER_H
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include <fstream>




using namespace std;


class UzytkownikMenedzer
{
     int idZalogowanegoUzytkownika;
     vector <Uzytkownik> uzytkownicy;
     bool czyIstniejeLogin(string login);
     int pobierzIdNowegoUzytkownika();
     PlikZUzytkownikami plik;
     Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

 public:
    void wczytajUzytkownikowZPliku();
    void rejestracjaUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void wypisz();
    void ustawWektorUzytkownicy(vector <Uzytkownik> dane);
    UzytkownikMenedzer(string nazwaPliku): plik(nazwaPliku){};

};

#endif
