#include "stack.h"

int main()
{
    char text[] = "()";
    if (braces(text, 2))
        printf("poprawne\n");
    else
        printf("niepoprawne\n");

    return 0;
}
