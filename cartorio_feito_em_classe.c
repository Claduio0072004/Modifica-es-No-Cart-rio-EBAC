#include <stdio.h> //biblioteca de cominca��o com o usi�rio
#include <stdlib.h> //bilioteca de aluca��o de espa�o de memoria
#include <locale.h> //bilbioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int cadastro()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40]; // definindo as strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // termindando a defini��o das strings
	
	printf("\n\n\tInsira os dados que deseja Cadastrar.\n\n\n");
	printf("\n\n   Digite o CPF para Cadastro:");
	scanf("%s",cpf); // "%s" responsavel por salvar os valores dentro das strings
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //criando arquivo no banco de dados
	file = fopen(arquivo,"w");
	fprintf(file,cpf); //salva o arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,"|");
	fclose(file);
	
	printf("\n\n   Digite o Nome para ser Cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"_");
	fclose(file);
	
	printf("\n\n   Digite o Sobrenome a ser Cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"|");
	fclose(file);
	
	printf("\n\n   Digite o Cargo que deseja Cadastrar:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("\n\n\tInsira o CPF do Usu�rio que deseja Consultar.\n\n\n");
	printf("  CPF:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\n  N�o foi encontrado o arquivo desejado\n\n");
	}
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\n\tEssas s�o as Informa��es do Usu�rio.");
		printf("\n\n  CPF|Nome_Sobrenome|Cargo:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("\n\n\tInsira o CPF do Usu�rio para Deletalo.\n\n\n");
	printf("\n\n  CPF:  ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\n\tUsu�rio N�o Encontrado!\n\n\n");
		printf("\n\n   Estamos te Encaminhando de Volta para o Menu.\n\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
	
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        
	    printf("\n\t### Cart�rio da EBAC ###\n\n"); //O come�o do menu
	    printf("   Escolha a Op��o Desejada no Menu:\n\n");
	    printf("\t1 - Registro de Usu�rios\n");
	    printf("\t2 - Consultar Usu�rio\n");
	    printf("\t3 - Deletar Usu�rio\n");
	    printf("\t4 - Sair do Sistema\n\n\n");
	    printf("  Op��o:"); //Final do menu
	    
	    scanf("%d", &opcao); //Armazenando Informa��es
	    
	    system("cls"); //Limpando a tela
	    
	    switch(opcao) //Come�o das op��es
	    {
	        case 1:
	        cadastro();
	        break;
	       
		    case 2:
	        consulta();
		    break;
		                      // switch de sele��o da opera��o desejada
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("\n\n\n\n\tObrigado por Usar o Sistema de Cart�rio EBAC!!\n\n\n");
		    return 0;
		    break;
		    
		    default:
		    printf("\n\n\tOp��o invalida tente novamente!\n\n\n");
	    	system("pause");
			break;	 	
    	} //Aparentemente o fim das op��es =)
	}
}
