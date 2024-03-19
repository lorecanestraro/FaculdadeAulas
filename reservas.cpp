#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

typedef struct {
    string nome;
    long long int cpf;
    long long int contato;
    int chegada;
    int saida;
    int numero_quarto;
    int dias;
    bool status_quarto;
} Reserva;

const int num_quartos_casal = 50;
const int num_quartos_solteiro = 50;
const int diaria_casal = 200;
const int diaria_solteiro = 150;

void menu();
void inicializarQuartosCasal(Reserva* quartos_casal);
void inicializarQuartosSolteiro(Reserva* quartos_solteiro);
void statusQuartoCasal(Reserva* quartos_casal);
void statusQuartoSolteiro(Reserva* quartos_solteiro);
void reservaCasal(Reserva* quartos_casal);
void reservaSolteiro(Reserva* quartos_solteiro);
void cancelarReservaCasal(Reserva* quartos_casal, int nquarto);
void cancelarReservaSolteiro(Reserva* quartos_solteiro, int nquarto);
void verInfoCasal(Reserva* quartos_casal);
void verInfoSolteiro(Reserva* quartos_solteiro);
void diasCasal(Reserva* quartos_casal, int nquarto2);
void diasSolteiro(Reserva* quartos_solteiro, int nquarto2);
double calcularPrecoCasal(Reserva* quartos_casal, int num_quarto, double preco_diaria);
double calcularPrecoSolteiro(Reserva* quartos_solteiro, int num_quarto, double preco_diaria);
void bubbleSortCpfCasal(Reserva* quartos_casal, int tamanho);
void bubbleSortCpfSolteiro(Reserva* quartos_solteiro, int tamanho);
int buscaBinariaCpfCasal(Reserva* quartos_casal, int inicio, int fim, long long int cpf);
int buscaBinariaCpfSolteiro(Reserva* quartos_solteiro, int inicio, int fim, long long int cpf);



