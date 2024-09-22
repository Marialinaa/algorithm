#include <iostream>
#include <fstream>
using namespace std;

struct indentificacao {
    string nome;
    char sexo;
    double altura;
    double peso; 
};

double calcularPesoIdeal(indentificacao p) {
    if (p.sexo == 'M') {
	return 72.7 * p.altura - 58;
    } else if (p.sexo == 'H') {
	return 62.1 * p.altura - 44.7;
    }
    return 1; 
}

int main() {
    int qntd;
    cin >> qntd;
    indentificacao id[qntd];

    for (int i = 0; i < qntd; i++) {
	cout << "Digite o nome do paciente " << i + 1 << ": ";
	getline(cin, id[i].nome);
	cout << "Digite o sexo do paciente " << i + 1 << " (M/H): ";
	cin >> id[i].sexo;
	cout << "Digite a altura do paciente " << i + 1 << " (em metros): ";
	cin >> id[i].altura;
	cout << "Digite o peso do paciente " << i + 1 << " (em quilos): ";
	cin >> id[i].peso;
    }

    indentificacao maisPesada = id[0];
    for (int i = 1; i < qntd; i++) {
	if (id[i].peso > maisPesada.peso) {
	    maisPesada = id[i];
	}
    }
    cout << "A pessoa mais pesada é " << maisPesada.nome << endl;

    cout << "Pessoas que estão acima do peso ideal:" << endl;
    for (int i = 0; i < qntd; i++) {
	double pesoIdeal = calcularPesoIdeal(id[i]);
	if (id[i].peso > pesoIdeal) {
	    cout << id[i].nome << " deve perder " << id[i].peso - pesoIdeal << " kg" << endl;
	}
    }

    return 0;
}
