#include <stdio.h>

int main(void){

    int n = 0;
    int num[100];
    int x = 0;
    int ans = 0;

    scanf("%d", &n);
    getchar();                  // 첫 숫자만 읽고 엔터는 입력 버퍼에 남겨두기에 getchar()을 통해 받아주기

    for (int i = 0; i < n; i++){

        num[i] = getchar();     // 아스키코드로 받음(문자) // '1''0''9'
        x = num[i] - '0';       // 숫자로 변환했을 때, '0' = 48 '1' = 49 '2' = 50... '0'을 빼면 ''를 뺀 정수 값이 나옴
        ans += x;
    }

    printf("%d\n", ans);

    return 0;
}   