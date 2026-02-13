#include <stdio.h>

int nCk(int n, int k){

    int z = 1;
    int p = n-k;
    while (p >= 1){

        z *= p;
        p--;
    } // z -> p!
    int x = 1;
    while (n >= 1){

        x *= n;
        n--;
    } // x -> n!

    int y = 1;
    while (k >= 1){

        y *= k;
        k--;
    } //y -> k!
    

    int ans = x/(y*z);
    return ans;
}
int main(void){

    int n,k;
    scanf("%d %d", &n, &k);
    
    printf("%d", nCk(n,k));

    return 0;
}
    