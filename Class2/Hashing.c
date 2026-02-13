#include <stdio.h>
#define M 1234567891
int main(void){

    int n;
    scanf("%d", &n);

    char eng[50];
    scanf ("%s", eng);
    
    long long sum = 0;              // int를 넘기 쉬워서 long long으로
    long long pow = 1;
    long mod = M;
    for (int i = 0; i < n; i++){

        int x = eng[i] - 96;
        if (i >= 1) pow = (pow * 31) % mod;
        sum = (sum + x * pow) % mod;
    }
    printf("%lld", sum);

    return 0;
}

    // for (int i = 0; i < n; i++){       // i -> 자릿수(제곱 해야하는 수)

    //     scanf(" %c", eng+i);
    //     printf("%d\n", eng[i]);
    // }