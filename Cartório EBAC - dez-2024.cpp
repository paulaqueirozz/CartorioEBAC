#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // respons�vel p�r copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, ","); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); // refere-se a strings
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file, nome); // salva o valor da vari�vel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); // refere-se a strings
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a");  //cria arquivo
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s", cargo); //refere-se a strings
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, cargo); // salva o valor da vari�vel
	fclose(file); //fecha arquivo
	
	system("pause"); //pausa para o usu�rio
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagens
	
	char cpf[40]; //caracteres - cpf
	char conteudo[200]; //caracteres - vari�veis poss�veis
	
	printf("Digite o CPF a ser consultado:  "); // consultando a informa��o salva 
	scanf("%s",cpf); // strings
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e l� 
	
	if(file == NULL) // se digitar um n�mero inexistente
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); // n�mero inexistente - n�o abre o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40]; // caracteres poss�veis do cpf
	
	printf("Digite o CPF a ser deletado: "); // inser��o do usu�rio
	scanf("%s",cpf); // strings
	
	remove(cpf); // remover o cpf
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e l�
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		return 0;
		
	}
	

	system("pause");
	return 0;
}

int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // respons�vel por limpar a tela
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagens
	
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:"); //Fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
				
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		}
	
	 //fim da sele��o
	
	}
}
