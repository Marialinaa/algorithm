#include <iostream>
#include <fstream>
#include <cmath>
 using namespace std;
struct bolao{
	int numero_times;
	string nome_time;
	int qntd_Golsmarcado;
	};
	void ler(bolao ve[],int tam){
    for(int i=0;i<tam;i++){
		cin>>ve[i].numero_times;
		cin>>ve[i].nome_time;
		cin>>ve[i].qntd_Golsmarcado;
		}
		}
		void ordena(bolao ve[],int tam){
			for(int i=1;i<tam;i++){
				bolao valor_pivo=ve[i];
				int j=i-1;
				while((j>=0 && valor_pivo.numero_times<ve[j].numero_times)){
					ve[j+1]=ve[j];
							j--;
					}
				ve[j+1]=valor_pivo;
				}
			}
			int procurar(bolao ve[],int tam,int buscado){
			
				for(int i=1;i<tam;i++){
					if(ve[i].numero_times==buscado){
						cout<<ve[i].nome_time<<ve[i].qntd_Golsmarcado;
						return i;
					}
				
				}
			return - 1;	
				}
 int main (){
	 int qntd;
	 cin>>qntd;
	bolao vetor[qntd];
	ler(vetor,qntd);
	 ordena(vetor,qntd);
	 int buscador;
		 cin>>buscador;
		 int posicao=procurar(vetor,qntd,buscador);

	 return 0;
	 }
	



