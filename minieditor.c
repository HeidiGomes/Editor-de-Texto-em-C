#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
//#include <io.h>

char cont[500];  //variável do tipo string
int op=1;
char arq;

void cabecalhomenu(); //cabecalho para o menu
void cabecalhoaa(); //cabecalho para abrir arquivo
void cabecalhoca(); //cabecalho criar arquivo
void abrirarq(); //função para abrir arquivo
void criararq();//função para criar o arquivo

int main(void){   //função principal
	char cont[500];  //variável do tipo string
	int op=1;
	char arq;

	do{
		cabecalhomenu();
		printf("Escolha uma Opcao: \n");
		printf("\n1  -   Abrir Arquivo: \n");
		printf("2  -   Criar Arquivo: \n");
		printf("3  -   Sair\n");
	
		printf("\nDigite uma Opcao: ");
		scanf("%d", &op); //lendo minha op
	
	    switch(op){
		    case 1 :
				abrirarq();
				break;
		    case 2 :
				criararq();
				break;
		    case 3 :
				printf("\n\nFinalizando...\n\n");
            	system("pause");
            	exit(0);
				break;
		    default :
				printf("\n\nOpcao invalida! Tente Novamente!\n\n");
            	system("pause");
            	break;
		}
	}while (op!=0);
 //getch();
 return 0;
}

void cabecalhomenu(){
	printf("\n-------------------------------------------\n");
	printf("             Seja Bem Vindo\n");
	printf("-------------------------------------------\n");
}

void cabecalhoaa(){
	printf("-------------------------------------------\n");
	printf("               ABRIR ARQUIVO\n");
	printf("-------------------------------------------\n");
}

void cabecalhoca(){
	printf("\n-------------------------------------------\n");
	printf("               CRIAR ARQUIVO\n");
	printf("-------------------------------------------\n");
	printf("Aviso: Adicionar o .txt ao final do nome\n");
}

void abrirarq(){
    //FILE *segpont; // segundo ponteiro para o arquivo que vai ser criado
	FILE* pont;  //cria variável ponteiro para o arquivo
        
    char arquivo[200] = {0}; // noeme do arquivo a ser aberto
    char filecontent[200] = {0}; // conteúdo do arquivo a ser aberto
        

    cabecalhoaa();
	printf("Digite o nome do arquivo:");
	scanf("%s", arquivo);
	pont = fopen(arquivo, "r"); //abrindo o arquivo_frase em modo "somente leitura"
        
    if(!pont){
	    printf("Arquivo n existe!");
	}else{
        //abrindo o arquivo com tipo de abertura r+
	    printf("\nArquivo existe\n\nO Conteudo eh: ");
		
		fgets(filecontent, 20, pont);
		printf("%s", filecontent); 
	}

	fclose(pont);
	//exit(0);
	//getchar();
}

void criararq(){
		FILE *segpont; // segundo ponteiro para o arquivo que vai ser criado
		FILE *pont;  //cria variável ponteiro para o arquivo
		
		char palavra[200] = {0};
		char conteudo[200] = {0};

		cabecalhoca();

		if(segpont == NULL){
			printf("Erro na abertura do arquivo!");

		}else{
			printf("\nDigite um nome para o arquivo: ");
			scanf("%s", palavra);
			segpont = fopen(palavra, "a");
			printf("\nDigite o conteudo: ");
			getchar();
			fgets(conteudo, 30, stdin);
			fprintf(segpont,"%s", conteudo);
			printf("\nConteudo Salvo com Sucesso!\n");
			fclose(segpont);
			//getch();
		} 
		//getch();
}

