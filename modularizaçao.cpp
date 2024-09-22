#include <iostream>
#include <fstream>
#include <cstdlib>
 using namespace std;
int busca_Binaria(int vetor [],int k,int tam){
	int i=0;
	
	while(i<tam){
		if(vetor[i]==k){
		return i;
		}
		else {
				return -1;
			
		} 
		i++;
		}
}
 int main (){
	 int tamanho,procurado;
	 cin>>tamanho;
	 int ve[tamanho];
	 for(int i=0;i<tamanho;i++){
		 cin>>ve[i];
		 }
		  cin>>procurado;
		cout<<busca_Binaria(ve,procurado,tamanho);
	
	 return 0;
	 }




