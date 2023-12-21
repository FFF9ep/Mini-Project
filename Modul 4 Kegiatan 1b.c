#include <stdio.h>
#include <string.h>

void searchWords(char *text, char *word) {
    char *token = strtok(text, " ");
    int position = 0;

    while (token != NULL) {
        position++;
        if (strcmp(token, word) == 0) {
            printf("Kata '%s' ditemukan pada posisi %d.\n", word, position);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char text[1000], word[100];
    int JalanLagi = 1;

    while (JalanLagi) {
        // Input teks
        printf("Masukkan teks yang ingin dicari : ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = '\0';

        // Input kata yang dicari
        printf("Masukkan kata yang ingin dicari : ");
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0';

        // Cari kata dalam teks
        searchWords(text, word);

        // Minta input untuk mencari lagi
        printf("Ingin mencari kata lagi? (1=Ya, 0=Tidak): ");
        scanf("%d", &JalanLagi);
        getchar(); // Mengonsumsi karakter newline
    }

    return 0;
}
