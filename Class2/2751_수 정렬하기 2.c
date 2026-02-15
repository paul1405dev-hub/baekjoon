#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int compare(const void* a, const void* b) {

    int x = *(const int*)a;
    int y = *(const int*)b;
	
    if (x < y)  return -1;
    if (x > y)  return 1;
    return 0;
}

int main(void){

    int x;
    scanf("%d", &x);

    int num[MAX];
    for (int i = 0; i < x; i++){

        scanf("%d", num + i);
    }

    qsort(num, x, sizeof(int), compare);

    for (int i = 0; i < x; i++){

        printf("%d\n", num[i]);
    }
    
    return 0;
}