#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct dataBuku
{
    int id;
    char judulBuku[100];
    char namaAuthor[100];
    int jumlahHalaman;
    char genreBuku[100];
} dataBuku;

void tulisListDiFile(FILE *kegiatan1, struct dataBuku *Books);
void bukuBaru();
void listBuku();
void cariID();
void updateBuku();
void hapusBuku();
void tampilkanMenu();
void kembaliKeMenu();
int cekIDFile(int id);
void updateBukuNext();

int main()
{
    system("color 0A");
    tampilkanMenu();
    return 0;
}

void tulisListDiFile(FILE *kegiatan1, struct dataBuku *Books)
{
    kegiatan1 = fopen("D:\\Books.txt", "a+");
    if (kegiatan1 == NULL)
    {
        printf("Erorr Membuka File!\n");
        exit(0);
    }
    else
    {
        fprintf(kegiatan1, "ID Buku             : %d\n", Books->id);
        fprintf(kegiatan1, "Judul Buku          : %s\n", Books->judulBuku);
        fprintf(kegiatan1, "Nama Author Buku    : %s\n", Books->namaAuthor);
        fprintf(kegiatan1, "Jumlah Halaman Buku : %d\n", Books->jumlahHalaman);
        fprintf(kegiatan1, "Genre Buku          : %s\n\n", Books->genreBuku);
    }
    fclose(kegiatan1);
}

