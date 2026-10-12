
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

double calculate_mean(const int data[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return (double)sum / n;
}

double calculate_median(const int data[], int n) {
    int *sorted = malloc((size_t)n * sizeof(int));
    if (sorted == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    memcpy(sorted, data, (size_t)n * sizeof(int));
    qsort(sorted, (size_t)n, sizeof(int), compare);

    double median;
    if (n % 2 == 0) {
        median = ((double)sorted[n / 2 - 1] +
                  sorted[n / 2]) / 2.0;
    } else {
        median = sorted[n / 2];
    }

    free(sorted);
    return median;
}

void calculate_mode(const int data[], int n) {
    int *sorted = malloc((size_t)n * sizeof(int));
    if (sorted == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    memcpy(sorted, data, (size_t)n * sizeof(int));
    qsort(sorted, (size_t)n, sizeof(int), compare);

    int max_count = 0;
    for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n && sorted[j] == sorted[i]) {
            j++;
        }
        if (j - i > max_count) {
            max_count = j - i;
        }
        i = j;
    }

    printf("Mode: ");
    if (max_count == 1) {
        printf("No mode (all values occur once)");
    } else {
        int first = 1;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && sorted[j] == sorted[i]) {
                j++;
            }

            if (j - i == max_count) {
                printf("%s%d", first ? "" : ", ", sorted[i]);
                first = 0;
            }
            i = j;
        }
    }
    printf("\n");

    free(sorted);
}

int main(void) {
    int data[COUNT] = {4, 2, 7, 4, 9, 2, 4, 6, 2, 8};

    printf("C - Procedural Statistics\n");
    printf("Dataset: ");
    for (int i = 0; i < COUNT; i++) {
        printf("%d%s", data[i],
               i == COUNT - 1 ? "\n" : ", ");
    }

    printf("Mean: %.2f\n", calculate_mean(data, COUNT));
    printf("Median: %.2f\n", calculate_median(data, COUNT));
    calculate_mode(data, COUNT);

    return 0;
}
