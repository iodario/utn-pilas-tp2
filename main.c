#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    ejercicio2();
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

void ejercicio2()
{
    printf("Cargar desde el teclado una pila llamada ORIGEN e inicializar en vacío la pila DESTINO.\n");
    printf("Pasar todos los elementos de la pila ORIGEN a la pila DESTINO. \n");

    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);

//    apilar(&origen,1);
//    apilar(&origen,2);
//    apilar(&origen,3);
//    apilar(&origen,4);
//    apilar(&origen,5);

    //mejorado con do while
    //carga de pila
    char option = 's';
    do
    {
        leer(&origen);
        printf("Desea continuar cargando la pila? Presione s/n. \n");
        fflush(stdin);
        scanf("%c",&option);
    }
    while
(
    option == 's'
);
printf("MOSTRAR PILA ORIGEN, ANTES: \n");
mostrar(&origen);

    //se pasa de una pila a la otra
    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    printf("MOSTRAR PILA ORIGEN, DESPUES \n");
    mostrar(&origen);

    printf("MOSTRAR PILA DESTINO \n");
    mostrar(&destino);



}
