#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int* array, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void permutations(int* array, int start, int end) {
    if (start == end) {
        print_array(array, end + 1);
    }
    else {
        for (int i=start; i <= end; i++) {
            swap(&array[start], &array[i]);

            permutations(array, start + 1, end);

            swap(&array[start], &array[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);
    int* array = (int*)malloc(n * sizeof(int));

    for (int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Permutations are:\n");
    permutations(array, 0, n-1);

    free(array);
    return 0;
}
