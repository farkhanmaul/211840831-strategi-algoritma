#include <cstdlib>
#include <iostream>
using namespace std;

typedef int larik[10]; // tipe data untuk merge
void baca_data(int A[], int n)
{
    // proses input dan baca data
    for (int i = 0; i < n; i++)
    {
        cout << "Data ke - " << i + 1 << " : ";
        cin >> A[i];
    }
}
void cetak_data(int A[], int n)
{
    // cetak data
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
void tukar_data(int *a, int *b)
{
    // tukar data
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void minimum(int A[], int dari, int n, int *tempat)
{
    int i, min;
    min = A[dari];
    *tempat = dari;
    for (i = dari + 1; i < n; i++)
        if (A[i] < min)
        {
            min = A[i];
            *tempat = i;
        }
}



void merge(larik a, int kiri, int tengah, int kanan)
{
    int bagkir, postemp, bykel, i;
    larik temp;
    bagkir = tengah - 1;
    postemp = kiri;
    bykel = kanan - kiri + 1;
    while ((kiri <= bagkir) && (tengah <= kanan))
    {
        if ((a[kiri] <= a[tengah]))
        {
            temp[postemp] = a[kiri];
            postemp = postemp + 1;
            kiri = kiri + 1;
        }
        else
        {
            temp[postemp] = a[tengah];
            postemp = postemp + 1;
            tengah = tengah + 1;
        }
        // kopi bagian kiri
        while ((kiri <= bagkir))
        {
            temp[postemp] = a[kiri];
            postemp = postemp + 1;
            kiri = kiri + 1;
        }
        // kopi bagian kanan
        while ((tengah <= kanan))
        {
            temp[postemp] = a[tengah];
            postemp = postemp + 1;
            tengah = tengah + 1;
        }
        // kopi ke aaray asal
        for (i = 1; i <= bykel; i++)
        {
            a[kanan] = temp[kanan];
            kanan = kanan - 1;
        }
    }
}
void merge_sort(larik A, int kiri, int kanan)
{
    int tengah;
    if (kiri < kanan)
    {
        tengah = (kiri + kanan) / 2;
        merge_sort(A, kiri, tengah);
        merge_sort(A, tengah + 1, kanan);
        merge(A, kiri, tengah , kanan);
    }
}



int main(int argc, char *argv[])
{
    int data[10], n;
    int pilih;
    cout << " MERGE SORT";
    cout << "\n\nMasukan data : ";
    cin >> n;
    baca_data(data, n);
    cout << "Data yang anda masukan : ";
    cetak_data(data, n);
    cout << endl;
    merge_sort(data, 0, n - 1);
    cout << "Setelah ditukar (Merge Sort): ";
    cetak_data(data, n);
    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
