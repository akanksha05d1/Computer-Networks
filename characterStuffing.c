#include <stdio.h>
#include <string.h>

int main() {
    char input[100], stuffed[200];
    char flag = 'F', esc = 'E';
    int i, j = 0;

    printf("Enter string: ");
    scanf("%s", input);

    stuffed[j++] = flag; // starting flag

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == flag || input[i] == esc) {
            stuffed[j++] = esc; // escape
        }
        stuffed[j++] = input[i];
    }

    stuffed[j++] = flag; // ending flag
    stuffed[j] = '\0';

    printf("After Character Stuffing: %s\n", stuffed);
    return 0;
}

