#include <stdio.h>
#include <stdlib.h> // qsort 사용을 위해(정렬을 위한 함수)
#include <string.h> //strcmp 사용을 위해(두 문자열의 내용을 사전순으로 비교하는 데 사용)

int compare(const void* a, const void* b){

    char *str1 = (char *)a;
    char *str2 = (char *)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2){

        return len1 - len2;
    }
    
    return strcmp(str1, str2);
}   
int main(void){

    int x;
    scanf("%d", &x);

    char word[20000][51];
    for (int i = 0; i < x; i++){

        scanf("%s", word[i]); 
    }

    qsort(word, x, sizeof(word[0]), compare);
    
    for (int i = 0; i < x; i++){

        if (i > 0 && strcmp(word[i],word[i-1]) == 0){

            continue;
        }

        printf("%s\n", word[i]);
    }

    return 0;
}