#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <iomanip>

using namespace std;

const int CAPACIDADE_INICIAL = 40;
const int INCREMENTO = 10;

// Estrutura de dados para representar uma música
struct Musica {
    char nome[100];
    unsigned int duracao;
    char dataLancamento[11];
    char artista[100];
    char genero[50];
    bool valido;  // Usar `false` para indicar remoção lógica
};

// Função para redimensionar o vetor de músicas
Musica* redimensionarVetor(Musica* musicas, int& capacidadeAtual, int incremento) {
    Musica* novoVetor = new Musica[capacidadeAtual + incremento];
    for (int i = 0; i < capacidadeAtual; ++i) {
        novoVetor[i] = musicas[i];
    }
    delete[] musicas;
    capacidadeAtual += incremento;
    return novoVetor;
}
// Função para carregar dados do arquivo CSV
bool carregarCSV(Musica*& musicas, int& quantidadeMusicas, int& capacidade) {
    ifstream arquivoCSV("dadosmusicas.csv");
    if (!arquivoCSV.is_open()) {
        cout << "Erro ao abrir o arquivo CSV." << endl;
        return false;
    }

    while (!arquivoCSV.eof()) {
        Musica temp;
        arquivoCSV.getline(temp.nome, 100, ';');
        arquivoCSV >> temp.duracao;
        arquivoCSV.ignore();
        arquivoCSV.getline(temp.dataLancamento, 11, ';');
        arquivoCSV.getline(temp.artista, 100, ';');
        arquivoCSV.getline(temp.genero, 50);
        temp.valido = true;

        if (quantidadeMusicas >= capacidade) {
            musicas = redimensionarVetor(musicas, capacidade, INCREMENTO);
        }
        musicas[quantidadeMusicas++] = temp;
    }

    arquivoCSV.close();
    return true;
}

// Função para exportar dados para CSV
void exportarParaCSV(Musica* musicas, int quantidadeMusicas) {
    ofstream arquivoCSV("dadosmusicas.csv");
    if (!arquivoCSV.is_open()) {
        cout << "Erro ao abrir o arquivo CSV para escrita." << endl;
        return;
    }

    for (int i = 0; i < quantidadeMusicas; ++i) {
        if (musicas[i].valido) {
            arquivoCSV << musicas[i].nome << ";"
                       << musicas[i].duracao << ";"
                       << musicas[i].dataLancamento << ";"
                       << musicas[i].artista << ";"
                       << musicas[i].genero << endl;
        }
    }

    cout << "Dados exportados com sucesso para o arquivo CSV." << endl;
    arquivoCSV.close();
}
// Função para inserir uma nova música no final do vetor
void inserirMusica(Musica*& musicas, int& quantidadeMusicas, int& capacidade, const Musica& novaMusica) {
    if (quantidadeMusicas >= capacidade) {
        musicas = redimensionarVetor(musicas, capacidade, INCREMENTO);
    }
    musicas[quantidadeMusicas++] = novaMusica;
}

