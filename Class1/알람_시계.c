#include <stdio.h>

void hour(int h,int m, int* ch, int* cm);
int main(void){

    int h, m, ch = 0, cm = 0;
    scanf("%d %d", &h, &m);

    hour(h, m - 45, &ch, &cm);

    printf("%d %d", ch, cm);
    return 0;
}

void hour(int h,int m, int* ch, int* cm){

    if (m < 0){

        *cm = 60 + m;
        if (h == 0){

            *ch = 23;
        }
        else {

            *ch = h - 1;
        }
    }
    else{

        *ch = h;
        *cm = m;
    }
}