#include <stdio.h> //biblioteca de comincação com o usiário
#include <stdlib.h> //bilioteca de alucação de espaço de memoria
#include <locale.h> //bilbioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int cadastro()
{
	
	int opcao=0;
	
	system("cls"); // limpando a tela
	
	
	char arquivo[40]; // definindo as strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // termindando a definição das strings
	
	printf("\n\n\tInsira os dados que deseja Cadastrar.\n\n\n");
	printf("\n\n   Digite o CPF para Cadastro:");
	scanf("%s", &cpf); // "%s" responsavel por salvar os valores dentro das strings
	
	strcpy(arquivo, cpf); 
	
	FILE *file; //Não sei se foi a melhor forma mas foi a forma que encontrei de fazer a verificação:
	file = fopen(arquivo,"r"); //Primeiro pedi para o computador pesquisar se havia algum arquivo com este CPF
	
		if(file == NULL) //Usei o IF...ELSE para deixar uma verificação se já estiver um usuário cadastrado
		{
		fclose(file); // Caso não enconte um usuário cadastrado o arquivo é fechado e depois reaberto para salvar.
		
		file = fopen(arquivo,"w"); // abrindo um novo arquivo e com o "w" escrevendo as informações dentro dele
		fprintf(file,"\n CPF: ");
		fprintf(file,cpf); //salva o arquivo
		fclose(file); // fecha o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,".\n NOME: ");
		fclose(file);
	
		printf("\n\n   Digite o Nome para ser Cadastrado:");
		scanf("%s", &nome);
	
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo,"a");
		fprintf(file,".\n SOBRENOME: ");
		fclose(file);
	
		printf("\n\n   Digite o Sobrenome a ser Cadastrado:");
		scanf("%s", &sobrenome);
	
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo,"a");
		fprintf(file,".\n CARGO: ");
		fclose(file);
	
		printf("\n\n   Digite o Cargo que deseja Cadastrar:");
		scanf("%s", &cargo);
	
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file, ".\n\n");
		fclose(file);
		
		system("cls");	//Aqui eu fiz uma limpa na tela para não haver uma quantidade muito grande de informações para o aviso que irá aparacer
		
		cadastro2(); // levando para o menu de retorno
		
		} //Aqui está o fim da verificação e claro caso não haja um usuário registrado o registro ocorre normalmente
		else //Agora caso haja um usuário registrado A mesagem seguir irá aparecer
		
		system("cls");
		
		printf("\n\n\n\t      Usuário Já Cadastrado!\n\n\n");
		printf("\n\n   Estamos te Encaminhando de Volta para o Menu.\n\n\n"); //Esta mensagem de retorno aparece em ambos os casos quando chega no fim da operação por isso achei bom limpar a tela acima
		system("pause"); 
		return 1;
}

int alterar() //achei uma boa ideia adicinar algo para alterar os dados ja cadastrados para que se o usuário tenha errado no registro ele não precise deletar e registrar novamente ou se o sobrenome da pssoa mudou também fique mais facil a alteração
{
	
	system("cls");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("\n\n\tInsira os dados para Alterar o Cadastro.\n\n\n");
	printf("\n\n   Digite o CPF:  ");
	scanf("%s", &cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; 
	file = fopen(arquivo,"r");
	
		if (file)
		{
		fclose(file);
		
		file = fopen(arquivo,"w");
		fprintf(file,"\n CPF: ");
		fprintf(file, cpf); //salva o arquivo
		fclose(file); // fecha o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,".\n NOME: ");
		fclose(file);
	
		printf("\n\n   Digite o Nome para ser Alterado:");
		scanf("%s", &nome);
	
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo,"a");
		fprintf(file,".\n SOBRENOME: ");
		fclose(file);
	
		printf("\n\n   Digite o Sobrenome a ser Alterado:");
		scanf("%s", &sobrenome);
	
		file = fopen(arquivo,"a");
		fprintf(file, sobrenome);
		fclose(file);
	
		file = fopen(arquivo,"a");
		fprintf(file,".\n CARGO: ");
		fclose(file);
	
		printf("\n\n   Digite o Cargo que deseja Alterado:");
		scanf("%s", &cargo);
	
		file = fopen(arquivo,"a");
		fprintf(file, cargo);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file, ".\n\n");
		fclose(file);
		
		printf("\n\n");
		system("pause");
		
		alterar2(); // levando para o menu de retorno
		}
		
		system("cls");
		
		if (file == NULL)
		{
			fclose(file);
			printf("\n\n\n\tO Usuário não está registrado .\n\n\n");
			printf("\n\n  Estamos te Encaminhando de Volta para o Menu.\n\n\n");
			system("pause");
			return 1;
		}
}

int consulta()
{

	system("cls");
	
	char cpf[40];
	char conteudo[200];	
	
	printf("\n\n\tInsira o CPF do Usuário que deseja Consultar.\n\n\n");
	printf("  CPF:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		fclose(file);
		printf("\n\n  Não foi encontrado o arquivo desejado.\n\n\n");
		system("pause");
		return 1;
	}
	
	system("cls");
	
	printf("\n\n\tEssas são as Informações do Usuário.\n");
	
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("%s",conteudo);
	}
	
	fclose(file);
	system("pause");
	consulta2(); // levando para o menu de retorno
	
	
}

