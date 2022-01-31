#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
void zamianaMiejscamiZWektorem(string* pierwszeDaneZBazy, string* drugieDaneZBazy)
{
    string temp;
    temp = *pierwszeDaneZBazy;
    *pierwszeDaneZBazy = *drugieDaneZBazy;
    *drugieDaneZBazy = temp;
}
void plikLiczacy(int numer)
{
    string liczbaUruchomien;
    ifstream liczba{ "uruchomienia.txt" };
    ofstream liczbaOPlus1{ "uruchomieniaO1Plus.txt" };
    if (liczba && liczbaOPlus1) {

        while (getline(liczba, liczbaUruchomien))
        {
            int k = stoi(liczbaUruchomien);
            int* numer = &k;
            *numer += 1;
            liczbaOPlus1 << *numer;
        }
    }
    liczba.close();
    liczbaOPlus1.close();
    cout << "Program uruchomiono " << stoi(liczbaUruchomien) + 1 << " raz" << endl << endl;
    Sleep(1000);
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
}
void sortowanieBabelkowe(vector <string>& bazaDanych)
{
    string alfabetycznieLubNie;
    cout << "W jaki sposob chcesz posortowac? alfabetycznie czy niealfabetycznie? a/n: ";
    cin >> alfabetycznieLubNie;
    if (alfabetycznieLubNie == "a")
    {
        for (int i = 0; i < bazaDanych.size(); i++)
            {
                for (int j = 0; j < bazaDanych.size() - 1; j++)
                {
                if (bazaDanych[j] > bazaDanych[j + 1])
                swap(bazaDanych[j], bazaDanych[j + 1]);
                }
            }
    }
    else
    {
        for (int i = 0; i < bazaDanych.size(); i++)
        {
            for (int j = 0; j < bazaDanych.size() - 1; j++)
            {
                if (bazaDanych[j] < bazaDanych[j + 1])
                    swap(bazaDanych[j], bazaDanych[j + 1]);
            }
        }
    }
}
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
string korektaDanych(vector <string> dane, int cyfra)
{
    int wybor = 0;
    string cosJeszczeZmienic = "tak";
    string sklejanka;
    string kopiaVectoru;
    string pomoc;
    string koncowy;
    vector <string> ulepszonyVector;
    kopiaVectoru = dane[cyfra-1];
    for (int i = 0; i < kopiaVectoru.length(); i++)
    {
        if (kopiaVectoru[i] != ' ')
        {
            pomoc += kopiaVectoru[i];
        }
        else {
            ulepszonyVector.push_back(pomoc);
            pomoc = "";
        }
    dane.push_back(pomoc);
    }
  
    string imie = ulepszonyVector[0];
    string nazwisko = ulepszonyVector[1];
    string kod = ulepszonyVector[2];
    string miejscowosc = ulepszonyVector[3];
    string kraj = ulepszonyVector[4];
    string ulica = ulepszonyVector[5];
    string numer = ulepszonyVector[6];

        cout << "Ktore dane chcesz zmienic? "<<endl;
        cout << "1. imie"<<endl;
        cout << "2. nazwisko" << endl;
        cout << "3. kod" << endl;
        cout << "4. miejscowosc" << endl;
        cout << "5. kraj" << endl;
        cout << "6. ulica" << endl;
        cout << "7. numer" << endl;
        cin >> wybor;
        system("CLS");
        switch (wybor)
        {
        case 1:
            cout << "Podaj nowe imie " << endl;
            cin >> imie;          
            break;
        case 2:
            cout << "Podaj nowe nazwisko " << endl;
            cin >> nazwisko;
            break;
        case 3:            
            cout << "Podaj nowy kod" << endl;
            cin >> kod;
            break;
        case 4:
            cout << "Podaj nowa miejscowosc " << endl;
            cin >> miejscowosc;
            break;
        case 5:
            cout << "Podaj nowy kraj" << endl;
            cin >> kraj;
            break;
          case 6:
              cout << "Podaj nowa ulice " << endl;
              cin >> ulica;
            break;
        case 7:
            cout << "Podaj nowy numer" << endl;
            cin >> numer;
            break;

        }
    koncowy = imie + " " + nazwisko + " " + kod + " " + miejscowosc + " " + kraj + " " + ulica + " " + numer+" ";
    return koncowy;
}
int main()
{
    int numerPierwszy, numerDrugi;
    string pierwszy, drugi;
    int potrzebneDoUruchomieniaFunkcji=0;
    int wybor = 0;
    int numerDanych = 0;
    vector <string> adresowaBazaDanych;
    string kopiaKorekty;
    string powtorzyc = "tak";
    plikLiczacy(potrzebneDoUruchomieniaFunkcji);
        while (powtorzyc == "tak")
        {
            system("CLS");
            cout << "1. Dopisz" << endl;
            cout << "2. Korekta" << endl;
            cout << "3. Skasuj" << endl;
            cout << "4. Pokaz baze" << endl;
            cout << "5. Sortowanie babelkowe" << endl;
            cout << "6. Zamiana miejscami" << endl;
            cout << "7. Wyjdz" << endl;
            cout << "Wybierz opcje: ";

            cin >> wybor;

            system("CLS");

            switch (wybor) {
            case 1:
                adresowaBazaDanych.push_back(dopisz(wybor));
                cout << endl << "Otworzyc ponownie wybor? tak/nie" << endl;
                cin >> powtorzyc;
                if (powtorzyc == "nie")
                {
                    exit(0);
                }
                break;
            case 2:
                cout << "Podaj numer danych ktory chcesz zmienic: ";
                cin >> numerDanych;
                kopiaKorekty = korektaDanych(adresowaBazaDanych, numerDanych);
                adresowaBazaDanych.erase(adresowaBazaDanych.begin() + numerDanych - 1);
                adresowaBazaDanych.insert(adresowaBazaDanych.begin() + (numerDanych - 1), kopiaKorekty);
                cout << "Otworzyc ponownie wybor? tak/nie" << endl;
                cin >> powtorzyc;
                if (powtorzyc == "nie")
                {
                    exit(0);
                }
                break;
            case 3:
                cout << "Podaj numer danych ktore chcesz usunac: ";
                cin >> numerDanych;
                adresowaBazaDanych.erase(adresowaBazaDanych.begin() + numerDanych - 1);
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
                    cout << i + 1 << ")" << adresowaBazaDanych[i] << endl;
                }
                cout << "Otworzyc ponownie wybor? tak/nie" << endl;
                cin >> powtorzyc;
                if (powtorzyc == "nie")
                {
                    exit(0);
                }
                break;
            case 5:
                sortowanieBabelkowe(adresowaBazaDanych);
                cout << "Sortowanie zostalo wykonane" << endl;
                cout << "Otworzyc ponownie wybor? tak/nie" << endl;
                cin >> powtorzyc;
                if (powtorzyc == "nie")
                {
                    exit(0);
                }
                break;
            case 6:
                cout << "Podaj numery danych ktore chcesz zamienic miejscami: ";
                cin >> numerPierwszy >> numerDrugi;
                pierwszy = adresowaBazaDanych[numerPierwszy-1];
                drugi = adresowaBazaDanych[numerDrugi-1];
                zamianaMiejscamiZWektorem(&pierwszy, &drugi);
                adresowaBazaDanych.erase(adresowaBazaDanych.begin() + numerPierwszy - 1);
                adresowaBazaDanych.insert(adresowaBazaDanych.begin() + (numerPierwszy - 1), pierwszy);
                adresowaBazaDanych.erase(adresowaBazaDanych.begin() + numerDrugi - 1);
                adresowaBazaDanych.insert(adresowaBazaDanych.begin() + (numerDrugi - 1), drugi);
                cout << "Zamiana wykonana";
                break;
            case 7:
                exit(0);

            default:
                cout << "Wybrales bledny numer sprobuj raz jeszcze";
                break;
            }
        }
    return 0;
}