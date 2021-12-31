#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string liczbaUruchomien;
    ifstream liczba{ "uruchomienia.txt" };
    ofstream liczbaOPlus1{ "uruchomieniaO1Plus.txt" };
    if (liczba && liczbaOPlus1) {

        while (getline(liczba, liczbaUruchomien))
        {
            int numer = stoi(liczbaUruchomien);
            numer += 1;
            liczbaOPlus1 << numer;
        }
    }
    liczba.close();
    liczbaOPlus1.close();

    string liczbaZwiekszonaO1KtoraTerazJestPrawidlowa;
    ifstream liczbaZPlus1{ "uruchomieniaO1Plus.txt" };
    ofstream liczbaTerazNormalna{ "uruchomienia.txt" };

    if (liczbaZPlus1 && liczbaTerazNormalna) {

        while (getline(liczbaZPlus1, liczbaZwiekszonaO1KtoraTerazJestPrawidlowa)) {
            liczbaTerazNormalna << liczbaZwiekszonaO1KtoraTerazJestPrawidlowa;
        }
    }
    liczbaZPlus1.close();
    liczbaTerazNormalna.close();
    return 0;
}