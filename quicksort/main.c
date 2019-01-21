#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {7, 6, 0, 5};
    quicksort(arr, 4);

    int i;

    for (i=0; i<4; i++)
        printf("%d; ", arr[i]);
    return 0;
}
