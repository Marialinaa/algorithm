#include <iostream>
#include <fstream>
 
using namespace std;
 
struct Medicoes{
	int graus[24];
	int humidade[24];
};

struct Tabela{
	int ID;
	string dia;
	float mediaGraus;
	float mediaHumidade;

	bool verifica;
};

void menu(){
	cout << " --------------------------------- " << endl
		 << "|              Menu               |" << endl 
		 << "|---------------------------------|" << endl
		 << "|1 - Inserir                      |" << endl
		 << "|2 - Remover                      |" << endl
		 << "|3 - Consultar                    |" << endl
		 << "|4 - Listar                       |" << endl
		 << "|5 - Salvar ordenado              |" << endl
		 << "|6 - Salvar Temperatura ordenado  |" << endl
		 << "|7 - Salvar Humidade ordenado     |" << endl
		 << "|0 - Sair                         |" << endl
		 << " --------------------------------- " << endl << endl;
}

void escolhaDia(){
	cout << " -------------------- " << endl
		 << "|   Escolha um dia   |" << endl
		 << "|--------------------|" << endl
		 << "| 1 - Domingo        |" << endl
		 << "| 2 - Segunda        |" << endl
		 << "| 3 - Terca          |" << endl
		 << "| 4 - Quarta         |" << endl
		 << "| 5 - Quinta         |" << endl
		 << "| 6 - Sexta          |" << endl
		 << "| 7 - Sabado         |" << endl
		 << " -------------------- " << endl << endl;
}

char opcoes(){
	char escolha = '0';
	bool verifica = false;

	while (escolha < '1' or escolha > '7'){
		if(not verifica){
			cout << "Insira a opcao: ";
			cin >> escolha;

			verifica = true;
		} else {
			 cout << "Escolha invalida!" << endl;
		}
	}
	return escolha;
}

void selectionSortID(Tabela* &tabela, int quant_atual){
	int posMenor;
	Tabela aux;

	for (int i = 0; i < quant_atual-1; i++){
		posMenor = i;
		for (int j = i+1; j < quant_atual; j++){
			if (tabela[j].ID < tabela[posMenor].ID){
				posMenor = j;
			}
		}
		aux = tabela[i];
		tabela[i] = tabela[posMenor];
		tabela[posMenor] = aux;
	}
}

void selectionSortTemperatura(Tabela* &tabela, int quant_atual){
	int posMenor;
	Tabela aux;

	for (int i = 0; i < quant_atual-1; i++){
		posMenor = i;
		for (int j = i+1; j < quant_atual; j++){
			if (tabela[j].mediaGraus < tabela[posMenor].mediaGraus){
				posMenor = j;
			}
		}
		aux = tabela[i];
		tabela[i] = tabela[posMenor];
		tabela[posMenor] = aux;
	}
}

void selectionSortHumidade(Tabela* &tabela, int quant_atual){
	int posMenor;
	Tabela aux;

	for (int i = 0; i < quant_atual-1; i++){
		posMenor = i;
		for (int j = i+1; j < quant_atual; j++){
			if (tabela[j].mediaHumidade < tabela[posMenor].mediaHumidade){
				posMenor = j;
			}
		}
		aux = tabela[i];
		tabela[i] = tabela[posMenor];
		tabela[posMenor] = aux;
	}
}

void incluir(Medicoes* &med, Tabela* &tabela, int &quant_atual){
	int hora = 0;

	for (int i = 0; i < 7; i++){
		tabela[quant_atual].mediaGraus = 0;
		tabela[quant_atual].mediaHumidade = 0;

		while(hora < 24){
			cin >> med[quant_atual].graus[hora]
				>> med[quant_atual].humidade[hora];

			hora++;
		}
		tabela[quant_atual].mediaGraus = med[quant_atual].graus[hora]/24;
		tabela[quant_atual].mediaHumidade = med[quant_atual].humidade[hora]/24;
		tabela[quant_atual].ID = quant_atual+1;

		tabela[quant_atual].verifica = true;

		quant_atual++;
	}

	
}

void excluir(Tabela* &tabela, int quant_atual){

}

