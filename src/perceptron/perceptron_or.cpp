#include <iostream>
#include <unistd.h>
using namespace std; 

class Perceptron
{
    private:
        float peso1, peso2;
        float taxa_aprendizado;

        // Função de ativação(degrau)
        int ativacao(float x)
        {
            if(x >= 0.5)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // Função que calcula a saída de acordo com as entradas e pesos
        int calcular_saida(int x1, int x2)
        {
            float soma = x1*peso1 + x2*peso2;
            return ativacao(soma);
        }
    
    public:
        // Costrutor
        Perceptron(float taxa_aprendizado = 0.1, float peso1 = 0.0, float peso2 = 0.0)
        {
            this->peso1 = peso1;
            this->peso2 = peso2;
            this->taxa_aprendizado = taxa_aprendizado;
        }

        // Método de treinamento
        void treinar(int entradas[4][2], int saidas_esperadas[4], int epocas)
        {
            for(int e = 0; e < epocas; e++)
            {
                cout << "EPOCA " << e+1 << endl;
                for (int i = 0; i < 4; i++) 
                {
                    int x1 = entradas[i][0];
                    int x2 = entradas[i][1];
                    int saida_correta = saidas_esperadas[i];
    
                    int saida = calcular_saida(x1, x2);
                    int erro = saida_correta - saida;
    
                    // Ajuste dos pesos
                    peso1 += taxa_aprendizado * erro * x1;
                    peso2 += taxa_aprendizado * erro * x2;
    
                    // Mostrar detalhes
                    cout << "Entrada: (" << x1 << "," << x2 << ") -> Saida: " << saida
                         << " | Correta: " << saida_correta << " | Erro: " << erro
                         << " | Pesos: (" << peso1 << ", " << peso2 << ")\n";
                    sleep(1); // Delay de 1 segundo
                }
                cout << "---------------------------------------------------------------------\n";
            }
        }

        // Método de teste após o treinamento
        void testar(int entradas[4][2]) 
        {
            cout << "\nTESTE:\n";
            for (int i = 0; i < 4; i++) {
                int x1 = entradas[i][0];
                int x2 = entradas[i][1];
                int saida = calcular_saida(x1, x2);
                cout << "Entrada: (" << x1 << "," << x2 << ") -> Saida final: " << saida << endl;
            }
        }
};

int main() 
{
    int entradas[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    int saidas_esperadas[4] = {0, 1, 1, 1}; // OR

    Perceptron p(0.1);
    p.treinar(entradas, saidas_esperadas, 10);
    p.testar(entradas);

    return 0;
}
