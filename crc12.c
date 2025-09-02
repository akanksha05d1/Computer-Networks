#include <stdio.h>
#include <string.h>

#define POLY "1100000001111"  // CRC-12 polynomial (x^12 + x^11 + x^3 + x^2 + x + 1)

void compute_crc(char data[], char crc[]) {
    int data_len = strlen(data);
    int poly_len = strlen(POLY);

    // Append (poly_len - 1) zeros to data
    char temp[1024];
    strcpy(temp, data);
    for (int i = 0; i < poly_len - 1; i++) {
        strcat(temp, "0");
    }

    int temp_len = strlen(temp);

    // Copy temp into remainder
    char remainder[1024];
    strcpy(remainder, temp);

    // Perform division
    for (int i = 0; i <= temp_len - poly_len; i++) {
        if (remainder[i] == '1') {
            for (int j = 0; j < poly_len; j++) {
                remainder[i + j] = (remainder[i + j] == POLY[j]) ? '0' : '1';
            }
        }
    }

    // Last (poly_len - 1) bits are the CRC
    strncpy(crc, &remainder[temp_len - (poly_len - 1)], poly_len - 1);
    crc[poly_len - 1] = '\0';
}

int main() {
    char data[512], crc[64];

    printf("Enter binary data: ");
    scanf("%s", data);

    compute_crc(data, crc);

    printf("CRC-12 for %s is: %s\n", data, crc);

    return 0;
}

