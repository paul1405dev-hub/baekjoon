#include <stdio.h>

int main(void){

    // 소수 찾기
    int n;
    scanf("%d", &n);

    int x;
    int count = 0;
    for (int i = 0; i < n; i++){

        scanf("%d", &x);

        int isPrime = 1;

        if (x == 1){

            isPrime = 0;
        }
        else{
            for (int j = 2; j * j <= x; j++){

                if((x % j) == 0){

                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime == 1){

            count++;
        }
    }

    printf("%d", count);
    
    return 0;
}