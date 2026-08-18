#include <iostream>
#include <string.h>
#include <clocale>
#include <cstdlib>
using namespace std;

#define LINHAS 5
#define COLUNAS 5

struct Problema{
    bool ocupado;
    char descricao[100];
    char bairro[30];
    char urgencia[10]; // "Urgente", "Medio", "Simples"
    bool resolvido;
};

Problema matriz[LINHAS][COLUNAS];

void inicializarMatriz(){
    for(int i=0;i<LINHAS;i++){
        for(int j=0;j<COLUNAS;j++){
            matriz[i][j].ocupado = false;
            matriz[i][j].resolvido = false;
            strcpy(matriz[i][j].descricao, "");
            strcpy(matriz[i][j].bairro, "");
            strcpy(matriz[i][j].urgencia, "");
        }
    }
}

bool encontrarPosicaoLivre(int &linha, int &coluna){
    for(int i=0;i<LINHAS;i++){
        for(int j=0;j<COLUNAS;j++){
            if(!matriz[i][j].ocupado){
                linha = i;
                coluna = j;
                return true;
            }
        }
    }
    return false;
}

void cadastrarProblema(){
    int linha, coluna;
    if(!encontrarPosicaoLivre(linha, coluna)){
        cout << "Matriz cheia. Nao e possivel cadastrar novo problema." << endl;
        return;
    }

    cin.ignore();
    cout << "Descricao do problema: ";
    cin.getline(matriz[linha][coluna].descricao, 100);

    cout << "Bairro: ";
    cin.getline(matriz[linha][coluna].bairro, 30);

    strcpy(matriz[linha][coluna].urgencia, "Simples");
    matriz[linha][coluna].ocupado = true;
    matriz[linha][coluna].resolvido = false;

    cout << "Problema cadastrado na posicao [" << linha << "][" << coluna << "]." << endl;
}

void listarProblemas(){
    bool existeProblema = false;
    cout << "\n--- Lista de Problemas ---" << endl;
    for(int i=0;i<LINHAS;i++){
        for(int j=0;j<COLUNAS;j++){
            if(matriz[i][j].ocupado){
                existeProblema = true;
                cout << "[" << i << "][" << j << "] "
                     << "Bairro: " << matriz[i][j].bairro
                     << " | Descricao: " << matriz[i][j].descricao
                     << " | Urgencia: " << matriz[i][j].urgencia
                     << " | Status: " << (matriz[i][j].resolvido ? "Resolvido" : "Pendente")
                     << endl;
            }
        }
    }
    if(!existeProblema){
        cout << "Nenhum problema cadastrado." << endl;
    }
}

void listarPorUrgencia(const char nivel[]){
    bool encontrado = false;
    cout << "\n--- Problemas com urgencia: " << nivel << " ---" << endl;
    for(int i=0;i<LINHAS;i++){
        for(int j=0;j<COLUNAS;j++){
            if(matriz[i][j].ocupado && strcmp(matriz[i][j].urgencia, nivel) == 0 && !matriz[i][j].resolvido){
                encontrado = true;
                cout << "[" << i << "][" << j << "] "
                     << "Bairro: " << matriz[i][j].bairro
                     << " | Descricao: " << matriz[i][j].descricao
                     << endl;
            }
        }
    }
    if(!encontrado){
        cout << "Nenhum problema encontrado nesse nivel." << endl;
    }
}

void listarPrioridade(){
    listarPorUrgencia("Urgente");
    listarPorUrgencia("Medio");
    listarPorUrgencia("Simples");
}

void definirUrgencia(){
    int linha, coluna;
    listarProblemas();
    cout << "\nDigite a linha do problema: ";
    cin >> linha;
    cout << "Digite a coluna do problema: ";
    cin >> coluna;

    if(linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS || !matriz[linha][coluna].ocupado){
        cout << "Posicao invalida ou vazia." << endl;
        return;
    }

    int opcao;
    cout << "\nDefina a urgencia:" << endl;
    cout << "1 - Urgente\n2 - Medio\n3 - Simples\n";
    cout << "Escolha: ";
    cin >> opcao;

    switch(opcao){
        case 1: strcpy(matriz[linha][coluna].urgencia, "Urgente"); break;
        case 2: strcpy(matriz[linha][coluna].urgencia, "Medio"); break;
        case 3: strcpy(matriz[linha][coluna].urgencia, "Simples"); break;
        default:
            cout << "Opcao invalida." << endl;
            return;
    }
    cout << "Urgencia atualizada com sucesso." << endl;
}

void marcarResolvido(){
    int linha, coluna;
    listarProblemas();
    cout << "\nDigite a linha do problema resolvido: ";
    cin >> linha;
    cout << "Digite a coluna do problema resolvido: ";
    cin >> coluna;

    if(linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS || !matriz[linha][coluna].ocupado){
        cout << "Posicao invalida ou vazia." << endl;
        return;
    }

    matriz[linha][coluna].resolvido = true;
    cout << "Problema marcado como resolvido." << endl;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    inicializarMatriz();

    int opcao = -1;
    while(opcao != 0){
        cout << "\n--- Cidade Inteligente - Menu ---\n";
        cout << "1 - Cadastrar novo problema\n";
        cout << "2 - Listar todos os problemas\n";
        cout << "3 - Listar problemas por ordem de prioridade\n";
        cout << "4 - Definir/alterar urgencia de um problema\n";
        cout << "5 - Marcar problema como resolvido\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";

        if(!(cin >> opcao)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Tente novamente." << endl;
            continue;
        }

        switch(opcao){
            case 1: system("cls"); cadastrarProblema(); break;
            case 2: system("cls"); listarProblemas(); break;
            case 3: system("cls"); listarPrioridade(); break;
            case 4: system("cls"); definirUrgencia(); break;
            case 5: system("cls"); marcarResolvido(); break;
            case 0: system("cls"); cout << "Saindo..." << endl; break;
            default: system("cls"); cout << "Opcao invalida." << endl;
        }
    }
    return 0;
}
