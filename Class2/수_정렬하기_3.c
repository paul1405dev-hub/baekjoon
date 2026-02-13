#include <stdio.h>
#define MAX 10000

int main(void){

    int num[MAX + 1] = {0};
    int value, x;
    scanf("%d", &x);
    
    for (int i = 1; i <= MAX; i++){

        num[i] = 0;
    }

    for (int i = 0; i < x; i++){

        scanf("%d", &value);
        num[value]++;
    }

    for (int i = 1; i <= MAX; i++){

        if (num[i] != 0){

            for (int j = 0; j < num[i]; j++){

                printf("%d\n", i);
            }
        }
    }

    return 0;
}