// Função para remover uma música logicamente
void removerMusica(Musica* musicas, int& quantidadeMusicas, const char* nome) {
    for (int i = 0; i < quantidadeMusicas; ++i) {
        if (strcmp(musicas[i].nome, nome) == 0 && musicas[i].valido) {
            musicas[i].valido = false;
            cout << "Música removida com sucesso." << endl;
            return;
        }
    }
    cout << "Música não encontrada." << endl;
}
// Função para buscar música pelo nome (usando busca binária)
bool buscarMusicaBinaria(Musica* musicas, int quantidadeMusicas, const char* nome, int& index) {
    int esquerda = 0;
    int direita = quantidadeMusicas - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(musicas[meio].nome, nome);
        if (cmp == 0 && musicas[meio].valido) {
            index = meio;
            return true;
        }
        if (cmp < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return false;
}

// Função para ordenar músicas usando Quick Sort
void quickSort(Musica* musicas, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = direita;
        int i = esquerda;
        for (int j = esquerda; j < direita; ++j) {
            if (strcmp(musicas[j].nome, musicas[pivo].nome) < 0) {
                swap(musicas[i], musicas[j]);
                ++i;
            }
        }
        swap(musicas[i], musicas[pivo]);
        quickSort(musicas, esquerda, i - 1);
        quickSort(musicas, i + 1, direita);
    }
} // Função para mostrar um trecho do vetor de músicas
void mostrarTrechoMusicas(Musica* musicas, int quantidadeMusicas, int inicio, int fim) {
    if (inicio < 0 || fim >= quantidadeMusicas || inicio > fim) {
        cout << "Intervalo inválido." << endl;
        return;
    }

    cout << "Mostrando músicas do registro " << inicio + 1 << " ao " << fim + 1 << ":" << endl;
    for (int i = inicio; i <= fim; ++i) {
        if (musicas[i].valido) {
            cout << "Registro " << i + 1 << ":" << endl;
            cout << "Nome: " << musicas[i].nome << endl;
            cout << "Duração: " << musicas[i].duracao << " segundos" << endl;
            cout << "Data de Lançamento: " << musicas[i].dataLancamento << endl;
            cout << "Artista: " << musicas[i].artista << endl;
            cout << "Gênero: " << musicas[i].genero << endl;
            cout << "--------------------" << endl;
        }
    }
}

// Função principal
int main() {
    int capacidade = CAPACIDADE_INICIAL;
    int quantidadeMusicas = 0;
    Musica* musicas = new Musica[capacidade];

    // Carregar dados do arquivo CSV
    if (!carregarCSV(musicas, quantidadeMusicas, capacidade)) {
        delete[] musicas;
        return 1;
    }
  cout<<" Para busca binária, os dados devem estar ordenados. Portanto, a ordenação deve ser feita antes da busca."<<endl;
    // Menu de opções
    int opcao;
    do {
        cout << "Menu:" << endl;
        cout << "1. Mostrar todas as músicas" << endl;
        cout << "2. Mostrar um trecho das músicas" << endl;
        cout << "3. Buscar música" << endl;
        cout << "4. Inserir nova música" << endl;
        cout << "5. Remover música" << endl;
        cout << "6. Ordenar músicas" << endl;
        cout << "7. Exportar dados para CSV" << endl;
        cout << "8. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpar buffer de entrada

        switch (opcao) {
            case 1:
                mostrarTrechoMusicas(musicas, quantidadeMusicas, 0, quantidadeMusicas - 1);
                break;
            case 2: {
                int inicio, fim;
                cout << "Digite o índice inicial: ";
                cin >> inicio;
                cout << "Digite o índice final: ";
                cin >> fim;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                mostrarTrechoMusicas(musicas, quantidadeMusicas, inicio - 1, fim - 1);
                break;
            }
            case 3:
                // Implementar busca de música
                break;
            case 4: {
                Musica novaMusica;
                cout << "Digite o nome da música: ";
                cin.getline(novaMusica.nome, 100);
                cout << "Digite a duração da música (em segundos): ";
                cin >> novaMusica.duracao;
                cin.ignore();
                cout << "Digite a data de lançamento (dd/mm/aaaa): ";
                cin.getline(novaMusica.dataLancamento, 11);
                cout << "Digite o nome do artista: ";
                cin.getline(novaMusica.artista, 100);
                cout << "Digite o gênero da música: ";
                cin.getline(novaMusica.genero, 50);
                novaMusica.valido = true;
                inserirMusica(musicas, quantidadeMusicas, capacidade, novaMusica);
                break;
            }
            case 5: {
                char nome[100];
                cout << "Digite o nome da música a ser removida: ";
                cin.getline(nome, 100);
                removerMusica(musicas, quantidadeMusicas, nome);
                break;
            }
            case 6:
                // Ordenar músicas
                quickSort(musicas, 0, quantidadeMusicas - 1);
                cout << "Músicas ordenadas." << endl;
                break;
            case 7:
                exportarParaCSV(musicas, quantidadeMusicas);
                break;
            case 8:
                // Salvar e sair
                exportarParaCSV(musicas, quantidadeMusicas);
                delete[] musicas;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }

    } while (opcao != 8);

    return 0;
}


