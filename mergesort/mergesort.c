#include "megesort.h"

void mergesort (double * arr, int size){
    int p=size/2;

    if(size>1){
        mergesort(arr, p);
        mergesort(arr+p, size-p);
        merge(arr, size, p);
    }

}

void merge (double * arr, int size, int p){
    int i=0, j=p, k=0;

    double result[size];

    while(k<size){
        if(i<p && (arr[i]<arr[j] || j>=size)){
            result[k]=arr[i];
            i++;
        }
        else{
            result[k]=arr[j];
            j++;
        }
        k++;
    }

    for(i=0; i<size; i++)
        arr[i]=result[i];
}
