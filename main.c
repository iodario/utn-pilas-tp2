#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"

int main()
{
    ejercicio11();
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
        printf("Desea continuar cargando datos a la pila? continuar s/n \n");
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

void ejercicio7()
{
    printf("Pasar el ultimo elemento (base) de la pila DADA a su primera posicion (tope), dejando los restantes elementos en el mismo orden.\n\n");


    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    //carga automatica
//    srand(time(NULL));
//    int cantElementos;
//    do
//    {
//        printf("Ingrese la cantidad de elementos a cargar en la pila, maximo 50 \n\n");
//        scanf("%d",&cantElementos);
//
//        if(cantElementos >0 && cantElementos <=50)
//        {
//            for( int i = 0; i < cantElementos ; i++)
//            {
//                apilar(&dada, rand() %11);
//            }
//        }else
//        {
//            printf("La cantidad ingresada es invalida, debe ser entre 1 y 50. \n");
//        };
//    }while (cantElementos <= 0 || cantElementos >50);

//    printf("SE MUESTRA LA PILA dada. Antes: \n");
//    mostrar(&dada);


    // otra forma, de carga
    int cantElementos;
    srand(time(NULL));
    do
    {
        printf("Ingrese la cantidad de elementos a cargar (maximo 50): \n");
        scanf("%d", &cantElementos);

        if (cantElementos > 0 && cantElementos <= 50)
        {
            for (int i = 0; i < cantElementos; i++)
            {
                apilar(&dada, rand() % 19);
            }
            break; // Salimos del bucle si la cantidad es válida
        }

        printf("La cantidad ingresada es inválida. Debe estar entre 1 y 50.\n");
    }
    while (1);   // Se repite hasta que se ingrese un valor válido

    printf("SE MUESTRA LA PILA dada. Antes: \n");
    mostrar(&dada);


    //logica
    while(!pilavacia(&dada))
    {
        apilar(&aux1,desapilar(&dada));
    }

    apilar(&aux2, desapilar(&aux1)); // paso el tope

    while(!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }

    apilar(&dada, desapilar(&aux2)); // paso el nuevo tope

    printf("Se muestra pila dada con la anterior base como nuevo tope. \n");
    mostrar(&dada);
}

ejercicio8()
{
    Pila mazo, jug1, jug2;
    inicpila(&mazo);
    inicpila(&jug1);
    inicpila(&jug2);

    //carga de pila
    srand(time(NULL));
    int cantElementos;

    do
    {
        printf("Ingrese la cantidad de cartas a utilizar, no mas de 40. \n\n");
        scanf("%d", &cantElementos);
        if(cantElementos>0 && cantElementos<=40)
        {
            for(int i=0; i<cantElementos; i++)
            {
                apilar(&mazo, rand() %40);
            }
            break; // salgo del bucle, si la cantidad ingresada es valida
        }
        printf("Error. La cantidad ingresada es no valida. Reintente. \n");
    }
    while (1); //se repite el bucle, hasta que se ingrese un valor valido.

    printf("Se muestra pila MAZO, antes de repartir. \n");
    mostrar(&mazo);

    //repartimos
    while(!pilavacia(&mazo))
    {
        apilar(&jug1, desapilar(&mazo));
        if(!pilavacia(&mazo))
        {
            apilar(&jug2, desapilar(&mazo));
        }
    }
    printf("Se muestra pila jugador 1: \n");
    mostrar(&jug1);

    printf("Se muestra pila jugador 2: \n");
    mostrar(&jug2);

}


void ejercicio9()

// variante, donde comparamos cantidad de elementos, y determinamos SOLO SI SON IGUALES O NO y cual tiene mas--
{
    Pila mazo, jug1, jug2;
    inicpila(&mazo);
    inicpila(&jug1);
    inicpila(&jug2);

    //carga de pila
    srand(time(NULL));
    int cantElementos;

    do
    {
        printf("Ingrese la cantidad de cartas a utilizar, no mas de 40. \n\n");
        scanf("%d", &cantElementos);
        if(cantElementos>0 && cantElementos<=40)
        {
            for(int i=0; i<cantElementos; i++)
            {
                apilar(&mazo, rand() %40);
            }
            break; // salgo del bucle, si la cantidad ingresada es valida
        }
        printf("Error. La cantidad ingresada es no valida. Reintente. \n");
    }
    while (1); //se repite el bucle, hasta que se ingrese un valor valido.

    printf("Se muestra pila MAZO, antes de repartir. \n");
    mostrar(&mazo);

    //repartimos
    while(!pilavacia(&mazo))
    {
        apilar(&jug1, desapilar(&mazo));
        if(!pilavacia(&mazo))
        {
            apilar(&jug2, desapilar(&mazo));
        }
    }
    printf("Se muestra pila jugador 1: \n");
    mostrar(&jug1);

    printf("Se muestra pila jugador 2: \n");
    mostrar(&jug2);

    //comparamos jug1 y jug2, para determinar cual tenia mas cartas
    while(!pilavacia(&jug1) && !pilavacia(&jug2))
    {
        apilar(&mazo,desapilar(&jug1));
        apilar(&mazo,desapilar(&jug2));
    }


    // Determinamos cuál pila quedó con elementos
    if (pilavacia(&jug1) && pilavacia(&jug2))
    {
        printf("Ambos jugadores tienen la misma cantidad de cartas.\n");
    }
    else if (pilavacia(&jug1))
    {
        printf("El jugador 2 tiene más cartas.\n");
    }
    else
    {
        printf("El jugador 1 tiene más cartas.\n");
    }

    //restauramos las cartas a cada jugador
    while(!pilavacia(&mazo))
    {
        apilar(&jug2, desapilar(&mazo));
        if(!pilavacia(&mazo))
        {
            apilar(&jug1, desapilar(&mazo));
        }
    }


    printf("----Se muestra pila mazo DESPUES de la comparacion: \n");
    mostrar(&mazo);

    printf("----Se muestra pila jugador 1 DESPUES de la comparacion: \n");
    mostrar(&jug1);

    printf("----Se muestra pila jugador 2 DESPUES de la comparacion: \n");
    mostrar(&jug2);


}




void ejercicio9opcion2()
// variante, donde comparamos cantidad de elementos, y determinamos SOLO SI SON IGUALES O NO y cual tiene mas--
{
    printf("Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.\n\n");

    Pila A, B, auxA, auxB;
    inicpila(&A);
    inicpila(&B);
    inicpila(&auxA);
    inicpila(&auxB);

    srand(time(NULL));

    // Variables independientes para la cantidad de elementos en cada pila
    int cantidadA = rand() % 5 + 1;
    int cantidadB = rand() % 3 + 1;

    // Carga de pilas
    for (int i = 0; i < cantidadA; i++)
    {
        apilar(&A, (rand() % 100) + 1);
    }
    for (int i = 0; i < cantidadB; i++)
    {
        apilar(&B, (rand() % 100) + 1);
    }

    // Mostramos pilas antes de comparar
    printf("\nPila A antes de comparar:\n");
    mostrar(&A);
    printf("\nPila B antes de comparar:\n");
    mostrar(&B);

    // Comparación sin perder datos
    while (!pilavacia(&A) && !pilavacia(&B))
    {
        apilar(&auxA, desapilar(&A));
        apilar(&auxB, desapilar(&B));
    }

    // Resultado de la comparación
    if (pilavacia(&A) && pilavacia(&B))
    {
        printf("\nLas pilas tienen la misma cantidad de elementos.\n");
    }
    else
    {
        printf("\nLas pilas NO tienen la misma cantidad de elementos.\n");
    }

}

void ejercicio9opcion3profe()
// variante, donde comparamos cantidad de elementos, y determinamos SOLO SI SON IGUALES O NO y cual tiene mas-
{
    printf("Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.\n\n");

    Pila A, B, aux, aux2;
    inicpila(&A);
    inicpila(&B);
    inicpila(&aux);
    inicpila(&aux2);

    //carga pila A--------------
    srand(time(NULL));
    int cantElementosA;
    do
    {
        printf("Ingrese la cantidad de elementos a utilizar en pila A, no mas de 50. \n\n");
        scanf("%d", &cantElementosA);
        if(cantElementosA>0 && cantElementosA<=50)
        {
            for(int i=0; i<cantElementosA; i++)
            {
                apilar(&A, rand() %50);
            }
            break; // salgo del bucle, si la cantidad ingresada es valida
        }
        printf("Error. La cantidad ingresada es no valida. Reintente. \n");
    }
    while (1); //se repite el bucle, hasta que se ingrese un valor valido.

    printf("Se muestra pila A. \n");
    mostrar(&A);

    //carga pila B------------------
    srand(time(NULL));
    int cantElementosB;
    do
    {
        printf("Ingrese la cantidad de elementos a utilizar en pila B, no mas de 50. \n\n");
        scanf("%d", &cantElementosB);
        if(cantElementosB>0 && cantElementosB<=50)
        {
            for(int i=0; i<cantElementosB; i++)
            {
                apilar(&B, rand() %50);
            }
            break; // salgo del bucle, si la cantidad ingresada es valida
        }
        printf("Error. La cantidad ingresada es no valida. Reintente. \n");
    }
    while (1); //se repite el bucle, hasta que se ingrese un valor valido.

    printf("Se muestra pila B. \n\n");
    mostrar(&B);
    printf("-------------------\n\n");

    //COMPARACION DE PILA A Y B --------------
    while(!pilavacia(&A) && !pilavacia(&B))
    {
        apilar(&aux, desapilar(&A));
        apilar(&aux2, desapilar(&B));
    }

    if (pilavacia(&A)&&pilavacia(&B))
    {
        printf("La cantidad de elementos es igual en ambas pilas \n");
    }
    else
    {
        printf("La cantidad de elementos es distinta entre las pilas\n");
        printf("Comparando ...\n");
        if(!pilavacia(&A))
        {
            printf("La pila A tiene mas elementos. \n");
        }
        else
        {
            printf("La pila B tiene mas elementos. \n");
        }
    }
}

void ejercicio9opcion4sergiogarguir()
//simplifica mucho mas la carga random, lo malo que hay que probar varias veces hasta obtener un resultado practico.

{
    printf("Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.\n\n");

    Pila A, B, auxA, auxB;
    inicpila(&A);
    inicpila(&B);
    inicpila(&auxA);
    inicpila(&auxB);

    //carga pila A Y B--------------
    srand(time(NULL));
    for(int i=1; i<rand()%20; i++)
    {
        apilar (&A, rand()%20);
    }

    for(int i=1; i<rand()%20; i++)
    {
        apilar (&B, rand()%20);
    }

    printf("Se muestra pila A. \n");
    mostrar(&A);
    printf("Se muestra pila B. \n\n");
    mostrar(&B);

    //COMPARACION DE PILA A Y B --------------
    while(!pilavacia(&A) && !pilavacia(&B))
    {
        apilar(&auxA, desapilar(&A));
        apilar(&auxB, desapilar(&B));
    }

    if (pilavacia(&A)&&pilavacia(&B))
    {
        printf("La cantidad de elementos es igual en ambas pilas \n");
    }
    else
    {
        printf("La cantidad de elementos es distinta entre las pilas\n");
        printf("Comparando ...\n");
        if(!pilavacia(&A))
        {
            printf("La pila A tiene mas elementos. \n");
        }
        else
        {
            printf("La pila B tiene mas elementos. \n");
        }
    }
    printf("\n Se muestra pila A. Despues \n");
    mostrar(&A);
    printf("\n Se muestra pila B. Despues \n\n");
    mostrar(&B);
}

void ejercicio10()
{
    printf("Cargar las pilas A y B y luego compararlas, evaluando si son completamente iguales, \n");
    printf("(en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. \n\n ");

    Pila A, B, aux1, aux2;
    inicpila(&A);
    inicpila(&B);
    inicpila(&aux1);
    inicpila(&aux2);

    srand(time(NULL));

    //carga de elementos -A
    int cantElementosA;
    do
    {
        printf("Ingrese cantidad de elementos en A: \n");
        scanf("%d",&cantElementosA);
        if(cantElementosA>0 && cantElementosA<=50)
        {
            for(int i=0; i<cantElementosA; i++)
            {
                apilar(&A, rand()%20);
            }
        }
        else
        {
            printf("Error: La cantidad ingresada en invalida. Reintente. \n");
        };
    }
    while(cantElementosA<=0 || cantElementosA>50);

    //carga de elementos -B
    int cantElementosB;
    do
    {
        printf("Ingrese cantidad de elementos en B: \n");
        scanf("%d",&cantElementosB);
        if(cantElementosB>0 && cantElementosB<=50)
        {
            for(int i=0; i<cantElementosB; i++)
            {
                apilar(&B, rand()%20);
            }
        }
        else
        {
            printf("Error: La cantidad ingresada en invalida. Reintente. \n");
        };
    }
    while(cantElementosB<=0 || cantElementosB>50);

    //Muestra de pilas
    printf("\n----PILA A --------\n");
    mostrar(&A);
    printf("\n----PILA B --------\n");
    mostrar(&B);

    //COMPARACION
    int bandera = 1; // flag, indica que las pilas son iguales hasta el momento (true)

    while(!pilavacia(&A)&&!pilavacia(&B)&& bandera == 1) // mientras tengan datos A y B
    {
        if (tope(&A) == tope(&B))   //comparamos los topes, y apilamos en aux1 y aux2
        {
            apilar(&aux1, desapilar(&A));
            apilar(&aux2, desapilar(&B));
        }
        else
        {
            bandera = 0; // indico bandera 0, cuando no son iguales los topes
        }
    }

    if(pilavacia(&A)&&pilavacia(&B)&&bandera ==1)
    {
        printf("La cantidad , la posicion y los valores de los elementos son iguales en ambas pilas. \n");
    }
    else
    {
        printf("La cantidad , la posicion y los valores de los elementos son diferentes en ambas pilas. \n");

    }
}

// MUCHO MEJOR
void ejercicio10cargamanual()
{
    printf("Cargar las pilas A y B y luego compararlas, evaluando si son completamente iguales, \n");
    printf("(en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. \n\n ");

    Pila A, B, aux1, aux2;
    inicpila(&A);
    inicpila(&B);
    inicpila(&aux1);
    inicpila(&aux2);

    //carga manual
    char option = 's';
    do
    {
        printf("\n Ingrese un numero para la pila A. ");
        leer(&A);
        printf("Desea continuar ? presione s/n \n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while
    (
        option == 's'
    );
    printf("\n----------------------\n");

    do
    {
        printf("\n Ingrese un numero para la pila B. ");
        leer(&B);
        printf("Desea continuar ? presione s/n \n");
        fflush(stdin);
        scanf("%c", &option);
    }
    while
    (
        option == 's'
    );
    printf("----------MOSTRAR PILA A: ------------\n");
    mostrar(&A);
    printf("----------MOSTRAR PILA B: ------------\n");
    mostrar(&B);

    //comparacion
    int bandera = 1; // flag para indicar un valor true

    while(!pilavacia(&A)&&!pilavacia(&B)&& bandera==1)
    {
        if(tope(&A) == tope(&B))
        {
            apilar(&aux1, desapilar(&A));
            apilar(&aux2, desapilar(&B));
        }
        else
        {
            bandera = 0;
        }
    }
    if(pilavacia(&A)&&pilavacia(&B))
    {
        printf("La cantidad, posicion, y valores de los elementos es IGUAL en ambas pilas");
    }
    else
    {
        printf("La cantidad, posicion, y valores de los elementos es DIFERENTE en ambas");
    }

}

void ejercicio11()
{
    Pila modelo,dada,basura,aux;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&basura);
    inicpila(&aux);

    //carga manual
    char option='s';
    do
    {
        printf("\n PILA MODELO.\n");
        leer(&modelo);
        printf("Desea continuar ? Presione s/n. \n");
        fflush(stdin);
        scanf("%c",&option);
    }
    while(option == 's');

    printf("\n-------------\n");
    do
    {
        printf("\n PILA DADA.\n");
        leer(&dada);
        printf("Desea continuar ? Presione s/n. \n");
        fflush(stdin);
        scanf("%c",&option);
    }
    while(option == 's');

    printf("\n -----PILA MODELO ------\n");
    mostrar(&modelo);
    printf("\n -----PILA DADA ------\n");
    mostrar(&dada);

    //comparacion y logica
    while(!pilavacia(&dada))
    {
        if(tope(&modelo)==tope(&dada))
        {
            apilar(&basura, desapilar(&dada));
        }
        else
        {
            apilar(&aux, desapilar(&dada));
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    };

    printf("\n pila dada, DESPUES \n");
    mostrar(&dada);
}



