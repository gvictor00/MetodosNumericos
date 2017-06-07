/*
	Estou mantendo o código no GitHub https://github.com/gvictor00/MetodosNumericos
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/////////Definição de todos os valores do problema/////
double C = 3000;   							// Constante (População Inicial)
double t = 2;   							// Tempo     
double k = 0.5493;  						//Constante  (Taxa de crescimento/decaimento)
double ti = 0;  							// Tempo inicial
///////////////////////////////////////////////////////
int n = 0;

//Solucao Analítica do problema de Dinamica populacional
double solucao(){
	return (C*exp(k*t));
}

double y_inicial(){							//Y inicial necessário para os cálculos dos métodos
	return (C*exp(k*ti));
}

double f (double X, double Y)				//Função F referente a equação diferencial do problema de Dinamica Populacional
{
	return (k*Y);
}

double passo()
{
	return (t-ti)/n;
}

double metodo_euler () {  			//Método de Euler
	double Y = y_inicial();
	double X = ti;
	double h = passo();
	int i;

	for ( i = 0; i < n; i++ ) {
		Y += (h*f(X,Y));
		X += h;
	}

	return Y;
}

double metodo_euler_modificado () { 	//Euler Modificado
	double Y_atual = y_inicial();
	double X_atual = ti;
	double Y_previsao;
	double X_proximo;
	double h = passo();
	int i;

	for ( i = 0; i < n; i++ ) {
		Y_previsao = Y_atual + h*f(X_atual, Y_atual);
		X_proximo = X_atual + h;
		Y_atual += (h/2)*(f(X_atual, Y_atual) + f(X_proximo, Y_previsao));
		X_atual += h;
	}

	return Y_atual;
}

double metodo_runge_kutta () { 		//Runge-Kutta
	double Y = y_inicial();
	double X = ti;
	double h = passo();
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

double metodo_passos_multiplos() 	//Adams-Bashforth-Moulton 4a Ordem
{
	//Variaveis auxiliares
	int j = 0;
	double K1 = 0, K2 = 0, K3 = 0, K4 = 0;

	//Tamanho do passo
	double h = passo();

	//Vetor de soluções
	double x[n+1], y[n+1]; 

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

	// Etapa para cálculo Preditor-Corretor
	double yp, yc;

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
    double erro; 							//Considerar erro ≤ 0,0001 
    double res_e, res_em, res_pm, res_rk;
    double sol;
    printf("--------------------------------------------------------------------\n");
    printf("O numero de subdivisoes: ");
    scanf("%d", &n);																	//User define o número de subdvisoes e o programa executa.
    printf("\n");

    sol = solucao();
    printf("A solucao analitica: %.5lf\n\n", sol);

    printf("  n\tEuler\t\tEuler Modif\tPassos-Mult.\tRunge-Kutta\n");
    printf("--------------------------------------------------------------------\n");
    do{

    	printf("%d\t", n);
    	
    	res_e = metodo_euler();
    	res_em = metodo_euler_modificado();
    	res_pm = metodo_passos_multiplos();
    	res_rk = metodo_runge_kutta();

    	printf("%.5lf\t%.5lf\t%.5lf\t%.5lf\t\n",res_e,res_em,res_pm,res_rk);

    	erro = fabs(sol - res_e);
    	if(erro < 10){

    		printf("\t%.5f\t\t", erro);
    	}
    	else
    	{
    		printf("\t%.5f\t", erro);
    	}
    	
    	erro = fabs(sol-res_em);
    	if(erro < 10)
    	{
    		printf("%.5f\t\t", erro);
    	}
    	else
    	{
    		printf("%.5f\t", erro);
    	}

    	erro = fabs(sol-res_pm);
    	if(erro < 10)
    	{
    		printf("%.5f\t\t", erro);
    	}
    	else
    	{
    		printf("%.5f\t", erro);
    	}

    	printf("%.5f\n", fabs(sol-res_rk));
    	n=n/2;

    printf("--------------------------------------------------------------------\n");
    }while(n>0);
    return 0;
}
