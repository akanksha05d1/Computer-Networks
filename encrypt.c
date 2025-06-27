#include <stdio.h>
#include <string.h>

// Alphabet with index mapping: A=1, B=2, ..., Z=26
const char alphabet[] = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to find the index of a character
int find_index(char ch) {
    for (int i = 1; i < strlen(alphabet); i++) {
        if (alphabet[i] == ch) return i;
    }
    return -1; 
}

// Modular exponentiation: (base^exp) % mod
int mod_pow(int base, int exp, int mod) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return (int)result;
}

int main() {
    int e, n;
    char plaintext[30];
    int cipher[30], len;

    // Input public key
    printf("Enter public key (e n): ");
    scanf("%d %d", &e, &n);

    // Input plaintext (uppercase letters only)
    printf("Enter the plaintext (CAPITAL LETTERS ONLY): ");
    scanf("%s", plaintext);
    len = strlen(plaintext);

    // Encrypt each character
    printf("\n--- Encryption ---\n");
    for (int i = 0; i < len; i++) {
        int index = find_index(plaintext[i]);
        if (index == -1) {
            printf("Invalid character: %c\n", plaintext[i]);
            return 1;
        }
        cipher[i] = mod_pow(index, e, n);
        printf("'%c' -> %d -> Cipher: %d\n", plaintext[i], index, cipher[i]);
    }

    // Display final cipher values
    printf("\nEncrypted numeric values: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", cipher[i]);
    }
    printf("\n");

    return 0;
}

	

