// Algoritma Decrease & Conquer
// Metode selection sort

#include <bits/stdc++.h>
using namespace std;

// Fungsi Swap/Menukar isi elemen
void swap(int *a, int *b, string *c, string *d){
    int tamp = *a;
    *a = *b;
    *b = tamp;
    string temp = *c;
    *c = *d;
    *d = temp;
}

// Fungsi mengurutkan nilai
void selectionSort(int nilai[], int n, string nama[]){
    int i, j, max;
    for (i = 0; i < n - 1; i++){
        // mencari nilai max di nilai
        max = i;
        for (j = i + 1; j < n; j++)
            if (nilai[j] > nilai[max])
                max = j;
                
        // menukar nilai yang lebih besar
        swap(&nilai[max], &nilai[i], &nama[max], &nama[i]);
    }
}

/* Fungsi Menampilkan Urutan Rangking */
void printnilai(int nilai[], int size, string nama[]){
    int i;
    for (i = 0; i < size; i++)
        cout << "     "<< i+1 << "\t\t" << nama[i]<< "\t\t" << nilai[i] <<endl;
}

int main(){
    int a;
	cout<<" Masukan jumlah siswa = ";
	cin>>a;
	cout<<endl;
	int nilai[a];
	string nama[a];
	for (int i=0; i<a; i++) {
		cout<<" Siswa ke-"<<i+1<<endl;
		cout<<" Nama\t: ";
		cin>>nama[i];
		cout<<" Nilai\t: ";
		cin>>nilai[i];
		cout<<endl;
	}

    cout << "\n-----------------------------------";
    cout << "\n TABEL URUTAN NILAI DARI PARA SISWA";
    cout << "\n-----------------------------------";
    cout << "\n Rangking\tNama\t\tNilai "<<endl;
    selectionSort(nilai, a, nama);
    printnilai(nilai, a, nama);
    cout << "\n-----------------------------------";
    return 0;
}
