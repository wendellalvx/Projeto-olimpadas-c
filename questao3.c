#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ATHELETES 200000
char sexo[MAX_ATHELETES]; 
/*Nessa questão dividi em duas partes uma sendo para separar quais atletas eram mulheres e 
a outra para dividir essas mulheres em suas respectivas edições*/
void carregarBios(){
FILE *arq + fopen("atheletes/bios.csv", "r");  
/*essa parte é pra abrir o arquivo que 
vai estar os dados, mas vai ser aberto somente em modo de leitura*/
if (!arq) return:
char linha[2048];
fgets(linha, sizeof(linha(, arq);
while(fgets(linha, sizeof(linha), arq)){
char *token;
char *copy = strdup(linha);
char *sexo = strtok(copy, ",");
char *id_str = NULL;
for(int i =0; i<7; i++) id_str = strtok(NULL, ",");
if (id_str && sexo) {
int id = atoi(id_str);
if (id<MAX_ATHELETES){
sexos[id] = sexo[0];
}}
free(copy);
} fclose(arq);
void calcular_quanti(){
FILE *arq +fopen("results/results.csv", "r");
if (!arq){
printf("Erro ao abrir o arquivo");
return;
}
char linha[2048];
char edicaoAtual[100] = "";
int contaMulher = 0;
fgets(linha, sizeof(linha), arq);
printf("Edição Olimpica | quantidade de mulheres\n");
while (fgets(linha, sizeof(linha), arq)){
char *edicao = strdup(linha), ",");
char *id_str =NULL;
char *linha_copy = strdup(linha);
char *t = strtok(linha_copy, ",");
for(int i =0; i < 6; i++) id_str = strtok(NULL,",");
if (edicao && id_str){
if(strcmp(edicaoAtual, "") !=0 && strcmp(edicaoAtual, edicao) !=0){
printf("%-20s | %d\n", edicaoAtual, contaMulher);
contaMulher = 0;
}
strcpy(edicaoAtual, edicao);
int id = atoi(id_str);
if (id< MAX_ATHELETES && sexos[id] =='F'){
contaMulher++;
}} free(linha_copy);
} printf("%-20s | %d\n", edicaoAtual, contaMulher);
fclose(arq);
}



