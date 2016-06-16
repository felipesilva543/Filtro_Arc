#include <stdio.h>


int main () {
  int tam = 0, tamFil = 0;

///////////Tamanho do Sinal////////////
  printf("Digite o tamanho do Sinal: ");
  scanf("%d", &tam);

///////////Tamanho do Filtro////////////
  printf("Digite o tamanho do Filtro: ");
  scanf("%d", &tamFil);

///////////Variáveis////////////
  int tamSai = (tam - tamFil+1);
  printf("%d", tamSai);
  int v[tam], f[tamFil], s[tamSai];
  int i, j, soma = 0, aux;

///////////Zerar Vetores////////////
  for (i = 0; i < tamSai; i++) {
    s[i] = 0;
  }

///////////Valores do Sinal////////////
  printf("Digite os valores do Sinal: \n");
    for (i = 0; i < tam; i++) {
      scanf("%d", &v[i]);
    }

///////////Valores do Filtro////////////
  printf("Digite os valores do Filtro: \n");
    for (i = 0; i < tamFil; i++) {
      scanf("%d", &f[i]);
    }

///////////Filtro////////////
    int n = 0;
    for (i = 0; i < tamSai; i++) {
      for ( j = 0; j < tamFil; j++) {
        s[n] += (f[j]*v[i+j]);
      }
      n++;
    }

///////////Imprimir Saída////////////
    printf("\n\n");
    for (i = 0; i < tamSai; i++) {
      printf("%d\n", s[i]);
    }
}
