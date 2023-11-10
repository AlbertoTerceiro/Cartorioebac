#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocções de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file =fopen(arquivo,"w"); // Cria o arquivo
	fprintf(file,cpf); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // Atualizar o arquivo
	fprintf(file," - "); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a"); // Atualizar o arquivo
	fprintf(file,nome); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // Atualizar o arquivo
	fprintf(file," "); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); // Atualizar o arquivo
	fprintf(file,sobrenome); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // Atualizar o arquivo
	fprintf(file," - "); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); // Atualizar o arquivo
	fprintf(file,cargo); // Salvo o valor do arquivo
	fclose(file); // Fecha o arquivo
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; // Cria o arquivo
	file =fopen(cpf,"r"); // Ler o arquivo
	
	if(file==NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa são as informações do usuário: ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
}

int main()
{
    int opcao=0;//Dedinindo variáveis 
    int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("--- Cartório da EBAC ---\n"); //Inicinado o menu
	    printf("### Seja bem-vindo ###\n\n");
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registar nomes:\n");
	    printf("\t2 - Consultar nomes:\n");
	    printf("\t3 - Deletar nomes:\n\n");
	    printf("\t4 - Sair do sistema?\n\n");
	    printf("Opção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao) //Inicio da seleção
	    {
	    	case 1:
	    	registro();
		    break;
		    
		    case 2:
			consultar();
		    break;
		    
		    case 3:
			deletar();
		    break;
		    
		    case 4:
			printf("Obrigado por utilizar o sistema! =)\n");
			return 0;
		    break;
		    
		    default:
		    printf("Essa opção não está disponivel, tente outro número!\n");
		    system("pause");
		    break;
		
		    }//Fim da seleção
	
    }
	
}


