#include <stdio.h>

int main(void){

    int n, m;
    scanf("%d %d", &n, &m);

    int x[100];
    for (int i = 0; i < n; i++){

        scanf("%d", x+i);
    }

    // 3개를 뽑아서 더했을 때, m과 최대한 가까운 카드 3장의 합
    int best = 0;

    for (int i = 0; i < n-2; i++){

        for (int j = i+1; j < n-1; j++){

            for (int k = j+1; k < n; k++){

                int sum = x[i] + x[j] + x[k];
                if (sum <= m && sum > best){

                    best = sum;
                }
            }
        }
    }

    printf("%d", best);

    return 0;
}