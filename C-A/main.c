#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <unistd.h>

struct  pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

int tempoEs(int *valor){
	if( poll(&mypoll, 1, 3000)) {
		scanf("%d", valor);
	}else{
		printf("Digite algo!!!\n");
		tempoEs(valor);
	}
}

void lerArquivo(int aux[]){
	int cont = 0;
	FILE *arq;
	arq = fopen("entrada.txt", "r");
	if (arq == NULL) {
			printf("Erro ao abrir o arquivo!!!");
			return;
	}else {
			while (fscanf (arq, "%d ", &aux[cont++]) != EOF);
		fclose (arq);
	}
}

int CMAIN (int *vEntr, int *vFil, int tamFil);

int main () {
	int tam = 0, tamFil = 0;
	int i, j;
	int inicio, fim;

	printf("Digite o tamanho da Entrada: \n");
	tempoEs(&tam);
	printf("Digite o tamanho do Filtro: \n");
	tempoEs(&tamFil);


	int tamSai = (tam-tamFil+1);
	int vSai[tamSai];
	int vEntr[tam], vFil[tamFil];

	lerArquivo(vEntr);

	for (i = 0; i < tamSai; i++) {
	}
	vSai[i] = 0;
	printf("Digite os Valores do Filtro: \n");
	for (i = 0; i < tamFil; i++) {
		tempoEs(&vFil[i]);
  }

	inicio = (double) clock();
	for (i = 0; i < tamSai; i++) {
			vSai[i] = CMAIN (vEntr+i, vFil, tamFil);
	}
	fim = (double) clock();

	FILE * resultado;
	resultado = fopen("result.txt", "w");
	for (i = 0; i < tamSai; i++) {
		fprintf(resultado, "%d\n", vSai[i]);
	}
	fclose(resultado);

	printf("Vetor de Saída\n| ");
	for (i = 0; i < tamSai; i++) {
		printf("%d | ", vSai[i]);
  }

	printf("\nTempo de execução do filtro: %.10lfs.\n", (fim-inicio)/(double)CLOCKS_PER_SEC);

}
