#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Generador de datos aleatorios para regresion lineal de una recta
//



int main (int argc, char *argv[])
{
        float m; // Pendiente
        float b; // Ordenada al oringen
        float xrange_inf; // Cota inferior
        float xrange_sup; // Cota superior
        int N; // Puntos a generar
        float stddev=0; // Desviaci'on al rededor de la recta
        float range; // Rango entre las cotas
        float x,y;   // Puntos generados
        int   i;     // indice del generador
        int   sign;  // signo de la desviacion

        fprintf (stderr, "Generador de datos para regresion lineal\n");

        fprintf(stderr,"Pendiente? ");
        scanf ("%f", &m);
        fprintf(stderr,"Ordenada al origen? ");
        scanf ("%f", &b);

        fprintf (stderr,"cota inferior para el rango? ");
        scanf ("%f",&xrange_inf);
        fprintf (stderr,"cota superior para el rango? ");
        scanf ("%f",&xrange_sup);

        fprintf (stderr,"Total de datos a generar ? ");
        scanf ("%d",&N);
        fprintf (stderr,"desviacion ? ");
        scanf ("%f",&stddev);

        srand ( time(0) ); // inicializa el generador de num. aleatorios
                                // la semilla es la hora al instante de ejecucion
                                // solo usarlo 1 vez al inicio del programa.
                                //
        range = xrange_sup - xrange_inf;

        for ( i=0 ; i < N ; i++ )
        {
                x = random()/(float)RAND_MAX;   // Se genera un numero entre 0 y 1
                x = x * range;          // Ajusta el valor en el rango
                x = x + xrange_inf;     // Desplaza al valor inicial

                y = m*x + b;

                sign=( random()%2 ? -1 : 1 );   // genera un signo al azar para la desviacion
                y = y + sign * ( random()/(float)RAND_MAX )*stddev; 

                printf ("%8.3f %8.3f\n",x,y);  // imprime los valores generados
        }

                

}