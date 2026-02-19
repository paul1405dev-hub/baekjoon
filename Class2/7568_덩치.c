#include <stdio.h>

typedef struct{

    int weight;
    int height;
    int rank;
} Member;

int main(void){

    int x;
    scanf ("%d", &x);

    Member arr[50];
    for (int i = 0; i < x; i++){

        scanf("%d %d", &arr[i].weight, &arr[i].height);
        arr[i].rank = 1;
    }

    for (int i = 0; i < x; i++){

        for (int j = 0; j < x; j++){

            if (arr[i].height < arr[j]. height && arr[i].weight < arr[j]. weight){

                arr[i].rank++;
            }

        }
    }

    for (int i = 0; i < x; i++){

        printf("%d ", arr[i].rank);
    }

    return 0;
}