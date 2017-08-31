# Métodos numéricos

Serão agrupados neste repositório soluções para problemas em que são empregadas **equações diferenciais** de 1º e 2º grau.

## Cálculo de EDO usando os métodos numéricos como:
 - Método de Euler;
 - Método de Euler Modificado;
 - Método de Adams-Bashforth-Moulton 4ª ordem; 
 - Método de Runge Kutta 4ª ordem.
## Os métodos
### Método de Euler 
Suponha que queremos aproximar a solução de um problema de valor inicial: 
![Metodo_Euler](https://wikimedia.org/api/rest_v1/media/math/render/svg/823a0cbb6755ef8910cb3bb018d11411e81e4120?raw=true) <br>
Escolhendo um valor h para tamanho de cada passo e atribuindo a cada passo um ponto dentro do intervalo, temos que tn = t0 + nh. Nisso, o próximo passo tn+1 a partir do anterior tn fica definido tn+1 = tn + h, então:<br>
![Metodo_Euler](https://wikimedia.org/api/rest_v1/media/math/render/svg/269f6c656eab53584639f205ecfe88b628af701a)
<br>
<br>
<b>Algoritmo do Método de Euler</b><br>
1. Entre com a condição inicial x(t0) = x0;<br>
2. Coloque o número de iterações desejadas n;<br>
3. Entre com o tempo final tf ;<br>
4. Faça h = (tf − t0)/n;<br>
5. Para i = 1 : n faça:<br>
	f(i) = x(i);<br>
	t(i + 1) = t(i) + h;<br>
	x(i + 1) = x(i) + h * f(i);<br>
	fim<br>
6. Imprima os pontos (t(i), x(i)).

### Método de Euler Modificado 
É possível notar que o erro no método de Euler é grande. Com o objetivo de diminuir este erro de aproximação, podemos utilizar o método de Euler melhorado ou método do Trapézio. Ele consiste em usar o Método de Euler como Preditor e fazer a corrteção atavés de uma nova equação. O Método de Euler Modificado também é conhecido como Runge-Kutta de 2ª ordem. <br><br>
<img src="http://latex.codecogs.com/gif.latex?Y_%7Bk&plus;1%7D%3DY_k&plus;%5Cfrac%7Bf%28t_k%2Cy_k%29h%7D%7B2%7D&plus;%5Cfrac%7Bf%28t_k&plus;h%2CY_k&plus;f%28t_k%2Cy_k%29h%29%7D%7B2%7D" align="center" border="0" alt="Y_m_+_1 = Y_m + \frac{f_m*h}{2} + \frac{f(t_m+h,Y_m + f(t_m,y_m))*h}{2}" width="421" height="43" />

### Runge Kutta
O método mais preciso e mais utilizado é o método de Runge-Kutta de quarto grau. Ele nasce do método de Euler, sendo o Runge-Kutta de primeiro grau o próprio método de Euler. O Runge-Kutta de segundo grau é o método de Euler melhorado, como veremos a seguir. Concluiremos a seção com o Runge-Kutta de quarto grau, que é o método mais preciso para a obtenção de soluções aproximadas para um problema de valor inicial. Cada método do Runge-Kutta é uma comparação com um polinômio de Taylor conveniente, daí que surgem os graus em seus nomes. Quando comparado a um polinômio de grau 1, teremos o Runge-Kutta de primeiro grau. Ao fazermos essa comparação, o cálculo da derivada é eliminado, fazendo-se assim avaliações da função f em cada iteração.
 <br>
![Runge-Kutta](https://wikimedia.org/api/rest_v1/media/math/render/svg/d8534f269d223b247698d487d6b93eef6a1070df)<br>
![Runge-Kutta](https://wikimedia.org/api/rest_v1/media/math/render/svg/42c75230fa264441ebc3725e456ea17147a604c3)

### Passo Múltiplos
Os métodos que veremos aqui, chamados de passos múltiplos, são bem precisos, porém eles necessitam de conhecimento prévio de alguns pontos da solução. Assim, os métodos e passos múltiplos são apropriados para os casos em que já se conhece alguns pontos do problema. Este método é uma combinação da fórmula de Adams-Bashforth e  Adams-Moulton de quarto grau. Ambas são de passos múltiplos, mas a diferença é que a primeira é uma fórmula explícita e a segunda implícita. O método de previsão e correção é a combinação desses dois métodos. Portanto, é necessário conhecer a priori quatro pontos:<br>
(tn-3,Xn-3), (tn-2,Xn-2), (tn-1,Xn-1), (tn,Xn)<br>
Com estes pontos conhecidos é possível calcular fn−3, fn−2, fn−1 e fn. Utilizando a fórmula de Adams-Bashforth, conseguimos estimar o valor de xn+1. Usando este valor encontrado, calculamos fn+1 e colocamos no método de Adams-Moulton, corrigindo o valor de xn+1. Dessa forma não teremos mais um método implícito.
<br><br>
O Preditor: <br>	
<img src="http://latex.codecogs.com/gif.latex?P_%7Bk&plus;1%7D%3DY_k&plus;%5Cfrac%7Bh%7D%7B24%7D%28-9f_%7Bk-3%7D-37f_%7Bk-2%7D-59f_%7Bk-1%7D&plus;55f_%7Bk%7D%29" align="center" border="0" alt="P_k_+_1 = Y_k + \frac{h}{24}(-9f_k_-_3 + 37f_k_-_2 - 59f_k_-_1 + 55f_k)" width="411" height="43" /><br>
O Corretor: <br>
<img src="http://latex.codecogs.com/gif.latex?Y_%7Bk&plus;1%7D%3DY_k&plus;%5Cfrac%7Bh%7D%7B24%7D%28f_%7Bk-2%7D-5f_%7Bk-1%7D&plus;19f_k&plus;9f%28t_%7Bk&plus;1%7D%2CP_%7Bk&plus;1%7D%29%29" align="center" border="0" alt="Y_k_+_1 = Y_k + \frac{h}{24}(f_k_-_2 - 5f_k_-_1 + 19f_k + 9f(t_k_+_1,P_k_+_1))" width="435" height="43" />

 ## Problemas resolvidos
 - [Dinâmica Populacional](Dinamica_populacional/README.md)
 - Circuitos RC 
 - Sistema Massa-Mola
 - [Lei de Resfriamento de Newton](Lei%20de%20resfriamento%20de%20Newton/README.md)
 - [Mistura de Substâncias](Mistura_de_substancias/README.md)
