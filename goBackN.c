#include <stdio.h>

int main() {
    int frames, window, i, ack;

    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter window size: ");
    scanf("%d", &window);

    i = 1;
    while (i <= frames) {
        printf("\nFrames sent: ");
        for (int j = i; j < i + window && j <= frames; j++)
            printf("%d ", j);

        printf("\nEnter last ACK received: ");
        scanf("%d", &ack);

        if (ack >= i && ack < i + window) {
            i = ack + 1; // move window
        } else {
            printf("Invalid ACK! Resending window...\n");
        }
    }
    return 0;
}

