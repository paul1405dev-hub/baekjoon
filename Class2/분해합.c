#include <stdio.h>

int cal(int x);

int main(void){

    int N;
    scanf ("%d", &N);

    for (int i = 1; i < N; i++){

        if (cal(i) == N){
                
            printf ("%d", i);
            return 0;
        }
    }
    
    printf("0");
    return 0;
}

int cal(int x){

    int sum = x;
    while (x > 0){

        sum += (x % 10);
        x /= 10;
    }

    return sum;
}