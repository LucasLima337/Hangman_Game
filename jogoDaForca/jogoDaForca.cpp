#include <iostream>
#include <string>
#include <new>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define QNTPALAVRA 10
#define NUMTENTATIVAS 10

using namespace std;

string sorteiaPalavra () {
    string palavras[QNTPALAVRA] = {
        "manga", "abacaxi", "morango",
        "uva", "pera", "tomate", 
        "laranja", "beterraba", "limao",
        "uva passa"
    };

    return palavras[rand() % QNTPALAVRA];
}

string mascararPalavra (string palavraSorteada) {
    string palavraComMascara;

    for (int i = 0; i < palavraSorteada.length(); i++) {
        if (palavraSorteada[i] != ' ') {
            palavraComMascara += "_";
        }
        else {
            palavraComMascara += " ";
        }
    }

    return palavraComMascara;
}

void exibeStatus (int tentativas, int maxTentativa, string palavraComMascara, string letrasChutadas) {
    cout << "Tentativas Restantes: " << maxTentativa - tentativas << "\n";
    cout << "Tamanho: " << palavraComMascara.length() << " letras\n\n";
    cout << "Letras Chutadas: " << letrasChutadas << "\n\n";
    cout << "Palavra: " << palavraComMascara << "\n\n";
}

void jogar (int players) {
    string palavraSorteada;

    if (players == 1) {
       palavraSorteada = sorteiaPalavra();
    }
    else {
        cout << "Digite uma palavra: ";
        getline(cin, palavraSorteada);
        system("cls");
    }

    string palavraComMascara = mascararPalavra(palavraSorteada);

    int tentativas = 0, maxTentativa = NUMTENTATIVAS, found = 0, reiniciar;
    bool secondLoop = true;
    string letrasChutadas;
    char letra;

    while (tentativas < maxTentativa) {
        exibeStatus(tentativas, maxTentativa, palavraComMascara, letrasChutadas);
        cout << "Digite uma letra: ";
        cin >> letra;

        system("cls");

        for (int i = 0; i < palavraSorteada.length(); i++) {
            if (tolower(letra) == palavraSorteada[i]) {
                palavraComMascara[i] = tolower(letra);
                found++;
            }
        }

        found == 0 ? tentativas++ : 0;
        found = 0;

        if (palavraSorteada == palavraComMascara) {
            cout << "Parabens! Voce ganhou!\n\n";
            cout << "A palavra era [ " << palavraSorteada << " ]\n\n";
            break;
        }
        else {
            if (letrasChutadas.find(tolower(letra)) != -1) {
                cout << "A letra digitada ja foi escolhida!\n\n";
            }
            else {
                letrasChutadas += tolower(letra);
            }
        }
    }

    if (tentativas == NUMTENTATIVAS) {
        cout << "Sinto muito, voce perdeu!\n\n";
        cout << "A palavra era [ " << palavraSorteada << " ]\n\n";
    }

    while (secondLoop) {
        cout << "Deseja reiniciar o jogo?\n\n";

        cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";
        cout << "[ 1 ] -- SIM" << endl;
        cout << "[ 2 ] -- NAO" << endl;
        cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";

        cout << "Sua escolha: ";
        cin >> reiniciar;

        if (reiniciar == 1) {
            system("cls");
            jogar(players);
        }

        else if (reiniciar == 2) {
            secondLoop = false;
            system("cls");
        }

        else {
            system("cls");
            cout << "\nPor favor, escolha uma das duas opcoes.\n\n";
        }
    }
}

void menu () {
    int opcao, opcaoSobre;
    bool mainLoop = true;

    while (mainLoop) {
        bool thirdLoop = true;

        cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";
        cout << " Bem vindo(a) ao Jogo da Forca! :)\n";
        cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";
        cout << "[ 1 ] -- Jogar Sozinho" << endl;
        cout << "[ 2 ] -- Jogar em Dupla" << endl;
        cout << "[ 3 ] -- Sobre" << endl;
        cout << "[ 4 ] -- Sair" << endl;
        cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";

        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        system("cls");

        switch (opcao) {
            case 1:
                jogar(1);
                break;

            case 2:
                jogar(2);
                break;

            case 3:
                system("cls");

                while (thirdLoop) {
                    cout << "Jogo da Forca desenvolvido por LUCAS LIMA! :)\n\n";

                    cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";
                    cout << "[ 1 ] -- Voltar" << endl;
                    cout << "[ 2 ] -- Sair" << endl;
                    cout << "=-==-==-==-==-==-==-==-==-==-==-==-=\n";

                    cout << "Escolha uma opcao: ";
                    cin >> opcaoSobre;

                    if (opcaoSobre == 1) {
                        system("cls");
                        thirdLoop = false;
                    } 
                    else if (opcaoSobre == 2) {
                        system("cls");
                        cout << "Jogo encerrado com sucesso!\n";
                        mainLoop = false;
                        thirdLoop = false;
                    }
                    else {
                        system("cls");
                        cout << "Por favor, escolha uma das duas opcoes.\n\n";
                    }
                }
                break;

            case 4:
                cout << "Jogo encerrado com sucesso!\n";
                mainLoop = false;
                break;

            default:
                cout << "Opcao escolhida invalida, tente novamente.\n\n";
        }
    }
}

int main() {
    srand((unsigned) time(NULL));
    system("cls");

    menu();

    return 0;
}
