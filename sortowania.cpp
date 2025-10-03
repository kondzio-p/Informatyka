#include <iostream>
using namespace std;
#define n 10

int T[n] = { 6, 4, 8, 2, 3, 9, 1 ,2, 6, 3 };
int l;

void Wypisz();

void sortujNaiwne() { // sortowanie babelkowe (naiwne)
    cout << "/------------------------------/" << endl;
    cout << "sortowanie babelkowe (naiwne)" << endl;
    cout << "/------------------------------/" << endl;
    for ( int i = 0; i < (n-1); i++) {
        for ( int j = 0; j < (n-1); j++) 
            if (T[j] > T[j + 1])
                swap(T[j], T[j + 1]);
        Wypisz();
    }
}

void sortujStraznik() { // sortowanie babelkowe (straznik)
    cout << "/------------------------------/" << endl;
    cout << "sortowanie babelkowe (straznik)" << endl;
    cout << "/------------------------------/" << endl;
    int st;
    for ( int i = 0; i < (n-1); i++) {
        st = 1;
        for ( int j = 0; j < (n-1); j++) 
            if (T[j] > T[j + 1]) {
                swap(T[j], T[j + 1]);
                st = 0;
            }
        Wypisz();
        if(st) break;
    }
}  

void sortujZmniejszRozmiar() { // sortowanie babelkowe (zmniejszanie rozmiaru)
    cout << "/------------------------------/" << endl;
    cout << "sortowanie babelkowe (zmniejszanie rozmiaru)" << endl;
    cout << "/------------------------------/" << endl;
    int m = n-1;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            l++;
            if (T[j] > T[j + 1])
                swap(T[j], T[j + 1]);
            }
        Wypisz();
        m--;
    }
}  

void sortowanieWybieranie() { // sortowanie babelkowe (przez wybieranie)
    cout << "/------------------------------/" << endl;
    cout << "sortowanie babelkowe (przez wybieranie)" << endl;
    cout << "/------------------------------/" << endl;
    for(int i = 0; i < n; i++) {
        int iMin = i;
        for(int j=i; j<n; j++) { // wyszukaj najmniejsza
            if(T[j]<T[iMin]) {
                iMin = j;
            }
        }
        swap(T[i], T[iMin]);
        Wypisz();
    }
    
}  

void Wypisz() {
    for (int i = 0; i < n; i++) cout << T[i] << " ";
        cout << endl;
    
}

int main()
{
    // sortujNaiwne();
    
    // cout << "==================" << endl;
    
    // sortujStraznik();
    
    // cout << "==================" << endl;
    
    // sortujZmniejszRozmiar();
    
    cout << "==================" << endl;
    
    sortowanieWybieranie();
}
