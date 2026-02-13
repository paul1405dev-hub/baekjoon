//#include <stdio.h>

// void jud(int a, int b, int c);

// int main(void){

//     int a,b,c;

//     while(1){

//     scanf("%d %d %d", &a,&b,&c);
//     if (getchar() == '\n'){

//         jud(a,b,c);
//     }
//     else{

//         break;
//     }
//     }

//     return 0;
// }

// void jud(int a, int b, int c){

//     if (c*c == a*a + b*b || b*b == a*a + c*c || a*a == c*c + b*b){

//         if (c != 0){

//             printf("right\n");
//         }

//     }
//     else{

//         printf("wrong\n");
//     }
// }

#include <stdio.h>

int main(void){

    int a,b,c;
    while (scanf("%d %d %d", &a, &b, &c) == 3){
        if(a==0 && b==0 && c==0)    break;

        int x = a, y = b, z = c, t;
        if (x > y) {t = x; x = y; y = t;}
        if (y > z) {t = y; y = z; z = t;}
        if (x > z) {t = x; x = z; z = t;}

        if (z*z == x*x + y*y){

            printf("right\n");
        }
        else{

            printf("wrong\n");
        }

    }

    return 0;
}