#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct{

    int x;
    int y;
    
} pos;

int compare(const void* a, const void* b){

    const pos* q = (const pos*) a;
    const pos* w = (const pos*) b;

    if (q->y < w->y) return -1;
    if (q->y > w->y) return 1;

    if (q->x < w->x) return -1;
    if (q->x > w->x) return 1;

}
int main(void){

    int n;
    scanf("%d", &n);

    pos arr[MAX];
    for (int i = 0; i < n; i++){

        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    qsort(arr, n, sizeof(arr[0]), compare);

    for (int i = 0; i < n; i++){

        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    return 0;
}