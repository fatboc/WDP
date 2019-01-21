#include"cezar.h"

int main(int argc, char *argv[])
{
    FILE *in, *out;

    if(!(in=fopen(argv[1], "r")))
        in=stdin;

    out=fopen(argv[2], "w");

    double * freq = stat(in);

    if(argc == 4)
        cezar(in, out, atoi(argv[3]));
    else if (argc == 3){
        if(!comp(freq, in))
        printf("Nie udalo sie znalezc klucza\n");
    }
    else
        printf("Niewlasciwa liczba argumentow\n");

    free(freq);
    freq=NULL;

    fclose(in);
    fclose(out);
    return 0;
}
