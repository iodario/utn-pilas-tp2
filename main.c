#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    ejercicio1();
    return 0;
}


void ejercicio1()
{
    printf(" Cargar desde el teclado una pila llamada DADA con 5 elementos.\n" );
    printf("Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.\n" );

    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&dada,1);
    apilar(&dada,2);
    apilar(&dada,3);
    apilar(&dada,4);
    apilar(&dada,5);

    printf("MOSTRAR: PILA DADA, ANTES \n");
    mostrar(&dada);

    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));

    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    printf("MOSTRAR: PILA DADA, DESPUES \n");
    mostrar(&dada);

    printf("MOSTRAR: PILA AUX1 \n");
    mostrar(&aux1);

    printf("MOSTRAR: PILA AUX2 \n");
    mostrar(&aux2);

}
