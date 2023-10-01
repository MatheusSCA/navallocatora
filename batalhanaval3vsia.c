#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>

#define TAMANHO 8
#define NAVIOS 25
#define AGUA '~'
#define NAVIO 'N'
#define ERRO 'E'
#define ACERTO 'A'

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

void imprimirTabuleiro1(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i + 1);
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
                printf("~ ");
            }
            else if (tabuleiro[i][j] == ACERTO)
            {
                printf("A ");
            }
            else if (tabuleiro[i][j] == ERRO)
            {
                printf("E ");
            }
            else
            {
                printf("N ");
            }
        }
        printf("\n");
    }
}

void imprimirTabuleiroIA(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i);
        //printf("%c  ", 'A' + i);//
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == ACERTO)
            {
                printf("O ");
            }
            else if (tabuleiro[i][j] == ERRO)
            {
                printf("X ");
            }
            else
            {
                printf("~ ");
            }
        }
        printf("\n");
    }
}

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNaviosJogador(char tabuleiro[TAMANHO][TAMANHO])
{
   int x,y,cont=-1,n=1,eixo;
   while(cont<0){
    printf("\nQual eixo você quer o %dºPorta Aviões(5 blocos):\n",n);
    printf("0-para vertical\n");
    printf("1-para horizontal\n");
    scanf("%d",&eixo);
    if (eixo == 0) {
    printf("\nOnde vc quer %dº Porta Aviões(5 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+4<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA&&tabuleiro[x][y+2]==AGUA&&tabuleiro[x][y+3]==AGUA&&tabuleiro[x][y+4]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      tabuleiro[x][y+2]=NAVIO;
      tabuleiro[x][y+3]=NAVIO;
      tabuleiro[x][y+4]=NAVIO;
      cont=cont+2;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
   if(eixo==1){
    printf("\nOnde vc quer %dº Porta Aviões(5 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+4<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA&&tabuleiro[x+2][y]==AGUA&&tabuleiro[x+3][y]==AGUA&&tabuleiro[x+4][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      tabuleiro[x+2][y]=NAVIO;
      tabuleiro[x+3][y]=NAVIO;
      tabuleiro[x+4][y]=NAVIO;
      cont=cont+2;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
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
    printf("0-para vertical\n");
    printf("1-para horizontal\n");
    scanf("%d",&eixo);
    if(eixo==0){
    printf("\nOnde vc quer %dº Navio tanque(4 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+3<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA&&tabuleiro[x][y+2]==AGUA&&tabuleiro[x][y+3]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      tabuleiro[x][y+2]=NAVIO;
      tabuleiro[x][y+3]=NAVIO;
      cont=cont+1;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
      n++;
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
    }

    if(eixo==1){
    printf("\nOnde vc quer %dº Navio Tanque(4 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+3<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA&&tabuleiro[x+2][y]==AGUA&&tabuleiro[x+3][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      tabuleiro[x+2][y]=NAVIO;
      tabuleiro[x+3][y]=NAVIO;
      cont=cont+1;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
      n++;
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
  }
  cont=0;
  n=1;
  while(cont<2){
    printf("\nQual eixo você quer o %dº Contratorpedeiro(3 blocos)?\n",n);
    printf("0-para vertical\n");
    printf("1-para horizontal\n");
    scanf("%d",&eixo);
    if(eixo==0){
    printf("Onde vc quer %dº contratorpedeiro(3 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+2<TAMANHO){
    if(tabuleiro[x][y]==AGUA && tabuleiro[x][y+1]==AGUA && tabuleiro[x][y+2]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      tabuleiro[x][y+2]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
    }
    }
    }

    if(eixo==1){
    printf("Onde vc quer %dº contratorpedeiro(3 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+2<TAMANHO){
    if(tabuleiro[x][y]==AGUA && tabuleiro[x+1][y]==AGUA && tabuleiro[x+2][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      tabuleiro[x+2][y]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
    }
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
    printf("0-para vertical\n");
    printf("1-para horizontal\n");
    scanf("%d",&eixo);
    if(eixo==0){
    printf("Onde vc quer %dº Rebocador(2 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+1<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
    }
    }
    }
    if(eixo==1){
    printf("Onde vc quer %d Rebocador(2 blocos)",n);
    scanf("%d %d",&x,&y);
    scanf("%d",&eixo);
    if(x+1<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      cont=cont+1;
      n++;
      printf("\nAssim está o tabuleiro:\n");
      imprimirTabuleiro(tabuleiro);
    }
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
}

void posicionarNaviosComputador(char tabuleiro2[TAMANHO][TAMANHO]){
   int x,y,cont=0,eixo;
   while(cont<1){
    eixo=rand() % 1;
    if(eixo==0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+4>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA&&tabuleiro2[x][y+2]==AGUA&&tabuleiro2[x][y+3]==AGUA&&tabuleiro2[x][y+4]==AGUA){
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
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+4>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA&&tabuleiro2[x+2][y]==AGUA&&tabuleiro2[x+3][y]==AGUA&&tabuleiro2[x+4][y]==AGUA){
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
  eixo=rand() % 1;
  if(eixo==0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+3<TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA&&tabuleiro2[x][y+2]==AGUA&&tabuleiro2[x][y+3]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      tabuleiro2[x][y+3]=NAVIO;
      cont=cont+1;
    }
  }
  }
  if(eixo==1){
  x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+3>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA&&tabuleiro2[x+2][y]==AGUA&&tabuleiro2[x+3][y]==AGUA&&tabuleiro2[x+4][y]==AGUA){
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
    eixo=rand() % 1;
    if(eixo==0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+2>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA&&tabuleiro2[x][y+2]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      cont=cont+1;

    }
    }
   }
   if(eixo==1){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+2>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA&&tabuleiro2[x+2][y]==AGUA){
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
    eixo=rand() % 1;
    if(eixo==0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+1>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      cont=cont+1;
    }
    }
   }
   if(eixo==1){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+1>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      cont=cont+1;
    }
    }
   }
   }
}

void ConferirTiro1P(char tabuleiro[TAMANHO][TAMANHO],int acertos,char tabuleiro2[TAMANHO][TAMANHO]){
int x,y;
  while(tabuleiro2[x][y]!=ERRO||tabuleiro2[x][y]!=ACERTO){
    printf("\nEsse local já foi atacado,entre coordernadas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",&x,&y);
  }  
  while(x<0||y<0||x>TAMANHO||y>TAMANHO){
    printf("\nCoodernadas inválidas,entre coordenas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",&x,&y);
  }
  if(tabuleiro2[x][y]==NAVIO){
    tabuleiro2[x][y]=ACERTO;
    printf("Você Acertou um Navio em %d %d",x,y);
    acertos++;
  }else{
    printf("Você errou, não tem nenhum navio em %d %d",x,y);
    tabuleiro2[x][y]=ERRO;
    return;
  }
}
void ConferirTiroIA(char tabuleiro2[TAMANHO][TAMANHO],int acertospc,char tabuleiro[TAMANHO][TAMANHO]){
  int x,y,ia=0,ax=0,ay=0;
  if(ia == 0){
    srand(time(NULL));

    do{
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    }while(tabuleiro[x][y]==NAVIO||tabuleiro[x][y]==AGUA);
    
    if(tabuleiro[x][y]==NAVIO&& ax==0 && ay==0){
      tabuleiro[x][y]=ACERTO;
      acertospc+=acertospc;
      ia=1;
      printf("Ia acertou Navio na posição %d %d",x,y);
      ax=1;
      ay=1;
    }else{
      tabuleiro2[x][y]=ERRO;
      printf("Ai errou");
      return;
    }
  }

  if(ia==1 && ax==1){
    if(tabuleiro[x+1][y]==NAVIO){
      tabuleiro[x+1][y]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x+1,y);
      ia=ia+1;
    }else{
      tabuleiro[x+1][y]=ERRO;
      printf("Ai errou");
      ax=-1;
      return;
    }
  }
   if(ia==1 && ay==1){
    if(tabuleiro[x][y+1]==NAVIO){
      tabuleiro[x][y+1]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x,y+1);
      ia=ia+1;
    }else{
      tabuleiro[x][y+1]=ERRO;
      printf("Ai errou");
      ay=-1;
      return;
    }
  }
  if(ia==1 && ax==-1){
    if(tabuleiro[x-1][y]==NAVIO){
      tabuleiro[x-1][y]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x-1,y);
      ia=-1;
    }else{
      tabuleiro[x-1][y]=ERRO;
      printf("Ai errou");
      ay=-1;
      return;
    }
  }
  if(ia==1 && ay==-1){
    if(tabuleiro[x][y-1]==NAVIO){
      tabuleiro[x][y-1]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x,y-1);
      ia=-1;
    }else{
      tabuleiro[x][y-1]=ERRO;
      printf("Ai errou");
      ay=0;
      return;
    }
  }
if(ia !=1 && ia !=0){
    if(ia>0){
    
    if(ax==1){
    if(tabuleiro[x+ia][y]==NAVIO){
      tabuleiro[x+ia][y]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x+ia,y);
      ia=ia+1;
    }else{
      tabuleiro[x+ia][y]=ERRO;
      printf("Ai errou");
      ax=-1;
      ia=1;
      return;
    }
  }
   if(ay==1){
    if(tabuleiro[x][y+ia]==NAVIO){
      tabuleiro[x][y+ia]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x,y+ia);
      ia=ia+1;
    }else{
      tabuleiro[x][y+ia]=ERRO;
      printf("Ai errou");
      ay=-1;
      ia=1;
      return;
    }
    }
    }

    if(ia<0){
    if(ax==-1){
    if(tabuleiro[x-ia][y]==NAVIO){
      tabuleiro[x-ia][y]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x-ia,y);
      ia=ia-1;
    }else{
      tabuleiro[x+ia][y]=ERRO;
      printf("Ai errou");
      ax=0;
      ia=0;
      return;
    }
  }
   if(ay==-1){
    if(tabuleiro[x][y-ia]==NAVIO){
      tabuleiro[x][y+ia]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x,y-ia);
      ia=ia-1;
    }else{
      tabuleiro[x][y-ia]=ERRO;
      printf("Ai errou");
      ay=0;
      ia=1;
      return;
    }
    }
    }
}
}

