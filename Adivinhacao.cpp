#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main (){
    cout << "************************************" <<endl;
    cout << "* Bem-Vindo ao jogo da adivinhação *" <<endl;
    cout << "************************************" <<endl;

    cout << "Escolha a sua dificuldade" <<endl;
    cout << "Facil (F), Medio (M), Dificil(D)"<<endl;

    char dificuldade;
    cin >> dificuldade;

    int numeroDeTentativas;

    if(dificuldade == 'F'){
        numeroDeTentativas = 19;
    }else if (dificuldade == 'M'){
        numeroDeTentativas = 14;
    }else if(dificuldade == 'D'){
        numeroDeTentativas = 9;
    }


    srand(time(NULL));
    const int NUMEROSECRETO = rand() %100;



    bool errou = true;
    int tentativas = 0;
    int chute;

    double pontos = 1000.0;

    for(tentativas; tentativas <= numeroDeTentativas; tentativas++){


        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "Voce esta na tentativa numero " << tentativas <<endl;
        cout << "Voce chutou: " << chute <<endl;

        double pontosPerdidos = abs(chute- NUMEROSECRETO)/2.0;
        pontos = pontos - pontosPerdidos;

        bool acertou = chute == NUMEROSECRETO;
        bool maior = chute > NUMEROSECRETO;


        if(acertou){
            cout << "Parabens, voce acertou o numero secreto" <<endl;

            errou = false;
        }else if(maior){
            cout << "Poxa, seu numero foi MAIOR que o numero secreto" <<endl;
        }else if(!maior){
            cout << "Poxa, seu numero foi MENOR que o numero secreto" <<endl;
        }
    }

    cout << "Fim de jogo"<< endl;

    cout << "o o chute certo foi" <<chute<<endl;
    cout << "voce usou " << tentativas << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Seus pontos sao " << pontos << endl;

}
