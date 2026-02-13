#include <stdio.h>

int main(void){

    // 0층 1호(1) 2호(2) 3호(3)
    // 1층 1호(1) 2호(3) 3호(6)
    // 2층 1호(1) 2호(4) 3호(10)
    //                  3호(15)
    // 

    // 뼈대 만들기

    int apt[15][15] = {0};

    for (int n = 1; n < 15; n++){
        apt[0][n] = n;
    }
    for (int k = 0; k < 15; k++){

        apt[k][1] = 1;
    }

    for (int k = 1; k < 15; k++){

        for (int n = 2; n < 15; n++){

            apt[k][n] = apt[k][n-1] + apt[k-1][n];
        }
    }

    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++){

        int floor, room;
        scanf("%d %d", &floor, &room);
        printf("%d\n", apt[floor][room]);

    }



    return 0;
}