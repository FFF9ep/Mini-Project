#include <stdio.h>

int main()
{
    int pilihOperasi;
    int elemenMat1[3][3], elemenMat2[3][3], hasilMatrix[3][3];
    char jalanLagi;
    // system("color 0A");

Awal:
    system("cls");
    printf("===== Modul 5 Kegiatan 2 =====\n\n");

pilihMenu:
    printf("\n===== Operasi Matrix 3x3 =====\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("Pilih Operasi Matrix Dalam Range 1 - 3 : ");
    scanf("%d", &pilihOperasi);

    if (pilihOperasi == 1)
    {
        printf("\nAnda Memilih Operasi Penjumlahan!");
        printf("\nSilahkan Masukkan Elemen Pada Matrix Pertama (3x3)!:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &elemenMat1[i][j]);
            }
        }
        printf("\nSilahkan Masukkan Elemen Pada Matrix Kedua (3x3)!:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &elemenMat2[i][j]);
            }
        }
        printf("Matrix Pertama :\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", elemenMat1[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("Matrix Kedua :\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", elemenMat2[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("Hasil Penjumlahan Matrix:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hasilMatrix[i][j] = elemenMat1[i][j] + elemenMat2[i][j];
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", hasilMatrix[i][j]);
                printf(" ");
            }
            printf("\n");
        }
    }
    else if (pilihOperasi == 2)
    {
        printf("\nAnda Memilih Operasi Pengurangan!");
        printf("\nSilahkan Masukkan Elemen Pada Matrix Pertama (3x3)!:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &elemenMat1[i][j]);
            }
        }
        printf("\nSilahkan Masukkan Elemen Pada Matrix Kedua (3x3)!:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &elemenMat2[i][j]);
            }
        }
        printf("Matrix Pertama :\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", elemenMat1[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("Matrix Kedua :\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", elemenMat2[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("Hasil Pengurangan Matrix:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hasilMatrix[i][j] = elemenMat1[i][j] - elemenMat2[i][j];
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", hasilMatrix[i][j]);
                printf(" ");
            }
            printf("\n");
        }
    }
    else if (pilihOperasi == 3)
    {
        printf("\nAnda Memilih Operasi Perkalian!");
        printf("\nSilahkan Masukkan Elemen Pada Matrix Pertama (3x3)!:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &elemenMat1[i][j]);
            }
        }
        printf("\nSilahkan Masukkan Elemen Pada Matrix Kedua (3x3)!:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &elemenMat2[i][j]);
            }
        }
        printf("Matrix Pertama :\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", elemenMat1[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("Matrix Kedua :\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", elemenMat2[i][j]);
                printf(" ");
            }
            printf("\n");
        }
        printf("Hasil Perkalian Matrix:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                hasilMatrix[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    hasilMatrix[i][j] += elemenMat1[i][k] * elemenMat2[k][j];
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", hasilMatrix[i][j]);
                printf(" ");
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nInput Tidak Valid!");
        goto pilihMenu;
    }

Question:
    printf("\nApakah Anda Ingin Menjalankan Program Kembali? (Y / N): ");
    scanf(" %c", &jalanLagi);
    if (jalanLagi == 'y' || jalanLagi == 'Y')
    {
        goto Awal;
    }
    else if (jalanLagi == 'n' || jalanLagi == 'N')
    {
        printf("\n\nBaik,Terimakasih!");
    }
    else
    {
        printf("\nInput Tidak Valid!");
        goto Question;
    }
    printf("\nProgram Selesai!\n");

    return 0;
}
