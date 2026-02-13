#include <stdio.h>

#define MAX 10000

int main(void){

    int n, x;
    int A[MAX];

    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++){

        scanf("%d ", &A[i]);

        if (A[i] < x){

            printf("%d ", A[i]);
        }
    }

    
    return 0;
}