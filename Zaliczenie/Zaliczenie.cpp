#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int wybor = 0;
    vector <string> adresowaBazaDanych;
    string sklejanka;
    string powtorzyc = "tak";
    string imie;
    string nazwisko;
    string kod;      // przy wywolaniu zmienic na int?
    string miejscowosc;
    string kraj;
    string ulica;
    string numer;    // przy wywolaniu zmienic na int?
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
                    cout << 4 << endl;
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