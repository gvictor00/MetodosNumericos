# Metodos Numericos

## Cálculo de EDO de dinâmica populacional usando os métodos numéricos como:
 - Método de Euler;
 - Método de Euler Modificado;
 - Método de Adams-Bashforth-Moulton 4ª ordem; 
 - Método de Runge Kutta 4ª ordem.

## O problema: Dinâmica populacional
O Malthusianismo é uma teoria demográfica criada pelo economista inglês Thomas Robert Malthus, no final do século XVIII. De acordo com esta teoria, a população mundial cresce em progressão geométrica, enquanto a produção de alimentos em progressão aritmética. Essa teoria foi definida por Malthus no livro Ensaio sobre o princípio da população, escrito em 1798. Malthus procurou alertar, com sua teoria, sobre os problemas gerados pelo elevado crescimento demográfico mundial. Porém no mundo de hoje suas teorias não se concretizam, a população não dobra a cada 50 anos, e a produção de alimentos é suficiente para alimentar essa população.

O modelo mais simples de crescimento populacional é aquele em que se supõe que a taxa de crescimento de uma população dx/dt é proporcional à população presente naquele instante x(t), ou seja, quanto mais pessoas houver em um instante (t), mais pessoas existirão

![Equation](/dinamica_populacional.jpg?raw=true)

## Os métodos
### Método de Euler 
Suponha que queremos aproximar a solução de um problema de valor inicial:
![Metodo_Euler](https://wikimedia.org/api/rest_v1/media/math/render/svg/823a0cbb6755ef8910cb3bb018d11411e81e4120?raw=true) <br>

Escolhendo um valor h para tamanho de cada passo e atribuindo a cada passo um ponto dentro do intervalo, temos que tn = t0 + nh. Nisso, o próximo passo tn+1 a partir do anterior tn fica definido tn+1 = tn + h, então:<br>
![Metodo_Euler](https://wikimedia.org/api/rest_v1/media/math/render/svg/269f6c656eab53584639f205ecfe88b628af701a)

### Método de Euler Modificado 
O método de Euler Modificado é um aperfeiçoamento do método de Euler simples. Ele consiste em usar o Método de Euler como Preditor e fazer a corrteção atavés de uma nova equação. O Método de Euler Modificado também é conhecido como Runge-Kutta de 2ª ordem. <br>
![Metetodo_Euler_Modificado](https://s16.postimg.org/3yyji0tu9/image.jpg)

### Runge Kutta
![Runge-Kutta](https://wikimedia.org/api/rest_v1/media/math/render/svg/d8534f269d223b247698d487d6b93eef6a1070df)<br>
![Runge-Kutta](https://wikimedia.org/api/rest_v1/media/math/render/svg/42c75230fa264441ebc3725e456ea17147a604c3)

### Passo Múltiplos
Métodos de passo múltiplos são utilizados para a soluções numéricas de equações diferenciais ordinárias. Conceitualmente, um método numérico começa a partir de um ponto inicial e, em seguida, leva um pequeno passo para a frente no tempo para encontrar o próximo ponto da solução. O processo continua com os passos subsequentes para mapear a solução. Métodos de uma etapa (como o método de Euler) referem-se a apenas um ponto anterior e sua derivada a determinar o valor atual. Métodos como os Runge-Kutta dão alguns passos intermediários (por exemplo, um meio-passo) para obter um método de ordem superior, mas, em seguida, descartam todas as informações anteriores antes de tomar uma segunda etapa. Métodos de várias etapas tentam ganhar eficiência, mantendo e usando as informações a partir das etapas anteriores, em vez de descartá-las. Consequentemente, os métodos de várias etapas referem-se a vários pontos anteriores e valores derivados. No caso de métodos de várias etapas lineares, uma combinação linear dos pontos anteriores e os valores derivados são utilizados.<br>
![PM](https://s16.postimg.org/g23v5l4wh/image.jpg)
## As soluções
### Condições Iniciais
Tomando os valores de C = 3000, t = 2, k = 0.5493 e 100 subdivisões temos as seguintes soluções para os métodos apresentados:<br>
![Resultados](/resultados.jpg?raw=true)