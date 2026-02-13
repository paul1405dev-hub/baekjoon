#include <stdio.h>

int main(void){

    int x,y;
    
    while(scanf("%d %d", &x, &y) != EOF){

        if (x+y == 0){

            continue;
        }
        else{
            printf("%d\n", x+y);
        }
    }

    return 0;
}