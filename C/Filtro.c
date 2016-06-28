#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <unistd.h>

struct  pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

int tempoEs(int *valor){
	if( poll(&mypoll, 1, 2000)) {
		scanf("%d", valor);
	}else{
		printf("Digite algo!!!\n");
		tempoEs(valor);
	}
}

void lerArquivo(int aux[]){
	int cont = 0;
	FILE *arq;
	arq = fopen("exemplo.txt", "r");

	if(arq == NULL){
			printf("Erro ao abrir o arquivo!!!");
			return;
	}else {
			printf("Pegando valores(DEBUG)\n");
			while(fscanf(arq, "%d,", &aux[cont++]) != EOF);
		fclose(arq);
	}
}

int filtro(int vEntr[], int vFil[], int vSai[], int tamSai, int tamFil){
	printf("Chegou na função FILTRO!!(DEBUG)");
	int n = 0;
	int i, j;
	for (i = 0; i < tamSai; i++) {
		for ( j = 0; j < tamFil; j++) {
			vSai[n] += (vFil[j]*vEntr[i+j]);
		}
		n++;
	}
}

int main () {
	int tam = 0, tamFil = 0;

	int i, j, soma = 0, aux;
	long int inicio, fim;

	printf("Digite o tamanho da Entrada: \n");
	tempoEs(&tam);

	printf("Digite o tamanho do Filtro: \n");
	tempoEs(&tamFil);

	int tamSai = (tam - tamFil+1);
	int vSai[tamSai];
	int vEntr[tam], vFil[tamFil];

	for (i = 0; i < tamSai; i++) {
    	vSai[i] = 0;
	}

	lerArquivo(vEntr);

	printf("\n\nVetor de Entrada(DEBUG)!!\n");

	for (i = 0; i < tam; i++) {
		printf("%d\n", vEntr[i]);
	}

	printf("\n\n");
	printf("Digite os valores do Filtro: \n");

	for (i = 0; i < tamFil; i++) {
		tempoEs(&vFil[i]);
    }

	inicio = clock();
	filtro(vEntr, vFil, vSai, tamSai, tamFil);
	fim = clock();

	FILE * resultado;
	resultado = fopen("result.txt", "w");
	for (i = 0; i < tamSai; i++) {
		fprintf(resultado, "%d\n", vSai[i]);
	}
	fclose(resultado);



    printf("\n\n");
    printf("Chegou em imprimir VETOR FINAL (DEBUG)!!!\n");
    for (i = 0; i < tamSai; i++) {
		printf("%d\n", vSai[i]);
    }

	printf("Tempo de execução do filtro: %.10lf segundos\n",
		  (double)(fim-inicio)/CLOCKS_PER_SEC);

}