int cekIDFile(int id)
{
    FILE *kegiatan1 = fopen("D:\\Books.txt", "r");
    if (kegiatan1 == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    else
    {
        struct dataBuku Books;

        while (fscanf(kegiatan1, "ID Buku             : %d\n", &Books.id) == 1)
        {
            fscanf(kegiatan1, "Judul Buku          : %[^\n]\n", Books.judulBuku);
            fscanf(kegiatan1, "Nama Author Buku    : %[^\n]\n", Books.namaAuthor);
            fscanf(kegiatan1, "Jumlah Halaman Buku : %d\n", &Books.jumlahHalaman);
            fscanf(kegiatan1, "Genre Buku          : %[^\n]\n\n", Books.genreBuku);

            if (Books.id == id)
            {
                fclose(kegiatan1);
                return 1;
            }
        }
        fclose(kegiatan1);
        return 0;
    }
}

void bukuBaru()
{
    FILE *kegiatan1 = fopen("D:\\Books.txt", "a+");
    if (kegiatan1 == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    else
    {
        struct dataBuku Books;
        int jumlahBukuBaru;

        system("cls");
        printf("========== Selamat Datang Di Menu Tambah Buku! ==========\n");
        printf("============ Silahkan Ikuti Instruksi Menu ! ============\n");
        printf("\n");
        printf("Input Jumlah Buku Yang Ingin Ditambah : ");
        scanf("%d", &jumlahBukuBaru);
        printf("Masukkan Informasi Buku!\n\n");

        for (int i = 0; i < jumlahBukuBaru; i++)
        {
            printf("Masukkan ID Buku        : ");
            scanf("%d", &Books.id);

            if (cekIDFile(Books.id))
            {
                printf("ID Buku sudah terdaftar. Masukkan ID lain.\n");
                i--;
                continue;
            }

            while (getchar() != '\n')
                ;

            printf("Masukkan Judul Buku     : ");
            fgets(Books.judulBuku, sizeof(Books.judulBuku), stdin);
            Books.judulBuku[strcspn(Books.judulBuku, "\n")] = '\0';

            printf("Masukkan Nama Author    : ");
            fgets(Books.namaAuthor, sizeof(Books.namaAuthor), stdin);
            Books.namaAuthor[strcspn(Books.namaAuthor, "\n")] = '\0';

            printf("Masukkan Jumlah Halaman : ");
            scanf("%d", &Books.jumlahHalaman);

            while (getchar() != '\n')
                ;

            printf("Masukkan Genre          : ");
            fgets(Books.genreBuku, sizeof(Books.genreBuku), stdin);
            Books.genreBuku[strcspn(Books.genreBuku, "\n")] = '\0';

            printf("\n");

            tulisListDiFile(kegiatan1, &Books);
        }
        fclose(kegiatan1);
        printf("Loading ");
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf("\nData Buku Berhasil di Input!\n");
        printf("Ke Menu Awal");
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf("\n");
    }
    tampilkanMenu();
}

void listBuku()
{
    FILE *kegiatan1 = fopen("D:\\Books.txt", "r");
    if (kegiatan1 == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    else
    {
        system("cls");
        printf("========== LIST OF BOOKS ===========\n");
        printf("====================================\n");

        struct dataBuku Books;
        int kosong = 1;

        while (fscanf(kegiatan1, "ID Buku             : %d\n", &Books.id) == 1)
        {
            kosong = 0;
            fscanf(kegiatan1, "Judul Buku          : %[^\n]\n", Books.judulBuku);
            fscanf(kegiatan1, "Nama Author Buku    : %[^\n]\n", Books.namaAuthor);
            fscanf(kegiatan1, "Jumlah Halaman Buku : %d\n", &Books.jumlahHalaman);
            fscanf(kegiatan1, "Genre Buku          : %[^\n]\n\n", Books.genreBuku);

            printf("ID Buku             : %d\n", Books.id);
            printf("Judul Buku          : %s\n", Books.judulBuku);
            printf("Nama Author Buku    : %s\n", Books.namaAuthor);
            printf("Jumlah Halaman Buku : %d\n", Books.jumlahHalaman);
            printf("Genre Buku          : %s\n\n", Books.genreBuku);
        }

        if (kosong)
        {
            printf("Tidak Ada Buku Yang Terdaftar!\n\n");
        }

        fclose(kegiatan1);
    }
    kembaliKeMenu();
}

void cariID()
{
    int idTarget;
    FILE *kegiatan1 = fopen("D:\\Books.txt", "r");
    struct dataBuku Books;
    int found = 0;

    if (kegiatan1 == NULL)
    {
        printf("Error opening file");
        exit(0);
    }

    system("cls");
    printf("=========== Selamat Datang Di Menu Cari Buku! ===========\n");
    printf("============ Silahkan Ikuti Instruksi Menu ! ============\n");
    printf("\n");
    printf("Input ID To Search: ");
    scanf("%d", &idTarget);

    printf("\nSearching");
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);

    while (fscanf(kegiatan1, "ID Buku             : %d\n", &Books.id) == 1)
    {
        fscanf(kegiatan1, "Judul Buku          : %[^\n]\n", Books.judulBuku);
        fscanf(kegiatan1, "Nama Author Buku    : %[^\n]\n", Books.namaAuthor);
        fscanf(kegiatan1, "Jumlah Halaman Buku : %d\n", &Books.jumlahHalaman);
        fscanf(kegiatan1, "Genre Buku          : %[^\n]\n\n", Books.genreBuku);

        if (Books.id == idTarget)
        {
            printf("\nID Found!\n");
            printf("ID Buku             : %d\n", Books.id);
            printf("Judul Buku          : %s\n", Books.judulBuku);
            printf("Nama Author Buku    : %s\n", Books.namaAuthor);
            printf("Jumlah Halaman Buku : %d\n", Books.jumlahHalaman);
            printf("Genre Buku          : %s\n\n", Books.genreBuku);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nID Not Found!\n");
    }
    fclose(kegiatan1);

invalid_Input:
    char jalaninFungsiLagi;
    printf("\nApakah Anda Ingin Menggunakan Menu Ini Lagi? (Y / N) : ");
    scanf(" %c", &jalaninFungsiLagi);

    if (jalaninFungsiLagi == 'y' || jalaninFungsiLagi == 'Y')
    {
        cariID();
    }
    else if (jalaninFungsiLagi == 'n' || jalaninFungsiLagi == 'N')
    {
        kembaliKeMenu();
    }
    else
    {
        printf("\nInput Tidak Valid!\n");
        goto invalid_Input;
    }
}

void updateBuku()
{
    FILE *kegiatan1 = fopen("D:\\Books.txt", "r+");
    if (kegiatan1 == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    else
    {
        int idTarget;
        struct dataBuku Books;
        FILE *tempFile = fopen("D:\\tempBooks.txt", "w");
        if (tempFile == NULL)
        {
            printf("Error creating temporary file\n");
            exit(0);
        }
        system("cls");
        printf("========== Selamat Datang Di Menu Update Buku! ==========\n");
        printf("============ Silahkan Ikuti Instruksi Menu ! ============\n");
        printf("\n");
        printf("Input ID Buku Yang Ingin DiUpdate : ");
        scanf("%d", &idTarget);

        int found = 0;

        while (fscanf(kegiatan1, "ID Buku             : %d\n", &Books.id) == 1)
        {
            fscanf(kegiatan1, "Judul Buku          : %[^\n]\n", Books.judulBuku);
            fscanf(kegiatan1, "Nama Author Buku    : %[^\n]\n", Books.namaAuthor);
            fscanf(kegiatan1, "Jumlah Halaman Buku : %d\n", &Books.jumlahHalaman);
            fscanf(kegiatan1, "Genre Buku          : %[^\n]\n\n", Books.genreBuku);

            if (Books.id == idTarget)
            {
                printf("\nData Buku Yang Ingin DiUpdate!\n");
                printf("ID Buku             : %d\n", Books.id);
                printf("Judul Buku          : %s\n", Books.judulBuku);
                printf("Nama Author Buku    : %s\n", Books.namaAuthor);
                printf("Jumlah Halaman Buku : %d\n", Books.jumlahHalaman);
                printf("Genre Buku          : %s\n\n", Books.genreBuku);
                found = 1;
                break;
            }
            else
            {
                fprintf(tempFile, "ID Buku             : %d\n", Books.id);
                fprintf(tempFile, "Judul Buku          : %s\n", Books.judulBuku);
                fprintf(tempFile, "Nama Author Buku    : %s\n", Books.namaAuthor);
                fprintf(tempFile, "Jumlah Halaman Buku : %d\n", Books.jumlahHalaman);
                fprintf(tempFile, "Genre Buku          : %s\n\n", Books.genreBuku);
            }
        }
        fclose(kegiatan1);
        fclose(tempFile);
        remove("D:\\Books.txt");
        rename("D:\\tempBooks.txt", "D:\\Books.txt");

        updateBukuNext();

        if (!found)
        {
            printf("\nID Not Found!\n");
        }

        char apusIDLagi;
    pesan:
        printf("\nApakah Anda Ingin Menjalankan Fungsi Kembali? (Y / N) : ");
        scanf(" %c", &apusIDLagi);

        if (apusIDLagi == 'y' || apusIDLagi == 'Y')
        {
            updateBuku();
        }
        else if (apusIDLagi == 'n' || apusIDLagi == 'N')
        {
            kembaliKeMenu();
        }
        else
        {
            printf("\nInput Tidak Valid!");
            goto pesan;
        }
    }
}

void hapusBuku()
{
    FILE *kegiatan1 = fopen("D:\\Books.txt", "r+");
    if (kegiatan1 == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    else
    {
        int idTarget;
        struct dataBuku Books;
        FILE *tempFile = fopen("D:\\tempBooks.txt", "w");
        if (tempFile == NULL)
        {
            printf("Error creating temporary file\n");
            exit(0);
        }
        system("cls");
        printf("========== Selamat Datang Di Menu Hapus Buku ! ==========\n");
        printf("============ Silahkan Ikuti Instruksi Menu ! ============\n");
        printf("\n");
        printf("Input ID Buku Yang Akan Dihapus: ");
        scanf("%d", &idTarget);

        int found = 0;

        while (fscanf(kegiatan1, "ID Buku             : %d\n", &Books.id) == 1)
        {
            fscanf(kegiatan1, "Judul Buku          : %[^\n]\n", Books.judulBuku);
            fscanf(kegiatan1, "Nama Author Buku    : %[^\n]\n", Books.namaAuthor);
            fscanf(kegiatan1, "Jumlah Halaman Buku : %d\n", &Books.jumlahHalaman);
            fscanf(kegiatan1, "Genre Buku          : %[^\n]\n\n", Books.genreBuku);

            if (Books.id == idTarget)
            {
                found = 1;
                printf("\nBuku dengan ID %d berhasil dihapus!\n", Books.id);
            }
            else
            {
                fprintf(tempFile, "ID Buku             : %d\n", Books.id);
                fprintf(tempFile, "Judul Buku          : %s\n", Books.judulBuku);
                fprintf(tempFile, "Nama Author Buku    : %s\n", Books.namaAuthor);
                fprintf(tempFile, "Jumlah Halaman Buku : %d\n", Books.jumlahHalaman);
                fprintf(tempFile, "Genre Buku          : %s\n\n", Books.genreBuku);
            }
        }
        fclose(kegiatan1);
        fclose(tempFile);
        remove("D:\\Books.txt");
        rename("D:\\tempBooks.txt", "D:\\Books.txt");

        if (!found)
        {
            printf("\nID Not Found!\n");
        }
    }

    char apusIDLagi;
pesan:
    printf("\nApakah Anda Ingin Menghapus ID Kembali? (Y / N) : ");
    scanf(" %c", &apusIDLagi);

    if (apusIDLagi == 'y' || apusIDLagi == 'Y')
    {
        hapusBuku();
    }
    else if (apusIDLagi == 'n' || apusIDLagi == 'N')
    {
        kembaliKeMenu();
    }
    else
    {
        printf("\nInput Tidak Valid!");
        goto pesan;
    }
}

void tampilkanMenu()
{
    system("cls");
    int pilihMenu;
    printf("Loading!");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
pilihan_Menu:
    system("cls");
    printf("========== Hello Welcome To Our Program! ============\n");
    printf("====== This Program It's For Library of Books! ======\n\n");
    printf("\nPlease Select Our Menu There Are Contains!\n");
    printf("[1] Create A New Book.      \n");
    printf("[2] Diplay List Of Books.   \n");
    printf("[3] Search A Book.          \n");
    printf("[4] Update Book Information.\n");
    printf("[5] Delete A Book.          \n");
    printf("[0] Exit The Program.       \n");
    printf("Select Menu Our Above !     : ");
    scanf("%d", &pilihMenu);

    switch (pilihMenu)
    {
    case 1:
        bukuBaru();
        break;
    case 2:
        listBuku();
        break;
    case 3:
        cariID();
        break;
    case 4:
        updateBuku();
        break;
    case 5:
        hapusBuku();
        break;
    case 0:
        printf("\nThank You For Using Our Program!\n");
        printf("See You Next Time!\n\n");
        exit(0);
        break;
    default:
        printf("Input Tidak Valid!");
        goto pilihan_Menu;
        break;
    }
}

void kembaliKeMenu()
{
invalidOpsi:
    char kembali;
    printf("Kembali Ke Menu Awal (Y / N) : ");
    scanf(" %c", &kembali);
    if (kembali == 'y' || kembali == 'Y')
    {
        printf("\nThanks!\n");
        tampilkanMenu();
    }
    else if (kembali == 'n' || kembali == 'N')
    {
        goto invalidOpsi;
    }
    else
    {
        printf("Input Tidak Valid!\n");
        goto invalidOpsi;
    }
}

void updateBukuNext()
{
    FILE *kegiatan1 = fopen("D:\\Books.txt", "a+");
    if (kegiatan1 == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    else
    {
        struct dataBuku Books;

        printf("Masukkan Informasi Baru Untuk Buku!\n\n");
        printf("Masukkan ID Buku        : ");
        scanf("%d", &Books.id);

        while (getchar() != '\n')
            ;

        printf("Masukkan Judul Buku     : ");
        fgets(Books.judulBuku, sizeof(Books.judulBuku), stdin);
        Books.judulBuku[strcspn(Books.judulBuku, "\n")] = '\0';

        printf("Masukkan Nama Author    : ");
        fgets(Books.namaAuthor, sizeof(Books.namaAuthor), stdin);
        Books.namaAuthor[strcspn(Books.namaAuthor, "\n")] = '\0';

        printf("Masukkan Jumlah Halaman : ");
        scanf("%d", &Books.jumlahHalaman);

        while (getchar() != '\n')
            ;

        printf("Masukkan Genre          : ");
        fgets(Books.genreBuku, sizeof(Books.genreBuku), stdin);
        Books.genreBuku[strcspn(Books.genreBuku, "\n")] = '\0';

        printf("\n");

        tulisListDiFile(kegiatan1, &Books);
    }
    fclose(kegiatan1);
}