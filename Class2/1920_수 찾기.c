#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int compare(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int binary_serach(int* arr, int n, int target){

    int left = 0, right = n - 1;

    while (left <= right){

        int mid = (left + right) / 2;

        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return 0;
}

int main(void){

    int n,m;
    int num[MAX];
    int exi[MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++){

        scanf("%d", num+i);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++){

        scanf("%d", exi+i);
    }

    qsort(num, n, sizeof(num[0]), compare);
    
    for (int i = 0; i < m; i++){

        printf("%d\n", binary_serach(num, n, exi[i]));
    }

    return 0;
}