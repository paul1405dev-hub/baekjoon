#include <stdio.h>

int main(void){

    char word[1000];
    int num;

    scanf("%s", word);
    //printf("%s", word);
    scanf("%d", &num);

    printf("%c", word[num-1]);

    return 0;
}