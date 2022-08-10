#include <conio.h>  
#include <iostream>  
using namespace std;  
  
int main() {  
    int m;  
    int n;  
    int total = 1;  
  
    cout << " ====================================" << endl;  
    cout << "          Program Perpangkatan       " << endl;  
    cout << " ====================================" << endl << endl;  
  
    cout << " Menghitung hasil m pangkat n" << endl << endl;  
    cout << " Masukkan nilai m = ";  
    cin >> m;  
    cout << endl << " Masukkan nilai n = ";  
    cin >> n;  
    for (int i = 1; i <= n; i++) {  
        total = total * m;  
    }  
  
    cout << endl << " Hasil dari " << m << " pangkat " << n << " adalah " << total << endl;  
    getch();  
}  
