# Time Complexity Analysis

Project for the class Complexity Analysis (Projeto e Análise de Algoritmos) regarding optmization of fibonnaci and matrices multiplication

## 1) Utilizando os slides vistos em aula implemente o calculo do n-ésimo termo de Fibonacci
utilizando os seguintes métodos:

1.1) ~~recursivo ingênuo~~
1.2) ~~direto utilizando um laço de repetição~~
1.3) ~~calculado diretamente utilizando a formula~~
1.4) ~~fazendo o cálculo através da matriz.~~

a) ~~Para cada um, utilize biblioteca “time.h” para medir o tempo de cada algoritmo para
calcular todos os primeiros:

* ~~5 termos~~
* ~~10 termos~~
* ~~20 termos~~
* ~~40 termos~~
* 60 termos
* 70 termos

![alt text](https://raw.githubusercontent.com/CS-Bachelor-UnB/fibonacci_and_strassen_complexity/master/assets/fibonacci_plot1.png)

**Use o tempo gasto para os problemas menores para estimar o tempo dos problemas maiores
quando for o caso**. Faça um gráfico com os tempos para cada algoritmo.

b) O método 1.3 falha em dar a resposta certa para qual termo (testar até encontrar erro) ?
> O cálculo utilizando a fórmula de Binet falha a partir do 40th termo.

c) Os tempos obtidos estão de acordo com a complexidade teórica esperada? Justifique.
> Sim. O cálculo por matriz segue O(log n), por recursão O(n^2), por fórmula O(log n), e looping O(n) como mostrado no gráfico. Note que y-axis está na escala log

d) Qual o maior termo de Fibonacci que você consegue calcular usando qualquer
algoritmo? Qual o motivo disto?

## 2) A multiplicação matrizes normal O(n3) deve ser comparado com o algoritmo de Strassen

a) Faça um gráfico onde x é a dimensão das matrizes multiplicadas e y é o tempo.
Os valores de x e devem ser escolhidos tal que fique clara a diferença de complexidades
(pode ser usado o log).

b) A seguir responda: os resultados obtidos estão de acordo com a complexidade esperada?
Explique. Para que tamanhos de n a multiplicação matrizes normal é melhor? A partir de
que valor de n algoritmo de Strassen ganha da multiplicação tradicional? 


## 3) How to Compile and Run it?
> intructions to follow shortly