int main(){

   
    Reserva* quartos_casal = new Reserva[num_quartos_casal];
    Reserva* quartos_solteiro = new Reserva[num_quartos_solteiro];


    inicializarQuartosCasal(quartos_casal);
    inicializarQuartosSolteiro(quartos_solteiro);

    int indice;
    long long int cpf_desejado;
    bool sessao = true;
    menu();

    do{
       

        int q;
        int q2;
        int escolha1;
        int escolha2;
        int escolha3;
        cin >> escolha1;
        while(escolha1 > 7 || escolha1 < 1){
            cout << "Opcao invalida, porfavor escolha novamente" << endl;
            cin >> escolha1;
        }

        switch(escolha1){
            case 1:
                cout << "1. Casal" << endl << "2. Solteiro" << endl;
                cin >> escolha2;
                while(escolha2 != 1 && escolha2 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha2;
                }
                switch(escolha2){
                    case 1:
                        statusQuartoCasal(quartos_casal);
                        cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                        break;
                    case 2:
                        statusQuartoSolteiro(quartos_solteiro);
                        cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                        break;
                    
                }
            break;
            case 2:
                cout << "1. Casal" << endl << "2. Solteiro" << endl;
                cin >> escolha2;
                while(escolha2 != 1 && escolha2 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha2;
                }
                switch(escolha2){
                    case 1:
                        reservaCasal(quartos_casal);
                        cout << "Reserva efetuada com sucesso, o que deseja fazer agora:";
                        cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                        break;
                    case 2:
                        reservaSolteiro(quartos_solteiro);
                        cout << "Reserva efetuada com sucesso, o que deseja fazer agora:";
                        cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                        break;
                    
                }
            break;
            case 3:
                cout << "1. Casal" << endl << "2. Solteiro" << endl;
                cin >> escolha2;
                while(escolha2 != 1 && escolha2 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha2;
                }
                switch(escolha2){
                    case 1:
                        cout << "Digite o numero do quarto a ser cancelado: ";
                        cin >> q;
                        while(q < 1 || q > 50){
                            cout << "Quarto nao existente, porfavor escolha novamente" << endl;
                            cin >> q;
                        }
                        cancelarReservaCasal(quartos_casal, q);
                        cout << "Cancelamento efetuado com sucesso, o que deseja fazer agora:";
                        cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                        break;
                    case 2:
                        cout << "Digite o numero do quarto a ser cancelado: ";
                        cin >> q;
                        while(q < 1 || q > 50){
                            cout << "Quarto nao existente, porfavor escolha novamente" << endl;
                            cin >> q;
                        }
                        cancelarReservaSolteiro(quartos_solteiro, q);
                        cout << "Cancelamento efetuado com sucesso, o que deseja fazer agora:";
                        cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                        break;
                    
                }
            break;
            case 4:
                cout << "1. Casal" << endl << "2. Solteiro" << endl;
                cin >> escolha2;
                while(escolha2 != 1 && escolha2 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha2;
                }
                switch(escolha2){
                    case 1:
                        verInfoCasal(quartos_casal);
                        break;
                    case 2:
                        verInfoSolteiro(quartos_solteiro);
                        break;
                    
                }
            break;
            case 5:
                cout << "1. Casal" << endl << "2. Solteiro" << endl;
                cin >> escolha2;
                while(escolha2 != 1 && escolha2 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha2;
                }
                switch(escolha2){

                    case 1:
                    cout << "Numero do quarto" << endl;
                    cin >> q2;
                    while(q2 < 1 || q2 > 50){
                        cout << "Quarto nao existente, porfavor escolha novamente" << endl;
                        cin >> q2;
                    }
                    diasCasal(quartos_casal, q2);
                    cout << "Preco total: ";
                    cout << calcularPrecoCasal(quartos_casal, q2, diaria_casal) << endl;
                    cout << "O que deseja fazer agora:";
                    cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                    break;

                    case 2:
                    cout << "Numero do quarto" << endl;
                    cin >> q2;
                    while(q2 < 1 || q2 > 50){
                        cout << "Quarto nao existente, porfavor escolha novamente" << endl;
                        cin >> q2;
                    }
                    diasSolteiro(quartos_solteiro, q2);
                    cout << "Preco total: ";
                    cout << calcularPrecoSolteiro(quartos_solteiro, q2, diaria_solteiro) << endl;
                    cout << "O que deseja fazer agora:";
                    cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                        cin >> escolha3;
                        while(escolha3 != 1 && escolha3 != 2){
                            cout << "Opcao invalida, porfavor escolha novamente" << endl;
                            cin >> escolha3;
                        }
                        if(escolha3 == 1){
                            menu();
                        }else{
                            if(escolha3 == 2){
                                sessao = false;
                            }
                        }
                    break;
                }
            break;

            case 6:
            cout << "1. Casal" << endl << "2. Solteiro" << endl;
            cin >> escolha2;
            while(escolha2 != 1 && escolha2 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha2;
                }
            switch(escolha2){
                case 1:
                bubbleSortCpfCasal(quartos_casal, 50);
                cout << "Digite um cpf para busca" << endl;
                cin >> cpf_desejado;
                indice = buscaBinariaCpfCasal(quartos_casal, 0, num_quartos_casal - 1, cpf_desejado);
                cout << "Indice do cpf: " << indice << endl;
                cout << "O que deseja fazer agora:";
                cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                cin >> escolha3;
                while(escolha3 != 1 && escolha3 != 2){
                        cout << "Opcao invalida, porfavor escolha novamente" << endl;
                        cin >> escolha3;
                }
                if(escolha3 == 1){
                        menu();
                }else{
                    if(escolha3 == 2){
                        sessao = false;
                    }
                }
                break;

                case 2:
                bubbleSortCpfSolteiro(quartos_solteiro, 50);
                cout << "Digite um cpf para busca" << endl;
                cin >> cpf_desejado;
                indice = buscaBinariaCpfSolteiro(quartos_solteiro, 0, num_quartos_solteiro - 1, cpf_desejado);
                cout << "Indice do cpf: " << indice << endl;
                cout << "O que deseja fazer agora:";
                cout << endl << "1. Menu" << endl << "2. Encerrar sessao" << endl;
                cin >> escolha3;
                while(escolha3 != 1 && escolha3 != 2){
                    cout << "Opcao invalida, porfavor escolha novamente" << endl;
                    cin >> escolha3;
                }
                if(escolha3 == 1){
                        menu();
                }else{
                    if(escolha3 == 2){
                        sessao = false;
                    }
                }
                break;
            } 
            break; 
            case 7:
            sessao = false;
            break;  
        }
    } while(sessao == true);

    delete[] quartos_casal;
    delete[] quartos_solteiro;

    return 0;
}

