# Solução do problema de Resfriamento de Newton

from math import *
from cmath import *

#========== Definição das variáveis =========
T0 = 50		   	# Tempo inicial
Tm = 0.01  		# Tempo final
C = 0		  	# Constante da formula C = (T0 - Tm)
k = 0.15	 	# Contante de resfriamento do material

t = 3			# Tempo
ti = 0	  		# Tempo inicial
#============================================

# Função F referente a equação diferencial do problema de Resfriamento de Newton
def solucao():
    return (C*exp((-1)*k*t)+Tm)

# Y inicial necessário para os cálculos dos métodos
def solucao_inicial():
    return (C*exp((-1)*k*ti)+Tm);

# Função principal
def f(X,T):
    return (-1)*k*(T-Tm)

# Cálculo do passo
def passo():
	return (t-ti)/n

# Método de EULER
def metodo_euler():
	Y = solucao_inicial()
	X = ti
	h = passo()

	i = 0
	while i < n:
		Y = Y + h*f(X,Y)
		X = X + h
		i = i + 1

	return Y

# Método de EULER MODIFICADO
def metodo_euler_modificado():
	Y_atual = solucao_inicial()
	X_atual = ti
	h = passo()

	Y_previsao, X_proximo = 0,0
	
	i = 0
	while i < n:
		Y_previsao = Y_atual + h*f(X_atual, Y_atual)
		X_proximo = X_atual + h
		Y_atual = Y_atual + (h/2)*(f(X_atual, Y_atual) + f(X_proximo, Y_previsao))
		X_atual = X_atual + h
		i = i + 1

	return Y_atual

# Método de Runge-Kutta
def metodo_runge_kutta():
	Y = solucao_inicial()
	X = ti
	h = passo()
	k1, k2, k3, k4 = 0, 0, 0, 0

	i = 0
	while i < n:
		k1 = f(X, Y)
		k2 = f(X + (h/2), Y + ((h/2)*k1))
		k3 = f(X + (h/2), Y + ((h/2)*k2))
		k4 = f(X + h, Y + (h*k3))

		X = X + h
		Y = Y + (h/6)*(k1 + (2*k2) + (2*k3) + k4)

		i = i + 1

	return Y

# Adams-Bashforth-Moulton 4a Ordem
def metodo_passos_multiplos():
	K1,K2,K3,K4 = 0,0,0,0
	h = passo()

	x, y = [], []

	for i in range(0,n+1):
		x.append(0)
		y.append(0)

	x[0],y[0] = ti,solucao_inicial()
	
	j = 0
	while j < 3:
		# Runge-Kutta 4a ordem
		# ===========================
		K1 = f(x[j], y[j]);
		K2 = f(x[j]+h/2, y[j]+(h/2)*K1);
		K3 = f(x[j]+h/2, y[j]+(h/2)*K2);
		K4 = f(x[j]+h, y[j]+h*K3);
		x[j+1] = x[j] + h;
		y[j+1] = y[j] + (h/6)*(K1 + 2*K2 + 2*K3 + K4);
		# ===========================
		j = j + 1

	j = 3
	while j < n:
		# ===========================
		x[j+1] = x[j] + h;
		# Preditor
		yp = y[j] + (h/24)*(55*f(x[j],y[j]) - 59*f(x[j-1],y[j-1]) + 37*f(x[j-2],y[j-2]) - 9*f(x[j-3],y[j-3]));
		# Corretor
		yc = y[j] + (h/24)*(9*f(x[j+1],yp) + 19*f(x[j],y[j]) - 5*f(x[j-1],y[j-1]) + f(x[j-2],y[j-2]));
		y[j+1] = y[j] + (h/24)*(9*f(x[j+1],yc) + 19*f(x[j],y[j]) - 5*f(x[j-1],y[j-1]) + f(x[j-2],y[j-2]));
		# ===========================
		j = j + 1

	return y[n]

n = int(input("O número de subdivisões: "))
C = T0 - Tm

print("A solução é: \t %.5f" % solucao().real)
print("--------------------------------------------------------------------\n");
print("  n\tEuler\t\tEuler Modif\tPassos-Mult.\tRunge-Kutta\n");
print("--------------------------------------------------------------------\n");
print(n,"\t%.5f" % metodo_euler().real,
	"\t%.5f" % metodo_euler_modificado().real,
	"\t%.5f" % metodo_passos_multiplos().real,
	"\t%.5f" % metodo_runge_kutta().real)