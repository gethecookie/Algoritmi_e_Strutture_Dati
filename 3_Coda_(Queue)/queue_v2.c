#include <stdio.h>
#include <stdbool.h>

#define LIMIT 5
#define EMPTY (-1)


int queue[LIMIT];
int tail = -1;      // Indice che mi indica da dove inserire
int head = -1;      // Indice che mi indica da dove estrarre


// Enqueue: funzione per inserire un nuovo elemento
bool enqueue(int nuovoElemento) {
    if (tail == LIMIT - 1)
        return false;               // Overflow

    if (head == EMPTY)
        head = 0;

    tail++;
    queue[tail] = nuovoElemento;
    return true;
}


// Dequeue: funzione per estrarre un elemento
int dequeue() {
    if (head == EMPTY || head > tail)
        return EMPTY;               // Underflow

    head++;
    return queue[head - 1];        // Restituisco il valore cancellato
}


void printQueue() {
    if (head == EMPTY)
        printf("Coda vuota!\n\n");

    else{
        printf("\t(exit) ← ");
        for (int i = head; i <= tail; i++)
            printf("| %02d | ", queue[i]);

        printf("← (entry)\n\n");
    }
}


int main() {
    printQueue();

    printf("Inserisco 15:\n");
    enqueue(15);
    printQueue();

    printf("Inserisco 6:\n");
    enqueue(6);
    printQueue();

    printf("Inserisco 2, 21 e 77:\n");
    enqueue(2);
    enqueue(21);
    enqueue(77);
    printQueue();

    if(!enqueue(9))
        printf("Con enqueue(9) si è verificato overflow, elemento non aggiunto! \nStato attuale coda:\n");
    printQueue();

    dequeue();
    printf("Dopo il primo dequeue:\n");
    printQueue();   // E' stato cancellato 9 che è proprio il primo elemento che ho aggiunto = FIFO

    dequeue();
    printf("Dopo il secondo dequeue:\n");
    printQueue();

    if(!enqueue(14))
        printf("Con enqueue(14) si è verificato overflow perché non abbiamo una coda circolare, elemento non aggiunto! \nStato attuale coda:\n");
    printQueue();

    // Cancello tutti gli elementi
    printf("Cancello tutti gli elementi:\n");
    int i;
    while((i = dequeue()) != EMPTY )
        printf("\tHo cancellato %d\n", i);

    // Provo ad eliminare un elemento dalla coda vuota
    if(dequeue() == EMPTY)
        printf("\nCon quest'ultimo dequeue() si è verificato underflow, non ci sono più elementi da cancellare!\n");

    return 0;
}