void menu(){
    cout << "MMMMMMM   EEEEE   N    N  U    U" << endl;
    cout << "M  M  M   E       NN   N  U    U" << endl;
    cout << "M  M  M   EEEE    N N  N  U    U" << endl;
    cout << "M  M  M   E       N  N N  U    U" << endl;
    cout << "M  M  M   EEEEE   N   NN   UUUU " << endl;
    cout << endl;
    cout << "1. Verificar status dos quartos" << endl;
    cout << "2. Cadastrar uma reserva" << endl;
    cout << "3. Cancelar uma reserva" << endl;
    cout << "4. Ver informacoes" << endl;
    cout << "5. Calcular Custo" << endl;
    cout << "6. Verificar indice do cpf" << endl;
    cout << "7. Encerrar sessao" << endl << endl;
    cout << "Escolha uma opcao: ";
}

void inicializarQuartosCasal(Reserva* quartos_casal){
    for (int i = 0; i < num_quartos_casal; i++) {
        quartos_casal[i].numero_quarto = i + 1;
        quartos_casal[i].status_quarto = true;
        quartos_casal[i].nome = "";
        quartos_casal[i].contato = 0;
        quartos_casal[i].cpf = 0;
        quartos_casal[i].chegada = 0;
        quartos_casal[i].saida = 0;
        quartos_casal[i].dias = 0;
    }
}

void inicializarQuartosSolteiro(Reserva* quartos_solteiro){
    for (int i = 0; i < num_quartos_solteiro; i++) {
        quartos_solteiro[i].numero_quarto = i + 1;
        quartos_solteiro[i].status_quarto = true;
        quartos_solteiro[i].nome = "";
        quartos_solteiro[i].contato = 0;
        quartos_solteiro[i].cpf = 0;
        quartos_solteiro[i].chegada = 0;
        quartos_solteiro[i].saida = 0;
        quartos_solteiro[i].dias = 0;
    }
}

void statusQuartoCasal(Reserva* quartos_casal){
    for(int i = 0; i < num_quartos_casal; i++){
       if((quartos_casal + i)->status_quarto == true){
            cout << "Quarto " << (quartos_casal + i)->numero_quarto << " Esta disponivel" << endl;
        }else{
            cout << "Quarto " << (quartos_casal + i)->numero_quarto << " Nao esta disponivel" << endl;
        }
    }
}

void statusQuartoSolteiro(Reserva* quartos_solteiro){
    for(int i = 0; i < num_quartos_solteiro; i++){
        if((quartos_solteiro + i)->status_quarto == true){
            cout << "Quarto " << (quartos_solteiro + i)->numero_quarto << " Esta disponivel" << endl;
        }else{
            cout << "Quarto " << (quartos_solteiro + i)->numero_quarto << " Nao esta disponivel" << endl;
        }
    }
}

void reservaCasal(Reserva* quartos_casal){
    int num_quarto;
    cout << "Escolha um quarto" << endl;
    cin >> num_quarto;
    while(num_quarto < 1 && num_quarto > 50){
        cout << "Quarto nao existente, porfavor escolha novamente" << endl;
        cin >> num_quarto;
    }
    if(quartos_casal[num_quarto - 1].status_quarto == false){
        do{
            cout << "Quarto Indisponivel, por favor escolha outro" << endl;
            cin >> num_quarto;
        } while(quartos_casal[num_quarto - 1].status_quarto == false);
    }
    cout << "Digite seu nome" << endl;
    cin.ignore();
    getline(cin, quartos_casal[num_quarto - 1].nome);
    cout << "Telefone para contato" << endl;
    cin >> quartos_casal[num_quarto - 1].contato;
    cout << "Digite seu cpf" << endl;
    cin >> quartos_casal[num_quarto - 1].cpf;
    cout << "Dia de chegada" << endl;
    cin >> quartos_casal[num_quarto - 1].chegada;
    cout << "Dia de saida" << endl;
    cin >> quartos_casal[num_quarto - 1].saida;
    quartos_casal[num_quarto - 1].status_quarto = false;
}

