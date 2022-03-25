#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Knot Knot;

struct Knot{
    int data;
    Knot *next;
}*start=NULL;

int menu(){
    int op;
    printf("Choose: \n1 - Insert at the beginning. \n2 - Insert at the end. \n3 - Show. \n4 - Change list. \n5 - Delete 1 element. \n6 - Delete all. \n0 - Finish. \nOption: ");
    scanf("%d", &op);
    return op;
}

void insert_beginning(int num){
    Knot *new;
    new = (Knot*) malloc(sizeof(Knot));

    new->data = num;

    new->next = start;
    start = new;
    printf("\nNUMBER ENTERED SUCCESSFULLY.\n\n");
}

void insert_end(int num){
    Knot *new;
    new = (Knot*) malloc(sizeof(Knot));
    new->data = num;

    if(start == NULL){
        new->next = start;
        start = new;
    }else{
        Knot *aux = start;
        while (aux->next != NULL) aux = aux->next;
        new->next = NULL;
        aux->next = new;
    }
    printf("\nNUMBER ENTERED SUCCESSFULLY.\n\n");
}

void show(){
    Knot *aux = start;
    printf("\n+----------------------------------------------------------------------+\n| List:");
    while (aux != NULL){
        printf(" %d ", aux->data);
        aux = aux->next;
    }
    printf("\n+----------------------------------------------------------------------+\n\n");
}

Knot* search(int num){
    Knot *aux = start, *retorno = NULL;
    
    do{
        if(num == aux->data){
            retorno = aux;
            break;
        }else
            aux = aux->next;
    }while (aux != NULL);

    return retorno;
}

void change_list(int num, Knot* element){
    element->data = num;
    printf("\n\nTHE NUMBER WAS SUCCESSFULLY CHANGED, CHECK THE UPDATED LIST.");
    show();
    sleep(2);
}

void delete(int number){
    Knot *delete, *aux;

    if(start->data == number){
        aux = start;
        start = aux->next;
        aux = NULL;
    }else{
        aux = start;
        while(aux->next && aux->next->data != number) aux = aux->next;

        if (aux->next){
            delete = aux->next;
            aux->next = delete->next;
            delete = NULL;
        }
    }

    printf("\n\nTHE NUMBER WAS SUCCESSFULLY DELETED, CHECK THE UPDATED LIST.");
    show();
    sleep(2);
}

void delete_all(){
    Knot *aux;
    while(start){
        if(start->next){
            aux = start;
            start = aux->next;
            aux = NULL;
        }else 
            start = NULL;
    }
    printf("\nALL THE ELEMENTS OF THE LIST WERE EXCLUDED.\n\n");
}

int check_list(){
    if(start)
        return 1;
    else{
        printf("\nEmpty list.\n\n");
        return 0;
    }
}

int main(){
    system("cls");
    int op, num;
    do{
        op=menu();
        switch (op){
        case 1: // INSERTS AT THE BEGINNING OF THE LIST
            printf("\nEnter a number to be inserted at the beginning of the list: ");
            scanf("%d", &num);
            insert_beginning(num);
        break;
        case 2: // INSERTS AT THE END OF THE LIST
            printf("\nEnter a number to be inserted at the end of the list: ");
            scanf("%d", &num);
            insert_end(num);
        break;
        case 3: // SHOWS LIST
            if(check_list())
                show();
        break;
        case 4: // CHANGES THE LIST
            if(check_list()){
                Knot *element;
                printf("\nTake a look at the current list situation.\n");

                show();
                sleep(2);

                printf("\nEnter the element you want to REPLACE in the list: ");
                scanf("%d", &num);

                element = search(num);

                if(element){
                    printf("\nNow, enter the value that will REPLACE the number %d: ", num);
                    scanf("%d", &num);
                    change_list(num, element);
                }else
                    printf("\nThe number entered was not found.\n\n");
            }
        break;

        case 5: // EXCLUDES FROM THE LIST
            if(check_list()){
                printf("\nObserve the current situation of the list.\n");

                show();
                sleep(2);
                   
                printf("\nEnter the element you want to DELETE from the list: ");
                scanf("%d", &num);
                    
                delete(num);
            }
        break;

        case 6: // DELETES ALL ELEMENTS FROM THE LIST
            if(check_list())
                delete_all();
            break; 

        case 0: // EXIT THE SYSTEM
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|         EXITING THE SYSTEM          |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            sleep(2);
        break;

        default:
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|           INVALID OPTION            |\n");
            printf("|   ENTER AN OPTION BETWEEN 0 AND 6   |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
        break;
        }
    }while (op);
}