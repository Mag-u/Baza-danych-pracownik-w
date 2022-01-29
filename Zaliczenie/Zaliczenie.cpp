#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
string dopisz(int iTakNiePotrzbny)
{
    string sklejanka;
    string imie;
    string nazwisko;
    string kod;
    string miejscowosc;
    string kraj;
    string ulica;
    string numer;

    cout << "Podaj imie: ";
    cin >> imie;
    sklejanka = imie + " ";
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    sklejanka += nazwisko +" ";
    cout << "Podaj kod: ";
    cin >> kod;
    sklejanka +=kod +" ";
    cout << "Podaj miejscowosc: ";
    cin >> miejscowosc;
    sklejanka +=miejscowosc +" ";
    cout << "Podaj kraj: ";
    cin >> kraj;
    sklejanka +=kraj +" ";
    cout << "Podaj ulice: ";
    cin >> ulica;
    sklejanka += ulica+" ";
    cout << "Podaj numer: ";
    cin >> numer;
    sklejanka += numer+" ";
    return sklejanka;
}
int main()
{
    int wybor = 0;
    vector <string> adresowaBazaDanych;
    string powtorzyc = "tak";
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
   
        do {
            while (powtorzyc == "tak")
            {
                cout << "1. Dopisz" << endl;
                cout << "2. Korekta" << endl;
                cout << "3. Skasuj" << endl;
                cout << "4. Pokaz baze" << endl;
                cout << "5. Wyjdz" << endl;
                cout << "Wybierz opcje: ";

                cin >> wybor;

                system("CLS");

                switch (wybor) {
                case 1:
                    adresowaBazaDanych.push_back(dopisz(wybor));
                    cout << endl << "Otworzyc ponownie wybor? tak/nie" << endl;
                    cin >> powtorzyc;
                    if(powtorzyc=="nie")
                    {
                        exit(0);
                    }
                    break;
                case 2:
                    cout << 2 << endl;
                    cout << "Otworzyc ponownie wybor? tak/nie" << endl;
                    cin >> powtorzyc;
                    if (powtorzyc == "nie")
                    {
                        exit(0);
                    }
                    break;
                case 3:
                    cout << 3 << endl;
                    cout << "Otworzyc ponownie wybor? tak/nie" << endl;
                    cin >> powtorzyc;
                    if (powtorzyc == "nie")
                    {
                        exit(0);
                    }
                    break;
                case 4:
                    for (int i = 0; i < adresowaBazaDanych.size(); i++)
                    {
                        cout << i + 1 << " " << adresowaBazaDanych[i] << endl;
                    }
                    cout << "Otworzyc ponownie wybor? tak/nie" << endl;
                    cin >> powtorzyc;
                    if (powtorzyc == "nie")
                    {
                        exit(0);
                    }
                    break;
                }
            }
        } while (wybor != 5);
    return 0;
}