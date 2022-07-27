#include <stdio.h>
#include <conio.h>
#define size 99
void sort(int[], int);

int main()
{
    int x[size], i, uang, n, k, hasil[size];
    printf("\n Banyak Koin : ");
    scanf("%d", &n);
    printf("\n \n Masukan Jenis Koin : \n");
    for (i = 1; i <= n; i++)
    {
        scanf("\n %d", &x[i]);
    }
    sort(x, n);
    printf("\n Koin yang tersedia : \n");
    for (i = 1; i <= n; i++)
    {
        printf("%d", x[i]);
        printf("\n");
    }
    printf("\n");
    printf("\n Masukan Nilai yang dipecah : ");
    scanf("%d", &uang);
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        hasil[i] = uang / x[i];
        uang = uang % x[i];
        k = uang % x[i];
    }
    for (i = 1; i <= n; i++)
    {
        printf("Keping %d", x[i]);
        printf("-an sebanyak : %d", hasil[i]);
        printf("\n \n");
    }
    printf("sisanya adalah %d", k);
    getch();
    return 0;
}
void sort(int a[], int siz)
{
    int pass, hold, j;
    for (pass = 1; pass <= siz - 1; pass++)
    {
        for (j = 0; j <= siz - 2; j++)
        {
            if (a[j + 1] < a[j + 2])
            {
                hold = a[j + 1];
                a[j + 1] = a[j + 2];
                a[j + 2] = hold;
            }
        }
    }
}
