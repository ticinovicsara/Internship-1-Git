#include <stdio.h>

void print_array(int* array, int n){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void change(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(int* array, int start, int end){
    if(start == end){
        print_array(array, end + 1);
    }
    else{
        for(int i=start; i<=end; i++){
            change(&array[start], &array[i]);

            permutations(array, start + 1, end);

            change(&array[start], &array[i]);
        }
    }
}

int main(){
    int n;
    printf("Put how many elements are in array: ");
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        printf("Type %d. element: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Permutations are: \n");
    permutations(array, 0, n-1);

    return 0;
}