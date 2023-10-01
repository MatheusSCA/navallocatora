#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 9
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
        printf("%d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        // printf("%d  ", i);
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TAMANHO; j++)
        {
            printf("%c  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void imprimirTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("   ");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%c  ", 'A' + i);
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == AGUA)
            {
                printf("~ ");
            }
            else if (tabuleiro[i][j] == ACERTO)
            {
                printf("O ");
            }
            else if (tabuleiro[i][j] == ERRO)
            {
                printf("X ");
            }
            else
            {
                printf("N ");
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
   int x,y,cont,n=1,eixo;
   while(cont<0){
    printf("\nQual eixo você quer o navio?");
    printf("0-para vertical");
    printf("1-para vertical");
    scanf("%d",&eixo);
    if(eixo=0){
    printf("\nOnde vc quer %dº Porta Aviões(5 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+4<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA&&tabuleiro[x][y+2]==AGUA&&tabuleiro[x][y+3]==AGUA&&tabuleiro[x][y+4]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      tabuleiro[x][y+2]=NAVIO;
      tabuleiro[x][y+3]=NAVIO;
      tabuleiro[x][y+4]=NAVIO;
      cont+=cont;
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
   if(eixo=1){
    printf("\nOnde vc quer %dº Porta Aviões(5 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+4<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA&&tabuleiro[x+2][y]==AGUA&&tabuleiro[x+3][y]==AGUA&&tabuleiro[x+4][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      tabuleiro[x+2][y]=NAVIO;
      tabuleiro[x+3][y]=NAVIO;
      tabuleiro[x+4][y]=NAVIO;
      cont+=cont;
   }
   }
   else{
    printf("opção inválida");
   }
   }
   }
    n=1;
    while(cont<2){
    printf("\nQual eixo você quer o navio?");
    printf("0-para vertical");
    printf("1-para vertical");
    if(eixo=0){
    printf("Onde vc quer %dº Navio tanque(4 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+3<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA&&tabuleiro[x][y+2]==AGUA&&tabuleiro[x][y+3]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      tabuleiro[x][y+2]=NAVIO;
      tabuleiro[x][y+3]=NAVIO;
      cont+=cont;
      n++;
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
    }
    if(eixo=1){
    printf("Onde vc quer %dº Navio Tanque(4 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+3<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA&&tabuleiro[x+2][y]==AGUA&&tabuleiro[x+3][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      tabuleiro[x+2][y]=NAVIO;
      tabuleiro[x+3][y]=NAVIO;
      cont+=cont;
      n++;
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
  }
  n=1;
  while(cont<4){
    printf("\nQual eixo você quer o navio?");
    printf("0-para vertical");
    printf("1-para vertical");
    if(eixo=0){
    printf("Onde vc quer %dº contratorpedeiro(3 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+2>TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA&&tabuleiro[x][y+2]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      tabuleiro[x][y+2]=NAVIO;
      cont+=cont;
      n++;
    }
    }
    }
    if(eixo=1){
    printf("Onde vc quer %dº contratorpedeiro(3 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+2>TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA&&tabuleiro[x+2][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      tabuleiro[x+2][y]=NAVIO;
      cont+=cont;
      n++;
    }
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
   n=1;
   while(cont<7){
    printf("\nQual eixo você quer o navio?");
    printf("0-para vertical");
    printf("1-para vertical");
    if(eixo=0){
    printf("Onde vc quer %d rebocador(2 blocos)",n);
    scanf("%d %d",&x,&y);
    if(y+1<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x][y+1]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x][y+1]=NAVIO;
      cont+=cont;
      n++;
    }
    }
    }
     if(eixo=1){
    printf("Onde vc quer %d rebocador(2 blocos)",n);
    scanf("%d %d",&x,&y);
    if(x+1<TAMANHO){
    if(tabuleiro[x][y]==AGUA&&tabuleiro[x+1][y]==AGUA){
      tabuleiro[x][y]=NAVIO;
      tabuleiro[x+1][y]=NAVIO;
      cont+=cont;
      n++;
    }
    }
    }
    else{
    printf("opção inválida ou navio em posição impossível(espaço cheio ou fora do tabuleiro)");
    }
   }
}

void posicionarNaviosComputador(char tabuleiro[TAMANHO][TAMANHO],char tabuleiro2[TAMANHO][TAMANHO]){
   int x,y,cont,eixo;
   while(cont<0){
    eixo=rand() % 1;
    if(eixo=0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+4>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA&&tabuleiro2[x][y+2]==AGUA&&tabuleiro2[x][y+3]==AGUA&&tabuleiro2[x][y+4]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      tabuleiro2[x][y+3]=NAVIO;
      tabuleiro2[x][y+4]=NAVIO;
      cont+=cont;
    }
    }
    }
    if(eixo=1){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+4>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA&&tabuleiro2[x+2][y]==AGUA&&tabuleiro2[x+3][y]==AGUA&&tabuleiro2[x+4][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      tabuleiro2[x+2][y]=NAVIO;
      tabuleiro2[x+3][y]=NAVIO;
      tabuleiro2[x+4][y]=NAVIO;
      cont+=cont;
   }
  }
  }
  }

  while(cont<2){
  eixo=rand() % 1;
  if(eixo=0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+3<TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA&&tabuleiro2[x][y+2]==AGUA&&tabuleiro2[x][y+3]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      tabuleiro2[x][y+3]=NAVIO;
      cont+=cont;
    }
  }
  }
  if(eixo=1){
  x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+3>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA&&tabuleiro2[x+2][y]==AGUA&&tabuleiro2[x+3][y]==AGUA&&tabuleiro2[x+4][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      tabuleiro2[x+2][y]=NAVIO;
      tabuleiro2[x+3][y]=NAVIO;
      cont+=cont;
    }
    }
  }
 } 

   while(cont<4){
    eixo=rand() % 1;
    if(eixo=0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+2>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA&&tabuleiro2[x][y+2]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      tabuleiro2[x][y+2]=NAVIO;
      cont+=cont;
    }
    }
   }
   if(eixo=1){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+2>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA&&tabuleiro2[x+2][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      tabuleiro2[x+2][y]=NAVIO;
      cont+=cont;
    }
    }
   }
   }
   while(cont<7){
    eixo=rand() % 1;
    if(eixo=0){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(y+1>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x][y+1]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x][y+1]=NAVIO;
      cont+=cont;
    }
    }
   }
   if(eixo=1){
    x = rand() % TAMANHO;
    y = rand() % TAMANHO;
    if(x+1>TAMANHO){
    if(tabuleiro2[x][y]==AGUA&&tabuleiro2[x+1][y]==AGUA){
      tabuleiro2[x][y]=NAVIO;
      tabuleiro2[x+1][y]=NAVIO;
      cont+=cont;
    }
    }
   }
   }
}

