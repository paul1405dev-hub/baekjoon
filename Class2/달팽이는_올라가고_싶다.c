#include <stdio.h>

int main(void){

    int a,b,v,day = 0;
    scanf("%d %d %d", &a,&b,&v);

    day = (v-a+(a-b-1)) / (a-b) + 1;

    printf("%d", day);

    return 0;
}