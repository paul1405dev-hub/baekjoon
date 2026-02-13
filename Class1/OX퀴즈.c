#include <stdio.h>

int func(int count);

int main(void){

    int x;
    scanf("%d", &x);

    char ox[81];

    for (int t = 0; t < x; t++){

        scanf("%s", ox);
        
        int ans = 0;
        int i = 0;

        while(ox[i] != '\0'){

            if(ox[i] == 'O'){               // O를 만나면 
                int count = 0   ;
                while(ox[i] == 'O'){        // O가 아닐때 까지 while문 실행

                    count++;                
                    i++;
                }

                ans += func(count);
            }
            else{

                i++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}


int func(int count){

    return count * (count + 1) / 2;
}