#include <stdio.h>
#include <stdbool.h>

#define LIMIT 5

int queue[LIMIT];
int tail = 0;      // Indice che mi indica da dove inserire


// Enqueue: funzione per inserire un nuovo elemento
bool enqueue(int nuovoElemento) {
    if (tail == LIMIT)
        return false;               // Overflow

    queue[tail] = nuovoElemento;
    tail++;
    return true;
}


// Dequeue: funzione per estrarre un elemento
int dequeue() {
    if(tail == 0)
        return -1;               // Underflow

    int deleted = queue[0];

    // Cambio gli indici degli elementi
    for(int i = 0; i < tail-1; i++)
        queue[i] = queue[i+1];

    tail--;
    return deleted;
}


void printQueue() {
    if (tail == 0)
        printf("Coda vuota!\n\n");

    else{
        printf("\t(exit) ← ");
        for (int i = 0; i <= tail-1; i++)
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

    enqueue(14);
    enqueue(16);
    enqueue(18);
    printf("Inserisco 14, 16 e 18:\n");
    printQueue();

    // Cancello tutti gli elementi
    printf("Cancello tutti gli elementi:\n");
    int i;
    while((i = dequeue()) != -1 )
        printf("\tHo cancellato %d\n", i);

    // Provo ad eliminare un elemento dalla coda vuota
    if(dequeue() == -1)
        printf("\nCon quest'ultimo dequeue() si è verificato underflow, non ci sono più elementi da cancellare!\n");

    return 0;
}