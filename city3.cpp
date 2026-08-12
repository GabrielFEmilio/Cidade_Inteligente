#include <iostream>
#include <string.h>
using namespace std;
struct Bairro{
	char ruas[20];
};
void imprimir (Bairro M[][3]){
	int Linha, Coluna;
	for(Linha=0;Linha<3;Linha++){
		for(Coluna=0;Coluna<3;Coluna++){
			
			cout << M[Linha][Coluna].ruas<<", ";
		}
		cout << endl;
	}
}
void inicializarBairro(Bairro Cidade[][3]){
strcpy(Cidade[0][0].ruas, "Rua Alberto Andaló");
strcpy(Cidade[1][0].ruas, "Rua General Glicério");
strcpy(Cidade[2][0].ruas, "Rua Antônio de Godoy");
strcpy(Cidade[0][1].ruas, "Rua João Pessoa");
strcpy(Cidade[1][1].ruas, "Rua Maria da Penha");
strcpy(Cidade[2][1].ruas, "Rua das Flores");
strcpy(Cidade[0][2].ruas, "Rua das Palmeiras");
strcpy(Cidade[1][2].ruas, "Rua das Acácias");
} 
int Tamanho(char T[]){
	int Tam=0;
	while(T[Tam] != '\0'){
		++Tam;
	}
	
	return Tam;
}
//Tamanho de vetor de caracteres: strlen, strcmp,strcpy
//Concatenação - strcat
Bairro Cidade[3][3]={{"Rua A","Rua B","Rua C"}, {"Rua D","Rua E","Rua F"}, {"Rua G","Rua H","Rua I"}};
int T = 10;
int main(){
	setlocale(LC_ALL,"Portuguese");
    inicializarBairro(Cidade);
    imprimir(Cidade);   

}