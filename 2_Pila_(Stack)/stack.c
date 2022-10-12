#include <stdio.h>
#include <stdbool.h>

#define LIMIT 5
#define EMPTY (-1)


int stack[LIMIT];
int top = EMPTY;      // Indice che mi indica l'ultimo elemento inserito


// Push: funzione per inserire un nuovo elemento
bool push(int nuovoElemento) {
    if(top == LIMIT - 1)
        return false;           // Overflow: lo stack è pieno, non posso aggiungere altro

    top++;
    stack[top] = nuovoElemento;
    return true;
}


// Pop: funzione per estrarre un elemento
int pop() {
    if(top == EMPTY)
        return EMPTY;           // Underflow: lo stack è vuoto, non posso cancellare nulla

    top--;
    return stack[top + 1];      // Restituisco il valore cancellato
}


void printStack() {
    if (top == EMPTY)
        printf("Stack vuoto!\n\n");

    else{
        printf("\t  ↑↓  \n");
        for(int i = top; i >= 0; i--)
            if(stack[i] != EMPTY)
                printf("\t| %02d |\n", stack[i]);

        printf("\n");
    }
}


int main() {
    printStack();

    printf("Inserisco 15:\n");
    push(15);
    printStack();

    printf("Inserisco 6:\n");
    push(6);
    printStack();

    printf("Inserisco 2, 21 e 77:\n");
    push(2);
    push(21);
    push(77);
    printStack();

    if(!push(9))
        printf("Con push(9) si è verificato overflow, elemento non aggiunto!\nStato attuale pila:\n");
    printStack();

    pop();
    printf("Dopo il primo pop:\n");
    printStack();   // E' stato cancellato 9 che è proprio l'ultimo elemento che ho aggiunto = LIFO

    pop();
    printf("Dopo il secondo pop:\n");
    printStack();

    // Cancello tutti gli elementi
    printf("Cancello tutti gli elementi:\n");
    int i;
    while((i = pop()) != EMPTY)
        printf("\tHo cancellato %d\n", i);

    // Provo ad eliminare un elemento dallo stack vuoto
    if(pop() == EMPTY)
        printf("\nCon quest'ultimo pop() si è verificato underflow, non ci sono più elementi da cancellare!\n");

    return 0;
}