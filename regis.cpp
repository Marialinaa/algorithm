#include <iostream>
#include <fstream>
#include <cstdlib>
 using namespace std;
 int Busca_Binaria(int vet[],int tamanho,int procurado){
	 int inicio=0;
	 int fim=tamanho-1,i=0;
	 int meio=inicio+(fim-inicio)/2;
	 
	   while(i<tamanho){
		   	 ++i;
		   if(vet[meio]==procurado){
			   return meio;
			   }
		    else if(vet[meio]<procurado){
			   inicio+=meio+1;
			   } 
			   else if(procurado<vet[meio]){
				   inicio+=meio-1;
				   }
					return inicio;
				}
		 return -1;
	 }
	 
 
 int main (){
	 int t;
	 cin>>t;
	 int ve[t],k;
	 for(int i=0;i<t;i++){
		 cin>>ve[i];
		 }
		 cin>>k;
		 for(int i=0;i<t;i++){
			 int j=0;
			 if(ve[j]>k){
				 j++;
				 cout<<j;    // questao 16 busca binaria
				 } 
			 }
	cout<<Busca_Binaria(ve,t,k);
	
	 return 0;
	 }



