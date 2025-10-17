#include <iostream>
#include <fstream>
using namespace std;

const int ROZMIAR = 30000;
int T[ROZMIAR] = {};  
int licznik = 0;

void Wczytaj() {
	ifstream plik("danesort.txt");
	if (!plik.is_open()) {
		cout << "Nie mozna otworzyc pliku!" << endl;
		return;
	}

	licznik = 0;
	while (plik >> T[licznik] && licznik < ROZMIAR) {
		licznik++;
	}

	plik.close();

	cout << "Wczytano " << licznik << " liczb z pliku.\n";
}

// rekurencja
int sb(int lewy, int prawy, int szukana) {
	if (lewy > prawy) return -1;

	int srodek = (lewy + prawy) / 2;

	if (T[srodek] == szukana)
		return srodek;
	else if (szukana < T[srodek])
		return sb(lewy, srodek - 1, szukana);
	else
		return sb(srodek + 1, prawy, szukana);
}

// iteracja
int sb2(int lewy, int prawy, int szukana) {
	while (lewy <= prawy) {
		int srodek = (lewy + prawy) / 2;

		if (T[srodek] == szukana)
			return srodek;
		else if (szukana < T[srodek])
			prawy = srodek - 1;
		else
			lewy = srodek + 1;
	}

	return -1;
}

int main() {
	Wczytaj();

	if (licznik == 0) {
		cout << "Brak danych. Zakonczono program.\n";
		return 1;
	}

	int szukana;
	cout << "Podaj liczbe do wyszukania: ";
	cin >> szukana;

	int wynik_rek = sb(0, licznik - 1, szukana);
	int wynik_iter = sb2(0, licznik - 1, szukana);

	// Wynik rekurencji
	cout << "\nRekurencyjnie: ";
	if (wynik_rek == -1)
		cout << "Liczba " << szukana << " nie wystepuje w tablicy.\n";
	else
		cout << "Liczba " << szukana << " znajduje sie na pozycji " << wynik_rek << ".\n";

	// Wynik iteracyjny
	cout << "Iteracyjnie: ";
	if (wynik_iter == -1)
		cout << "Liczba " << szukana << " nie wystepuje w tablicy.\n";
	else
		cout << "Liczba " << szukana << " znajduje sie na pozycji " << wynik_iter << ".\n";

	return 0;
}
