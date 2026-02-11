#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEDALHAS 9999
#define MAX_RANKING 100

/*Ranking dos países com mais medalhas em cada esporte.*/

void carregarBios(){
    FILE *arq = fopen("results/results.csv", "r");
        if (!arq) return;
        char linha[2048];
        fgets(linha, sizeof(linha), arq);
while (fgets(linha, sizeof(linha), arq)){
    char *copy = strdup(linha);
    for(int i=0; i<4; i++) strtok(copy, ",");
    char *Medal = strtok(NULL, ","); 
    for(int i=0; i<2; i++) strtok(copy, ",");
    char *NOC = strtok(NULL, ","); /*AKA "NOC"*/
    char *Discipline = strtok(NULL, ",");
    if (strlen(Medal) > 0) {
    strcpy(medalhas[total_medalhas].NOC, NOC);
    strcpy(medalhas[total_medalhas].Discipline, Discipline);
    medalhas[total_medalhas].medalhas = 1;
    total_medalhas++;
    free(copy);
    }
  }fclose(arq);
} /*Parte de leitura explicada na questão 3, reutilizada para
facilitar nosso trabalho o_o*/

typedef struct {
    char NOC[50];
    char Discipline[50];
    int medalhas;
} Medalha;
Medalha medalhas[MAX_MEDALHAS];
int total_medalhas = 0;

typedef struct {
    char NOC[50];
    int total;
} Ranking;

void rankingSport(Medalha medalhas[], int total_medalhas, char *Discipline) {
    Ranking ranking[MAX_RANKING];
    int count = 0;
for (int x=0; x < total_medalhas; x++) {  /*Agrupando as medalhas de cada país*/
        if (strcmp(medalhas[x].Discipline, Discipline) == 0) {
        int existingnac = 0; /*Verifica se o país já tá no ranking*/
        for (int y=0; y<count; y++) {
            if (strcmp(ranking[y].NOC, medalhas[x].NOC) == 0) {
            ranking[y].total += medalhas[x].medalhas;
            existingnac = 1;
            }
        }
        if (!existingnac) {
            strcpy(ranking[count].NOC, medalhas[x].NOC);
            ranking[count].total = medalhas[x].medalhas;
            count++;
        }
    }
 } for (int i=0; i < count-1; i++) {
        for (int j=0; j < count-i-1; j++) {
            if (ranking[j].total < ranking[j+1].total) {
                Ranking temp = ranking[j];
                ranking[j] = ranking[j+1];
                ranking[j+1] = temp;
            }
        }
    } /*Bubble Sort :D*/

printf("\n===== TOP 10 %s =====\n", Discipline);
    for (int i = 0; i < (count < 10 ? count : 10); i++) {
        printf("%d. %s - %d medalhas\n", i + 1, ranking[i].NOC, ranking[i].total);
    }
}
int main() {
    carregarBios();
    char digitasport[50];
printf("Digite o esporte que deseja: ");
fgets(digitasport, sizeof(digitasport), stdin);
digitasport[strcspn(digitasport, "\n")] = '\0'; 
rankingSport(medalhas, total_medalhas, digitasport);
return 0;
}
