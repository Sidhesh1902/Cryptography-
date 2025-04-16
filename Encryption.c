#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 100

// Caesar Cipher
void caesarEncrypt(char* text, int shift) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

// Atbash Cipher
void atbashEncrypt(char* text) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = base + (25 - (text[i] - base));
        }
    }
}

// Affine Cipher
int modInverse(int a, int m) {
    a %= m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

void affineEncrypt(char* text, int a, int b) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = ((a * (text[i] - base) + b) % 26) + base;
        }
    }
}

// Vigenere Cipher
void vigenereEncrypt(char* text, char* key) {
    int j = 0, klen = strlen(key);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[j % klen]) - 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

// Gronsfeld Cipher
void gronsfeldEncrypt(char* text, char* digits) {
    int len = strlen(digits);
    for (int i = 0, j = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            int shift = digits[j % len] - '0';
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }
}

// Beaufort Cipher
void beaufortEncrypt(char* text, char* key) {
    int j = 0, klen = strlen(key);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            int pt = tolower(text[i]) - 'a';
            int kt = tolower(key[j % klen]) - 'a';
            text[i] = 'A' + (26 + kt - pt) % 26;
            j++;
        }
    }
}

// Autokey Cipher
void autokeyEncrypt(char* text, char* key) {
    int tlen = strlen(text);
    char fullKey[SIZE];
    strcpy(fullKey, key);
    strncat(fullKey, text, tlen - strlen(key));

    for (int i = 0, j = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            int shift = tolower(fullKey[j]) - 'a';
            text[i] = ((tolower(text[i]) - 'a' + shift) % 26) + 'a';
            j++;
        }
    }
}

// N-Gram (simple digraph example)
void ngramEncrypt(char* text) {
    for (int i = 0; text[i] && text[i+1]; i += 2) {
        char temp = text[i];
        text[i] = text[i+1];
        text[i+1] = temp;
    }
}

// Hill Cipher (2x2)
void hillEncrypt(char* text, int key[2][2]) {
    int len = strlen(text);
    if (len % 2 != 0) strcat(text, "X");  // Pad
    for (int i = 0; i < len; i += 2) {
        int x = text[i] - 'A';
        int y = text[i + 1] - 'A';
        int new1 = (key[0][0] * x + key[0][1] * y) % 26;
        int new2 = (key[1][0] * x + key[1][1] * y) % 26;
        text[i] = new1 + 'A';
        text[i + 1] = new2 + 'A';
    }
}

// Rail Fence Cipher
void railFenceEncrypt(char* text, int rails) {
    char rail[rails][SIZE];
    for (int i = 0; i < rails; i++) memset(rail[i], '\n', SIZE);

    int dir_down = 0, row = 0, len = strlen(text), col = 0;

    for (int i = 0; i < len; i++) {
        rail[row][col++] = text[i];
        if (row == 0 || row == rails - 1) dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }

    int idx = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                text[idx++] = rail[i][j];
    text[idx] = '\0';
}

// Route Cipher (5x5)
void routeEncrypt(char* text) {
    char grid[5][5];
    int k = 0;
    for (int i = 0; i < 5 && k < strlen(text); i++)
        for (int j = 0; j < 5 && k < strlen(text); j++)
            grid[i][j] = text[k++];

    k = 0;
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 5; i++)
            text[k++] = grid[i][j];
    text[k] = '\0';
}

// Myszkowski Cipher (simple implementation for key "BANANA")
void myszkowskiEncrypt(char* text) {
    int order[] = {1, 3, 2, 3, 2, 3}; // B A N A N A
    int len = strlen(text);
    int cols = 6;
    int rows = (len + cols - 1) / cols;
    char grid[rows][cols];
    memset(grid, 'X', sizeof(grid)); // padding

    int k = 0;
    for (int i = 0; i < rows && k < len; i++)
        for (int j = 0; j < cols && k < len; j++)
            grid[i][j] = text[k++];

    k = 0;
    for (int n = 1; n <= 3; n++) {
        for (int j = 0; j < cols; j++) {
            if (order[j] == n) {
                for (int i = 0; i < rows; i++)
                    text[k++] = grid[i][j];
            }
        }
    }
    text[k] = '\0';
}

// Menu
int main() {
    char input[SIZE], key[SIZE];
    int a, b, choice, mat[2][2];

    while (1) {
        printf("\n--- Cryptography Cipher Menu ---\n");
        printf("1. Caesar\n2. Atbash\n3. August\n4. Affine\n5. Vigenere\n6. Gronsfeld\n");
        printf("7. Beaufort\n8. Autokey\n9. N-Gram\n10. Hill\n11. Rail Fence\n12. Route\n13. Myszkowski\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); getchar();

        if (choice == 14) break;

        printf("Enter text (only alphabets, no spaces): ");
        fgets(input, SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';

        switch (choice) {
            case 1:
                printf("Enter shift: ");
                scanf("%d", &a); getchar();
                caesarEncrypt(input, a); break;
            case 2: atbashEncrypt(input); break;
            case 3: caesarEncrypt(input, 1); break;
            case 4:
                printf("Enter a and b (a must be coprime with 26): ");
                scanf("%d %d", &a, &b); getchar();
                affineEncrypt(input, a, b); break;
            case 5:
                printf("Enter key: ");
                fgets(key, SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                vigenereEncrypt(input, key); break;
            case 6:
                printf("Enter numeric key (e.g., 1234): ");
                fgets(key, SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                gronsfeldEncrypt(input, key); break;
            case 7:
                printf("Enter key: ");
                fgets(key, SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                beaufortEncrypt(input, key); break;
            case 8:
                printf("Enter keyword: ");
                fgets(key, SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                autokeyEncrypt(input, key); break;
            case 9: ngramEncrypt(input); break;
            case 10:
                printf("Enter 2x2 matrix (row-wise): ");
                scanf("%d%d%d%d", &mat[0][0], &mat[0][1], &mat[1][0], &mat[1][1]); getchar();
                hillEncrypt(input, mat); break;
            case 11:
                printf("Enter number of rails: ");
                scanf("%d", &a); getchar();
                railFenceEncrypt(input, a); break;
            case 12: routeEncrypt(input); break;
            case 13: myszkowskiEncrypt(input); break;
            default: printf("Invalid choice.\n"); continue;
        }

        printf("Encrypted text: %s\n", input);
    }

    return 0;
}
