#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define is_alpha(c) ((((c)>='a') && ((c)<='z')) || (((c)>='A') && ((c)<='Z')))
#define is_digit(c) (((c)>='0') && ((c)<='9'))

char awesome_compare(char* str0, char* str1) {
    int i;
    for(i=0;is_alpha(str0[i]) && is_alpha(str1[i]);++i)
        if(str0[i] != str1[i])
            return 0;
    return 1;
}

int _random(int max) {
	double ret_val = ((double)rand())/RAND_MAX;
	return ret_val*max+1;
}

void roll_dice(char* dice) {
	int d = atoi(dice);
	printf("\n>>>Voce roda um D%d e tira %d!<<<\n", d, _random(d));
}

int main (){
    int i, n, dano, alive, init;
    int lives[10];
    char name[10], name2[10];
    char players[10][10];
    int command = 1;

	srand(time(NULL));
	rand(), rand();
    while(command) {
        printf("#################################\n#################################\n");
        printf("##### MEGA CONTADOR DE VIDA #####\n");
        printf("#################################\n#################################\n");
        printf("\n            -by totoro and rica\n\n");
        puts("Digite o total de vida inicial:");
        scanf("%d", &init);
        puts("Numero de pessoas:");
        scanf("%d", &n);
        puts("Nomes (max 10 caracteres sem numeros):");
        for(i=0;i<n;++i) {
            scanf("%s", players[i]);
            lives[i] = init;
        }


        alive = n;

        while(command) {
            puts ("\n        --------\n");
            for(i=0;i<n;++i)
                printf("> %s tem %d pontos de vida\n", players[i], lives[i]);

            puts ("\n        --------\n");
            puts("################################################################");
            puts("# Digite um alvo para aplicar alguma acao                      #");
            puts("# Digite n para rolar um Dn                                    #");
            puts("# Digite \"first\" para ver quem começa                          #");
            puts("################################################################\n");
            fflush(stdin);
            scanf("%s", name);
            if(is_digit(name[0])) {
                roll_dice(name);
                continue;
            }
            else if(strcmp("first", name) == 0) {
                printf("\n>>>%s comeca!<<<\n",players[_random(n)-1]);
            }
            else {
                puts("\nDigite a acao:(ou digite \"/help\" para uma lista de acoes)\n");
                scanf("%s", name2);
                if(!strcmp(name2, "/help")){
                    puts("\n################################################################");
                    puts("# Digite um valor para tirar ou dar vida ao jogador alvo       #");
                    puts("# Digite \"extort\" para o jogador alvo extorquir                #");
                    puts("# Digite \"ganhou\" para delarar o jogador alvo como vencedor    #");
                    puts("################################################################\n");
                    scanf("%s", name2);
                }
                if(!strcmp(name2, "ganhou")) {
                    for(i=0; i<n; i++) {
                        if(!awesome_compare(name, players[i])){
                        lives[i] = 0;
                        --alive;
                        }
                    }
                }
                else if(!strcmp(name2, "extort")) {
                    int life = 0;
                    for(i=0; i<n; i++)
                        if(!awesome_compare(name, players[i])){
                            if(lives[i] > 0){
                                lives[i] -= 1;
                                if(lives[i] <= 0) --alive;
                                life++;
                            }
                    }
                    for(i=0; i<n; i++)
                        if(awesome_compare(name, players[i]))
                            lives[i] += life;
                }
                else{
                    dano = atoi(name2);

                    for(i=0;i<n;++i) {
                        if(awesome_compare(name, players[i])) {
                            lives[i] += dano;
                            if(lives[i] <= 0)
                                --alive;
                        }
                    }
                }
            }

            if(alive <= 1) {
                puts ("\n----------------\n\n");
                for(i=0;i<n;++i)
                    if(lives[i]>0)
                        printf(">>>> %s GANHOU! <<<<\n\n", players[i]);
                        printf("\n\nDigite 0 para finalizar ou 1 para continuar\n\n>");
                        scanf("%d",&command);
                        break;
            }
        }

    }
    return 0;
}
