# Métodos numéricos

## O problema: Mistura de substâncias
Problemas de mistura ocorrem com bastante frequência na indústria química. Por exemplo: determinar a concentração de uma certa substância, passado um tempo t, numa mistura; determinar a taxa de vazão de um líquido em um tanque industrial, etc.

Nas atividades industriais, a maioria dos processos apresenta a necessidade de agitação e mistura em ao menos uma de suas etapas. No caso de um processo de mistura, supõe-se geralmente que os componentes da mistura são perfeitamente misturados para facilitar a modelagem. Quanto aos calculos, balanços de massa devem ser realizados para o componente que se deseja estudar, a fim de que se obtenha uma equação diferencial, e assim, seja possível conhecer o modelo que descreve o estado transiente do sistema (BOYCE; PRIMA,1994).

O problema afirma o seguinte "a taxa de variação, no tempo, de uma substância e proporcional a diferença entre as taxas de entrada e saída da mesma". Este conceito e representado por uma equação diferencial ordinária: <br>
<img src="https://latex.codecogs.com/gif.latex?\frac{dY}{dt}&space;=&space;T_0&space;-&space;Tf_y" title="\frac{dY}{dt} = T_0 - Tf_y"/>

Por fim, após resolver a equação diferencial temos a seguinte equação:<br>
<img src="https://latex.codecogs.com/gif.latex?y(t)=\frac{T_0}{T_f}&plus;Ce^{-Tft}" title="y(t)=\frac{T_0}{T_f}+Ce^{-Tft}" />