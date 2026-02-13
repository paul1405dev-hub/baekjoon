#include <stdio.h>

// int main(void){

//     int num[10];
//     for (int i = 0; i < 10; i++){

//         scanf("%d", num+i);
//     }

//     int seen[42];
//     for (int i = 0; i < 42; i++){

//         seen[i] = 0;
//     }

//     int count = 0;
//     for (int i = 0; i < 10; i++){

//         int r = num[i] % 42;
//         if (seen[r] == 0){

//             seen[r] = 1;
//             count++;
//         }
//     }

//     printf("%d", count);

//     return 0;
// }


int main(void){


    int num[10];
    for (int i = 0; i < 10; i++){

        scanf("%d", num+i);
    }

    int new[10];
    int count = 0; 

    for (int i = 0; i < 10; i++){                   // new[0] -> 39 , count = 1;

        int r = num[i] % 42;
        int found = 0;

        for (int j = 0; j < count; j++){

            if (new[j] == r){

                found = 1;
                break;
            }
        }
        
        if (found == 0){

            new[count] = r;
            count++;
        }
    }

    printf("%d", count);
    return 0;
}