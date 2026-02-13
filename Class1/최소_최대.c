#include <stdio.h>
#include <stdlib.h>

int main(void){

    int x;
    scanf("%d", &x);

    int *num = malloc(sizeof(int) * x);
    if (num == NULL) return 1;

    for (int i = 0; i < x; i++){

        scanf("%d", num+i);
    }

    int min = num[0];
    int max = num[0];

    for (int i = 1; i < x; i++){

        if (num[i] < min){

            min = num[i];
        }
        else if(num[i] > max){

            max = num[i];
        }
    }

    printf("%d %d", min, max);
    free(num);
    return 0;
}