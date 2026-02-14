#include <stdio.h>
#include <string.h>

int main(void){

    int n;
    scanf ("%d", &n);

    int i = 666, count = 0;
    char buffer[20];
    while (count != n){

        sprintf (buffer, "%d", i);

        if (strstr(buffer , "666") != NULL){

            count++;
        }

        i++;
    }

    printf("%d", i-1);

    return 0;
}