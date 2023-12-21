#include <stdio.h>
#include <stdlib.h>

enum MenuMakanan
{
    Nasgor = 15000,
    Miegor = 10000,
    Ayamgor = 20000,
    IkanGor = 20000,
    Steak = 50000,
};

enum MenuMinuman
{
    Airmineral = 3000,
    Esteh = 3000,
    Jusjeruk = 5000,
    AnggurMerah = 10000,
    EsKelapa = 8000,
};

enum Dessert
{
    Cake = 25000,
    Eskrim = 5000,
    Pudding = 10000,
};

void MyFunction()
{
    system("color 0A");

    int MenuMakanan, MenuMinuman, Dessert = 0, totalbelanja, uang, totalakhir; // ini adalah deklarasi variabel
    char member, pesanlagi;
    float kembalian, diskon;

menuawal:
    system("cls");
    printf("\n==========================================+=+=+=+ RUMAH MAKAN FANDI ARDYAN +=+=+=+=======================================");
    printf("\n================================================ JL. Raya Tlogomas  Malang ==============================================");
    printf("\n==================================================== IG : Fanndi._ ======================================================");
    printf("\n=================================================== Telp : 082123456789 =================================================");
    printf("\n================================================ www.Rumahmakanfandi.co.id ==============================================");
    printf("\n========================================== Selamat Datang di Rumah Makan Kami ===========================================");

    int pesananMakanan = 0;
    int pesananMinuman = 0;
    int pesananDessert = 0;

makananMenu:
    printf("\n\n\n\n-------------------------------------------------------------------------------------------------------------------------\n");
    printf("\nMenu Makanan : \n");
    printf("1.Nasi Goreng    Rp.15000\n");
    printf("2.Mie Goreng     Rp.10000\n");
    printf("3.Ayam Goreng    Rp.20000\n");
    printf("4.Ikan Goreng    Rp.20000\n");
    printf("5.Steak          Rp.50000\n");
    printf("Pilih Menu Makanan (1-5): ");
    scanf("%d", &MenuMakanan);

    int porsiMakanan;
    printf("Berapa porsi yang ingin Anda pesan? : ");
    scanf("%d", &porsiMakanan);
    switch (MenuMakanan)
    {
    case 1:
        MenuMakanan = Nasgor * porsiMakanan;
        break;
    case 2:
        MenuMakanan = Miegor * porsiMakanan;
        break;
    case 3:
        MenuMakanan = Ayamgor * porsiMakanan;
        break;
    case 4:
        MenuMakanan = IkanGor * porsiMakanan;
        break;
    case 5:
        MenuMakanan = Steak * porsiMakanan;
        break;
    default:
        printf("INPUT TIDAK VALID. SILAHKAN MEMILIH DENGAN RENTANG 1 - 5 !!!");
        goto makananMenu;
    }

    pesananMakanan += MenuMakanan;

minumanmenu:
    printf("\n-------------------------------------------------------------------------------------------------------------------------");
    printf("\nMenu Minuman : \n");
    printf("1.Air Mineral     Rp.3000\n");
    printf("2.Es Teh          Rp.3000\n");
    printf("3.Jus Jeruk       Rp.5000\n");
    printf("4.Anggur Merah    Rp.10000\n");
    printf("5.Es Kelapa       Rp.8000\n");
    printf("Pilih Menu Minuman (1-5): ");
    scanf("%d", &MenuMinuman);

    int porsiMinuman;
    printf("Berapa porsi yang ingin Anda pesan? : ");
    scanf("%d", &porsiMinuman);
    switch (MenuMinuman)
    {
    case 1:
        MenuMinuman = Airmineral * porsiMinuman;
        break;
    case 2:
        MenuMinuman = Esteh * porsiMinuman;
        break;
    case 3:
        MenuMinuman = Jusjeruk * porsiMinuman;
        break;
    case 4:
        MenuMinuman = AnggurMerah * porsiMinuman;
        break;
    case 5:
        MenuMinuman = EsKelapa * porsiMinuman;
        break;
    default:
        printf("INPUT TIDAK VALID. SILAHKAN MEMILIH DENGAN RENTANG 1 - 5 !!!");
        goto minumanmenu;
    }

    pesananMinuman += MenuMinuman;

Maudessert:
    printf("\nApakah Anda Ingin Memesan Dessert? (Y/N) : ");
    char pesanDessert;
    scanf(" %c", &pesanDessert);

    if (pesanDessert == 'Y' || pesanDessert == 'y')
    {
    pesandessert:
        printf("\n-------------------------------------------------------------------------------------------------------------------------");
        printf("\nMenu Dessert : \n");
        printf("1.Cake    Rp.25000\n");
        printf("2.Es Krim Rp.5000\n");
        printf("3.Pudding Rp.10000\n");
        printf("Silahkan Pilih Menu Dessert (1-3): ");
        int pilihanDessert;
        scanf("%d", &pilihanDessert);

        int porsiDessert;
        printf("Berapa porsi yang ingin Anda pesan? : ");
        scanf("%d", &porsiDessert);
        switch (pilihanDessert)
        {
        case 1:
            Dessert = Cake * porsiDessert;
            break;
        case 2:
            Dessert = Eskrim * porsiDessert;
            break;
        case 3:
            Dessert = Pudding * porsiDessert;
            break;
        default:
            printf("INPUT TIDAK VALID. SILAHKAN MEMILIH DENGAN RENTANG 1 - 3");
            goto pesandessert;
        }
        pesananDessert += Dessert;
    }
    else if (pesanDessert == 'N' || pesanDessert == 'n')
    {
        Dessert = 0;
    }
    else
    {
        printf("Input Tidak Valid. Silahkan Masukkan (Y/N)!");
        goto Maudessert;
    }

    totalbelanja = pesananMakanan + pesananMinuman + pesananDessert;
    diskon = totalbelanja * 0.2;
    printf("\n-------------------------------------------------------------------------------------------------------------------------");
    printf("\nPesanan Anda:\n");
    printf("Makanan: Rp%d\n", pesananMakanan);
    printf("Minuman: Rp%d\n", pesananMinuman);
    printf("Dessert: Rp%d\n", pesananDessert);
    printf("Total Belanja Anda Adalah: Rp%d\n", totalbelanja);

membernot:
    printf("\nApakah Anda Adalah Seorang Member Resto Kami? (Y/N): ");
    scanf(" %c", &member);

    if (member == 'Y' || member == 'y')
    {
        printf("\n!!!Selamat!!!\nKarena Anda Adalah Member Anda Mendapatkan Diskon Sebesar 20%%!");
        totalakhir = totalbelanja - diskon;
        printf("\nMaka Total Belanja Anda Adalah: Rp%d", totalakhir);
    }
    else if (member == 'N' || member == 'n')
    {
        printf("\nSegeralah Membuat Member untuk Mendapatkan Diskon Sebesar 20%% Di Setiap Pembelian Anda!");
        totalakhir = totalbelanja;
        printf("\nMaka Total Belanja Anda Adalah: Rp%d", totalbelanja);
    }
    else
    {
        printf("\nINPUT TIDAK VALID. SILAHKAN MEMILIH (Y/N)!");
        goto membernot;
    }

duitulang:
    printf("\nMasukkan Nominal Uang Yang Ingin Anda Gunakan Untuk Bayar: Rp");
    scanf(" %d", &uang);

    kembalian = uang - totalakhir;
    if (uang < totalakhir)
    {
        printf("\nUang Anda Tidak Mencukupi!");
        goto duitulang;
    }
    else if (uang > totalakhir)
    {
        printf("\nUang Anda Lebih Maka Kembalian Anda: Rp%.f", kembalian);
    }
    else if (uang == totalakhir)
    {
        printf("\nUang Anda Pas!");
    }

    printf("\nTERIMAKASIH TELAH BERBELANJA DI RESTORANT KAMI!\nSILAHKAN DATANG KEMBALI!");

tidakvalid:
    printf("\nApakah Anda Ingin Memesan Lagi? (Y/N): ");
    scanf(" %c", &pesanlagi);

    if (pesanlagi == 'Y' || pesanlagi == 'y')
    {
        pesananMakanan = 0;
        pesananMinuman = 0;
        pesananDessert = 0;
        goto menuawal;
    }
    else if (pesanlagi == 'N' || pesanlagi == 'n')
    {
        printf("\nTERIMAKASIH TELAH BERBELANJA DI RESTORANT KAMI!\nSILAHKAN DATANG KEMBALI!");
    }
    else
    {
        printf("\n =+=+= INPUT TIDAK VALID. SILAHKAN MEMILIH (Y/N)! =+=+= ");
        goto tidakvalid;
    }

    printf("\nAlamat Memori Variabel Total: %p\n", &totalakhir);
    printf("\n-------------------------------------------------------------------------------------------------------------------------");
}
int main()
{
    MyFunction();
    return 0;
}