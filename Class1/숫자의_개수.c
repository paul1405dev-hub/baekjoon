#include <stdio.h>

int main(void){

    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);

    int x = a*b*c;

    int cnt[10] = {0};      // 0으로 초기화

    while(x > 0){

        cnt[x % 10]++;
        x /= 10;
    }

    for (int i = 0; i < 10; i++){

        printf("%d\n", cnt[i]);
    }
    return 0;
}