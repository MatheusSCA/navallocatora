#include <stdio.h>
#include <string.h>
#include <locale.h>
#define ARQUIVO "filmes.txt"

#define MAX_STRING 100
#define MAX_FILMES 5

typedef struct
{
    char titulo[MAX_STRING];
    char diretor[MAX_STRING];
    int anoLancamento;
    float classificacao;
    int quantidade;
} Filme;

void mostrarFilmes();
Filme cadastrarFilme();
void exibirFilme(int i);
void salvarFilmes();
void carregarFilmes();
void PesquisarFilmes();

Filme filmes[MAX_FILMES];
int totalFilmes = 0;

Filme cadastrarFilme()
{
    Filme f;
    getchar();

    printf("\n--- Cadastro de Filme ---\n");
    printf("Informe o título do filme: ");
    fgets(f.titulo, MAX_STRING, stdin);
    f.titulo[strcspn(f.titulo, "\n")] = '\0';

    printf("Informe o diretor do filme: ");
    fgets(f.diretor, MAX_STRING, stdin);
    f.diretor[strcspn(f.diretor, "\n")] = '\0';

    printf("Informe o ano de lançamento do filme: ");
    scanf("%d", &f.anoLancamento);

    printf("Informe a classificação do filme (0.0 a 10.0): ");
    scanf("%f", &f.classificacao);

    printf("Informe a quantidade de cópias em estoque: ");
    scanf("%d", &f.quantidade);

    return f;
}

void exibirFilme(int i)
{
    Filme f = filmes[i];
    printf("\nTítulo: %s\n", f.titulo);
    printf("Diretor: %s\n", f.diretor);
    printf("Ano de Lançamento: %d\n", f.anoLancamento);
    printf("Classificação: %.1f\n", f.classificacao);
    printf("Quantidade em estoque: %d\n", f.quantidade);
}

void mostrarFilmes()
{
    printf("\n--- Lista de Filmes ---\n");

    if (totalFilmes == 0)
    {
        printf("Nenhum filme foi cadastrado ainda!\n");
    }
    else
    {
        for (int i = 0; i < totalFilmes; i++)
        {
            exibirFilme(i);
        }
    }
}

void salvarFilmes() {
    FILE *file = fopen(ARQUIVO, "w");
    if (file == NULL) {
        printf("Erro ao salvar os filmes!\n");
        return;
    }

    for (int i = 0; i < totalFilmes; i++) {
        fprintf(file, "\"%s\",\"%s\",%d,%.1f,%d\n", 
                filmes[i].titulo, 
                filmes[i].diretor, 
                filmes[i].anoLancamento, 
                filmes[i].classificacao, 
                filmes[i].quantidade);
    }

    fclose(file);
    printf("Filmes salvos com sucesso!\n");
}

void carregarFilmes() {
    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("\n---------Nenhum filme salvo-----------");
        return; 
    }

    while (fscanf(file, "\"%[^\"]\",\"%[^\"]\",%d,%f,%d\n", 
                  filmes[totalFilmes].titulo, 
                  filmes[totalFilmes].diretor, 
                  &filmes[totalFilmes].anoLancamento, 
                  &filmes[totalFilmes].classificacao, 
                  &filmes[totalFilmes].quantidade) != EOF) {
        totalFilmes++;
    }
    printf("\nfilmes carregados\n");
    fclose(file);
}

void PesquisarFilmes(){
    
    int metodo;
    char pesquisa[MAX_STRING];
    getchar();

    if (totalFilmes == 0)
    {
    printf("Nenhum filme foi cadastrado ainda!\n");
    }
    else
    {
    printf("\n-------Pesquisa de filmes------\n");
    printf("0-Nome do filme\n");
    printf("1-Nome do Diretor\n");
    printf("Digite o meio que quer pesquisar filme:");
    scanf("%d",&metodo);
    getchar();

    if(metodo==0){
    printf("\n----Pesquisa por NOME DO FILME----\n");    
    printf("Digite o nome do filme:");    
    fgets(pesquisa, MAX_STRING, stdin);
    pesquisa[strcspn(pesquisa,"\n")] = '\0';

    for(int i=0;i<totalFilmes;i++){
    if(strcmp(filmes[i].titulo,pesquisa)==0){
    printf("\nFilme na posição:%d",i);
    exibirFilme(i);
    printf("\n");
    }
    }
    }

    if(metodo==1){    
    printf("\n----Pesquisa por NOME DO DIRETOR----\n");    
    printf("Digite o nome do diretor:");    
    fgets(pesquisa,MAX_STRING,stdin);
    pesquisa[strcspn(pesquisa,"\n")] = '\0';

    for(int i=0;i<totalFilmes;i++){
    if (strcmp(filmes[i].diretor,pesquisa)==0){
    printf("\nFilme na posição:%d",i);
    exibirFilme(i);
    printf("\n");
    }
    }
    }
    else{
        printf("\nOpção invalida");
    }
}
}

