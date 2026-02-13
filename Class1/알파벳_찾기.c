#include <stdio.h>

int main(void){

    // 26 a~z 97 ~ 122

    //26칸이 있는 배열을 -1로 다 초기화/ for 문을 돌면서/ if 문을 통해 같은지 확인/ 같으면 i의 값을 같은 곳에 넣기/배열 출력

    char str[101];
    scanf("%s", str);  

    int abc[123];
    for (int i = 97; i <= 122; i++){

        abc[i] = -1;

    }

    for (int i = 0; str[i] != '\0'; i++){

        //abc[97] -> -1 이고, str[0] -> b(98), str[1] -> a(97)
        int j = 97;
        while(j <= 122){

            if (str[i] == j && abc[j] == -1){

                abc[j] = i;
                break;
            }
            j++;
        }

    }

    for (int i = 97; i <= 122; i++){

        printf("%d ", abc[i]);
    }

    return 0;
}