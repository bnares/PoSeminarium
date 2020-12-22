#include <iostream>
#include <sstream>
#include "MetodyPomocnicze.h"



using namespace std;


string MetodyPomocnicze:: wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}


string MetodyPomocnicze:: konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