void DeletarFilme(){
    int deletar;
    if(totalFilmes>0){
    printf("\n--- Deletar Filmes ---\n");
    PesquisarFilmes();
    printf("\nQual Filme vc quer deletar?(Escolha baseado na posição do filme)");
    scanf("%d",&deletar);

    int IndiceExclusao = -1;
    for (int i=0;i< totalFilmes;i++){
        if(strcmp(filmes[i].titulo,filmes[deletar].titulo)==0){
            IndiceExclusao = i;
            break;
        }
    }
    if(IndiceExclusao != -1){
    for(int i = IndiceExclusao;i < totalFilmes-1;i++){
    filmes[i] = filmes[i+1];
    }
    totalFilmes--;
    printf("filme excluido com sucesso!\n");
    salvarFilmes();
    }else{
    printf("filme não encontrado\n");
    }
    }
    }

void AlugarFilme(){
    printf("\n--- Alugar Filmes ---\n");
    int Alugar;
    PesquisarFilmes();
    if(totalFilmes>0){
    printf("\nQual Filme vc quer alugar?(Escolha baseado na posição do filme):");
    scanf("%d",&Alugar);

    if(filmes[Alugar].quantidade>=1){
    filmes[Alugar].quantidade=filmes[Alugar].quantidade-1;
    printf("\nFilme Alugado");
    printf("\nAVISO AVISO AVISO AVISO\n");
    printf("Devolução em 3 dias,em caso de atraso valor de multa será adicionado ao valor total\n");
    }else{
    printf("\nTodos as copioas desses filmes foram alugados ou não existem");
    }
    }
}
void DevolverFilme(){
    int Devolver,Dias,Atraso,precototal;
    PesquisarFilmes();
    if(totalFilmes>0){
    printf("\n----Devolução de Filmes----\n");    
    printf("\nQual Filme você está sendo desevolveido?(Escolha baseado na posição do filme):");
    scanf("%d",&Devolver);
    if(filmes[Devolver].quantidade='\0'){
    filmes[Devolver].quantidade=filmes[Devolver].quantidade+1;

    printf("\nQuantos dias esse filme foi alugado?");
    scanf("%d",&Dias);
    if(Dias>3){
        Atraso=Dias-3;
        precototal=4*Atraso+12;
        printf("\nPreço total:$%d",precototal);
        printf("\nAluguel do Filme:$12,00");
        printf("\nTaxa adicional de $%d,devido ao atraso de %d Dias",4*Atraso,Dias-3);
    }
    if(Dias<=3){
        precototal=12;
        printf("\nPreço total:$%d",precototal);
    }

    }else{
    printf("\nTodos as copioas desses filmes foram devolvidas ou n?o existem");
    }
    }
}
int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    int opcao, index;
    do
    {
        printf("\n-------Locadora de Filmes-------\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Ver Filmes Cadastrados\n");
        printf("3. Ver Dados de um filme\n");
        printf("4. Salvar Filmes \n");
        printf("5. Carregar Filmes \n");
        printf("6. Pesquisar Filmes \n");
        printf("7. Deletar Filmes \n");
        printf("8. Alugar Filmes \n");
        printf("9. Devolver Filmes \n");
        printf("10. Para sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            if (totalFilmes < MAX_FILMES)
            {
                filmes[totalFilmes] = cadastrarFilme();
                totalFilmes++;
            }
            else
            {
                printf("Quantidade máxima de filmes cadastrada\n");
            }
            break;
        case 2:
            mostrarFilmes();

            break;
        case 3:
            printf("Informe o indice do filme que você deseja: ");
            scanf("%d", &index);
            exibirFilme(index);
            break;
        case 4:
            salvarFilmes();
            break;
        case 5:
            carregarFilmes();
            break;
        case 6:
            PesquisarFilmes();
            break;
        case 7:
            DeletarFilme();
            break;
        case 8:
            AlugarFilme();
            break;
        case 9:
            DevolverFilme();
            break;
        default:
            if(opcao<0){
            printf("\nOpção inválida!\n");
            }
        }

    } while (opcao!=10);
    printf("\nOBRIGADO POR SUA PREFERENCIA E VOLTE SEMPRE");

    return 0;
}