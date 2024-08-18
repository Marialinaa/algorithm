#include <iostream>
using namespace std;

// Fun‡Æo de ordena‡Æo por Insertion Sort em ordem crescente
void insertion_sort_crescente(int vetor[], int inicio, int fim) {
    for (int i = inicio + 1; i <= fim; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= inicio && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

// Fun‡Æo de ordena‡Æo por Insertion Sort em ordem decrescente
void insertion_sort_decrescente(int vetor[], int inicio, int fim) {
    for (int i = inicio + 1; i <= fim; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= inicio && vetor[j] < chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

// Fun‡Æo  de ordena‡Æo
void orde_sort(int vetor[], int tam) {
    int div = tam / 2;

    insertion_sort_crescente(vetor, 0, div - 1);

    insertion_sort_decrescente(vetor, div, tam - 1);

    for (int k = 0; k < tam; k++) {
        cout << vetor[k] << " ";
    }
    cout << endl;

    // Exibe o elemento do meio
    if (tam % 2 == 0) {
        cout << "Elemento do meio: " << vetor[div - 1] << " (primeiro do segundo grupo)" << endl;
    } else {
        cout << "Elemento do meio: " << vetor[div] << endl;
    }
}

int main() {
    int tam;
    cin >> tam;

    if (tam % 2 == 0) {
        int vetor[tam];
        for (int i = 0; i < tam; i++) {
            cin >> vetor[i];
        }

        orde_sort(vetor, tam);
    } else {
        cout << "O tamanho do vetor deve ser par. Insira um tamanho par." << endl;
    }

    return 0;
}