void listar(Tabela* &tabela, int quant_atual){
	bool entrou = false;

	cout << " ---------------------------------------------- " << endl
		 << "|                    Dados                     |" << endl 
		 << "|----------------------------------------------|" << endl
		 << "| ID | Dia da Semana | Temperatura | Humidadde |" << endl;

	for (int i = 0; i < quant_atual; i++){
		if(tabela[i].verifica){
			cout << "| " << tabela[i].ID << "  | " << tabela[i].dia;

			int qtd = tabela[i].dia.size();

			if(qtd < 7){
				for (int i = qtd; i < 7-qtd; i++){
					cout << " ";
				}
			}
			cout << "       | " << tabela[i].mediaGraus << "ºC        | " << tabela[i].mediaHumidade << "%       |" << endl;

			entrou = true;
		}
	}
	if(not entrou){
		cout << "| Nao ha dados para exibir                     |" << endl;
	}
	cout << " ---------------------------------------------- " << endl;
}

void salvarArquivo(Tabela* &tabela, int quant_atual){
	ofstream arqS ("dados.txt");

	selectionSortID(tabela, quant_atual);

	if(arqS){
		arqS << "				**** TEMPERATURAS DA SEMANA ****"               << endl
			 << "					RESULTADOS OBTIDOS:"                                   << endl
			 << endl
			 << endl
			 << endl
			 << "			ID	Dia		Temperatura		Humidade" << endl << endl;

		for (int i = 0; i < quant_atual; i++){
			arqS << "			" << tabela[i].ID << "	" << tabela[i].dia;

			int qtd = tabela[i].dia.size();

			if(qtd < 7){
				for (int i = qtd; i < 7-qtd; i++){
					arqS << " ";
				}
			}
			arqS << tabela[i].mediaGraus << "ºC			" << tabela[i].mediaHumidade << "%" << endl;
		}
		arqS << "				  CÁLCULOS EFETUADOS COM ALTA PRECISÃO." << endl
			 << endl
			 << "			     *********************************************" << endl
			 << endl
			 << "			     Dados processados com o programa de monitoramento climátco, V. 1.0.5-Beta" << endl
			 << " 		 Departamento de Ciência da Computação - Universidade Federal de Lavras" << endl
			 << " 					    dcc@dcc.ufla.br";
		
		arqS.close();
	} else {
		cout << "Nao foi possivel criar o arquivo!" << endl;
	}
}

void salvarTempOrdenado(Tabela* &tabela, int quant_atual){
	selectionSortTemperatura(tabela, quant_atual);

	ofstream arqS ("dadosTemperatura.txt");

	if(arqS){
		arqS << "				**** TEMPERATURAS DA SEMANA ****"               << endl
			 << "					RESULTADOS OBTIDOS:"                                   << endl
			 << endl
			 << endl
			 << endl
			 << "			ID	Dia		Temperatura		Humidade" << endl << endl;

		for (int i = 0; i < quant_atual; i++){
			arqS << "			" << tabela[i].ID << "	" << tabela[i].dia;

			int qtd = tabela[i].dia.size();

			if(qtd < 7){
				for (int i = qtd; i < 7-qtd; i++){
					arqS << " ";
				}
			}
			arqS << tabela[i].mediaGraus << "ºC			" << tabela[i].mediaHumidade << "%" << endl;
		}
		arqS << "				  CÁLCULOS EFETUADOS COM ALTA PRECISÃO." << endl
			 << endl
			 << "			     *********************************************" << endl
			 << endl
			 << "			     Dados processados com o programa de monitoramento climátco, V. 1.0.5-Beta" << endl
			 << " 		 Departamento de Ciência da Computação - Universidade Federal de Lavras" << endl
			 << " 					    dcc@dcc.ufla.br";
		
		arqS.close();
	} else {
		cout << "Nao foi possivel criar o arquivo!" << endl;
	}
}