void ConferirTiro1P(char tabuleiro[TAMANHO][TAMANHO],int acertos,char tabuleiro2[TAMANHO][TAMANHO]){
int x,y,i,j;
  if(tabuleiro2[x][y]==ERRO||tabuleiro2[x][y]==ACERTO){
    printf("\nEsse local já foi atacado,entre coordernadas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",x,y);
  }  
  while(x<0||y<0||x>TAMANHO||y>TAMANHO){
    printf("\nCoodernadas inválidas,entre coordenas novamente:\n");
    printf("\nOnde quer atacar?:");
    scanf("%d %d",x,y);
  }
  if(tabuleiro2[x][y]==NAVIO){
    tabuleiro2[x][y]=ACERTO;
    printf("Você Acertou um Navio em %d %d",x,y);
    acertos++;
  }else{
    printf("Você errou, não tem nenhum navio em %d %d",x,y);
    tabuleiro2[x][y]=ERRO;
  }
}
void ConferirTiroIA(char tabuleiro2[TAMANHO][TAMANHO],int acertospc,char tabuleiro[TAMANHO][TAMANHO]){
  int x,y,ia,ax=0,ay=0;
  if(ia==0){
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
      return;
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
      return;
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
      return;
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
      ia=ia+1;
      return;
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
      ia=ia+1;
      return;
    }else{
      tabuleiro[x][y-1]=ERRO;
      printf("Ai errou");
      ay=0;
      return;
    }
  }
  if(ia==2 && ax==1){
    if(tabuleiro[x+2][y]==NAVIO){
      tabuleiro[x+2][y]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x+2,y);
      ia=ia+1;
      return;
    }else{
      tabuleiro[x+2][y]=ERRO;
      printf("Ai errou");
      ax=-1;
      ia=1;
      return;
    }
  }
  if(ia==2 && ay==1){
    if(tabuleiro[x][y+2]==NAVIO){
      tabuleiro[x][y+2]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x,y+2);
      ia=ia+1;
      return;
    }else{
      tabuleiro[x][y+2]=ERRO;
      printf("Ai errou");
      ay=-1;
      ia=1;
      return;
    }
  }
  if(ia==2 && ax==-1){
    if(tabuleiro[x-2][y]==NAVIO){
      tabuleiro[x-2][y]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x-1,y);
      ia=ia+1;
      return;
    }else{
      tabuleiro[x-1][y]=ERRO;
      printf("Ai errou");
      ax=-1;
      ia=1;
      return;
    }
  }
  if(ia==2 && ay==-1){
    if(tabuleiro[x][y-2]==NAVIO){
      tabuleiro[x][y-2]=ACERTO;
      acertospc+=acertospc;
      printf("Ia acertou Navio na posição %d %d",x,y-2);
      ia=ia+1;
      return;
    }else{
      tabuleiro[x-1][y]=ERRO;
      printf("Ai errou");
      ax=-1;
      ia=1;
      return;
    }
  }
}