#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int angka, jumlah, max, min, total, avg;
	total=0;
    cout << "===================" << endl;
    cout << "PROGRAM MAX_MIN_AVG" << endl;
    cout << "===================" << endl;
    cout << endl;
    cout << "Masukkan jumlah angka: ";
    cin >> jumlah;
    cout << endl;
    for (int i = 1; i <= jumlah; i++){
        cout << "Masukkan Angka       : ";
        cin >> angka;
		total = total+ angka;
        if (i == 1){
            min = angka;
            max = angka;
        }
        else if (min > angka){
            min = angka;
        }
        else if (max < angka){
            max = angka;
        }
        else{}
    }
    avg = total/jumlah;
    cout << endl;
    cout << "Nilai terkecil \t\t: " << min << endl;
    cout << "Nilai terbesar \t\t: " << max << endl;
    cout << "Nilai rata-rata \t: " << avg << endl;
    getch();
}
