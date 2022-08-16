#include <iostream>
using namespace std;

int A[100];

int masukan(int n){
    int i;
    for (i = 0; i < n; i++){
        cout << "Masukan bilangan ke " << i + 1 << " : ";
        cin >> A[i];
    }
}

int hasil(int n) {
    int i, max, min;
    max = A[0];
   
    for (i = 0; i < n; i++){
        if (min > A[i]) {
            min = A[i];
        }
    } 
    cout << "Nilai terkecil adalah : " << min << endl;
}

int main()
{
    int n;
    cout << "Masukan Jumlah Data : ";
    cin >> n;   
    masukan(n); 
    hasil(n);  
}
