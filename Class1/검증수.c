#include <stdio.h>

int main(void){

    int uniqueNum[5];
    int calNum[5];
    int sum = 0; 

    for (int i = 0; i < 5; i++){

        scanf("%d", &uniqueNum[i]);
        calNum[i] = uniqueNum[i] * uniqueNum[i];
        //printf("%d\n", calNum[i]);
        sum += calNum[i];                           
        //printf("%d\n", sum);
    }

    printf("%d", sum % 10);

    return 0;
}