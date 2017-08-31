# Métodos numéricos

## O problema: Lei de resfriamento de Newton
Problema descrito como `Problema 23 da sessão 1.1, capítulo um, do livro` **Equações Diferenciais** [Boyce, Diprima]
A Lei do resfriamento de Newton expressa que a taxa de perda de calor de um corpo é proporcional à diferença de temperatura entre o corpo e a meio em que está.

Um modelo real simples que trata sobre a troca de calor de um corpo com o meio ambiente onde está posto, aceita três hipóteses básicas:
  1. A temperatura T=T(t) depende do tempo e é a mesma em todos os pontos do corpo.
  2. A temperatura Tm do meio ambiente permanece constante no decorrer da experiência.
  3. A taxa de variação da temperatura com relação ao tempo é proporcional à diferença de temperatura entre o corpo e o meio ambiente. 

A lei do resfriamento de Newton diz que a temperatura do objeto varia a uma taxa proporcional à diferença entre a temperatura do objeto e a do seu meio ambiente (na maioria dos casos, a temperatura do ar ambiente). (BOYCE; DIPRIMA, 1994).

Com o conceito apresentado acima, podemos representar o problema por uma equação diferencial ordinária: <br><br>
<img src="https://latex.codecogs.com/gif.latex?\frac{dT}{dt}=-k(T-T_m)" title="\frac{dT}{dt}=-k(T-T_m)" /><br>

Onde T = T(t) é a temperatura do corpo no instante t, Tm é a temperatura constante do meio ambiente, T-Tm é a diferença de temperatura e k é a constante que depende do material que está sendo utilizado.

Por fim, após resolver a equação diferencial temos a seguinte equação:<br><br>
<img src="https://latex.codecogs.com/gif.latex?T(t)=Ce^{-kt}&plus;T_m" title="T(t)=Ce^{-kt}+T_m" />
<br>
Onde C = T0 - Tm
