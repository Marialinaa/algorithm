#include <iostream>
#include <fstream>
 using namespace std;
 int main (){
	 int const t=10;
	 int vet[t],ve[t],i=0;
	 	ifstream arquivo("estudo.txt");

	 for(i=0;i<t;i++){
		 arquivo>>vet[i];
		 }
		  for(i=0;i<t;i++){
		 arquivo>>ve[i];
		 }
	int menor;
	menor=ve[0];
   
    
    for(i=0;i<t;i++){
		  if(ve[i]<menor){
		  menor=ve[i];	 
		  }}
		  int*novo=new int[t];

		  for(i=0;i<t;i++){
		  novo=vet;
		  cin>>novo[i];
			  } 
			  
		  for(i=0;i<t;i++){
		  if(novo[i]<menor){
			menor=novo[i];
			  }}   
			  

			  cout<<"o menor valor"<<menor;
	 return 0;
	 }



