#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

typedef struct{
	char nome[150];//300 bytes
	int matricula[13];//26 bytes
	char cargo[70];//140 bytes
	float salario[13];//26 bytes
	char data[13];//26 bytes
	int idade[3];//6 bytes
}funcionario;

int menu(){
	system("cls");
	int escolha;
	printf("\nMENU\n\n1 - cadastrar \n2 - imprimir\n0 - sair");
	printf("\nEscolha: \n");
	scanf("%d",&escolha);
	return(escolha);
}

void cadastrar(FILE *arq, char arquivo[20]){
	funcionario f;
	
	printf("\nnome\n");
	fflush(stdin);
	gets(f.nome);
	
	printf("\nmatricula\n");
	scanf("%d",&f.matricula);
	
	printf("\nsalario\n");
	scanf("%f",&f.salario);
	
	printf("\ncargo\n");
	fflush(stdin);
	gets(f.cargo);

	printf("idade");
	scanf("%d",&f.idade);

	printf("data de adimissão");
	fflush(stdin);
	gets(f.data);

	arq = fopen(arquivo,"ab");
	
	if(arq == NULL){
		printf("O arquivo não existe");
		exit(1);
	}
	fwrite(&f,sizeof(funcionario),1,arq);
	fclose(arq);
}

void imprimir(FILE *arq, char arquivo[20]){
	 funcionario f;
	 arq = fopen(arquivo,"rb");
	 
	 while(fread(&f,sizeof(funcionario),1,arq) != 0){
	 	printf("\nNome: %s		Matricula: %d",f.nome,f.matricula);
	 	printf("\nCargo: %s		salario: R$:%.2f	data %s",f.cargo,f.salario,f.data);
	 	printf("\n%d anos de idade",f.idade);
	 	printf("\n------------------------------------------------------------------------\n");
	 }
	 fclose(arq);
}

int main(){
	
	return 0;
}
