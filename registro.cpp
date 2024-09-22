#include <iostream>
#include <fstream>
#include <cstdlib>
 using namespace std;
 struct data{
	 int dia;
	 int mes;
	 int ano;
	 };
struct animais {
	int id;
	string nome_animal;
	string dono;
	 data ultimaVacina;
	};
	
	int busca_Binaria(const animais animal[],int tamanho,int idbuscado){
   int inicio=0;
   int fim=tamanho-1;
   
      while(inicio<fim){
		  int meio=inicio+(fim-inicio)/2;
		  if(animal[meio].id==idbuscado){
			  return meio;
		  } else if(animal[meio].id<idbuscado){
			  inicio=meio+1;
			  }		else {
				  fim=meio-1;
				  }		
	}
	return -1;
		}
		
 int main (){
	 const int ta=100;   //questao 13 busca binaria
	 animais animal[ta];
	 int cont=0;
	 bool parada=true;
	 while(cont<ta){
		 int ide;
		 cin>>ide;
		 if(ide==0){
			 parada=false;
			 }  
			 animal[cont].id=ide;
			 cin>>animal[cont].nome_animal;			 
			 cin>>animal[cont].dono;
			 cin>>animal[cont].ultimaVacina.dia;
			 cin>>animal[cont].ultimaVacina.mes;
			 cin>>animal[cont].ultimaVacina.ano;
			 cont++;
			 }
  int idB;
  cin>>idB;
  int posicao=busca_Binaria(animal,cont,idB);
  if(posicao!=-1){
	  cout<<animal[posicao].nome_animal<<endl;
	  cout<<animal[posicao].ultimaVacina.dia<<endl;
	  cout<<animal[posicao].ultimaVacina.mes<<endl;
	  cout<<animal[posicao].ultimaVacina.ano<<endl;
	  }
else {
	cout<<"nao existe";
	}
		 
		 
		 
	
	 return 0;
	 }




