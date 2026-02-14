#include <stdio.h>

int main(void){

    int n;
    scanf("%d", &n);

    int cnt = 0;
    while (n >= 5){

        n /= 5;
        cnt += n;
    }

    printf ("%d", cnt);
    return 0;
}