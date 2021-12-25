// Napisać program, który utworzy adresową bazę danych(osoba - imię(imiona) i nazwisko(nazwiska),
// kod, miejscowość, kraj, ulica, numer) i będzie ją obsługiwać(dopisywanie, korekta, kasowanie)
// STRUCT
// 
// oraz sortować według uznania użytkownika algorytmem bąbelkowym.          
// 
// Program napisać tak, aby: aby po uruchomieniu była wyświetlana informacja,
// który raz program został uruchomiony.
// Stworzyc plik tekstowy z liczba zero, wczytywac ten plik za kazdym razem i dodawac jeden.
// Wczytaj plik dodaj jeden wyswietl liczbe


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream liczbaUruchomien;
    liczbaUruchomien.open("uruchomienia.txt");
    int liczba;
    liczbaUruchomien >> liczba;
    liczba = liczba+1;
    liczbaUruchomien << 2;
    cout << liczba;
    liczbaUruchomien.close();


}
