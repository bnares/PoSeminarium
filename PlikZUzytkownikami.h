#include <iostream>
#include <fstream>
#include <sstream>
#ifndef  PLIKZUZYTKOWNIKAMI_H

#define PLIKZUZYTKOWNIKAMI_H
#include "Uzytkownik.h"



using namespace std;

class PlikZUzytkownikami
{
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
public:
    const string nazwaPlikuZUzytkownikami;
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    PlikZUzytkownikami(string nazwaPliku): nazwaPlikuZUzytkownikami(nazwaPliku){};

};


#endif
