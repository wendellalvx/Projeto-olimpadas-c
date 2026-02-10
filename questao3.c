#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ATLETAS 200000
char sexos[MAX_ATLETAS]; 
/*Nessa questão dividi em duas partes uma sendo para separar quais atletas eram mulheres e 
a outra para dividir essas mulheres em suas respectivas edições*/
void carregarBios(){
FILE *arq = fopen("athletes/bios.csv", "r");  
/*essa parte é pra abrir o arquivo que 
vai estar os dados, mas vai ser aberto somente em modo de leitura*/
if (!arq) return; /* aqui é pra se der erro em achar ou o arquivo estiver corrompido ele parar*/
char linha[2048];
fgets(linha, sizeof(linha), arq);
while(fgets(linha, sizeof(linha), arq)){  /*vai ler todas a linhas até o final exceto a primeira que é o cabeçalho*/
char *copy = strdup(linha); /* essa parte vai criar uma copia da linha que está sendo lida para poder fazer a alteração que é tirar a virgula que separa cada coluna*/
char *sexo = strtok(copy, ",");/* o motivo dessa retirada da virgula é que sem ela a maquina iria ler a linha inteira como se fosse uma única string, mas com essa separação consigo separar as informações necessarias*/
char *id_str = NULL; /* parte que vai guardar o id do atleta com string inicialmente*/
char *token;
for(int i =0; i<7; i++) id_str = strtok(NULL, ","); /* o id está na 8º coluna, como foi feito o primeiro corte fora for, dentro dele só precisa de 7*/
if (id_str && sexo) /* garante que só seja feita essa operação se achar o sexo e o id */{
int id = atoi(id_str); /* essa parte transforma o id que está como string em inteiro, isso td porque facilita trabalhar com ele mais para frente*/
if (id<MAX_ATLETAS) /* garante que a quantidade esteja dentro do limite*/ 
{
sexos[id] = sexo[0]; /* facilita pegando somente a inicial do sexo e atribui ao id daquele atleta*/
}}
free(copy); /* apaga a copia que fiz para realizar essas alterações*/
} fclose(arq); /* fecha o arquivo depois de ter utilizado ele para que possa ser usando em outras questões*/
}
void calcular_quanti(){
FILE *arq = fopen("results/results.csv", "r"); /* abri o arquivo em modo de leitura*/
if (!arq){
printf("Erro ao abrir o arquivo"); /* se caso ocorrer um erro na hora de abrir o arquivo*/
return;
}
char linha[2048]; /* parte que criar um vetor de caracteres para armazenar a linha completa*/
char edicaoAtual[100] = ""; /* essa variavel vai guardar o nome da edição enquanto o ano não mudar*/
int contaMulher = 0; /* para iniciar a contagem*/ 
fgets(linha, sizeof(linha), arq); 
/* segue a mesma logica da separação de mulheres e homens anteriormente*/
printf("Edição Olimpica | quantidade de mulheres\n");
while (fgets(linha, sizeof(linha), arq)){
char *edicao = strtok(linha_copy, ",");
char *linha_copy = strdup(linha); /* separa o nome e ano da edição como ela é a primeira parte*/
char *id_str =NULL;
for(int i =0; i < 6; i++) id_str = strtok(NULL,","); /* pulo todas as outras colunas até chegar na parte do id do atleta*/
if (edicao && id_str){
if(strcmp(edicaoAtual, "") !=0 && strcmp(edicaoAtual, edicao) !=0){ /* testa se na nova linha é a mesma edição ou já é outra*/
printf("%-20s | %d\n", edicaoAtual, contaMulher); /* ai se for outra já imprime o acumulado*/ 
contaMulher = 0; /* zera td de novo se for outro ano*/
}
strcpy(edicaoAtual, edicao); /* atualiza que é uma nova edição*/
int id = atoi(id_str); 
if (id< MAX_ATLETAS && sexos[id] =='F'){ /* a parte mais importante do codigo porque vai verificar se esse id está marcado com "F", e se tiver ele vai adicionar na contagem*/
contaMulher++;
}} free(linha_copy);
} printf("%-20s | %d\n", edicaoAtual, contaMulher);
fclose(arq);
}







