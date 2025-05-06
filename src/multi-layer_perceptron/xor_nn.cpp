#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Neuronio
{
    private:
        vector<float> pesos;
        float bias;
        float taxa_aprendizado;

    public:
        //Construtor: inicializar os pesos com valores aleatórios e entre -1 e 1
        Neuronio(int num_entradas)
        {
            for(int i = 0; i < num_entradas; i++)
            {
                pesos.push_back(((float)rand() / RAND_MAX) * 2 - 1);
            }
            bias = ((float)rand() / RAND_MAX) * 2 - 1;
        }

        //Função de ativação(sigmoide)
        float sigmoide(float x)
        {
            return 1.0/(1.0 + exp(-x));
        }

        //Função de saída do neurônio (feedforward)
        float feedforward(const vector<float>& entradas)
        {
            float soma = 0.0;
            for(int i = 0; i < entradas.size(); i++)
            {
                soma += entradas[i] * pesos[i];
            }
            soma += bias;
            return sigmoide(soma);
        }
};