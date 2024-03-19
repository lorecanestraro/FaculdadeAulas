#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <chrono>

using namespace std;

int vidas = 3;
char cenario[17][13];
int linhas = 17;
int colunas = 13;
bool fimdejogo = false;
int jogadorX = 6;
int jogadorY = 15;
char esferas[17][13];


std::chrono::steady_clock::time_point inicio; // Variável para o tempo inicial

void quadro() {
    system("cls");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i == jogadorY && j == jogadorX) {
                cenario[i][j] = '^';
            } else if (esferas[i][j] == '*') {
                cenario[i][j] = '*';
            } else if (i == 0 || i == linhas - 1 || j == 0 || j == colunas - 1) {
                cenario[i][j] = '#';
            } else {
                cenario[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << cenario[i][j] << " ";
        }
        cout << endl;
        
    }
    cout << "Vidas: " << vidas << endl;
}

void moverEsferas() {
    for (int i = linhas - 2; i > 0; i--) { //percorre as linhas do cenário do jogo de baixo para cima,para que as esferas possam se mover para baixo.
        for (int j = 1; j < colunas - 1; j++) {//verifica se há uma esfera (asteroide)
            if (esferas[i][j] == '*') {
                esferas[i][j] = ' ';
                if (i + 1 < linhas - 1) {
                    esferas[i + 1][j] = '*';
                }
            }
        }
    }

    for (int j = 1; j < colunas - 1; j++) {
        if (rand() % 17 == 0) {
            esferas[1][j] = '*';
        }
    }
}

void tecladoAD(){
    if (_kbhit()) { //verifica se uma tecla foi pressionada 
            char movimento = getch(); //lê a tecla pressionada.
            int novoX = jogadorX;//calcular e verificar as novas coordenadas do jogador antes de efetivamente movê-lo no cenário do jogo,
            int novoY = jogadorY;// garantindo que os movimentos do jogador sejam válidos e dentro dos limites do cenário. 
            switch (movimento) {
                case 'a':
                    novoX--;
                    break;

                case 'd':
                    novoX++;
                    break;

                case 'p':
                    fimdejogo = true;
                    break;
            }

            if (novoX >= 0 && novoX < colunas && novoY >= 0 && novoY < linhas) {
                jogadorX = novoX;
                jogadorY = novoY;
            }
    }
}

void tecladoNumerico(){
    if (_kbhit()) {
            char movimento = getch();
            int novoX = jogadorX;
            int novoY = jogadorY;
            switch (movimento) {
                case 75:
                    novoX--;
                    break;

                case 77:
                    novoX++;
                    break;

                case 'p':
                    fimdejogo = true;
                    break;
            }

            if (novoX >= 0 && novoX < colunas && novoY >= 0 && novoY < linhas) {
                jogadorX = novoX;
                jogadorY = novoY;
            }
    }
}

void nivelFacil(){
    Sleep(40);
}
void nivelDificil(){
    Sleep(20);
}

void jogo() {

    int teclado;
    int dificuldade;

    cout << "Seja bem vindo ao Fuga de Asteroides" << endl;
    cout << endl << "O objetivo desse jogo e fugir dos asteroides por pelo menos 1 minuto, sera que voce e capaz?" << endl;
    cout << "Boa sorte!" << endl << endl; 

    srand(time(0));

    cout << "Escolha o modo do teclado (nao digite letras):" << endl;
    cout << "1. Teclado a-d" << "      " << "2. Teclado Numerico" << endl;
    cin >> teclado;

    while(true){
        
        if(teclado != 1 && teclado != 2){
            cout << "Essa nao e uma opcao, selecione outra" << endl;
            cout << "1. Teclado a-d" << "      " << "2. Teclado Numerico" << endl;
            cin >> teclado;
        }else{
            break;
        }
    }

    cout << endl;
    cout << "Escolha o nivel de dificuldade (nao digite letras):" << endl;
    cout << "1. Facil" << "       " << "2. Dificil" << endl;
    cin >> dificuldade;

    while(true){
        if(teclado != 1 && teclado != 2){
            cout << "Essa nao e uma opcao, selecione outra" << endl;
            cout << "1. Facil" << "      " << "2. Dificil" << endl;
            cin >> dificuldade;
        }else{
            break;
        }
    }
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            esferas[i][j] = ' ';
        }
    }
  

    inicio = std::chrono::steady_clock::now(); // Tempo inicial

    while (!fimdejogo) {
        quadro();
        moverEsferas();
        if (esferas[jogadorY][jogadorX] == '*') {
           vidas--;
        }
        if(vidas == 0){
            fimdejogo = true;
        }


        switch(teclado){
            case 1:
            tecladoAD();
            break;

            case 2:
            tecladoNumerico();
            break;
        }

        switch(dificuldade){
            case 1:
            nivelFacil();
            break;

            case 2:
            nivelDificil();
            break;
        }   
    }
    std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now(); // Tempo final
    std::chrono::duration<int> duration = std::chrono::duration_cast<std::chrono::duration<int>>(fim - inicio);

    char resposta; 
    
    cout << "Voce conseguiu fugir por: " << duration.count() << " segundos" << endl;
    if(duration.count() >= 60){
        cout << "Parabens voce ganhou!" << endl;
        cout << "Digite 'j' para jogar novamente ou 's' para sair" << endl;
        cin >>  resposta;
        switch(resposta){
            case 'j':
            fimdejogo = false;
            vidas = 3;
            jogo();
            break;

            case 's':
            cout << "Obrigado por jogar" << endl;
            break;
        }
    }else{
        cout << "Voce perdeu" << endl;
        cout << "Digite 'j' para jogar novamente ou 's' para sair" << endl;
        cin >>  resposta;
        switch(resposta){
            case 'j':
            fimdejogo = false;
            vidas = 3;
            jogo();
            break;

            case 's':
            cout << "Obrigado por jogar" << endl;
            break;
        }
    }

    
}

int main(){
    jogo();
    return 0;
}
