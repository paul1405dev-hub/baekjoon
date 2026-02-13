#include <stdio.h>

int main(void){

    int num;
    scanf ("%d", &num);

    // 1
    // 2~7 (6)
    // 8~19 (12)
    // 20~37 (18)
    // 38~61 (24)       
    // 늘어난 갯수에 6을 나눈 것 + 1 

    // 1 + 6 + 12 + 18 -> 1 + 6(1+2+3) 

    int i = 1;
    int sum = 1;
    int floor = 0;
    while(i){

        sum += 6*i;
        if (num == 1){
            printf("%d", 1);
            break;
        }
        if (num <= sum){

            floor = i;
            printf("%d", floor+1);
            break;
        }
        
        i++;
    }
    return 0;
}