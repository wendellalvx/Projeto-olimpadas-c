#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ATLETAS 1000
#define MAX_GRUPOS 100

typedef struct {
    char As[128];
    char Discipline[128];
    char NOC[10];
} Atleta;
Atleta atletas[MAX_ATLETAS];
int total_atletas = 0;

typedef struct {
    char As[128];
} Nome;

typedef struct {
    char NOC[10];
    char Discipline[128];
 Nome atletas[MAX_ATLETAS];
    int total_atletas;
} Grupo;
Grupo grupos[MAX_GRUPOS];
int total_grupos = 0;

void carregarBios(){
    FILE *arq = fopen("results/results.csv", "r");
        if (!arq) return;
        char linha[2048];
        fgets(linha, sizeof(linha), arq);
while (fgets(linha, sizeof(linha), arq)){
    char *copy = strdup(linha);
    for(int i=0; i<5; i++) strtok(copy, ",");
    char *As = strtok(NULL, ",");
    strtok(NULL, ",");
    char *NOC = strtok(NULL, ",");
    char *Discipline = strtok(NULL, ",");
    if (As && NOC && Discipline && total_atletas < MAX_ATLETAS){
    strcpy(atletas[total_atletas].As, As);
    strcpy(atletas[total_atletas].NOC, NOC);
    strcpy(atletas[total_atletas].Discipline, Discipline);
    total_atletas++;
    } free(copy);
  } fclose(arq);
}

int grupoExiste(char *NOC, char *Discipline){ /*Como diz o nome, vê se algum grupo já existe, evitando caso de duplicatas*/
    for (int i=0; i<total_grupos; i++){
        if (strcmp(grupos[i].NOC, NOC) == 0 &&
        strcmp(grupos[i].Discipline, Discipline) == 0)
        return i;
    } return -1;
}

int AsGrupo(Grupo *g,char *As){ /*Verifica se um atleta já está em um grupo*/
    for (int i=0; i<g->total_atletas; i++){
        if (strcmp(g->atletas[i].As, As) == 0)
        return 1;
    } return 0;
}

void agrupar(){ /*O querido criador de grupos*/
    for (int i=0; i<total_atletas; i++){
        int grupo = grupoExiste(atletas[i].NOC, atletas[i].Discipline);
    if (grupo == -1 && total_grupos < MAX_GRUPOS){
        grupo = total_grupos++;
        strcpy(grupos[grupo].NOC, atletas[i].NOC);
        strcpy(grupos[grupo].Discipline, atletas[i].Discipline);
        grupos[grupo].total_atletas = 0;
    }
   if (!AsGrupo(&grupos[grupo], atletas[i].As)){
        strcpy(grupos[grupo].atletas[grupos[grupo].total_atletas].As, atletas[i].As);
        grupos[grupo].total_atletas++;
    }
 }
}

void lista(){ /*Imprime o resultado*/
    for (int i=0; i<total_grupos; i++){
        printf("\nPaís: %s | Disciplina: %s\n", grupos[i].NOC, grupos[i].Discipline);
    for (int j=0; j<grupos[i].total_atletas; j++){
        printf("%s\n", grupos[i].atletas[j].As);
        }
    }
}
