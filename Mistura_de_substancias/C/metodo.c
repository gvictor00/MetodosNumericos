#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Ti = Taxa de entrada de Sal
    Tf = Taxa de saída
    ti = Tempo inicial (0)
    t = Tempo final
    C = Constante de decaimento
    h = O tamanho das subdiviões de X
    n = O número de subdivisões de X

    Ti = 80 ºC
    Tf = 0 ºC
    ti = 0 minutos
    k = 0.1386

    Alguns exemplos:
    t = 30 minutos => T = 1.25 ºC
    t = 5 minutos => T = 40 ºC
    t = 10 minutos => T = 20 ºC
*/

/*
    Q0 = Quantidade Inicial
    Q(t) = Quantidade em função do tempo
    lambda = Constante de decaimento
    Tf = Tempo final
    Ti = Tempo inicial

*/
double Ti = 0;  // Tempo inicial
double Tf = 0;  // Tempo final
double C = 0;   // Contante
double t = 0;   // Tempo
double ti = 0;  // Tempo inicial

/// y(t) = T0/Tf + exp(-Tf*t)*C
double solucao(){
    return (Ti/Tf + C*exp(-Tf*t));
}
/// Y'(t) = T0 - Tf*Y - ("Lei de Equilibrio")
/// Y'(t) = Taxa de entrada de Sal - Taxa de saída de sal

double f (double X, double Y)
{
    return Ti - Tf*Y;
}

double metodo_euler ( int n ) {
    double Y = Ti;
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
    double Y_atual = Ti;
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
    double Y = Ti;
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
    double erro, resposta_solucao, resposta_euler;
    double resposta_euler_modificado;
    double resposta_runge_kutta;

    printf("Digite as condicoes do problema\n");
    printf("Taxa de entrada de sal (T0): ");
    scanf("%lf", &Ti);
    printf("Taxa de saida de sal (TF): ");
    scanf("%lf", &Tf);
    printf("Tempo: ");
    scanf("%lf", &t);
    printf("A constante de decaimento (0,1386): ");
    scanf("%lf", &C);

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
            printf("O erro: %lf\n\n", erro);

            resposta_euler_modificado = metodo_euler_modificado(n);
            printf("Metodo modificado de Euler: %.5lf\n", resposta_euler_modificado);
            erro = fabs(resposta_solucao - resposta_euler_modificado);
            printf("O erro: %.5lf\n\n", erro);

            resposta_runge_kutta = metodo_runge_kutta(n);
            printf("Metodo de Runge Kutta: %.5lf\n", resposta_runge_kutta);
            erro = fabs(resposta_solucao - resposta_runge_kutta);
            printf("O erro: %.5lf\n", erro);
        }
    } while ( n > 0 );
    return 0;
}