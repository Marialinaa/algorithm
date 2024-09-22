#include <iostream>
 using namespace std;
 struct compadre{
	 string nome;
	 string alimento1;
	  string alimento2;
	 int quantidade1;
	 int quantidade2;
	 };
	 
	 struct alimento{
	    string nome;
	    int quantidade;
	    };
	    
 
	void inserirAlimento(alimento vetorAlim[],int& tamVa, string alimento, int qntdAlimento ){
	   int i=0;
	   while((i <tamVa) and (vetorAlim[i].nome != alimento)){
	      i++;
	   }
      if(i<tamVa){
	 vetorAlim[i].quantidade+=qntdAlimento;
	}
	
	else {
	   vetorAlim[i].nome=alimento;
	   vetorAlim[i].quantidade=qntdAlimento;
	   tamVa++;
	   }
	 }
	 
	 
	 
 int main (){
	 int num;
	 cin>>num;
	 
	 compadre vetorComprade[num];
	 
 for (int i=0;i<num;i++){
	 cin>> vetorComprade[i].nome
	 >>vetorComprade[i].alimento1
	 >>vetorComprade[i].quantidade1
	 >>vetorComprade[i].quantidade2;
	 }
	 alimento vetorAlimento[2*num];
	 
	 int qntdAli=0;
	  for (int i=0;i<num;i++){
		 inserirAlimento(vetorAlimento,qntdAli,
		 vetorComprade[i].alimento1,vetorComprade[i].quantidade1);
		 		 inserirAlimento(vetorAlimento,qntdAli,
				 vetorComprade[i].alimento2,vetorComprade[i].quantidade2);
		  }
		   for (int i=0;i<qntdAli;i++){
		      cout<<vetorAlimento[i].nome <<" "
		      <<vetorAlimento[i].quantidade<<endl;
		      }
	 
	 return 0;
	 }

