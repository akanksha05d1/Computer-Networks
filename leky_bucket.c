/* Leaky Bucket simulation */
#include <stdio.h>

int main(){
    int capacity, leakRate, steps;
    printf("Bucket capacity (packets): ");
    scanf("%d",&capacity);
    printf("Leak rate (packets per time unit): ");
    scanf("%d",&leakRate);
    printf("Number of time units to simulate: ");
    scanf("%d",&steps);

    int bucket = 0;
    for(int t=1; t<=steps; t++){
        int arrivals;
        printf("Time %d - incoming packets: ", t);
        scanf("%d",&arrivals);

        // accept as many as capacity allows
        int space = capacity - bucket;
        int accepted = arrivals <= space ? arrivals : space;
        int dropped = arrivals - accepted;
        bucket += accepted;

        // leak out
        int transmitted = (bucket >= leakRate) ? leakRate : bucket;
        bucket -= transmitted;

        printf("Accepted: %d, Dropped: %d, Transmitted: %d, InBucket(after): %d\n",
               accepted, dropped, transmitted, bucket);
    }
    return 0;
}