void reservaSolteiro(Reserva* quartos_solteiro){
    int num_quarto;
    cout << "Escolha um quarto" << endl;
    cin >> num_quarto;
    while(num_quarto < 1 && num_quarto > 50){
        cout << "Quarto nao existente, porfavor escolha novamente" << endl;
        cin >> num_quarto;
    }
    if(quartos_solteiro[num_quarto - 1].status_quarto == false){
        do{
            cout << "Quarto Indisponivel, por favor escolha outro" << endl;
            cin >> num_quarto;
        } while(quartos_solteiro[num_quarto - 1].status_quarto == false);
    }
    cout << "Digite seu nome" << endl;
    cin.ignore();
    getline(cin, quartos_solteiro[num_quarto - 1].nome);
    cout << "Telefone para contato" << endl;
    cin >> quartos_solteiro[num_quarto - 1].contato;
    cout << "Digite seu cpf" << endl;
    cin >> quartos_solteiro[num_quarto - 1].cpf;
    cout << "Dia de chegada" << endl;
    cin >> quartos_solteiro[num_quarto - 1].chegada;
    cout << "Dia de saida" << endl;
    cin >> quartos_solteiro[num_quarto - 1].saida;
    quartos_solteiro[num_quarto - 1].status_quarto = false;
}

void cancelarReservaCasal(Reserva* quartos_casal, int nquarto){
    quartos_casal[nquarto - 1].nome = "";
    quartos_casal[nquarto - 1].contato = 0;
    quartos_casal[nquarto - 1].cpf = 0;
    quartos_casal[nquarto - 1].status_quarto = true;
    quartos_casal[nquarto - 1].chegada = 0;
    quartos_casal[nquarto - 1].saida = 0;
    quartos_casal[nquarto - 1].dias = 0;
}

void cancelarReservaSolteiro(Reserva* quartos_solteiro, int nquarto){
    quartos_solteiro[nquarto - 1].nome = "";
    quartos_solteiro[nquarto - 1].contato = 0;
    quartos_solteiro[nquarto - 1].cpf = 0;
    quartos_solteiro[nquarto - 1].status_quarto = true;
    quartos_solteiro[nquarto - 1].chegada = 0;
    quartos_solteiro[nquarto - 1].saida = 0;
    quartos_solteiro[nquarto - 1].dias = 0;
}

void verInfoCasal(Reserva* quartos_casal){
    cout << "Selecione um quarto" << endl;
    int quarto;
    cin >> quarto;
    while(quarto < 1 || quarto > 50){
        cout << "Quarto nao existente, porfavor escolha novamente" << endl;
        cin >> quarto;
    }
    cout << "Nome: " << quartos_casal[quarto - 1].nome << endl;
    cout << "Contato: " << quartos_casal[quarto - 1].contato << endl;
    cout << "CPF: " << quartos_casal[quarto - 1].cpf << endl;
    cout << "Dia de chegada: " << quartos_casal[quarto - 1].chegada << endl;
    cout << "Dia de saida: " << quartos_casal[quarto - 1].saida << endl; 

    char checar;
    cout << "Digite 's' para ver mais um quarto ou 'v' para voltar" << endl;
    cin >> checar;
    if(checar == 's'){
        verInfoCasal(quartos_casal);
    }else{
        menu();
    }
}

