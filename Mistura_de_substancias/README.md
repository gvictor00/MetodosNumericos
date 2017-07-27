# Métodos numéricos

## O problema: Mistura de substâncias
Problema descrito como `Exemplo 1 da página 29, capítulo 2 do livro` **Equações Diferenciais** [Boyce, Diprima]
Problemas de mistura ocorrem com bastante frequência na indústria química. Por exemplo: determinar a concentração de uma certa substância, passado um tempo t, numa mistura; determinar a taxa de vazão de um líquido em um tanque industrial, etc.

Nas atividades industriais, a maioria dos processos apresenta a necessidade de agitação e mistura em ao menos uma de suas etapas. No caso de um processo de mistura, supõe-se geralmente que os componentes da mistura são perfeitamente misturados para facilitar a modelagem. Quanto aos calculos, balanços de massa devem ser realizados para o componente que se deseja estudar, a fim de que se obtenha uma equação diferencial, e assim, seja possível conhecer o modelo que descreve o estado transiente do sistema (BOYCE; PRIMA,1994).

O problema afirma o seguinte "a taxa de variação, no tempo, de uma substância e proporcional a diferença entre as taxas de entrada e saída da mesma". Este conceito e representado por uma equação diferencial ordinária: <br><br>
<img src="https://latex.codecogs.com/gif.latex?\frac{dY}{dt}&space;=&space;T_0&space;-&space;T_fY(t)" title="\frac{dY}{dt} = T_0 - T_fY(t)" />
Por fim, após resolver a equação diferencial temos a seguinte equação:<br><br>
<img src="https://latex.codecogs.com/gif.latex?y(t)=\frac{T_0}{T_f}&plus;Ce^{-Tft}" title="y(t)=\frac{T_0}{T_f}+Ce^{-Tft}" />

## O resultado:
O tanque contém 1000 galões de água, em que 100 libras de sal estão inicialmente dissolvidas. No tanque, despeja-se salmoura a uma taxa de 10 galoes/min, sendo que cada galão de salmoura contém 5 libras de sal dissolvido. A mistura no tanque é constantemente revolvida de modo a mante-la uniforme. A mistura de água e sal também escoa do tanque a uma taxa de 10 galoes/min. 
Encontre a quantidade de sal presente no tanque num instante `t=1`. É possível encontrar os valores de To e Tf. Multiplicando 5 libras por 10 galoes, calculamos para o tanque um fluxo de entrada de 50 libras de sal. Por outro lado, o fluxo de saída é de 10 galões de salmoura, o que corresponde a 10/1000 = 0,01 (= 1 porcento) do conteúdo total de salmoura no tanque, ou seja, a 0,01 do conteudo de sal y ou a 0,01y.
