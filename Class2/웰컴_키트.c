#include <stdio.h>

int main(void){

    int n;
    scanf("%d", &n);

    // int s,m,l,xl,xxl,xxxl;
    // scanf("%d %d %d %d %d %d", &s,&m,&l,&xl,&xxl,&xxxl);
    int size[6];
    for (int i = 0; i < 6; i++){
        
        scanf("%d", size+i);

    }
    
    int t,p;
    scanf("%d %d", &t, &p);

    int countT = 0;
    for (int i = 0; i < 6; i++){

        if ((size[i] % t) != 0){

            countT += (size[i]/t + 1);
        }
        else{

            countT += size[i]/t;
        }

        // 올림 나눗셈
        // countT += (size[i] + t -1) / t
    }

    printf("%d\n", countT);
    printf("%d %d\n", n/p, n%p);
    return 0;
}