#include <iostream>

using namespace std;

struct City {
    string city;
};

struct Login {
    string username, telephone, user;
};

struct Event {
    string event, description, street;
};

void LoginMenu(Login &user) {


    
    cout << "Bem vindo ao sistema de monitoramento cidadão!" << endl;
    cout << "Faça seu login para acessar o sistema." << endl;
    cout << "Digite seu nome de usuário: ";
    getline(cin, user.username);
    cout << "Digite seu telefone: ";
    getline(cin, user.telephone);

}

void RegisterUser(Login &user) {
    cout << "Usuário registrado com sucesso!" << endl;
    cout << "Nome de usuário: " << user.username << endl;
    cout << "Telefone: " << user.telephone << endl << endl;
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.get();
}

void CityMenu(City &city) {
    int choice;
    do {
        system("cls");
        cout << "Cidades - Escolha uma opção:" << endl;
        cout << "[1] - Cidade Piloto" << endl;
        cout << "[2] - Cadastrar nova cidade" << endl;
        cout << "[4] - Sair" << endl;
        cin >> choice;
        if (choice == 1) {
            city = {"Cidade Piloto"};
        } else {}
    } while (choice != 4);
}

void CityChoice(City &city) {
    int choice;
    do {
        system("cls");
        cout << "Escolha uma cidade:" << endl;
        cout << "[1] - Cidade Piloto" << endl;
        cout << "[2] - Voltar ao menu anterior" << endl;
        cout << "[3] - Sair" << endl;
        cin >> choice;
    } while (choice != 3);
}

void MainMenu() {
    int choice;
    do {
        system("cls");
        cout << "Menu - Escolha uma opção:" << endl;
        cout << "[1] - Indicar um evento/problema" << endl;
        cout << "[2] - Consultar eventos/problemas" << endl;
        cout << "[3] - Sair" << endl;
        cin >> choice;
    } while (choice != 3);
}

void RegisterEvent(Event &event) {
    cin.ignore();
    cout << "Digite o nome do evento/problema: ";
    getline(cin, event.event);
    cout << "Digite a descrição do evento/problema: ";
    getline(cin, event.description);
    cout << "Digite a rua onde o evento/problema ocorreu: ";
    getline(cin, event.street);
}




Event CidadePiloto[5][5] = {
    {{"Centro"}},
    {{"Bairro 1"}},
    {{"Bairro 2"}},
    {{"Bairro 3"}},
    {{"Bairro 4"}}
};
int main() {
    setlocale(LC_ALL, "Portuguese");

    Login user;
    City city;

    LoginMenu(user);
    RegisterUser(user);
    CityMenu(city);
    CityChoice(city);
    MainMenu();

    return 0;
}