void salvarHumiOrdenado(Tabela* &tabela, int quant_atual){
	selectionSortHumidade(tabela, quant_atual);

	ofstream arqS ("dadosHumidade.txt");

	if(arqS){
		arqS << "				**** TEMPERATURAS DA SEMANA ****"<< endl
			 << "					RESULTADOS OBTIDOS:"<< endl
			 << endl
			 << endl
			 << endl
			 << "			ID	Dia		Temperatura		Humidade" << endl << endl;

		for (int i = 0; i < quant_atual; i++){
			arqS << "			" << tabela[i].ID << "	" << tabela[i].dia;

			int qtd = tabela[i].dia.size();

			if(qtd < 7){
				for (int i = qtd; i < 7-qtd; i++){
					arqS << " ";
				}
			}
			arqS << tabela[i].mediaGraus << "ºC			" << tabela[i].mediaHumidade << "%" << endl;
		}
		arqS << "				  CÁLCULOS EFETUADOS COM ALTA PRECISÃO." << endl
			 << endl
			 << "			     *********************************************" << endl
			 << endl
			 << "			     Dados processados com o programa de monitoramento climátco, V. 1.0.5-Beta" << endl
			 << " 		 Departamento de Ciência da Computação - Universidade Federal de Lavras" << endl
			 << " 					    dcc@dcc.ufla.br";
		
		arqS.close();
	} else {
		cout << "Nao foi possivel criar o arquivo!" << endl;
	}
}

void consultar(Tabela* &tabela, int quant_atual){
	escolhaDia();

	char opcao = opcoes();

	if(opcao == '1'){
		cout << "Os dados de " << tabela[0].dia           << " sao de:"
			 << "Graus   : "   << tabela[0].mediaGraus    << endl
			 << "Humidade: "   << tabela[0].mediaHumidade << endl << endl;
	} else if(opcao == '2'){
		cout << "Os dados de " << tabela[1].dia           << " sao de:"
			 << "Graus   : "   << tabela[1].mediaGraus    << endl
			 << "Humidade: "   << tabela[1].mediaHumidade << endl << endl;
	} else if(opcao == '3'){
		cout << "Os dados de " << tabela[2].dia           << " sao de:"
			 << "Graus   : "   << tabela[2].mediaGraus    << endl
			 << "Humidade: "   << tabela[2].mediaHumidade << endl << endl;
	} else if(opcao == '4'){
		cout << "Os dados de " << tabela[3].dia           << " sao de:"
			 << "Graus   : "   << tabela[3].mediaGraus    << endl
			 << "Humidade: "   << tabela[3].mediaHumidade << endl << endl;
	} else if(opcao == '5'){
		cout << "Os dados de " << tabela[4].dia           << " sao de:"
			 << "Graus   : "   << tabela[4].mediaGraus    << endl
			 << "Humidade: "   << tabela[4].mediaHumidade << endl << endl;
	} else if(opcao == '6'){
		cout << "Os dados de " << tabela[5].dia           << " sao de:"
			 << "Graus   : "   << tabela[5].mediaGraus    << endl
			 << "Humidade: "   << tabela[5].mediaHumidade << endl << endl;
	} else if(opcao == '7'){
		cout << "Os dados de " << tabela[6].dia           << " sao de:"
			 << "Graus   : "   << tabela[6].mediaGraus    << endl
			 << "Humidade: "   << tabela[6].mediaHumidade << endl << endl;
	}
}
 
int main () {
	int quant_atual = 0;
	char opcao;

	Medicoes* med = new Medicoes[7];
	Tabela* tabela = new Tabela[7];

	tabela[0].dia = "Segunda";
	tabela[1].dia = "Terca";
	tabela[2].dia = "Quarta";
	tabela[3].dia = "Quinta";
	tabela[4].dia = "Sexta";
	tabela[5].dia = "Sabado";
	tabela[6].dia = "Domingo";

	do{
		menu();

		opcao = opcoes();

		switch(opcao){
			case '1':{
				incluir(med, tabela, quant_atual);
				break;
			}
			case '2':{
				//excluir(tabela, quant_atual);
				break;
			}
			case '3':{
				consultar(tabela, quant_atual);
				break;
			}
			case '4':{
				listar(tabela, quant_atual);
				break;
			}
			case '5':{
				salvarArquivo(tabela, quant_atual);
				break;
			}
			case '6':{
				salvarTempOrdenado(tabela, quant_atual);
				break;
			}
			case '7':{
				salvarHumiOrdenado(tabela, quant_atual);
				break;
			}
		}
	} while(opcao != '7');

	delete[] med;
	delete[] tabela;

	med = NULL;
	tabela = NULL;

	return 0;
}

