void partBrasil(){
FILE *arq = fopen("results/results.csv", "r");
if (!arq) return;
char linha[2048];
char edicaoAtual[100] = "";
int totalBrasil = 0;
fgets(linha, sizeof(linha), arq ); 
printf(" Evolução das participações do Brasil na Olímpiadas\n");

while(fgets(linha, sizeof(linha), arq)){
char *linha_copy = strdup(linha);


