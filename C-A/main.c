#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <unistd.h>

struct  pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

//Função para verificar se o Usuário digitou!
int tempoEs(int *valor){
	if( poll(&mypoll, 1, 3000)) {
		scanf("%d", valor);
	}else{
		printf("Digite algo!!!\n");
		tempoEs(valor);
	}
}

//Ler Arquivo
void lerArquivo(int aux[]){
	int cont = 0;
	FILE *arq;
	arq = fopen("entrada.txt", "r");
	if (arq == NULL) {
		printf("Erro ao abrir o arquivo!!!");
		return;
	}else {
		while (fscanf (arq, "%d,", &aux[cont++]) != EOF);
			fclose (arq);
	}
}

//Função em Assembly
void CMAIN (int *vFil, int *vEntr, int *vSai, int tamFil, int tam, int tamSai);

int main () {
	//Variáveis de Controle
	int tam = 0, tamFil = 0;
	int i;
	int inicio, fim;

	printf("Digite o tamanho da Entrada: \n");
	tempoEs(&tam);
	printf("Digite o tamanho do Filtro: \n");
	tempoEs(&tamFil);

	//Variável de controle Tamanho do vetor de Saída
	int tamSai = (tam-tamFil+1);

	//Vetores de Entrada, Filtro e Saída
	int vSai[tamSai], vEntr[tam], vFil[tamFil];

	//Lendo entradas do Arquivo
	lerArquivo(vEntr);

	//Zerando vetor de Saída
	for (i = 0; i < tamSai; i++) {
		vSai[i] = 0;
	}

	printf("Digite os Valores do Filtro: \n");
	for (i = 0; i < tamFil; i++) {
		tempoEs(&vFil[i]);
  }

	inicio = (double) clock();
	CMAIN (vFil, vEntr, vSai, tamFil, tam, tamSai);
	fim = (double) clock();

	//Escrevendo Arquivo de Resultado
	FILE * resultado;
	resultado = fopen("result.txt", "w");
	for (i = 0; i < tamSai; i++) {
		fprintf(resultado, "| %d ", vSai[i]);
	}
		fprintf(resultado, "|");
		fprintf(resultado,"\nTempo de execução do filtro: %.10lfs.\n", (fim-inicio)/(double)CLOCKS_PER_SEC);
	fclose(resultado);

	//Printando vetor de Saída
	printf("Vetor de Saída\n| ");
	for (i = 0; i < tamSai; i++) {
		printf("%d | ", vSai[i]);
  }

	printf("\nTempo de execução do filtro: %.10lfs.\n", (fim-inicio)/(double)CLOCKS_PER_SEC);

}
