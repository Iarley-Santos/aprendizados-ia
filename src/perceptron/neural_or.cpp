#include <stdio.h>   
#include <stdlib.h> 
#include <time.h>   
#include <iostream>
#include <unistd.h>
using namespace std; 

float peso;                
float taxa_aprendizado = 0.1;

// Função de ativação: degrau
int ativacao(float x) 
{
    return x >= 0.5 ? 1 : 0; // Se for >= 0.5 -> retorna 1 | Senão -> retorna 0
}

int calcular_saida(int x1, int x2, float peso1, float peso2)
{
    float soma = x1*peso1 + x2*peso2;
    return ativacao(soma);
}

// Função de treinamento
void treinar(int entradas[4][2], int saidas_esperadas[4], float& peso1, float& peso2, float taxa_aprendizado, int epocas)
{
    for(int e = 0; e < epocas; e++)
    {
        cout << "EPOCA" << e+1 << endl;
        for(int i = 0; i < 4; i++)
        {
            int x1 = entradas[i][0];
            int x2 = entradas[i][1];
            int saida_correta = saidas_esperadas[i];

            int saida = calcular_saida(x1, x2, peso1, peso2);
            int erro = saida_correta - saida;

             // Ajuste dos pesos
             peso1 += taxa_aprendizado * erro * x1;
             peso2 += taxa_aprendizado * erro * x2;

             // Mostrar detalhes
            cout << "Entrada: (" << x1 << "," << x2 << ") -> Saida: " << saida
            << " | Correta: " << saida_correta << " | Erro: " << erro
            << " | Pesos: (" << peso1 << ", " << peso2 << ")\n";
            sleep(1);
        }
        cout << "---------------------------------------------------------\n";
    }
}

// Testa a rede após o treinamento
void testar(int entradas[4][2], float peso1, float peso2)
{
    cout << "\nTeste apos treinamento:\n";
    for (int i = 0; i < 4; i++) {
        int x1 = entradas[i][0];
        int x2 = entradas[i][1];
        int saida = calcular_saida(x1, x2, peso1, peso2);
        cout << "Entrada: (" << x1 << "," << x2 << ") -> Saida final: " << saida << endl;
    }
}

int main()
{
    int entradas[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int saidas_esperadas[4] = {0, 1, 1, 1}; // OR

    float peso1 = 0.0, peso2 = 0.0;
    float taxa_aprendizado = 0.1;
    int epocas = 10;

    treinar(entradas, saidas_esperadas, peso1, peso2, taxa_aprendizado, epocas);
    testar(entradas, peso1, peso2);

    return 0;
}