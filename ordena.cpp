#include <iostream>
#include <string>
using namespace std;

// Estrutura para armazenar dados de um aluno
struct Aluno {
    int matricula;
    string nome;
};

// Função para realizar busca binária
int buscaBinaria(Aluno alunos[], int tam, int matriculaProcurada) {
    int esquerda = 0;
    int direita = tam - 1;
    int meio;
    
    while (esquerda <= direita) {
        meio = esquerda + (direita - esquerda) / 2;
        
        // Exibe o número da matrícula comparado
        cout << alunos[meio].matricula << endl;
        
        if (alunos[meio].matricula == matriculaProcurada) {
            return meio; // Encontrou o aluno
        }
        if (alunos[meio].matricula < matriculaProcurada) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    
    return -1; // Não encontrado
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Ignora o newline após a leitura do número de alunos

    Aluno alunos[n];
    
    // Leitura dos dados dos alunos
    for (int i = 0; i < n; i++) {
        cin >> alunos[i].matricula;
        cin.ignore(); // Ignora o espaço após a matrícula
        getline(cin, alunos[i].nome);
    }
    
    int matriculaProcurada;
    cin >> matriculaProcurada;

    // Busca binária e exibição do nome
    int resultado = buscaBinaria(alunos, n, matriculaProcurada);
    
    if (resultado != -1) {
        cout << alunos[resultado].nome << endl;
    }

    return 0;
}
