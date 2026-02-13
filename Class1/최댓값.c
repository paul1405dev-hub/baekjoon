#include <stdio.h>

int main(void){
    
    int num[9];
    int x = 0;
    int max;

    for (int i = 0; i < 9; i++){

        //scanf("%d", &num[i]);
        scanf("%d", num + i); 
        
    }
    
    max = num[0];

    for (int i = 1; i < 9; i++){

        if (num[i] > max){

            max = num[i];
            x = i;
        }

    }  

    printf("%d\n", max);
    printf("%d", x+1);

    

    return 0;
}