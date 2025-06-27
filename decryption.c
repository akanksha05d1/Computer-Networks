#include <stdio.h>
#include <string.h>

// Alphabet with index mapping: A=1, B=2, ..., Z=26
const char alphabet[] = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Modular exponentiation: (base^exp) % mod
int mod_pow(int base, int exp, int mod) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return (int)result;
}

int main() {
    int d, n, len;

    // Cipher array to hold encrypted numeric values
    int cipher[30];
    char decrypted[30];

    // Input private key
    printf("Enter private key (d n): ");
    scanf("%d %d", &d, &n);

    // Input length of ciphertext
    printf("Enter number of encrypted values: ");
    scanf("%d", &len);

    // Input ciphertext numeric values
    printf("Enter encrypted numeric values separated by space:\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &cipher[i]);
    }

    // Decrypt each numeric cipher to plaintext index
    printf("\n--- Decryption ---\n");
    for (int i = 0; i < len; i++) {
        int decrypted_index = mod_pow(cipher[i], d, n);
        if (decrypted_index < 1 || decrypted_index > 26) {
            printf("Decryption error: invalid decrypted index %d\n", decrypted_index);
            return 1;
        }
        decrypted[i] = alphabet[decrypted_index];
        printf("Cipher %d -> %d -> '%c'\n", cipher[i], decrypted_index, decrypted[i]);
    }

    decrypted[len] = '\0';

    // Output decrypted plaintext
    printf("\nDecrypted plaintext: %s\n", decrypted);

    return 0;
}

