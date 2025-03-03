#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    ejercicio6 ();
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


void ejercicio3()
{
    printf(" Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.\n\n");
    Pila dada, distintos, aux;
    inicpila(&dada);
    inicpila( &distintos);
    inicpila(&aux);

    //carga
    char option = 's';
    do
    {
        leer(&dada);
        printf("Desea continuar cargando datos a la pila? continuar s/n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while
    (
        option == 's'
    );

    printf("MOSTRAR PILA DADA, ANTES: \n");
    mostrar(&dada);

    //logica

    while (!pilavacia(&dada))
    {
        if(tope(&dada)==8)
        {
            apilar(&aux, desapilar(&dada));
        }
        else
        {
            apilar(&distintos, desapilar(&dada));
        }
    };

    printf("MOSTRAR PILA DADA, DESPUES: \n");
    mostrar(&dada);

    printf("MOSTRAR PILA DISTINTOS: \n");
    mostrar(&distintos);

    printf("MOSTRAR PILA AUX: \n");
    mostrar(&aux);


}

void ejercicio4()
{
    printf(" Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. \n");
    printf("Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.\n\n");

    Pila origen, destino, aux;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    //carga
    char option = 's';
    do
    {
        leer(&origen);
        printf("Desea continuar cargando datos a la pila? continuar s/n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while
    (
        option == 's'
    );

    printf("MOSTRAR PILA origen, ANTES: \n");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }

    while(!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }

    printf("MOSTRAR PILA origen, DESPUES: \n");
    mostrar(&origen);

    printf("MOSTRAR PILA DESTINO: \n");
    mostrar(&destino);

}

void ejercicio5()
{
    printf(" Cargar desde el teclado la pila DADA \n");
    printf(" Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.\n\n");

    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    //carga
    char option = 's';
    do
    {
        leer(&dada);
        printf("Desea continuar cargando datos a la pila? continuar s/n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while
    (
        option == 's'
    );

    printf("MOSTRAR PILA dada, ANTES: \n");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }

    while(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }

    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("MOSTRAR PILA dada, DESPUES: \n");
    mostrar(&dada);


}

void ejercicio6()
{
    printf("Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden. \n\n");

    Pila dada, aux1, aux2;
    inicpila(&aux1);
    inicpila(&dada);
//    inicpila(&aux2); // otra solucion

    //INCLUIMOS CARGA CON RAND, PARA CUATRO ELEMENTOS
    int i=0;
    int num;
    srand(time(NULL));
    while(i<4)
    {
        num = rand()%10+1;
        apilar (&dada, num);
        i++;
    }
    printf("MOSTRAR PILA DADA, ANTES: \n");
    mostrar(&dada);

    //separo el tope y lo guardo en una variable
    int dato;
    dato=desapilar(&dada);
    printf("PILA DADA, SIN EL TOPE: \n");
    mostrar(&dada);

    //otra solucion
//    if(!pilavacia(&dada))
//    {
//        apilar(&aux2, desapilar(&dada));
//    }


    //desapilo dada y apilo en aux1
    while(!pilavacia(&dada))
    {
        apilar(&aux1,desapilar(&dada));
    }
    //mostrar(&aux1);

    //apilo en dada y coloco primero la variable dato
    apilar(&dada,dato);

    //desapilo aux1 y apilo en dada
    while(!pilavacia(&aux1))
    {
        apilar(&dada,desapilar(&aux1));
    }

    printf("PILA DADA, con el anterior tope como base: \n");
    mostrar(&dada);


}




