#include <stdio.h>
#include <string.h>

int main() {
    char data[100], temp[200];
    char poly[] = "1100000001111"; 
    int datalen, polyl = strlen(poly), i, j;

    printf("Enter binary data: ");
    scanf("%s", data);

    datalen = strlen(data);
    strcpy(temp, data);

    for (i = 0; i < polyl - 1; i++)
        temp[datalen + i] = '0';
    temp[datalen + i] = '\0';

   
    for (i = 0; i < datalen; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < polyl; j++) {
                temp[i + j] = (temp[i + j] == poly[j]) ? '0' : '1';
            }
        }
    }

    printf("CRC: %s\n", temp + datalen);
    return 0;
}
