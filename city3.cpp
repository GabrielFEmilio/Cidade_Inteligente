#include <iostream>
#include <string.h>
using namespace std;
struct cidade{
    char nome[20];
    char bairros[3][20];
};
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
void imprimirCidades(cidade C[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << "Posicao ["<<i<<"]["<<j<<"] - Cidade: " << C[i][j].nome << " | Bairros: ";
			for(int k=0;k<3;k++){
				cout << C[i][j].bairros[k];
				if(k<2) cout << ", ";
			}
			cout << endl;
		}
	}
}
void inicializarCidade(cidade Cidade[][3]){
	strcpy(Cidade[0][0].nome, "São José do Rio Preto");
	strcpy(Cidade[0][0].bairros[0], "Higienópolis");
	strcpy(Cidade[0][0].bairros[1], "Jardim Walkiria");
	strcpy(Cidade[0][0].bairros[2], "Estoril");
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
strcpy(Cidade[2][2].ruas, "Rua das Orquídeas");
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
Bairro bairros[3][3] = {{"Rua A","Rua B","Rua C"}, {"Rua D","Rua E","Rua F"}, {"Rua G","Rua H","Rua I"}};
cidade cidades[3][3];
int T = 10;
int main(){
	setlocale(LC_ALL,"Portuguese");
	int opcao = -1;
	while(opcao != 0){
		cout << "\n--- Menu ---\n";
		cout << "1 - Inicializar bairros\n";
		cout << "2 - Inicializar cidades\n";
		cout << "3 - Imprimir bairros\n";
		cout << "4 - Imprimir cidades\n";
		cout << "0 - Sair\n";
		cout << "Escolha uma opcao: ";
		if(!(cin >> opcao)){
			cin.clear();
			cin.ignore(10000,'\n');
			cout << "Entrada invalida. Tente novamente." << endl;
			continue;
		}
		switch(opcao){
			case 1:
				inicializarBairro(bairros);
				cout << "Bairros inicializados." << endl;
				break;
			case 2:
				inicializarCidade(cidades);
				cout << "Cidades inicializadas." << endl;
				break;
			case 3:
				imprimir(bairros);
				break;
			case 4:
				imprimirCidades(cidades);
				break;
			case 0:
				cout << "Saindo..." << endl;
				break;
			default:
				cout << "Opcao invalida." << endl;
		}
	}
	return 0;
}