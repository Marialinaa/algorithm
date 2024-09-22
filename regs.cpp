#include <iostream>
#include <string>
using namespace std;

struct Jedi {
    string nome;
    int posicao;
    string nome_Cristal;
    string cor;
};

int main() {
    int qntd;
    cin >> qntd;
    
    Jedi jedis[qntd];
    string busca;

    // Leitura dos dados dos Jedis
    
    cin >> busca;

    // Definindo o máximo de posições esperadas
    const int MAX_POSICOES = 100;
    int contagem[MAX_POSICOES] = {0};
    bool posicaoPresente[MAX_POSICOES] = {false};
    int num_posicoes = 0;

    // Contar o número de Jedis para cada posição com a cor desejada
    for (int i = 0; i < qntd; ++i) {
        if (jedis[i].cor == busca) {
            bool encontrada = false;
            for (int j = 0; j < num_posicoes; ++j) {
                if (posicaoPresente[j] && jedis[i].posicao == j) {
                    contagem[j]++;
                    encontrada = true;
                    break;
                }
            }
            if (!encontrada) {
                posicaoPresente[num_posicoes] = true;
                contagem[num_posicoes] = 1;
                num_posicoes++;
            }
        }
    }

    // Exibe o resultado para cada posição na ordem em que apareceram
    for (int i = 0; i < num_posicoes; ++i) {
        cout <<jedis[i].posicao << i << ": " << contagem[i] << endl;
    }

    return 0;
}
