#include<stdlib.h>
#include<stdio.h>

// Regresion lineal por el metodo de minimos cuadrados para ajuste a una recta

int main()
{
        float m,b;
        int N;
        int i;
        float sumX=0;
        float sumY=0;
        float sumXX=0;
        float sumXY=0;

        float x[100];  // maximo 100 puntos
        float y[100];

        i=0;
        while (scanf ("%f %f", &x[i] , &y[i])!=EOF && i<100) i++;
        N=i;

        // realiza sumatorias
        for (i=0; i<N; i++) 
        {
                sumX = sumX + x[i];
                sumY = sumY + y[i];
                sumXY = sumXY + x[i]*y[i];
                sumXX = sumXX + x[i]*x[i];
        }

        // Calcula valor de la pendiente y la ordenada al origen
        m = (N*sumXY-sumX*sumY)/(N*sumXX-sumX*sumX);
        b = (sumY - m * sumX)/N;
        
        // Imprime resultados
        printf ("m = %8.3f\n", m);
        printf ("b = %8.3f\n",b);
}