int main(){
setlocale(LC_ALL,"Portuguese");
char tabuleiro1[TAMANHO][TAMANHO],tabuleiro2[TAMANHO][TAMANHO];
int acertos=0,acertospc=0,x,y;

inicializarTabuleiro(tabuleiro1);
inicializarTabuleiro(tabuleiro2);

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
printf("\ncriando tabuleiro do computador....");
posicionarNaviosComputador(tabuleiro2);

do{
 printf("Vez do Jogador 1:\n");
 imprimirTabuleiroIA(tabuleiro1);
 printf("\nDigite as cordernadas:(exemplo linha (espaço) coluna)\n");
 scanf("%d %d",&x,&y);
 ConferirTiro1P(tabuleiro1,acertos,tabuleiro2);

 printf("\nVez do Computador:\n");
 ConferirTiroIA(tabuleiro2,acertospc,tabuleiro1);
 
printf("\nBATALHA NAVAL!!!!!!!\n");
printf("\ntabuleiro dos humanos:\n");
imprimirTabuleiro1(tabuleiro1);
printf("\ntabuleiro do Computador:\n");
imprimirTabuleiroIA(tabuleiro2);
printf("\nLEGENDA:\n");
printf("AGUA=>~\n");
printf("NAVIOS=>N\n");
printf("NAVIOS ACERTADOS=>A\n");
printf("ERROS=>E\n");

if(acertos==NAVIOS||acertospc==NAVIOS){
  break;
}
}while(1);

if(acertos==NAVIOS){
  printf("\nPARABENS VOCÊ VENCEU!!!!(YAAAAYyy...)\n");
}else{
  printf("\nVocê Perdeu!\n(SadFaceSpongebob.mp4)");
}
 return 0;
}