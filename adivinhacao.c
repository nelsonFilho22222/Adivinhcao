//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE  
//#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N_TNT 5


int main(){

        printf("****************************************\n");
        printf ("* bem vindo ao nosso jogo de adivinhacao *\n");
        printf("****************************************\n");
        printf("Voce deve adivnhar qual o numero secreto \n  Escreva um numero de 1 a 100 \n  BOA SORTE \n");
        printf("\n \n \n \n \n Facil: 20 tentativas \n Medio: 15 tentativas \n Dificil: 6 tentativas ");

        int semente = time(0);
        srand(semente);
        int numerogrande = rand();
        int numerosecreto = numerogrande % 100;
        int numerodetentativas = 7;
        int chute;
        int fimdeloop = 1;
        int tentativas = 1;
        double pontos = 1000;
        

        int nivel;
        printf("Qual o nivel de dificuldade? \n");
        printf("(1) facil (2) Medio (3) Dificil \n \n");
        printf("Escolha: ");
        scanf("%d", &nivel);


        if (nivel == 1){
            numerodetentativas = 20;
        }else if (nivel == 2){
            numerodetentativas =15;
        }else {
            numerodetentativas = 6;
        }


         for(int i = 1; i <= numerodetentativas; i++){

        printf("\n Voce esta na tentativa %d\n",tentativas);
        printf(" Qual e o seu chute? ");

        scanf("%d", &chute);
        printf(" seu chute foi %d\n ", chute);

        if (chute < 0.0){
            printf(" Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;


        if(acertou){
       
        printf(" Parabens! Voce acertou! \n Joque de novo. Voce e um bom jogador \n");
        printf(" total de pontos %.1f\n", pontos);
         break;
        
        }

         else if (maior) {
                printf(" Voce errou! \n Tente novamente \n");
                printf("seu chute foi maior que o numero secreto\n");

            }
            else{
                printf(" Voce errou! \n Tente novamente\n");
                printf("seu chute foi menor que o numero secreto\n");
            }
            tentativas++;

               double pontosperdidos = (abs(chute - numerosecreto) / (double)2);
               pontos = pontos - pontosperdidos;
               fimdeloop = 0;
        }



};
