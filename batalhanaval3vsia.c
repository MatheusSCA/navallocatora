#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>

#define TAMANHO 9
#define NAVIOS 25
#define AGUA '~'
#define NAVIO 'N'
#define ERRO 'E'
#define ACERTO 'A'

//criar tabuleiro//
void imprimirTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i);
        //printf("%c  ", 'A' + i);//
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%c  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//imprimir tabuleiro do jogador(mostrando onde tem os navios)//
void imprimirTabuleiro1(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i);
        //printf("%c  ", 'A' + i);//
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == AGUA)
            {
                printf("~  ");
            }
            else if (tabuleiro[i][j] == ACERTO)
            {
                printf("A  ");
            }
            else if (tabuleiro[i][j] == ERRO)
            {
                printf("E  ");
            }
            else
            {
                printf("N  ");
            }
        }
        printf("\n");
    }
}
//imprimir tabuleiro da ia(não mostra onde tem os navios)//
void imprimirTabuleiroIA(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d   ", i);
        //printf("%c  ", 'A' + i);//
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == ACERTO)
            {
                printf("O  ");
            }
            else if (tabuleiro[i][j] == ERRO)
            {
                printf("X  ");
            }
            else
            {
                printf("~  ");
            }
        }
        printf("\n");
    }
}
//criar tabuleiro vazios//
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i <= TAMANHO; i++)
    {
        for (int j = 0; j <= TAMANHO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
    }
}
//criando navios do jogador//
void posicionarNaviosJogador(char tabuleiro1[TAMANHO][TAMANHO])
{
   int x,y,cont=-1,n=1,eixo;
   while(cont<0){
    printf("\nQual eixo você quer o %dºPorta Aviões(5 blocos):\n",n);
    printf("0-para horizontal\n");
    printf("1-para vertical\n");
    scanf("%d",&eixo);
    if (eixo == 0) {
    printf("\nOnde vc quer %dº Porta Aviões-5 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(y+4<TAMANHO && y!=TAMANHO && y+1!=TAMANHO && y+2!=TAMANHO && y+2!=TAMANHO && y+3!=TAMANHO && y+4!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x][y+1]==AGUA && tabuleiro1[x][y+2]==AGUA && tabuleiro1[x][y+3]==AGUA && tabuleiro1[x][y+4]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x][y+1]=NAVIO;
      tabuleiro1[x][y+2]=NAVIO;
      tabuleiro1[x][y+3]=NAVIO;
      tabuleiro1[x][y+4]=NAVIO;
      cont=cont+2;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
    }
    else{
      printf("Espaço prenchido por um Navio");
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
   else if(eixo==1){
    printf("\nOnde vc quer %dº Porta Aviões-5 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(x+4<TAMANHO&& x!=TAMANHO &&x+1!=TAMANHO &&x+2!=TAMANHO && x+3!=TAMANHO && x+4!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x+1][y]==AGUA&&tabuleiro1[x+2][y]==AGUA&&tabuleiro1[x+3][y]==AGUA&&tabuleiro1[x+4][y]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x+1][y]=NAVIO;
      tabuleiro1[x+2][y]=NAVIO;
      tabuleiro1[x+3][y]=NAVIO;
      tabuleiro1[x+4][y]=NAVIO;
      cont=cont+2;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
   }
   else{
   printf("Opção invalida");
   }
   }
   else{
    printf("opção inválida");
   }
   }
   }
    cont=0;
    n=1;
    while(cont<2){
    printf("\nQual eixo você quer o %dº Navio tanque(4 blocos)?\n",n);
    printf("0-para horizontal\n");
    printf("1-para vertical\n");
    scanf("%d",&eixo);
    if(eixo==0){
    printf("\nOnde vc quer %dº Navio tanque-4 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(y+3<TAMANHO && y!=TAMANHO&& y+1!=TAMANHO && y+2!=TAMANHO && y+2!=TAMANHO && y+3!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x][y+1]==AGUA && tabuleiro1[x][y+2]==AGUA && tabuleiro1[x][y+3]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x][y+1]=NAVIO;
      tabuleiro1[x][y+2]=NAVIO;
      tabuleiro1[x][y+3]=NAVIO;
      cont=cont+1;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
      n++;
    }else{
    printf("Opção invalida");
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
    }

    else if(eixo==1){
    printf("\nOnde vc quer %dº Navio Tanque-4 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(x+3<TAMANHO && x!=TAMANHO &&x+1!=TAMANHO &&x+2!=TAMANHO && x+3!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x+1][y]==AGUA && tabuleiro1[x+2][y]==AGUA && tabuleiro1[x+3][y]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x+1][y]=NAVIO;
      tabuleiro1[x+2][y]=NAVIO;
      tabuleiro1[x+3][y]=NAVIO;
      cont=cont+1;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
      n++;
    }
    else{
   printf("Opção invalida");
   }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
   else{
    printf("opção inválida");
   }
  }
  cont=0;
  n=1;
  while(cont<2){
    printf("\nQual eixo você quer o %dº Contratorpedeiro(3 blocos)?\n",n);
    printf("0-para horizontal\n");
    printf("1-para vertical\n");
    scanf("%d",&eixo);
    if(eixo==0){
    printf("Onde vc quer %dº contratorpedeiro-3 blocos(Exemplo:linha (espaço) coluna)",n);
    scanf("%d %d",&x,&y);
    if(y+2<TAMANHO&& y!=TAMANHO&& y+1!=TAMANHO && y+2!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x][y+1]==AGUA && tabuleiro1[x][y+2]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x][y+1]=NAVIO;
      tabuleiro1[x][y+2]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
    }
  else{
   printf("Opção invalida");
   }
    }
  else{
   printf("Opção invalida");
   }
    }

    else if(eixo==1){
    printf("Onde vc quer %dº contratorpedeiro-3 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(x+2<TAMANHO&&x!=TAMANHO && x!=TAMANHO &&x+1!=TAMANHO &&x+2!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x+1][y]==AGUA && tabuleiro1[x+2][y]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x+1][y]=NAVIO;
      tabuleiro1[x+2][y]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
    }
    else{
   printf("Opção invalida");
   }
    }
    else{
   printf("Opção invalida");
   }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
   cont=0;
   n=1;
   while(cont<3){
    printf("\nQual eixo você quer o %dº Rebocador(2 blocos)?\n",n);
    printf("0-para horizontal\n");
    printf("1-para vertical\n");
    scanf("%d",&eixo);
    if(eixo==0){
    printf("Onde vc quer %dº Rebocador-2 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(y+1<TAMANHO && y!=TAMANHO && y+1!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x][y+1]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x][y+1]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
    }
  }
  else{
   printf("Opção invalida");
   }
    }
    else if(eixo==1){
    printf("Onde vc quer %d Rebocador-2 blocos(Exemplo:linha (espaço) coluna):",n);
    scanf("%d %d",&x,&y);
    if(x+1<TAMANHO && x!=TAMANHO &&x+1!=TAMANHO){
    if(tabuleiro1[x][y]==AGUA && tabuleiro1[x+1][y]==AGUA){
      tabuleiro1[x][y]=NAVIO;
      tabuleiro1[x+1][y]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro1);
    }
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
}
//criando navios do computador//
void posicionarNaviosComputador(char tabuleiro2[TAMANHO][TAMANHO]){
   int x,y,cont=0,eixo;
   while(cont<1){
    eixo=rand() % 2;
    if(eixo==0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+4<TAMANHO && y!=TAMANHO && y+1!=TAMANHO && y+2!=TAMANHO && y+3!=TAMANHO && y+4!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x][y+1]==AGUA && tabuleiro2[x][y+2]==AGUA && tabuleiro2[x][y+3]==AGUA && tabuleiro2[x][y+4]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      tabuleiro2[x][y+3]=NAVIO;
      tabuleiro2[x][y+4]=NAVIO;
      cont=cont+1;
    }
    }
    }
    if(eixo==1){
    x = rand() % TAMANHO-1;
    y = rand() % TAMANHO-1;
    if(x+4<TAMANHO&& x!=TAMANHO &&x+1!=TAMANHO &&x+2!=TAMANHO && x+3!=TAMANHO && x+4!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x+1][y]==AGUA && tabuleiro2[x+2][y]==AGUA && tabuleiro2[x+3][y]==AGUA && tabuleiro2[x+4][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      tabuleiro2[x+2][y]=NAVIO;
      tabuleiro2[x+3][y]=NAVIO;
      tabuleiro2[x+4][y]=NAVIO;
      cont=cont+1;
   }
  }
  }
  }
  cont=0;
  while(cont<2){
  eixo=rand() % 2;
  if(eixo==0){
    x = rand() % TAMANHO-1;
    y = rand() % TAMANHO-1;
    if(y+3<TAMANHO && y!=TAMANHO && y+1!=TAMANHO && y+2!=TAMANHO && y+2!=TAMANHO && y+3!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x][y+1]==AGUA && tabuleiro2[x][y+2]==AGUA && tabuleiro2[x][y+3]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      tabuleiro2[x][y+3]=NAVIO;
      cont=cont+1;
    }
  }
  }
  if(eixo==1){
  x = rand() % TAMANHO-1;
    y = rand() % TAMANHO-1;
    if(x+3<TAMANHO && x!=TAMANHO && x+1!=TAMANHO && x+2!=TAMANHO && x+3!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x+1][y]==AGUA && tabuleiro2[x+2][y]==AGUA && tabuleiro2[x+3][y]==AGUA && tabuleiro2[x+4][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      tabuleiro2[x+2][y]=NAVIO;
      tabuleiro2[x+3][y]=NAVIO;
      cont=cont+1;
    }
    }
  }
 } 
  cont=0;
  while(cont<2){
    eixo=rand() % 2;
    if(eixo==0){
    x = rand() % TAMANHO-1;
    y = rand() % TAMANHO-1;
    if(y+2<TAMANHO && y!=TAMANHO && y+1!=TAMANHO && y+2!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x][y+1]==AGUA && tabuleiro2[x][y+2]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      cont=cont+1;

    }
    }
   }
   if(eixo==1){
    x = rand() % TAMANHO-1;
    y = rand() % TAMANHO-1;
    if(x+2<TAMANHO&& x!=TAMANHO && x+1!=TAMANHO &&x+2!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x+1][y]==AGUA && tabuleiro2[x+2][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      tabuleiro2[x+2][y]=NAVIO;
      cont=cont+1;
    }
    }
   }
   }
  cont=0;
  while(cont<3){
    eixo=rand() % 2;
    if(eixo==0){
    x = rand() % TAMANHO-1;
    y = rand() % TAMANHO-1;
    if(y+1<TAMANHO&& y!=TAMANHO && y+1!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x][y+1]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      cont=cont+1;
    }
    }
   }
   if(eixo==1){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+1<TAMANHO&& x!=TAMANHO &&x+1!=TAMANHO){
    if(tabuleiro2[x][y]==AGUA && tabuleiro2[x+1][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      cont=cont+1;
    }
    }
   }
   }
}
//testando se os tiros do jogador são possiveis//
void ConferirTiro1P(int *acertos,char tabuleiro2[TAMANHO][TAMANHO]){
int x,y;
while(1){
 printf("\nDigite as cordernadas:(exemplo linha (espaço) coluna)\n");
 scanf("%d %d",&x,&y);
  while(tabuleiro2[x][y]==ERRO||tabuleiro2[x][y]==ACERTO){
    printf("\nEsse local já foi atacado,entre coordernadas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",&x,&y);
  }  
  while(x<0||y<0||x>TAMANHO||y>TAMANHO){
    printf("\nCoodernadas inválidas,entre coordenas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",&x,&y);
  }
  while(x==TAMANHO||y==TAMANHO){
    printf("\nCoodernadas inválidas,entre coordenas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",&x,&y);
  }
  if(tabuleiro2[x][y]==NAVIO){
    tabuleiro2[x][y]=ACERTO;
    printf("Você Acertou um Navio em %d %d\n",x,y);
    *acertos=*acertos+1;
    // Para ver os Navios do computador//
    //imprimirTabuleiro1(tabuleiro2);//
    imprimirTabuleiroIA(tabuleiro2);
  }else{
    printf("Você errou, não tem nenhum navio em %d %d",x,y);
    tabuleiro2[x][y]=ERRO;
    break;
  }
}
}
//testando se os tiros do computador são possiveis//
void ConferirTiroIA(char tabuleiro2[TAMANHO][TAMANHO],int *acertospc,char tabuleiro1[TAMANHO][TAMANHO]){
  int x,y,ia=0,ax=0,ay=0;
  if(ia == 0){
    do{
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    }while(tabuleiro1[x][y]==ACERTO||tabuleiro1[x][y]==ERRO||x==TAMANHO||y==TAMANHO);
    printf("<IA tentou atirar em %d %d>\n",x,y);

    if(tabuleiro1[x][y]==NAVIO && ax==0 && ay==0){
      tabuleiro1[x][y]=ACERTO;
      *acertospc=*acertospc+1;
      ia=1;
      printf("<Ia acertou Navio na posição %d %d>\n",x,y);
      ax=1;
      ay=1;
    }else{
      tabuleiro2[x][y]=ERRO;
      printf("<Ai errou.>\n");
      return;
    }
  }

  if(ia==1 && ax==1){
    if(tabuleiro1[x+1][y]==NAVIO){
      tabuleiro1[x+1][y]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x+1,y);
      ia=ia+1;
    }else{
      tabuleiro1[x+1][y]=ERRO;
      printf("<Ai errou.>\n");
      ax=-1;
      return;
    }
  }
   if(ia==1 && ay==1){
    if(tabuleiro1[x][y+1]==NAVIO){
      tabuleiro1[x][y+1]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x,y+1);
      ia=ia+1;
    }else{
      tabuleiro1[x][y+1]=ERRO;
      printf("<Ai errou.>\n");
      ay=-1;
      return;
    }
  }
  if(ia==1 && ax==-1){
    if(tabuleiro1[x-1][y]==NAVIO){
      tabuleiro1[x-1][y]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x-1,y);
      ia=-1;
    }else{
      tabuleiro1[x-1][y]=ERRO;
      printf("<Ai errou.>\n");
      ay=-1;
      return;
    }
  }
  if(ia==1 && ay==-1){
    if(tabuleiro1[x][y-1]==NAVIO){
      tabuleiro1[x][y-1]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x,y-1);
      ia=-1;
    }else{
      tabuleiro1[x][y-1]=ERRO;
      printf("<Ai errou.>\n");
      ay=0;
      return;
    }
  }
