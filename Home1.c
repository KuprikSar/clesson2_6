#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 2000

#define DEBUG

typedef struct list
{
    char* word;
    struct list *next;
}list;


list* insert2(char* value,list *head);
void print_list(list * head);
void choose_sort_array_list(list * head);
void swap_elements(list *e1,list *e2);
void delete_list(list *head);
void print_first_last(list *head);
void remove_odd(list *head);

int main(int argc, char** argv)
{
list *w_list=NULL;
char word[STR_SIZE]="";
int ch = ' ';
int i=0;
    while(EOF != (ch = getchar()))
    {
        switch(ch)
        {
            case '.':
            case ' ':
                word[i] = '\0';
                w_list  = insert2(word, w_list);
                i=0;
            break;
            default:
                word[i++] = ch;
                if(i>=STR_SIZE)
                    i=0;
        }
        if('.' == ch)
            break;
    }

// #ifdef DEBUG
//     print_list(w_list);
// #endif


//    choose_sort_array_list(w_list);
//    print_list(w_list);
    remove_odd(w_list);
    printf("\n");
    print_first_last(w_list);
    delete_list(w_list);
    return 0;
}

void delete_list(list * l)
{
list * c =l;
list * n;
    while(c != NULL)
    {
        n = c->next;
        free(c->word);
        free(c);
        c = n;
    }
}

void choose_sort_array_list(list * head)
{
    for(list *i = head; i->next!=NULL; i=i->next)
    {
        list *min = i;
        for (list *j = i->next; j!=NULL; j=j->next)
            if(strcmp(j->word,min->word)>0)
                min = j;
        if( min != i )
            swap_elements(i,min);
    }
}


list* insert2(char* value,list *head)
{
 list *res = (list*)calloc(1,sizeof(list));
 int len = strlen(value);//определяем размер строки
 res->word = malloc(len+1);//выделяем память под строку
 strcpy(res->word, value);//копируем строку в память
 res->next = head;//смещаем указатель на следующий
 return res;
}

void swap_elements(list * e1, list *e2)
{
char* tmp    = e1->word;
    e1->word = e2->word;
    e2->word = tmp;
}

void print_list(list * head)
{
    for (list* i = head; i!=NULL; i=i->next)
        printf("%s ", i->word);
    putchar('\n');
}

void print_first_last(list *head)
{
    if (head == NULL)
        return;

    printf("%s ", head->word);

    list *last = head;
    while (last->next != NULL)
        last = last->next;

    printf("%s\n", last->word);
}

void remove_odd(list *head)
{
    list *current = head;
    list *prev = NULL;

    while (current != NULL)
    {
        if (current->next != NULL && current->next->next != NULL)
        {
            list *oddElement = current->next;
            current->next = oddElement->next;
            printf("%s ", oddElement->word);
            free(oddElement->word);
            free(oddElement);
        }
        prev = current;
        current = current->next;
    }
}