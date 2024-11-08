#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis
	
	printf("Digite o CPF a ser cadastrado:");//coletando informacao do usuario
	scanf("%s", cpf);//refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo e o "w" significa escrever
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, ",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando informacoes do usuario
	scanf("%s", nome);//refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, ",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informacoes do usuario
	scanf("%s", sobrenome);//refere-se a string
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo
	fprintf(file, ",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");//coletando informacoes do usuario
	scanf("%s",cargo);//refere-se a string
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// cria o arquivo
	fprintf(file, ",");//salva o valor da string
	fclose(file);//fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio criacao de variaveis
	char cpf[40];
	char conteudo[200];
	//final criacao de variaveis
	
	printf("Digite o CPF a ser consultado: ");//coltando dados do usuario
	scanf("%s", cpf);//refere-se a string
	
	FILE *file;//cria o arquivo
	file = fopen(cpf,"r");//cria o arquivo
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informacoes do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];//criacao de variavel
	
	printf("Digite o CPF do usuario a ser deletado:");//coletando informacoes do usuario
	scanf("%s", cpf);//refere-se a string
	
	remove(cpf);//apaga o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema! \n");
		system ("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo as váriaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");//responsavel por limpar a tela
		
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
		printf("##### CARTÓRIO DA EBAC #####\n\n"); //inicio do menu
		printf("Escolha a opcao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("opcao: ");//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
    	system("cls");
    	
    	switch(opcao)//inicio da selecao do menu
    	{
    		case 1: 
    		registro();//chamada de funcoes
        	break;
        	
        	case 2:
        	consulta();
    		break;
    		
    		case 3:
    		deletar();
			break;
			
			default:
			printf("Esta opcao nao esta disponivel\n");
			system("pause"); //fim da selecao
		}
    }
}
