#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char nome[150];
	int matricula[13];
	int idade[3];
	char funcao[130];
	int salario[13];
	char data[10];
}workers;

void cadastrar(){
	printf("");
	gets(workers.nome);
	printf("");
	scanf("");
	fflush(stdin);
	printf("");
	scanf("");
	fflush(stdin);
	printf("");
	gets(workers.funcao);
	printf("");
	scanf("");
	fflush(stdin);
	printf("");
	gets(workers.data);
}

void imprimir(){
	
}

void sair(){
	FILE *arch;
	arch = fopen("arquivo.txt","w");
	fclose(arch);
}

int main(){
	setlocale(LC_ALL,"portuguese");
	
	FILE *arch;
	arch = fopen("arquivo.txt","w");
	
	char texto[100];
	gets(texto);
	fprintf(arch,texto);
	return 0;
}
