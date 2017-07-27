#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Ti = 50;  // Tempo inicial
double Tf = 0.01;  // Tempo final
double C = -4900;   // Contante
double t = 1;   // Tempo
double ti = 0;  // Tempo inicial
int n = 0;

/// y(t) = T0/Tf + exp(-Tf*t)*C
double solucao(){
    return (Ti/Tf + C*exp(-Tf*t));
}
/// Y'(t) = T0 - Tf * Y - ("Lei de Equilibrio")
/// Y'(t) = Taxa de entrada de Sal - Taxa de saída de sal * Quantidade presente na mistura

double y_inicial(){
    return (Ti/Tf + C*exp(-Tf*ti));
}
double f (double X, double Y)
{
    return Ti + (-Tf*Y);
}

double metodo_euler ( int n ) {
    double Y = 100;
    double X = ti;
    double h = (t-ti)/n;
    int i;

    for ( i = 0; i < n; i++ ) {
        Y += (h*f(X,Y));
        X += h;
    }

    return Y;
}

double metodo_euler_modificado ( int n ) {
    double Y_atual = 100;
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

double metodo_runge_kutta ( int n ) {
    double Y = 100;
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

double metodo_passos_multiplos()        //Adams-Bashforth-Moulton 4a Ordem
{
    //Variaveis auxiliares
    int j = 0;
    double K1 = 0, K2 = 0, K3 = 0, K4 = 0;

    //Tamanho do passo
    double h = (t-ti)/n;

    //Vetor de soluções
    double x[n+1], y[n+1]; 

    // Etapa para cálculo Preditor-Corretor
    double yp, yc;

    for(j=0;j<n+1;j++)
    {
        x[j]=0;
        y[j]=0;
    }
    
    //Condição Inicial
    x[0] = ti;
    y[0] = y_inicial();

    // Calcula os 3 proximos valores (x,y)
    for(j=0;j<3;j++)
    {
        // Runge-Kutta 4a ordem
        //===========================
        K1 = f(x[j], y[j]);
        K2 = f(x[j]+h/2, y[j]+(h/2)*K1);
        K3 = f(x[j]+h/2, y[j]+(h/2)*K2);
        K4 = f(x[j]+h, y[j]+h*K3);
        x[j+1] = x[j] + h;
        y[j+1] = y[j] + (h/6)*(K1 + 2*K2 + 2*K3 + K4);
        //========================= 
    }

    for(j=3;j<n;j++)
    {
        x[j+1] = x[j] + h;
        // Preditor
        yp = y[j] + (h/24)*(55*f(x[j],y[j]) - 59*f(x[j-1],y[j-1]) + 37*f(x[j-2],y[j-2]) - 9*f(x[j-3],y[j-3]));
        // Corretor
        yc = y[j] + (h/24)*(9*f(x[j+1],yp) + 19*f(x[j],y[j]) - 5*f(x[j-1],y[j-1]) + f(x[j-2],y[j-2]));
        y[j+1] = y[j] + (h/24)*(9*f(x[j+1],yc) + 19*f(x[j],y[j]) - 5*f(x[j-1],y[j-1]) + f(x[j-2],y[j-2]));
    }

    return y[n];
}
int main()
{
    double erro, resposta_solucao, resposta_euler, resposta_passos_mult;
    double resposta_euler_modificado;
    double resposta_runge_kutta;

    do {
        printf("---------------------------------------------\n");
        printf("O numero de subdivisoes: ");
        scanf("%d", &n);
        if ( n > 0 ) {
            resposta_solucao = solucao();
            printf("A solucao: %.5lf\n\n", resposta_solucao);

            resposta_euler = metodo_euler(n);
            printf("Metodo de Euler: %.5lf\n", resposta_euler);
            erro = fabs(resposta_solucao - resposta_euler);
            printf("O erro: %.5lf\n\n", erro);

            resposta_euler_modificado = metodo_euler_modificado(n);
            printf("Metodo modificado de Euler: %.5lf\n", resposta_euler_modificado);
            erro = fabs(resposta_solucao - resposta_euler_modificado);
            printf("O erro: %.5lf\n\n", erro);

            resposta_runge_kutta = metodo_runge_kutta(n);
            printf("Metodo de Runge Kutta: %.5lf\n", resposta_runge_kutta);
            erro = fabs(resposta_solucao - resposta_runge_kutta);
            printf("O erro: %.5lf\n\n", erro);

            resposta_passos_mult = metodo_passos_multiplos(n);
            printf("Metodo de Passos Multiplos: %.5lf\n", resposta_passos_mult);
            erro = fabs(resposta_solucao - resposta_passos_mult);
            printf("O erro: %.5lf\n", erro);
        }
    } while ( n > 0 );
    return 0;
}