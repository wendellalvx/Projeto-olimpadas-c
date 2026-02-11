void partBrasil(){
FILE *arq = fopen("results/results.csv", "r");
if (!arq) return;
char linha[2048];
char edicaoAtual[100] = "";
int totalBrasil = 0;
fgets(linha, sizeof(linha), arq ); 
printf(" Evolução das participações do Brasil na Olímpiadas\n");
while(fgets(linha, sizeof(linha), arq)){ /*vai ser repetido esse caminha ate o fim do arquivo, copiando a linha e realizando as alterações*/
char *linha_copy = strdup(linha);
char *edicao = strtok(linha_copy, ",");
char *noc = NULL;
for(int i=0; i<4; i++) noc = strtok(NULL, ",");
if (edicao && noc){
if(strcmp(edicaoAtual, "") !=0 && strcmp(edicaoAtual, edicao) != 0){
  if(totalBrasil>0) {
  printf("%-30s | %d\n", edicaoAtual, totalBrasil); /* basicamente testa se mudou a edição, se mudou já imprime o resultado*/ 
}
totalBrasil = 0; /* zera tudo de novo*/
}
strcpy(edicaoAtual, edicao);
if (strcmp(noc, "BRA") ==0){ /* parte mais importante no codigo, porque é aqui que calcula quantas vezes o brasil participou*/
totalBrasil++;
}}
free(linha_copy);}
if (totalBrasil>0){ /* imprime a ultima linha, porque como no "if" anterior não resolveria porque naõa mudaria a edição, essa parte teve que ser feita*/
printf("%-30s | %d\n", edicaoAtual, totalBrasil);
}
fclose(arq);
}