int deletar()
{	
	int opcao=1;

	char cpf[40];
	
	system("cls");
	
	printf("\n\n\tInsira o CPF do Usuário para Deletalo.\n\n\n");
	printf("\n\n  CPF:  ");
	scanf("%s", &cpf);
			
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n\n\n\tUsuário Não Encontrado no Sistema.\n\n\n");
		printf("\n\n   Estamos te Encaminhando de Volta para o Menu.\n\n\n");
		system("pause");
		return 1;
	}
	else

	
	printf("\n\n\tTem certeza que quer Deletar o Usuário?\n");
	printf("\n\n\n  Digite 1 para deletalo ou qualquer outro caractere para voltar ao menu.");
	printf("\n\n  Digite: ");
	
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case 1:
		remove(cpf);
		deletar2(); // levando para o menu de retorno
		break;
	
		default:
		return 1;
		break;
	}
	 	
}

//Aqui em abaixo tem os ""MENUS"" de retorno para as opções que foram realizadas com sucesso fiz desta forma pois achei que não pesaria tanto no código 
// Todos os ""MENUS"" de retorno sengue a mesma logica simples mas que aparentemente bem pratica

int cadastro2()
{     int opcao=0;
     
     system("cls");
     
     setlocale(LC_ALL, "Portuguese");
	 
	 	printf("\n\n\n\tUsuário Cadastrado com Sucesso.\n\n\n");
		printf("\n\n   Deseja Cadastrar um novo Usuário?\n\n\n");
		printf("\n\n Digite 1 para Cadastrar, ou outro caractere para Voltar ao Menu:");
	
		scanf("%d", &opcao);
		
		switch (opcao)
	{
		case 1:
		cadastro();
		break;
	
		default:
		return 1;
		break;
	
	}
}

int alterar2()
{
	     int opcao=0;
     
     system("cls");
     
     setlocale(LC_ALL, "Portuguese");
	 
	 	printf("\n\n\n\tAlteração de Cadastro Concluida!!\n\n\n");
		printf("\n\n   Deseja Alterar o Cadastro de outro Usuário?\n\n\n");
		printf("\n\n Digite 1 para Alterar, ou outro caractere para Voltar ao Menu:");
	
		scanf("%d", &opcao);
		
		switch (opcao)
	{
		case 1:
		alterar();
		break;
	
		default:
		return 1;
		break;
	
	}
}

int consulta2()
{
	int opcao=0;
     
    system("cls");
    
    setlocale(LC_ALL, "Portuguese");
	 
	printf("\n\n\n\tDeseja Consultar outro Usuário?\n\n\n");
	printf("\n\n Digite 1 para Consultar, ou outro caractere para Voltar ao Menu:");
	
	scanf("%d", &opcao);
		
		switch (opcao)
	{
		case 1:
		consulta();
		break;
	
		default:
		return 1;
		break;
	
	}
}

int deletar2()
{
     int opcao=0;
     
     system("cls");
     
     setlocale(LC_ALL, "Portuguese");
	 
	 	printf("\n\n\n\tUsuário Deletado do Sistema.\n\n\n");
		printf("\n\n   Deseja Deletar outro Usuário?\n\n\n");
		printf("\n\n Digite 1 para Continuar ou outro caractere para Voltar ao Menu:");
	
		scanf("%d", &opcao);
		
		switch (opcao)
	{
		case 1:
		deletar();
		break;
	
		default:
		return 1;
		break;
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int x=1;
	
	char senha[20] ="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\n\t### Cartório da EBAC ###\n\n");
	printf("\n\tLogin de Administrador\n\n\n");
	printf("  Digite sua Senha:");
	scanf("%s",senha);
	
	comparacao = strcmp(senha, "admin");
	
	if (comparacao == 0)
	{
		for(x=1;x=1;)
		{
		
			system("cls");
	
    	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        
		    printf("\n\t### Cartório da EBAC ###\n\n"); //O começo do menu
		    printf("   Escolha a Opção Desejada no Menu:\n\n");
	    	printf("\t1 - Registro de Usuários.\n");
		    printf("\t2 - Alterar dados do Usuário.\n");
		    printf("\t3 - Consultar Usuário.\n");
		    printf("\t4 - Deletar Usuário.\n");
		    printf("\t5 - Deslogar do Sistema\n");
		    printf("\t6 - Sair do Sistema.\n\n\n");
		    printf("  Opção:"); //Final do menu
	    
		    scanf("%d", &opcao); //Armazenando Informações
	    
		    system("cls"); //Limpando a tela
	    
		    switch(opcao) //Começo das opções
		    {
		        case 1:
		        cadastro();
		        break;
	        
		        case 2:
		        alterar();
			    break;
	    				    // switch de seleção da operação desejada
			    case 3:
		        consulta();
			    break;
		
			    case 4:
			    deletar();
			    break;
			    
			    case 5:
			    main();
			    break;
			    
			    case 6:
			    printf("\n\n\n\n\tObrigado por Usar o Sistema de Cartório EBAC!!\n\n\n");
			    return 0;
			    break;
		    
			    default:
		   	 	printf("\n\n\n\n\tOpção invalida tente novamente!\n\n\n");
	    		system("pause");
				break;	 	
    		} //Aparentemente o fim das opções =)
		}
	}
	else
	
	printf("\n\n\n\tSenha de Administrador Incorreta!!\n\n\n");	
	
}
