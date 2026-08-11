#include <iostream>

using namespace std;


// Estrutura para armazenar informações da cidade
struct Cidade {
    string cidade, nome_bairro, nome_rua;
};


// Estrutura para armazenar informações do usuário
struct Login {
    string nome_usuario, telefone, usuario;
};


// Estrutura para armazenar informações de um evento/problema
struct Evento {
    string evento, descricao, rua;
};


// Menu de login
void MenuLogin(Login &usuario) {

    cout << "Bem-vindo ao sistema de monitoramento cidadão!" << endl;
    cout << "Faça seu login para acessar o sistema." << endl;

    
    cout << "Digite seu nome de usuário: ";
    getline(cin, usuario.nome_usuario);

    cout << "Digite seu telefone: ";
    getline(cin, usuario.telefone);
}


// Cadastro do usuário
void CadastrarUsuario(Login &usuario) {

    cout << "Usuário registrado com sucesso!" << endl;
    cout << "Nome de usuário: " << usuario.nome_usuario << endl;
    cout << "Telefone: " << usuario.telefone << endl << endl;

    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.get();
}


// Menu de cidades
void MenuCidade(Cidade &cidade) {

    int escolha;

    do {

        system("cls");

        cout << "Cidades - Escolha uma opção:" << endl;
        cout << "[1] - Cidade Piloto" << endl;
        cout << "[2] - Cadastrar nova cidade" << endl;
        cout << "[4] - Sair" << endl;

        cin >> escolha;

        if (escolha == 1) {
            cidade = {"Cidade Piloto"};
        }

    } while (escolha != 4);
}


// Escolha da cidade
void EscolherCidade(Cidade &cidade) {

    int escolha;

    do {

        system("cls");

        cout << "Escolha uma cidade:" << endl;
        cout << "[1] - Cidade Piloto" << endl;
        cout << "[2] - Voltar ao menu anterior" << endl;
        cout << "[3] - Sair" << endl;

        cin >> escolha;

    } while (escolha != 3);
}


// Menu principal
void MenuPrincipal() {

    int escolha;

    do {

        system("cls");

        cout << "Menu - Escolha uma opção:" << endl;
        cout << "[1] - Indicar um evento/problema" << endl;
        cout << "[2] - Consultar eventos/problemas" << endl;
        cout << "[3] - Sair" << endl;

        cin >> escolha;

    } while (escolha != 3);
}


// Cadastro de evento/problema
void CadastrarEvento(Evento &evento) {

    cin.ignore();

    cout << "Digite o nome do evento/problema: ";
    getline(cin, evento.evento);

    cout << "Digite a descrição do evento/problema: ";
    getline(cin, evento.descricao);

    cout << "Digite a rua onde o evento/problema ocorreu: ";
    getline(cin, evento.rua);
}


// Cidade Piloto
Evento CidadePiloto[5][5] = {
    {{"Centro"}},
    {{"Bairro 1"}},
    {{"Bairro 2"}},
    {{"Bairro 3"}},
    {{"Bairro 4"}}
};


int main() {

    setlocale(LC_ALL, "Portuguese");

    Login usuario;
    Cidade cidade;

    MenuLogin(usuario);
    CadastrarUsuario(usuario);
    MenuCidade(cidade);
    EscolherCidade(cidade);
    MenuPrincipal();

    return 0;
}