if(ia !=1 && ia !=0){
    if(ia>0){
    if(ax==1){
    if(tabuleiro1[x+ia][y]==NAVIO){
      tabuleiro1[x+ia][y]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x+ia,y);
      ia=ia+1;
    }else{
      tabuleiro1[x+ia][y]=ERRO;
      printf("<Ai errou.>\n");
      ax=-1;
      ia=1;
      return;
    }
  }
   if(ay==1){
    if(tabuleiro1[x][y+ia]==NAVIO){
      tabuleiro1[x][y+ia]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x,y+ia);
      ia=ia+1;
    }else{
      tabuleiro1[x][y+ia]=ERRO;
      printf("<Ai errou.>\n");
      ay=-1;
      ia=1;
      return;
    }
    }
    }

    if(ia<0){
    if(ax==-1){
    if(tabuleiro1[x-ia][y]==NAVIO){
      tabuleiro1[x-ia][y]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x-ia,y);
      ia=ia-1;
    }else{
      tabuleiro1[x+ia][y]=ERRO;
      printf("<Ai errou.>\n");
      ax=0;
      ia=0;
      return;
    }
  }
   if(ay==-1){
    if(tabuleiro1[x][y-ia]==NAVIO){
      tabuleiro1[x][y+ia]=ACERTO;
      *acertospc=*acertospc+1;
      printf("<Ia acertou Navio na posição %d %d>\n",x,y-ia);
      ia=ia-1;
    }else{
      tabuleiro1[x][y-ia]=ERRO;
      printf("<Ai errou.>\n");
      ay=0;
      ia=1;
      return;
    }
    }
    }
}
}
//função principal//
int main(){
setlocale(LC_ALL,"Portuguese");
char tabuleiro1[TAMANHO][TAMANHO],tabuleiro2[TAMANHO][TAMANHO];
int acertos=0,acertospc=0,jogo=0;

inicializarTabuleiro(tabuleiro1);
inicializarTabuleiro(tabuleiro2);

srand(time(NULL));

printf("Carregando...\n");
printf("\nBATALHA NAVAL!!!!!!!\n");
printf("\n(humano contra computador)\n");
imprimirTabuleiro(tabuleiro1);
printf("LEGENDA:\n");
printf("AGUA=>~\n");
printf("NAVIOS=>N\n");
printf("NAVIOS ACERTADOS=>A\n");
printf("ERROS=>E\n");

printf("CRIE O SEU TABELEIRO:\n");
posicionarNaviosJogador(tabuleiro1);
printf("\n<criando tabuleiro do computador....\n>");
posicionarNaviosComputador(tabuleiro2);
printf("IA criada.");

while(jogo!=0){
printf("Vez do Jogador 1:\n");
//Para ganhar ou perder instaniamente//
//acertos=NAVIOS;//
//acertospc=NAVIOS;//
ConferirTiro1P(&acertos,tabuleiro2);

printf("\n<Vez do Computador:>\n");
ConferirTiroIA(tabuleiro2,&acertospc,tabuleiro1);
imprimirTabuleiro1(tabuleiro1);  
printf("\n");
printf("\n<Sua vez:>\n");
//Para ver os navio do computador//
//imprimirTabuleiro1(tabuleiro2);//
imprimirTabuleiroIA(tabuleiro2);

if(acertos==25){
  printf("\nPARABENS VOCÊ VENCEU!!!!<YAAAAYyy...>\n");
  break;
}

if(acertospc==25){
  printf("\n<Você Perdeu!\n01100101 01110101 00100000 01100111 01100001 01101110 01101000 01100101 01101001 00001010>\n");
  break;
}
}
 return 0;
}