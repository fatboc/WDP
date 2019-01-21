#include "quicksort.h"

void quicksort(int * arr, int size){
    int i;
    printf("Jedziemy z quicksortem\n");
    for (i=0; i<size; i++)
        printf("%d; ", arr[i]);
    printf("\n");

        int p;
    if (size>5){
        p=part(arr, size);
        for (i=0; i<size; i++)
        printf("%d; ", arr[i]);
    printf("\n");
        quicksort(arr, p);
        quicksort(arr+p, size-p);
    }
    else switch(size){
        case 2:
            sort_2(arr);
            break;
        case 3:
            sort_3(arr);
            break;

        case 4:
            sort_4(arr);
            break;
            /*
        case 5:
            sort_5(arr);*/
    }
    printf("Wynik:\n");
    for(i=0; i<size; i++)
        printf("%d; ", arr[i]);
    printf("\n\n");
}

int part(int * arr, int size){
    int p=(size+1)/2, q=arr[p-1], i=-1, j=size, tmp;

    while(i<j){

        do{
            i++;
        }
        while(arr[i]<q);

        do{
            j--;
        }while(q<arr[j]);

        if (i>=j)
            return j+1;
        tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
    }

    return j+1;
}

void sort_2(int * arr){
    if(arr[0]>arr[1]){
        int tmp=arr[0];
        arr[0]=arr[1];
        arr[1]=tmp;
    }
}

void sort_3(int * arr){
    if(arr[0]>arr[1]){
        int tmp=arr[0];
        arr[0]=arr[1];
        arr[1]=tmp;
    }

    if(arr[1]>arr[2]){
        if(arr[0]>arr[2]){
            int tmp=arr[2];
            arr[2]=arr[1];
            arr[1]=arr[0];
            arr[0]=tmp;
        }
        else{
            int tmp=arr[2];
            arr[2]=arr[1];
            arr[1]=tmp;
        }
    }
}

void sort_4(int * arr){

//a,b,c,d
    if(arr[0]>arr[1]){
        int tmp=arr[0];
        arr[0]=arr[1];
        arr[1]=tmp;
    }
    if(arr[2]>arr[3]){
        int tmp=arr[2];
        arr[2]=arr[3];
        arr[3]=tmp;
    }

    //(a,b),(c,d)

    int tmp;

    if(arr[2]<arr[1]){
        if(arr[2]<arr[0]){
            if(arr[3]<arr[0]){ //c,d,a,b
                tmp=arr[2];
                arr[2]=arr[0];
                arr[0]=tmp;
                tmp=arr[1];
                arr[1]=arr[3];
                arr[3]=tmp;
            }
            else if(arr[3]<arr[1]){
                tmp=arr[2];
                arr[2]=arr[3];
                arr[3]=arr[1];
                arr[1]=arr[0];
            } //c,a,d,b
            else {
                tmp=arr[2];
                arr[2]=arr[1];
                arr[1]=arr[2];
                arr[2]=tmp;
            }//c, a, b,d
        }

        else{ //a<c, b>c, a, c, d?, b, d?
            if(arr[1]<arr[3]){
                tmp=arr[2];
                arr[2]=arr[3];
                arr[3]=tmp;
            } //a,c,b,d
            else{
                tmp=arr[2];
                arr[2]=arr[3];
                arr[3]=arr[1];
                arr[1]=tmp;
            } //a,c,d,b
        }
    }//a,b,c,d

}

