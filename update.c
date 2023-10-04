#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct{
	char nome[50];
	int matricula;
	int idade;
	char funcao[20];
	float salario;
	char admissao[11];
}funcionario;

int menu(){
	int escolha;
	system("cls");
	printf("\n\nMENU\n");
	printf("1 - Cadastrar\n2 - Imprimir\n0 - Sair");
	printf("\n\nEscolha: ");
	scanf("%d",&escolha);
	return escolha;
}

void cadastrar(FILE *arq, char arquivo[20]){
	funcionario func;
	printf("Informe o nome do funcionario: ");
	fflush(stdin);
	gets(func.nome);
	printf("Matricula: ");
	scanf("%d",&func.matricula);
	fflush(stdin);
	printf("Data de Admissao: ");
	gets(func.admissao);
	printf("Funcao: ");
	gets(func.funcao);
	printf("Salario: ");
	scanf("%f",&func.salario);
	printf("Idade: ");
	scanf("%d",&func.idade);
	arq = fopen(arquivo,"ab");
	if(arq == NULL){
		printf("Erro na abertura do arquivo");
		exit(1);
	}
	fwrite(&func,sizeof(funcionario),1,arq);
	fclose(arq);
}

void imprimir(FILE *arq, char arquivo[20]){
	funcionario func;
	arq = fopen(arquivo,"rb");
	system("cls");
	printf("\n\nRELATORIO\n\n");
	while(fread(&func,sizeof(funcionario),1,arq) != 0){
		printf("Nome: %s		Matricula: %s\n",func.nome,func.matricula);
		printf("Idade: %d	Funcao: %s	Data de Admissao: %s\n",func.idade,func.funcao,func.admissao);
		printf("Salario: R$ %.2f",func.salario);
		printf("\n\n\n");
	}
	fclose(arq);
	system("pause");
}

int submenu(){
	int escolha;
	printf("\n\n\n1 - Pesquisa por nome \n2 - pequisa por matricula");
	scanf("%d",&escolha);
	return escolha;
}

void pesquisar(FILE *arq,char arquivo[20], int sub){
	funcionario f;
	char desejado[100];
	int mat;
	if(sub == 1){
		printf("\nDigite o nome desejado\n");
		fflush(stdin);
		gets(desejado);
	}else if(sub == 2){
		printf("\nDigite a matricula\n");
		scanf("%d",&mat);
	}
	else{
		printf("\nopção inválida\n");
	}
	arq = fopen(arquivo,"rb");
	while(fread(&f,sizeof(funcionario),1,arq) != 0){
		if(strcmp(desejado,f.nome) == 0 || mat == f.matricula){
		printf("Nome: %s		Matricula: %s\n",f.nome,f.matricula);
		printf("Idade: %d	Funcao: %s	Data de Admissao: %s\n",f.idade,f.funcao,f.admissao);
		printf("Salario: R$ %.2f",f.salario);
		printf("\n\n\n");
		system("pause");
		break;
		}
	}
	
}

int main(){
	FILE *arq;
	char arquivo[20];
	int opcao, sub;
	printf("Informe o nome do arquivo: ");
	fflush(stdin);
	gets(arquivo);
	do{
		opcao = menu();
		switch(opcao){
			case 1: cadastrar(arq,arquivo); break;
			case 2: imprimir(arq,arquivo); break;
			case 3: submenu(); pesquisar(arq, arquivo,sub); break;
			case 0: break;
			default: printf("Opcao invalida\n\n"); system("pause");
		}
	}while(opcao != 0);
	return 0;
}



