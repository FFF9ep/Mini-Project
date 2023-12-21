#include <stdio.h>

void hehe()
{
    system("color 0A");

awal:
    system("cls");
    printf("===== Modul 5 Kegiatan 1 =====\n\n");
    int batasArray, i;

    printf("Masukkan Batas Bilangan : ");
    scanf("%d", &batasArray);

    int array[batasArray], arrayGanjil[batasArray], arrayGenap[batasArray];
    int angkaGanjil = 0, angkaGenap = 0;

    printf("Input Bilangan Sebanyak Batas (%d): \n", batasArray);
    for (i = 0; i < batasArray; i++)
    {
        printf("Bilangan ke- %d : ", i + 1);
        scanf("%d", &array[i]);
    }

    for (i = 0; i < batasArray; i++)
    {
        if (array[i] % 2 == 0)
        {
            arrayGenap[angkaGenap] = array[i];
            angkaGenap++;
        }
        else
        {
            arrayGanjil[angkaGanjil] = array[i];
            angkaGanjil++;
        }
    }

    printf("\nBilangan Ganjil Dalam Array : \n");
    for (i = 0; i < angkaGanjil; i++)
    {
        printf("%d ", arrayGanjil[i]);
    }
    printf("\nBilangan Genap Dalam Array : \n");
    for (i = 0; i < angkaGenap; i++)
    {
        printf("%d ", arrayGenap[i]);
    }

    char programRestart;
nanya:
    printf("\n\nApakah Anda Ingin Menjalankan Program Lagi? (Y / N) : ");
    scanf(" %c", &programRestart);
    if (programRestart == 'y' || programRestart == 'Y')
    {
        goto awal;
    }
    else if (programRestart == 'n' || programRestart == 'N')
    {
        printf("Okay Thanks!");
    }
    else
    {
        printf("Input Tidak Valid!");
        goto nanya;
    }

    printf("\n\nProgram Finished.");
    printf("\n");
}

int main()
{

    hehe();

    return 0;
}
