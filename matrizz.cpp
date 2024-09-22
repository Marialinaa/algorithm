#include <iostream>
#include <fstream>
#include <cstdlib>
 using namespace std;
 int main (){
	const int t=5;
    int matriz[t][t];
		for(int i=0;i<t;i++){
			for(int j=0;j<t;j++){
			cin>>matriz[i][j];
		}
		}  // questao 20 de matrizes
			int coluna=0,soma=0;
			
			for(int j=0;j<t;j++){
				soma+=matriz[j][coluna];
				}
			cout<<"A soma e:"<<soma;

	 return 0;
	 }



