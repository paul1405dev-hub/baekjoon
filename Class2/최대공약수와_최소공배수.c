#include <stdio.h>

int gcd(int a, int b);

int main(void){

    int x,y;
    scanf("%d %d", &x, &y);

    int g = gcd(x,y);
    long long l = (long long)(x / g) * y;

    printf("%d\n", g);
    printf("%lld\n", l);
    return 0;
}

int gcd(int a, int b){

    if (b == 0){

        return a;
    }
    else{

        return gcd(b, a%b);
    }
}