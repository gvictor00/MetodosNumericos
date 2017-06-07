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
![Metodo_Euler](https://wikimedia.org/api/rest_v1/media/math/render/svg/823a0cbb6755ef8910cb3bb018d11411e81e4120?raw=true)
Escolhendo um valor para h {\displaystyle h} h para o tamanho de cada passo e atribuindo a cada passo um ponto dentro do intervalo, temos que t n = t 0 + n h {\displaystyle t_{n}=t_{0}+nh} {\displaystyle t_{n}=t_{0}+nh}. Nisso, o próximo passo t n + 1 {\displaystyle t_{n+1}} t_{n+1} a partir do anterior t n {\displaystyle t_{n}} t_n fica definido como t n + 1 = t n + h {\displaystyle t_{n+1}=t_{n}+h} {\displaystyle t_{n+1}=t_{n}+h}.

## As soluções
### Condições Iniciais
Tomando os valores de C = 3000, t = 2 e k = 0.5493 temos as seguintes soluções para os métodos apresentados: