#include <stdio.h>
#include <stdlib.h>

int main(void){

    //    === 문제 착각으로 잘못짠 코드 ===

    // int x;                                         
    // scanf ("%d", &x);

    // char** arr = malloc(sizeof(char*) * x);       //arr[x][size] 

    // for (int i = 0; i < x; i++){

    //     int size;
    //     scanf("%d", &size);
    //     getchar();
    //     arr[i] = malloc(sizeof(char) * size);

    //     for (int j = 0; j < size; j++){

    //         arr[i][j] = getchar();
    //     }
        
    //     int k = 0;
    //     int c = 0;
    //     while (1){

    //         printf("%c", arr[i][k]);            
    //         if (c < size){                      
    //             c++;                            
    //         }
    //         if (c == size){
    //             c = 0;
    //             k++;
    //         }
    //         if (k == size){
    //             break;
    //         }
    //     }
    //     printf("\n");

    // }



    int x;                                         
    scanf ("%d", &x);
    
    int r;
    char sen[21];

    for (int i = 0; i < x; i++){

        scanf("%d %s", &r,sen);

        int y = 0;  //배열 값
        int t = 0;  //r 만큼 반복 
        // while(1){

        //     printf("%c",sen[y]);  
        //     if (t < r){             
        //         t++;
        //     }
        //     if (t == r){    
        //         t = 0;        
        //         y++;
        //     }
        //     if (sen[y] == '\0'){
        //         break;
        //     }

        // }

        while (sen[y] != '\0'){

            printf("%c",sen[y]);
            if (t < r){             
                t++;
            }
            if (t == r){
                t = 0;
                y++;
            }
        }
        printf("\n");
        
    }

    return 0;
}