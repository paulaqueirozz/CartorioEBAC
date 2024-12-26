#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	// início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); // responsável pór copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, ","); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); // refere-se a strings
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file, nome); // salva o valor da variável
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, ","); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); // refere-se a strings
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a");  //cria arquivo
	fprintf(file, ","); //salva o valor da variável
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", cargo); //refere-se a strings
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, cargo); // salva o valor da variável
	fclose(file); //fecha arquivo
	
	system("pause"); //pausa para o usuário
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagens
	
	char cpf[40]; //caracteres - cpf
	char conteudo[200]; //caracteres - variáveis possíveis
	
	printf("Digite o CPF a ser consultado:  "); // consultando a informação salva 
	scanf("%s",cpf); // strings
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e lê 
	
	if(file == NULL) // se digitar um número inexistente
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); // número inexistente - não abre o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40]; // caracteres possíveis do cpf
	
	printf("Digite o CPF a ser deletado: "); // inserção do usuário
	scanf("%s",cpf); // strings
	
	remove(cpf); // remover o cpf
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e lê
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		return 0;
		
	}
	

	system("pause");
	return 0;
}

int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); // responsável por limpar a tela
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagens
	
		printf("### Cartório da EBAC ###\n\n"); // Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:"); //Fim do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
				
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			
		}
	
	 //fim da seleção
	
	}
}
