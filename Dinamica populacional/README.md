# Metodos Numericos

## O problema: Dinâmica populacional
O Malthusianismo é uma teoria demográfica criada pelo economista inglês Thomas Robert Malthus, no final do século XVIII. De acordo com esta teoria, a população mundial cresce em progressão geométrica, enquanto a produção de alimentos em progressão aritmética. Essa teoria foi definida por Malthus no livro Ensaio sobre o princípio da população, escrito em 1798. Malthus procurou alertar, com sua teoria, sobre os problemas gerados pelo elevado crescimento demográfico mundial. Porém no mundo de hoje suas teorias não se concretizam, a população não dobra a cada 50 anos, e a produção de alimentos é suficiente para alimentar essa população.

O modelo mais simples de crescimento populacional é aquele em que se supõe que a taxa de crescimento de uma população dx/dt é proporcional à população presente naquele instante x(t), ou seja, quanto mais pessoas houver em um instante (t), mais pessoas existirão

![Equation](Dinamica_populacional/dinamica_populacional.jpg?raw=true)

## As soluções
### Condições Iniciais
Tomando os valores de C = 3000, t = 2, k = 0.5493 e 100 subdivisões temos as seguintes soluções para os métodos apresentados:<br>
![Resultados](/resultados.jpg?raw=true)

#### EULER
Foram precisas 5431201 repeticoes e 1006.000000ms para um erro de 0.001

#### EULER MODIFICADO
Foram precisas 4461 repeticoes e 0.000000ms para um erro de 0,0001

#### PASSOS MULTIPLOS
Foram precisas 44 repeticoes e 0.000000ms para um erro de 0,0001

#### RUNGE KUTTA
Foram precisas 34 repeticoes e 0.000000ms para um erro de 0,0001
