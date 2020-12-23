#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"

using namespace std;

int main()
{

    KsiazkaAdresowa a("nowe.txt");
    a.rejestracja();
    a.rejestracja();
    a.wyswietlWszystkich();


    return 0;
}
