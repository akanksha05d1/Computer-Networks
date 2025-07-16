#include <stdio.h>
#include <string.h>

// Function to perform XOR operation between remainder and divisor
void xor(char *remainder, char *divisor, int len) {
    for (int i = 0; i < len; i++) {
        if (remainder[i] == divisor[i]) {
            remainder[i] = '0';
        } else {
            remainder[i] = '1';
        }
    }
}

int main() {
    char data[100], divisor[100], transmitted[200], remainder[100];
    int dataLen, divisorLen, totalLen;

    // Get input
    printf("Enter the data bits: ");
    scanf("%s", data);
    printf("Enter the divisor: ");
    scanf("%s", divisor);

    dataLen = strlen(data);
    divisorLen = strlen(divisor);
    totalLen = dataLen + divisorLen - 1;

    // Copy original data and append zeros for division
    strcpy(transmitted, data);
    for (int i = 0; i < divisorLen - 1; i++) {
        transmitted[dataLen + i] = '0';
    }
    transmitted[totalLen] = '\0';

    // Copy initial bits to remainder
    strncpy(remainder, transmitted, divisorLen);
    remainder[divisorLen] = '\0';

    // Perform CRC division
    for (int i = 0; i <= totalLen - divisorLen; i++) {
        if (remainder[0] == '1') {
            xor(remainder, divisor, divisorLen);
        }

        // Shift left and bring the next bit down
        for (int j = 0; j < divisorLen - 1; j++) {
            remainder[j] = remainder[j + 1];
        }
        remainder[divisorLen - 1] = transmitted[i + divisorLen];
    }

    // Append remainder (CRC bits) to original data
    strncpy(transmitted + dataLen, remainder, divisorLen - 1);
    transmitted[totalLen] = '\0';

    // Output result
    printf("CRC Remainder: ");
    for (int i = 0; i < divisorLen - 1; i++) {
        printf("%c", remainder[i]);
    }
    printf("\n");

    printf("Transmitted Data: %s\n", transmitted);

    return 0;
}

