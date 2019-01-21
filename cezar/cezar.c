#include "cezar.h"

void cezar (FILE * source, FILE * dest, int key){
    int c;
    while((c=fgetc(source))!=EOF){
        if (isalpha(c)){
            if (isupper(c))
                fputc((c-65+key)%26 + 65, dest);
            else if (islower(c))
                fputc((c-97+key)%26 + 97, dest);
        }
        else
           fputc(c, dest);
    }

    rewind(source);
}

double * stat(FILE * file){

    double *result, sum=0.0;
    int i, c;
    result = calloc(26, sizeof(double));
    for (i=0; i<26; i++)
        result[i]=0;

    while((c=fgetc(file))!=EOF){
        if(isalpha(c)){
            if(islower(c))
                c-=97;
            else
                c-=65;
            result[c]++;
        }
    }

    for (i=0; i<26; i++)
        sum+=result[i];

    for (i=0; i<26; i++)
        result[i]/=sum*0.01;

    printf("Wyniki analizy statystycznej:\n");
    for (i=0; i<26; i++)
        printf("%c:\t%lf\n", i+65, result[i]);

    rewind(file);
    return result;
}

int max_2(double *arr, int size, int offset){

    double tmp[size];
    int i;
    for(i=0; i<size; i++)
        tmp[i]=arr[i];


    mergesort(tmp, size);

    for(i=0; i<size; i++)
        if(arr[i]==tmp[size-1-offset])
            return i;

    return -1;
}

int comp(double * freq, FILE * in){
    FILE * data;
    int count=0, c=0;
    double * values = NULL, * nvalues, cmp_limit;
    int max_freq, tmp, offset=0;

    if(!(data=fopen("frequency.txt", "r")))
        data=stdin;

    fscanf(data, "%lf\n", &cmp_limit);

    while ((c=fgetc(data))!=EOF){
        ungetc(c, data);
        nvalues = (double *) realloc(values, sizeof(double)*(count+1));
        values = nvalues;
        fscanf(data, "%lf\n", values+count);
        count++;
    }

    fclose(data);

    max_freq=max_2(freq, count, 0);

    tmp=max_2(values, count, offset);

    while (values[tmp]>cmp_limit){
        printf("Proponowany wynik:\n");
        cezar(in, stdout, -(tmp-1-max_freq-1)%26);
        printf("Czy wynik jest prawidlowy?(y/n)\n");

        while((c=getchar())!='n' ){
            if(c=='y')
                return 1;
            else{
                printf("Czy wynik jest prawidlowy?(y/n)\n");
                scanf("\n");
            }

        scanf("\n");
        }
        offset++;
        tmp=max_2(values, count, offset);
    }

    free(values);
    values=NULL;

    return 0;

}
