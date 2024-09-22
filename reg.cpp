#include <iostream>
#include <fstream>
using namespace std;
struct  crianca{
	string nome;
	 string presente;
	 int boasAcoes;
	 int travessuras;
	};
int main (){
 int  num;
 cin>>num;
 
 crianca vetorCrianca[num];
  bool comPre=false;
  
  
 for (int i=0;i<num;i++){
	 cin>> vetorCrianca[i].nome
	 >>vetorCrianca[i].presente
	 >>vetorCrianca[i].boasAcoes
	 >>vetorCrianca[i].travessuras;
	 }
	  for (int i=0;i<num;i++){
     if (vetorCrianca[i].boasAcoes >= vetorCrianca[i].travessuras){
     cout<<vetorCrianca[i].presente<<endl;
     comPre=true;
}
}
 if(comPre==false){
	 cout<<"NADA DE PRESENTES";
	 
	 }
	return 0;
}

