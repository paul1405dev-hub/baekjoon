#include <stdio.h>

int main(void){

    int x;
    scanf("%d", &x);

    int num[1001];
    int max = 0;
    for (int i = 0; i < x; i++){    

        scanf("%d", num+i);
        if (num[i] >= max){

            max = num[i];
        }
    }

    float mul = 0;
    for (int i = 0; i < x; i++){

        mul += num[i] / (float)max * 100;
   }
   
    printf ("%f", mul/x);

    return 0;
}