#include <iostream>
#include <fstream>
#include <cmath>
 using namespace std;
 void troca(int& a,int& b){
	 int c=a;
	 a=b;
	 b=c;
	 }
	int ordena(int ve[],int c,int f){
			int pivo=ve[f];
			int i=c-1;
			for(int j=c;j<f;j++){
				if(ve[j]<pivo){
				i++;
				troca(ve[i],ve[j]);
				}
				}
			   troca(ve[i+1],ve[f]);
				 i=i+1;
				 return i;
			  }
	void modificar(int ve[],int c,int f,int k){
		int pi;
				  if(c<f){
					  pi=ordena(ve,c,f);
					  }
				  if(pi>k-1){
					  modificar(ve,c,pi-1,k);
					  }
					  else {
						  modificar(ve,c,pi-1,k);
						  modificar(ve,pi+1,f,k);
						  }
				  
				  
				  }
 int main (){
	 int tam;
	 cin>>tam;
	 int vetor[tam];
	 for(int i=0;i<tam;i++){
		 cin>>vetor[i];
		 }
		 int deseja_ordena;
		 cin>>deseja_ordena;
		 if(deseja_ordena>0){
			 modificar(vetor,0,tam-1,deseja_ordena);
			 }
		   cout<<endl;
		   for(int i=0;i<tam;i++){
			   cout<<vetor[i];
			   }
		 

	 return 0;
	 }
	




