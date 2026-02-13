#include <stdio.h>
#include <stdlib.h>

int isNum(char str[]){

    if (str[0] >= '0' && str[0] <= '9'){

        return 1;
    }
    return 0;
}

int isFizz(int target){

    if (target % 3 == 0 && target % 5 == 0){

        return 2;
    }
    else if (target % 3 != 0 && target % 5 == 0){

        return 1;
    }
    else if (target % 3 == 0 && target % 5 != 0){

        return 0;
    }
    else return -1;
}
int main(void){

    char str1[10];
    char str2[10];
    char str3[10];

    scanf("%s %s %s", str1,str2,str3);

    int num, target;

    if (isNum(str1)){

        num = atoi(str1);
        target = num + 3;
    }
    else if (isNum(str2)){

        num = atoi(str2);
        target = num + 2;
    }   
    else if (isNum(str3))
    {
        num = atoi(str3);
        target = num + 1;
    }
    
    int r = isFizz(target);

    if (r == -1) printf("%d", target);
    else if (r == 0) printf("Fizz");
    else if (r == 1) printf("Buzz");
    else printf("FizzBuzz");

    return 0;
}