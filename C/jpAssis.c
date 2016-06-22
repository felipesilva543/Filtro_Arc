#include <stdio.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int filtro(int * key, int * entrada, int atual, int tamKey){
  int i, sum = 0;
  for(i = 0; i < tamKey; i++){
    sum += entrada[atual] * key[i];
    atual++;
  }
  return sum;
}

int kbhit(void){
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}
int main(){
  FILE *arq;
  arq = fopen("banco.txt", "r");
  if(arq == NULL){
    printf("Erro ao abrir o arquivo!!!");
    return(0);
  }

  int start, stop;
  start = (double) clock();
  int i,  n,size;
  while(1){
    printf("Digite o tamanho do filtro\n");
    sleep(2);
    if(kbhit()){
        scanf("%d", &n);
        break;
    }

  }
  int key[n];

  printf("valores do filtro\n");
  for(i = 0; i < n; i++){
    scanf("%d", &key[i]);
  }

  int numbers[100];
  int x=0;

	while(fscanf(arq, "%d,", &numbers[x++]) != EOF);

  int entrada[x], saida[x-(n-1)];

  for(i=0; i<x; i++)
    entrada[i] = numbers[i];


  for(i = 0; i < (x-n+1); i++ )
    saida[i] = filtro(key,entrada, n, i);


  for(i=0;i<(x-n); i++)
    printf("%d  ", saida[i]);

  stop = (double)clock();

  printf("\n\nTempo de exucação: %0.2fms\n", 1000*(stop - start)/(double)CLOCKS_PER_SEC);
}
