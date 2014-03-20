#include <stdio.h>
#define is_alpha(c) (((c>='a') && (c<='z')) || (c>='A') && (c<='Z'))

char awesome_compare(char* str0, char* str1) {
    int i;
    for(i=0;is_alpha(str0[i]) && is_alpha(str1[i]);++i)
        if(str0[i] != str1[i])
            return 0;
    return 1;
}

int main (){
    int i, n, dano, alive, init;
    int lives[10];
    char winner = 0;    
    char name[10];
    char players[10][10];

    printf("\n##### MEGA CONTADOR DE VIDA #####\n\n            ~by totoro and rica\n\n");

    puts("Digite o total de vida inicial:");
    scanf("%d", &init);
    puts("Numero de pessoas:");
    scanf("%d", &n);
    puts("Nomes (max 10 caracteres):");
    for(i=0;i<n;++i) {
        fflush(stdin);
        scanf("%s", players[i]);
        lives[i] = init;
    }
    

    alive = n;

    while(!winner) {
        puts ("\n######################\n");
        for(i=0;i<n;++i)
            printf("> %s tem %d pontos de vida\n", players[i], lives[i]);

        puts ("\n        --------\n");
        puts("Digite o target:");
        fflush(stdin);
        scanf("%s", name);
        puts("Digite a diferenca de vida:");
        scanf("%d", &dano);

        for(i=0;i<n;++i) {
            if(awesome_compare(name, players[i])) {
                lives[i] += dano;
                if(lives[i] <= 0)
                    --alive;
            }
        }

        if(alive == 1) {
            puts ("\n----------------\n\n");
            for(i=0;i<n;++i)
                if(lives[i]>0)
                    printf(">>>> %s GANHOU! <<<<\n\n", players[i]);
            return 0;
        }
    }

    return 0;
}
