#include "megesort.h"

int main()
{
    double arr[] = {7.0, 6.3, 0.0, 17.2, 9.6, 2.8, 5.5};
    mergesort(arr, 7);

    int i;

    for (i=0; i<7; i++)
        printf("%lf; ", arr[i]);
    return 0;
}
