#include <stdio.h>
#define MAX 1000005

int main(void){

    char str[MAX];
    fgets(str,MAX,stdin);

    int count = 0;
    int i = 0;
    //        //==== 공백의 갯수를 통해 단어의 갯수를 세는 코드 ====
    // while(1){


    //     if (str[i] == ' '){

    //         count++;
    //         if (i == 0){
    //             count--;
    //         }
    //     }
    //     if (str[i] == '\n'){
            
    //         if (str[i-1] == ' '){
    //             count--;
    //         }
    //         break;
    //     }
    //     i++;             //마지막 printf("%d\n", count + 1);
    // }

    //==== '단어 시작'을 세는 방식 ====

    while(str[i] != '\0' && str[i] != '\n'){

            if (str[i] != ' ' && (i == 0 || str[i-1] == ' ')){

                count++;
            }
            i++;
        }

    printf("%d\n", count);

    return 0;
}