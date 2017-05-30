#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/////////Definição de todos os valores do problema/////
double C = 3000;   							// Constante (População Inicial)
double t = 2;   							// Tempo     
double k = 0.5493;  						//Constante  (Taxa de crescimento/decaimento)
double ti = 0;  							// Tempo inicial
///////////////////////////////////////////////////////

double solucao(){							//Solucao Analítica do problema de Dinamica populacional
    return (C*exp(k*t));
}

/*Solução obtida através da resolucao de uma equacao diferencial de primeira ordem. 
  Foi utilizado a estratégia do fator integrante. Maiores detalhes estão descritos no relatório*/

double y_inicial(){							//Y inicial necessário para os cálculos dos métodos
	return (C*exp(k*ti));
}

double f (double X, double Y)				//Função F referente a equação diferencial do problema de Dinamica Populacional
{
    return (k*Y);
}

double metodo_euler ( int n ) {  			//Método de Euler
    double Y = y_inicial();
    double X = ti;
    double h = (t-ti)/n;
    int i;

    for ( i = 0; i < n; i++ ) {
        Y += (h*f(X,Y));
        X += h;
    }

    return Y;
}

double metodo_euler_modificado ( int n ) { 	//Euler Modificado
    double Y_atual = y_inicial();
    double X_atual = ti;
    double Y_previsao;
    double X_proximo;
    double h = (t-ti)/n;
    int i;

    for ( i = 0; i < n; i++ ) {
        Y_previsao = Y_atual + h*f(X_atual, Y_atual);
        X_proximo = X_atual + h;
        Y_atual += (h/2)*(f(X_atual, Y_atual) + f(X_proximo, Y_previsao));
        X_atual += h;
    }

    return Y_atual;
}

double metodo_runge_kutta ( int n ) { 		//Runge-Kutta
    double Y = y_inicial();
    double X = ti;
    double h = (t-ti)/n;
    double k1, k2, k3, k4;
    int i;

    for ( i = 0; i < n; i++ ) {
        k1 = f(X, Y);
        k2 = f(X + (h/2), Y + ((h/2)*k1));
        k3 = f(X + (h/2), Y + ((h/2)*k2));
        k4 = f(X + h, Y + (h*k3));

        X += h;
        Y += (h/6)*(k1 + (2*k2) + (2*k3) + k4);
    }

    return Y;
}

int main()
{
    int n;
    double erro; 							//Considerar erro ≤ 0,0001 

    //do {
        printf("---------------------------------------------\n");
        printf("O numero de subdivisoes: ");
        scanf("%d", &n);																	//User define o número de subdvisoes e o programa executa.
        printf("\n");

        if ( n > 0 ) {
            printf("A solucao: %.5lf\n\n", solucao());

            printf("Metodo de Euler: %.5lf\n", metodo_euler(n));
            erro = fabs(solucao() - metodo_euler(n));
            printf("O erro: %.5lf\n\n", erro);												//Cálculo do erro feito tendo como base a solucao analitica

            printf("Metodo modificado de Euler: %.5lf\n", metodo_euler_modificado(n));
            erro = fabs(solucao() - metodo_euler_modificado(n));
            printf("O erro: %.5lf\n\n", erro);

            printf("Metodo de Runge Kutta: %.5lf\n", metodo_runge_kutta(n));
            erro = fabs(solucao() - metodo_runge_kutta(n));
            printf("O erro: %.5lf\n", erro);
        }
        printf("---------------------------------------------\n");
  //   } while ( n > 0 );

    return 0;
}