#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct{

    int age;
    char name[101];
    int idx;              // 입력 순서
} Member;

int compare(const void* a, const void* b){

    const Member* x = (const Member*)a;
    const Member* y = (const Member*)b;

    if (x->age < y->age) return -1;
    if (x->age > y->age) return 1;

    if (x->idx < y->idx) return -1;
    if (x->idx > y->idx) return 1;

    return 0;
}

int main(void){

    int x;
    scanf("%d", &x);

    Member arr[MAX];

    for (int i = 0; i < x; i++){

        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].idx = i;
    }

    qsort(arr, x, sizeof(Member), compare);

    for (int i = 0; i < x; i++){

        printf("%d %s\n", arr[i].age, arr[i].name);
    }

    return 0;
}