void verInfoSolteiro(Reserva* quartos_solteiro){
    cout << "Selecione um quarto" << endl;
    int quarto;
    cin >> quarto;
    while(quarto < 1 || quarto > 50){
        cout << "Quarto nao existente, porfavor escolha novamente" << endl;
        cin >> quarto;
    }
    cout << "Nome: " << quartos_solteiro[quarto - 1].nome << endl;
    cout << "Contato: " << quartos_solteiro[quarto - 1].contato << endl;
    cout << "CPF: " << quartos_solteiro[quarto - 1].cpf << endl;
    cout << "Dia de chegada: " << quartos_solteiro[quarto - 1].chegada << endl;
    cout << "Dia de saida: " << quartos_solteiro[quarto - 1].saida << endl; 

    char checar;
    cout << "Digite 's' para ver mais um quarto ou 'v' para voltar" << endl;
    cin >> checar;
    if(checar == 's'){
        verInfoSolteiro(quartos_solteiro);
    }else{
        menu();
    }

    
}

void diasCasal(Reserva* quartos_casal, int nquarto2){
    int entrada = quartos_casal[nquarto2 - 1].chegada;
    int out = quartos_casal[nquarto2 - 1].saida;

    if(entrada < out){
        quartos_casal[nquarto2 - 1].dias = out - entrada;
    }
    if(entrada > out){
        quartos_casal[nquarto2 - 1].dias = out - entrada + 30;
    }
}

void diasSolteiro(Reserva* quartos_solteiro, int nquarto2){
    int entrada = quartos_solteiro[nquarto2 - 1].chegada;
    int out = quartos_solteiro[nquarto2 - 1].saida;

    if(entrada < out){
        quartos_solteiro[nquarto2 - 1].dias = out - entrada;
    }
    if(entrada > out){
        quartos_solteiro[nquarto2 - 1].dias = out - entrada + 30;
    }
}

double calcularPrecoCasal(Reserva* quartos_casal, int num_quarto, double preco_diaria) {
    if (quartos_casal[num_quarto - 1].dias == 0) { 
        return 0;
    } else {
        quartos_casal[num_quarto - 1].dias--; 
        return preco_diaria + calcularPrecoCasal(quartos_casal, num_quarto, preco_diaria); 
    }
}

double calcularPrecoSolteiro(Reserva* quartos_solteiro, int num_quarto, double preco_diaria) {
    if (quartos_solteiro[num_quarto - 1].dias == 0) { 
        return 0;
    } else {
        quartos_solteiro[num_quarto - 1].dias--; 
        return preco_diaria + calcularPrecoSolteiro(quartos_solteiro, num_quarto, preco_diaria); 
    }
}

void bubbleSortCpfCasal(Reserva* quartos_casal, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (quartos_casal[j].cpf > quartos_casal[j + 1].cpf) {
                // Troca de elementos
                Reserva temp = quartos_casal[j];
                quartos_casal[j] = quartos_casal[j + 1];
                quartos_casal[j + 1] = temp;
            }
        }
    }
}

void bubbleSortCpfSolteiro(Reserva* quartos_solteiro, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (quartos_solteiro[j].cpf > quartos_solteiro[j + 1].cpf) {
                // Troca de elementos
                Reserva temp = quartos_solteiro[j];
                quartos_solteiro[j] = quartos_solteiro[j + 1];
                quartos_solteiro[j + 1] = temp;
            }
        }
    }
}

int buscaBinariaCpfCasal(Reserva* quartos_casal, int inicio, int fim, long long int cpf) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        if (quartos_casal[meio].cpf == cpf)
            return meio;

        if (quartos_casal[meio].cpf > cpf)
            return buscaBinariaCpfCasal(quartos_casal, inicio, meio - 1, cpf);

        
        return buscaBinariaCpfCasal(quartos_casal, meio + 1, fim, cpf);
    }

    
    return -1;
}

int buscaBinariaCpfSolteiro(Reserva* quartos_solteiro, int inicio, int fim, long long int cpf) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        if (quartos_solteiro[meio].cpf == cpf)
            return meio;

        if (quartos_solteiro[meio].cpf > cpf)
            return buscaBinariaCpfSolteiro(quartos_solteiro, inicio, meio - 1, cpf);

        return buscaBinariaCpfSolteiro(quartos_solteiro, meio + 1, fim, cpf);
    }
    return -1;
}