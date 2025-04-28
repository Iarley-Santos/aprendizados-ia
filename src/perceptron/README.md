## ➡️ Perceptron em C++ – Portas Lógicas OR e AND

Este repositório contém implementações em C++ de um perceptron de camada única, treinado para simular as portas lógicas OR e AND. O objetivo é entender, de forma prática e didática, como funciona o algoritmo de aprendizado do perceptron.

## 🔍 O que é um Perceptron?

O perceptron é um modelo matemático inspirado no funcionamento dos neurônios biológicos, proposto por Frank Rosenblatt em 1958. Em um neurônio biológico, os dendritos recebem sinais elétricos de outros neurônios, processam esses sinais e, se a soma ultrapassar um determinado limiar, o neurônio "dispara" um impulso elétrico. Analogamente, o perceptron recebe múltiplas entradas, cada uma associada a um peso, calcula uma soma ponderada dessas entradas e aplica uma função de ativação para determinar a saída.
Matematicamente, o funcionamento de um perceptron pode ser descrito da seguinte forma:

![Texto alternativo](caminho/para/imagem.png)

1. **Entradas**: Um vetor de valores de entrada ($$x = [x_1, x_2, ..., x_n]$$).
2. **Pesos**: Cada entrada possui um peso associado ($$w = [w_1, w_2, ..., w_n]$$).
3. **Soma ponderada**: Calcula-se a soma ponderada das entradas e adiciona-se um viés ($b$ = bias):

$$
z = \sum_{i=1}^{n} w_i \cdot x_i + b
$$


4. **Função de ativação**: Aplica-se uma função de ativação à soma ponderada para determinar a saída do perceptron. No caso mais simples, utiliza-se a função degrau:

$$
f(z) = \begin{cases}
1, & \text{se } z \geq 0 \\
0, & \text{se } z < 0
\end{cases}
$$

🔄Durante o treinamento, os pesos e o viés são ajustados iterativamente com base no erro entre a saída prevista e a saída desejada, utilizando a seguinte regra de atualização:

$$
erro = d - y
$$

$$
w_i = w_i + \eta \cdot erro \cdot x_i
$$

$$
b = b + \eta \cdot erro
$$

Onde:
- $\eta$ : Taxa de aprendizado (learning rate).
- $d$ : Saída desejada.
- $y$: Saída prevista pelo perceptron.

Essa abordagem permite que o perceptron ajuste seus parâmetros para minimizar o erro de classificação em problemas onde os dados são **linearmente separáveis**.
