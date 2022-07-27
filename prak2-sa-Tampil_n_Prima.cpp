#include <iostream>
using namespace std;
int main(){
    int x, z, a, b, cek;
    cout << "================================================" << endl;
    cout << "Masukan batasan suku ke-n prima : ";
    cin >> x;
    cout << "================================================" << endl;
    cout << "Cetak bilangan prima dari batasan yang dimasukan" << endl;
	z = 0;
    for (a = 2; a <= x; a++){
        cek = 0;
        for (b = 2; b < a; b++){
            if (a % b == 0){
                cek = 1;
            }
        }
        if (cek == 0){
            cout << a << " ";
            z++;
        }
    }
    cout << endl;
    cout << "Jumlah bilangan prima dari 0 Sampai "<<x<<" adalah : "<< z<<endl;
    cout << "================================================" << endl;
    return 0;
}
