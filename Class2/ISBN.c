#include <stdio.h>

int main(void){

    // * -> 42
    char str[20];
    int isbn[13];
       
    scanf("%s", str);

    for (int i = 0; i < 13; i++){

        if (str[i] == '*'){

            isbn[i] = -1;
        }
        else{

            isbn[i] = str[i] - '0';
        }
    }

    //10 - isbn[12] = () % 10
    int x = 0;
    int count = 0;  // 3을 곱하는지 여부
    for (int i = 0; i < 13; i++){

        if (i == 0 || i%2 == 0){

            if (isbn[i] == -1){

                continue;
            }
            x += isbn[i];
        }
        else{

            if (isbn[i] == -1){

                count = 1;
                continue;
            }            
            x += isbn[i] * 3;
        }
    }

    int ans = (10 - (x % 10)) % 10;
    
    if (count == 1){
        
        for (int i = 0; i <= 9; i++){

            if ((i * 3) % 10 == ans){

                printf("%d", i);
                break;
            }
        }
    }
    else printf("%d", ans);

    return 0;
}