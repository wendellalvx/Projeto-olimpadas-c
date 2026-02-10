#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEDALHAS 9999
#define MAX_RANKING 100

/*8º Questão - Ranking dos países com mais medalhas em cada esporte.*/
/*2 dados: Nacionalidade e Esporte (Nationality, Discipline)*/

void carregarBios(){
    FILE *arq = fopen("results/results.csv", "r");
        if (!arq) return;
        char linha[2048];
        fgets(linha, sizeof(linha), arq);
while (fgets(linha, sizeof(linha), arq)){
    char *token;
    char *copy = strdup(linha);
    for(int i=0; i<7; i++) strtok(copy, ","); /*Ordem de chamada estava errada; decidi puxar NOC ao invés de Nacionality, visto que no CSV Nacionality está vazio.*/
    char *Nationality = strtok(NULL, ","); /*AKA NOC*/
    char *Discipline = strtok(NULL, ",");
    free(copy);
  }fclose(arq);
} /*Parte de leitura explicada na questão 3, reutilizada para
facilitar nosso trabalho o_o*/

typedef struct {
    char Nationality[50];
    char Discipline[50];
    int medalhas;
} Medalha;
Medalha medalhas[MAX_MEDALHAS];
int total_medalhas = 0;

typedef struct {
    char Nationality[50];
    int total;
} Ranking;

void rankingSport(Medalha medalhas[], int total_medalhas, char *Discipline) {
    Ranking ranking[MAX_RANKING];
    int count = 0;
for (int x=0; x < total_medalhas; x++) {  /*Agrupando as medalhas de cada país*/
        if (strcmp(medalhas[x].Discipline, Discipline) == 0) {
        int existingnac = 0; /*Verifica se o país já tá no ranking*/
        for (int y=0; y<count; y++) {
            if (strcmp(ranking[y].Nationality, medalhas[x].Nationality) == 0) {
            ranking[y].total += medalhas[x].medalhas;
            existingnac = 1;
            }
        }
        if (!existingnac) {
            strcpy(ranking[count].Nationality, medalhas[x].Nationality);
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
        printf("%d. %s - %d medalhas\n", i + 1, ranking[i].Nationality, ranking[i].total);
    }
}
int main() {
    carregarBios();
    char digitasport[50];
    printf("Digite o esporte que deseja: ");
    fgets(digitasport, sizeof(digitasport), stdin);
    rankingSport(medalhas, total_medalhas, digitasport);
}



