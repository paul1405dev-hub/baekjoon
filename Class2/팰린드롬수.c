#include <stdio.h>
#define MAX 100000

int makeArr(int num, int arr[MAX], int* lastNum);

int main (void){

    int num;
    while (scanf("%d", &num) == 1){

        if (num == 0) break;

        int arr[MAX];
        int lastNum = 0;
        if (makeArr(num, arr, &lastNum) == 1){

            int i = 0;
            int isPal = 1;
            while (i < lastNum/2){

                if (arr[i] != arr[lastNum -1 - i]){

                    isPal = 0;
                    break;
                }
                i++;
            }
            if (isPal) printf("yes\n");
            else printf("no\n");
        }

    }

    return 0;
}

int makeArr(int num, int arr[MAX], int* lastNum){     // 숫자 배열 생성, 자릿수 확인, 0판별
    int  i = 0;
    int check = 1;
    while (num > 0){

        arr[i] = num % 10;
        num /= 10;
        i++;
    }
    *lastNum = i; // 1231 -> lastNum = 4
    return check;

}