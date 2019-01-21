#include "stack.h"

stack * add_element(stack * head, int val){
    stack * element = malloc(sizeof(stack));
    element->c=val;
    element->next=head;
    head=element;

    return element;
}

int read_element(stack * head){
    if(head)
        return head->c;

    return 0;
}

stack * delete_element(stack * head){
    stack * nhead=head->next;
    free(head);
    head=NULL;

    return nhead;
}

void delete_stack(stack * head){
    if (head->next)
        delete_stack(head->next);

    free(head);
    head=NULL;
}

int braces(char * string, int size){
    char left[] = "{[(<";
    char right[] = "}])>";
    int i;
    stack * head=NULL;

    for(i=0; i<size; i++)
            if(find(string[i], left, 4))
                head=add_element(head, string[i]);

    if(head)
        for (i=0; i<size; i++)
            if(find(string[i], right, 4))
                if(read_element(head)!=string[i])
                    return 0;
                else
                    delete_element(head);

    if(head)
        return 0;

    return 1;
}

int find(int val, int * arr, int size){
    int i=0;

    while(i<size){
        if(arr[i]==val)
            return 1;

        i++;
    }

    return 0;

}
