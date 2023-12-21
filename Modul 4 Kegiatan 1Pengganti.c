#include <stdio.h>

int main() {
    int angka, batas, i, j;

    printf("Masukkan nilai: ");
        scanf("%d", &angka);

    printf("Masukkan batas perkalian atau pangkat: ");
        scanf("%d", &batas);

    printf("\n=== Perkalian ===\n");
    for(i = 1; i <= batas; i++) {
        printf("%d x %d = %d\n", angka, i, angka * i);
    }

    printf("\n=== Perpangkatan ===\n");
    for(i = 1; i <= batas; i++) {
        int hasil = angka;
        for(j = 1; j < i; j++) {
            hasil *= angka;
        }
        printf("%d pangkat %d = %d\n", angka, i, hasil);
    }

    return 0;
}
