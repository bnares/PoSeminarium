#include <iostream>

#include "UzytkownikMenedzer.h"
#ifndef  KSIAZKAADRESOWA_H

#define KSIAZKAADRESOWA_H



using namespace std;

class KsiazkaAdresowa
{

UzytkownikMenedzer menedzer;
public:
    KsiazkaAdresowa(string nazwaPliku) : menedzer(nazwaPliku){
        menedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracja();
    void wyswietlWszystkich();


};
#endif
