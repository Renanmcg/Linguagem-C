#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIVROS "livros.dat"
#define CLIENTES "clientes.dat"
#define VENDAS "vendas.dat"
#define RELATORIO "relatório detalhado.dat"

struct reg_livro{
  int codigo;
  char titulo[30];
  float preco;
  int estoque;
};

struct reg_cliente{
  int codigo;
  char nome[50];
  char fone[15];
  char email[30];
};

struct reg_venda{
  int codvenda;
  int codcliente; //Código do Cliente que comprou
  int codlivro; //Código do Livro vendido
  int qtde; //Qtde vendida
};

struct reg_fechado{
  int codigoVenda;
  int codigoCliente;
  char nome[50];
  int codigoLivro;
  char titulo[30];
  float preco;
  int qtde; 
  float total;
};

void strUpper(char s[]){
  int i;

  for (i=0; i<strlen(s); i++){
    s[i] = toupper(s[i]);
  }

}//Fim strUpper()

void cadastrarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  char opc;

  //Entrada dos dados do Livro
  printf("\nCodigo: ");
  fflush(stdin); scanf("%i",&livro.codigo);
  printf("Titulo: ");
  fflush(stdin); gets(livro.titulo);
  printf("Preco: ");
  fflush(stdin); scanf("%f",&livro.preco);
  printf("Estoque: ");
  fflush(stdin); scanf("%d",&livro.estoque);
  //Pedir Confirmação
  printf("\nGravar?(S/N): ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc == 'N')||(opc == 'n')){
    printf("\nOperacao Cancelada!");
    return;
  }

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"ab");

  //Gravar no Arquivo
  fwrite(&livro,sizeof(livro),1,fplivro);

  printf("\nLivro cadastrado com Sucesso.");

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim cadastrarLivro()

void cadastrarCliente(){
  FILE *fpcliente;
  struct reg_cliente cliente;
  char opc;

  //Entrada dos dados do Cliente
  printf("\nCodigo: ");
  fflush(stdin); scanf("%i",&cliente.codigo);
  printf("Nome: ");
  fflush(stdin); gets(cliente.nome);
  printf("Fone: ");
  fflush(stdin); gets(cliente.fone);
  printf("Email: ");
  fflush(stdin); gets(cliente.email);

  //Pedir Confirmação
  printf("\nGravar?(S/N): ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc == 'N')||(opc == 'n')){
    printf("\nOperacao Cancelada!");
    return;
  }

  //Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"ab");

  //Gravar no Arquivo
  fwrite(&cliente,sizeof(cliente),1,fpcliente);

  printf("\nCliente cadastrado com Sucesso.");

  //Fechar o Arquivo
  fclose(fpcliente);
}

void listarLivros(){
 FILE *fplivro;
 struct reg_livro livro;

 //Abrir o Arquivo de Livros
 fplivro = fopen(LIVROS,"rb");

 printf("\n - - - Livraria Tec Info - - - ");
 printf("\n    Relatorio de todos Livros\n");

 //Ler struct por struct e mostrar dados na tela
 while (fread(&livro,sizeof(livro),1,fplivro)==1){
    printf("\nCodigo: %i",livro.codigo);
    printf("\nTitulo: %s",livro.titulo);
    printf("\nPreco: %5.2f", livro.preco);
    printf("\nEstoque: %d", livro.estoque);
    printf("\n---------------------------------------------");
 }

 //Fechar o Arquivo
 fclose(fplivro);

}//Fim listarLivros()

void listarClientes(){
 FILE *fpcliente;
 struct reg_cliente cliente;

 //Abrir o Arquivo de Livros
 fpcliente = fopen(CLIENTES,"rb");

 printf("\n - - - Livraria Tec Info - - - ");
 printf("\n    Relatorio de todos clienteS\n");

 //Ler struct por struct e mostrar dados na tela
 while (fread(&cliente,sizeof(cliente),1,fpcliente)==1){
    printf("\nCodigo: %i",cliente.codigo);
    printf("\nNome: %s",cliente.nome);
    printf("\nFone: %s",cliente.fone);
    printf("\nEmail: %s",cliente.email);
    printf("\n---------------------------------------------");
 }

 //Fechar o Arquivo
 fclose(fpcliente);

}//Fim listarClientes()

void consultarLivroCodigo(){
  FILE *fplivro;
  struct reg_livro livro;
  int codprocurado,achou=0;

  //Solicitar o codigo do Livro a ser Localizado
  printf("\nDigite o Codigo do Livro a ser Localizado: ");
  fflush(stdin); scanf("%i",&codprocurado);

  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
        printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;
  }

  //Ler struct por struct e comparar o codigo do Livro
   while ((!achou)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
        //printf("\nEntrou");
        if (livro.codigo==codprocurado){
            printf("\nCodigo: %i",livro.codigo);
            printf("\nTitulo: %s",livro.titulo);
            printf("\nPreco: %5.2f", livro.preco);
            printf("\nEstoque: %d", livro.estoque);
            achou=1;
        }
   }

   if (!achou){
      printf("\nLivro NAO Localizado!");
   }

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarLivroCodigo()

void consultarLivroTitulo(){
  FILE *fplivro;
  struct reg_livro livro;
  int achou=0;
  char tituloprocurado[30];

  //Solicitar o Título do Livro a ser Localizado
  printf("\nDigite o Titulo do Livro a ser Localizado: ");
  fflush(stdin); gets(tituloprocurado);

  strUpper(tituloprocurado);
  printf("\nTitulo Procurado: %s",tituloprocurado);

  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
        printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;
  }

  //Ler struct por struct e comparar o codigo do Livro
   while ((!achou)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
        //printf("\nEntrou");
        strUpper(livro.titulo);
        if (strcmp(livro.titulo,tituloprocurado)==0){
            printf("\nCodigo: %i",livro.codigo);
            printf("\nTitulo: %s",livro.titulo);
            printf("\nPreco: %5.2f", livro.preco);
            printf("\nEstoque: %d", livro.estoque);
            achou=1;
        }
   }

   if (!achou){
      printf("\nNenhum Livro Localizado com o titulo: %s",tituloprocurado);
   }

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarLivroTitulo()

void consultarLivroPlvChTitulo(){
  FILE *fplivro;
  struct reg_livro livro;
  int achou=0;
  char palavra[30];

  //Solicitar a Palavra Chave a ser Localizada
  printf("\nDigite a Palavra Chave a ser Localizada: ");
  fflush(stdin); gets(palavra);

  strUpper(palavra);
  printf("\nTitulo Procurado: %s",palavra);

  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
        printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;
  }

  printf("\nCodigo Titulo                         Preco");
  //Ler struct por struct e comparar o codigo do Livro
   while (fread(&livro,sizeof(livro),1,fplivro)==1){
        //printf("\nEntrou");
        strUpper(livro.titulo);
        if (strstr(livro.titulo,palavra)!=NULL){
            printf("\n%-6i %-30s %5.2f %-6d",livro.codigo,livro.titulo, livro.preco, livro.estoque);
            achou=1;
        }
   }

   if (!achou){
      printf("\nNenhum Livro Localizado com a Palavra %s no titulo: ",palavra);
   }

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarLivroPlvChTitulo()

void alterarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  int codprocurado,achou=0;
  char opc;

  //Solicitar o codigo do Livro que será alterado
  printf("\nDigite o Codigo do Livro a ser alterado: ");
  fflush(stdin); scanf("%i",&codprocurado);

  //Localizar e exibir os dados atuais do Livro
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb+"))==NULL){
        printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;
  }

  //Ler struct por struct e comparar o codigo do Livro
   while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
        //printf("\nEntrou");
        if (livro.codigo==codprocurado){
            printf("\nCodigo: %i",livro.codigo);
            printf("\nTitulo: %s",livro.titulo);
            printf("\nPreco: %5.2f", livro.preco);
            printf("\nEstoque: %d", livro.estoque);
            achou=1;
        }
   }

   if (achou==0){
      printf("\nLivro NAO Localizado!");
      fclose(fplivro);
      return; //Volta para o programa principal
   }
   //Livro encontrado, pede confirmacao
   printf("\nConfirma Livro?(S/N) ");
   fflush(stdin); scanf("%c",&opc);
   if ((opc=='N')||(opc=='n')){
      fclose(fplivro);
      return; //Volta para o programa principal
   }

  //Solicitar novos dados (Título, Preço)
   printf("\nDeseja alterar o Titulo?(S/N) ");
   fflush(stdin); scanf("%c",&opc);
   if ((opc=='S')||(opc=='s')){
      printf("\nDigite o novo Titulo: ");
      fflush(stdin); gets(livro.titulo);
   }
   printf("\nDeseja alterar o Preco?(S/N) ");
   fflush(stdin); scanf("%c",&opc);
   if ((opc=='S')||(opc=='s')){
      printf("\nDigite o novo Preco: ");
      fflush(stdin); scanf("%f", &livro.preco);
   }
    printf("\nDeseja alterar o estoque?(S/N) ");
   fflush(stdin); scanf("%c",&opc);
   if ((opc=='S')||(opc=='s')){
      printf("\nDigite o novo estoque: ");
      fflush(stdin); scanf("%f", &livro.estoque);
   }

   printf("\nSalvar Novos Dados?(S/N) ");
   fflush(stdin); scanf("%c",&opc);
   if ((opc=='N')||(opc=='n')){
      printf("\nOperacao Cancelada!!");
      fclose(fplivro);
      return; //Volta para o programa principal
   }

  //Voltar o ponteiro do Arquivo para o registro anterior
  // que será alterado
  fseek(fplivro,-sizeof(livro),SEEK_CUR);

  //Salvar novo registro no arquivo
  fwrite(&livro,sizeof(livro),1,fplivro);

  printf("\nDados gravados com Sucesso.");

  //Fechar o Arquivo
  fclose(fplivro);
}//Fim alterarLivro()

void excluirLivro(){
  FILE *fplivro, *fplivrosnew;
  struct reg_livro livro;
  int codprocurado,achou=0;
  char opc;

  //Solicitar o codigo do Livro que será excluído
  printf("\nDigite o Codigo do Livro a ser excluido: ");
  fflush(stdin); scanf("%i",&codprocurado);

  //Localizar e exibir os dados atuais do Livro
  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
        printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;
  }

  //Ler struct por struct e comparar o codigo do Livro
   while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
        //printf("\nEntrou");
        if (livro.codigo==codprocurado){
            printf("\nCodigo: %i",livro.codigo);
            printf("\nTitulo: %s",livro.titulo);
            printf("\nPreco: %5.2f", livro.preco);
            printf("\nEstoque: %d", livro.estoque);
            achou=1;
        }
   }
   fclose(fplivro);

   if (achou==0){
      printf("\nLivro NAO Localizado!");
      return; //Volta para o programa principal
   }
   //Livro encontrado, pede confirmacao
   printf("\nConfirma Exclusao?(S/N) ");
   fflush(stdin); scanf("%c",&opc);
   if ((opc=='N')||(opc=='n')){
      printf("\nOperacao Cancelada!!");
      return; //Volta para o programa principal
   }

   //Confirmou exclusão
   fplivro = fopen(LIVROS,"rb");
   fplivrosnew = fopen("livrosnew.dat","wb");
   while (fread(&livro,sizeof(livro),1,fplivro)==1){
        if (livro.codigo!=codprocurado){
            fwrite(&livro,sizeof(livro),1,fplivrosnew);
        }
   }
   fclose(fplivro);
   fclose(fplivrosnew);
   system("del livros.dat");  //Exclui o arquivo antigo
   system("ren livrosnew.dat livros.dat"); //Renomeia o novo arquivo

   printf("\nExclusao realizada com Sucesso.");
}//Fim excluirLivro()

struct reg_cliente localizarCliente(int codcli){
  FILE *fpcliente;
  struct reg_cliente cliente;
  int achou=0;

  fpcliente = fopen(CLIENTES,"rb");
  achou = 0;
  while ((achou==0)&&(fread(&cliente,sizeof(cliente),1,fpcliente)==1)){
        if (cliente.codigo==codcli){
            achou=1;
        }
  }
  fclose(fpcliente);

  if (achou==0){ //Cliente NAO localizado
    cliente.codigo = -1; //Sinalizo que o cliente NÃO foi localizado
  }

  return cliente;

}//Fim localizarCliente()

struct reg_livro localizarLivro(int codliv){
  FILE *fplivro;
  struct reg_livro livro;
  int achou=0;

  //Abrir o Arquivo
  if ((fplivro = fopen(LIVROS,"rb"))==NULL){
        printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;
  }

  //Ler struct por struct e comparar o codigo do Livro
   achou=0;
   while ((!achou)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
        if (livro.codigo==codliv){
            achou=1;
        }
   }
   fclose(fplivro);

   if (achou==0){
      livro.codigo=-1; //Sinaliza que o Livro NAO foi localizado
   }

   return livro;

} //Fim localizarLivro()

void efetuarVenda(){
  FILE *fplivro, *fpcliente, *fpvenda;
  struct reg_livro livro;
  struct reg_cliente cliente;
  struct reg_venda venda;
  char opc;
  int achou, codvenda, codcli, codliv;

  printf("\nDigite o Codigo da Venda: ");
  fflush(stdin); scanf("%i",&codvenda);

  //Solicitar o codigo do Cliente
  printf("\nDigite o codigo do cliente: ");
  fflush(stdin); scanf("%i",&codcli);

  cliente = localizarCliente(codcli);
  if (cliente.codigo==-1){ //Cliente NÃO foi localizado
    printf("\nCliente NÃO Localizado!");
    return; //Retorna para o Menu Principal
  }else{
    printf("\nCliente: %s",cliente.nome);
  }

  printf("\nConfirma Cliente?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc=='N')||(opc=='n')){
    printf("\nCliente NAO Confirmado!!");
    return;
  }

  do {

      //Solicitar o Codigo do Livro
      printf("\nDigite o Codigo do Livro: ");
      fflush(stdin); scanf("%i",&codliv);

      livro = localizarLivro(codliv);

      if (livro.codigo!=-1){
          printf("\nTitulo: %s - Preco: %5.2f",livro.titulo,livro.preco);
          printf("\nConfirma Livro?(S/N) ");
          fflush(stdin); scanf("%c",&opc);
          if (livro.estoque > 0){
            if ((opc=='s')||(opc=='S')){
            //Salvar a venda
            printf("\nGravar Venda deste item?(S/N) ");
            fflush(stdin); scanf("%c",&opc);
             if ((opc=='s')||(opc=='S')){
                printf("\nDigite a Quantidade: ");
                fflush(stdin); scanf("%i",&venda.qtde);
                
				livro.estoque -= venda.qtde;
				
                venda.codvenda = codvenda;
                venda.codlivro = livro.codigo;
                venda.codcliente = cliente.codigo;

                fpvenda = fopen(VENDAS,"ab");
                fwrite(&venda,sizeof(venda),1,fpvenda);
                fclose(fpvenda);
                printf("\nItem da venda gravado.");
            }else{
                printf("\nItem Cancelado!");
            }
           }else{
                printf("\nLivro NAO Confirmado!!");
          }
		  }else{
              printf("\nNão há exemplares desse livro no estoque.");
              }
        }
        else{
            printf("\nLivro NAO Localizado!");
        }

        printf("\nDeseja inserir outro item nesta venda?(S/N)");
        fflush(stdin); scanf("%c",&opc);

    }while ((opc=='s')||(opc=='S'));

}//Fim efetuarVenda()

void listarVendas(){
  FILE *fpvenda;
  FILE *fplivro;
  FILE *fpcliente;
  FILE *fplistavendas;
  struct reg_venda venda;
  struct reg_livro livro;
  struct reg_cliente cliente;
  float total=0, preco=0;
  int qtde;

 
  
  if ((fpvenda = fopen(VENDAS,"rb"))==NULL){
		printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;  
    }
        
  printf("\n                               - - - Livraria Tec Info - - -\n ");
  printf("\n                                     Lista de Vendas\n");
  printf("---------------------------------------------------------------------------------------------------------");
  
  while (fread(&venda,sizeof(venda),1,fpvenda)==1){
 	
  			livro = localizarLivro(venda.codlivro);
			cliente = localizarCliente(venda.codcliente);
			printf("\nPedido nº: %d\n", venda.codvenda);
			printf("\nCliente: %s\n",cliente.nome);		
			total = livro.preco * venda.qtde;
			printf("\n   Codigo  Titulo                         Preco      Qtde    Estoque \n");
			printf("  %4i    %-30s  %5.2f       %d      %d\n", livro.codigo, livro.titulo, livro.preco, venda.qtde, livro.estoque );
			printf("\n    Total: %5.2f\n", total);
			printf("---------------------------------------------------------------------------------------------------------");

			}	
				
  fclose(fpvenda);

}//Fim listarVendas()

void listarLivrosTXT(){
  FILE *fplivro, *fpreltxt;
  struct reg_livro livro;
  char linha[100];

  fplivro = fopen(LIVROS,"rb");
  fpreltxt = fopen("RelLivros.txt","w");

  fputs("\n        * * *  Livraria Tech Info  * * *\n",fpreltxt);
  fputs("            RELATORIO DE TODOS OS LIVROS\n",fpreltxt);
  fputs("\nCodigo Titulo                          Preco   Estoque\n",fpreltxt);

  while (fread(&livro,sizeof(livro),1,fplivro)==1){
    sprintf(linha,"%4i    %-30s  %5.2f    %d\n",livro.codigo,livro.titulo,livro.preco, livro.estoque);
    fputs(linha,fpreltxt);
  }

  fclose(fplivro);
  fclose(fpreltxt);

  printf("\nRelatorio de Livros gerado em RelLivros.txt\n");

}//Fim listarLivrosTXT()

void fecharPedido(){
  FILE *fpvenda;
  FILE *fplivro;
  FILE *fpcliente;
  struct reg_venda venda;
  struct reg_livro livro;
  struct reg_cliente cliente;
  int codigo, qtde;
  float total=0, preco;

  
  
  printf("\n - - - Livraria Tec Info - - - ");
  
  printf("\n    Digite o código da venda:\n");
  fflush(stdin); scanf("%d",&codigo);
  
  if ((fpvenda = fopen(VENDAS,"rb"))==NULL){
		printf("\nErro ao abrir arquivo %s\n",LIVROS);
        return;  
    }
        
    
  while (fread(&venda,sizeof(venda),1,fpvenda)==1){
        
        	
        	/*if ((fplivro = fopen(LIVROS,"rb"))==NULL){
        		printf("\nErro ao abrir arquivo %s\n",LIVROS);
        		return;
        	}
		    while ((achou1=0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){			
		    	if(venda.codlivro==livro.codigo){
		    		strcpy(fechado.titulo, livro.titulo);
		    		fechado.preco = livro.preco;
		    		achou1=1;
				}
			}
			if ((fpcliente = fopen(CLIENTES,"rb"))==NULL){
        		printf("\nErro ao abrir arquivo %s\n",LIVROS);
        		return;
            }
		    while ((achou2=0)&&(fread(&cliente,sizeof(cliente),1,fpcliente)==1)){
			   	if(venda.codcliente==cliente.codigo){
			   		strcpy(fechado.nome, cliente.nome);
		    		achou2=1;
				}
        	}*/
        if(venda.codvenda==codigo){	
        	localizarCliente(venda.codcliente);
        	localizarLivro(venda.codlivro);
        	
        	/*fechado.qtde = venda.qtde;
        	strcpy(fechado.titulo, livro.titulo);
        	fechado.preco = livro.preco;
        	strcpy(fechado.nome, cliente.nome);*/
        	 fflush(stdout);
			total = preco * qtde;
			printf("\n    Relatorio da Venda\n");
			printf("\n   Cliente: %s\n", cliente.nome);
			printf("\n   Codigo do produto: %d\n", venda.codvenda);
			printf("\n   Titulo: %s\n", livro.titulo);
			printf("\n   Quantidade: %i\n", venda.qtde);
			printf("\n   Preco do exemplar: %f\n", livro.preco);
			printf("\n   Total do item: %f\n", total);
			printf("\n   Total: %f\n", total);
		}

		/*printf("\n    Relatorio da Venda\n");
		printf("\n   Cliente: %s\n", fechado.nome);
		printf("\n   Codigo do produto: %d\n", fechado.codigoVenda);
		printf("\n   Titulo: %s\n", fechado.titulo);
		printf("\n   Quantidade: %i\n", fechado.qtde);
		printf("\n   Preco do exemplar: %f\n", fechado.preco);
		printf("\n   Total do item: %f\n", fechado.total);*/
	}


		  
  fclose(fpvenda);

}//Fim fecharPedido()

void estoqueMinimo(){
	
	int minimo=0;
	FILE *fplivro, *fpreltxt;
	struct reg_livro livro;
	char linha[100];
	
	fplivro = fopen(LIVROS, "rb");
	fpreltxt = fopen("relEstoqueBaixo.txt", "w");
	
	printf("Indique o estoque minimo: ");
	fflush(stdin); scanf("%d",&minimo);

	fputs("\n             - - - Livraria Tec Info - - - \n", fpreltxt);
	fputs("\n              Relatorio de Estoque Baixo\n", fpreltxt);
	fputs("\nCodigo Titulo                          Preco   Estoque\n",fpreltxt);
	
	while(fread(&livro, sizeof(livro), 1, fplivro)==1){
		if (livro.estoque<=minimo){
					sprintf(linha,"%4i    %-30s  %5.2f    %d\n", livro.codigo, livro.titulo, livro.preco, livro.estoque);
					fputs(linha, fpreltxt);	
		}
	}
	fclose(fplivro);
	fclose(fpreltxt);
	printf("Relatorio de livros gerado em Reltxt.");
	
}//Fim estoqueMinimo

main(){
  int op;

  do {
    printf("\n\n###### - Livraria Tec Info - ######");
    printf("\n# 1) Cadastrar Livro              #");
    printf("\n# 111) Cadastrar Cliente          #");
    printf("\n# 2) Listar todos os Livros       #");
    printf("\n# 222) Listar todos os Clientes   #");
    printf("\n# 3) Consultar Livro pelo Codigo  #");
    printf("\n# 4) Consultar Livro pelo Titulo  #");
    printf("\n# 5) Consultar Livro por Palavra Chave no Titulo");
    printf("\n# 6) Alterar dados do Livro       #");
    printf("\n# 7) Excluir Livro (exclusao Fisica)#");
    printf("\n# 8) Evetuar Venda                #");
    printf("\n# 9) Listar Vendas                #");
    printf("\n# 10) Relatorio Livros em TXT     #");
    printf("\n# 11) Fechar Pedido               #");
    printf("\n# 12) Estoque Minimo             #");
    printf("\n# 0) Sair                         #");
    printf("\n\n Opcao -> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
    case 1: //Cadastro de Livro
        printf("\nCadastro de Livro:\n");
        cadastrarLivro();
        break;
    case 111: //Cadastro de Cliente
        printf("\nCadastro de Cliente:\n");
        cadastrarCliente();
        break;

    case 2: //Relatorio de todos os Livros
        listarLivros();
        break;

    case 222: //Relatorio de todos os Clientes
        listarClientes();
        break;

    case 3: //Consultar Livro Pelo Codigo
        consultarLivroCodigo();
        break;
    case 4: //Consultar Livro Pelo Titulo
        consultarLivroTitulo();
        break;
    case 5: //Consultar Livro Por Palavra Chave no Titulo
        consultarLivroPlvChTitulo();
        break;
    case 6: //Alterar dados de um Livro
        alterarLivro();
        break;
    case 7: //Exclusão Física do Arquivo
        excluirLivro();
        break;
    case 8: //Efetuar venda
        efetuarVenda();
        break;

    case 9:  //Listar Vendas
        listarVendas();
        break;

    case 10: //Relatorio de todos os livros em TXT
        listarLivrosTXT();
        break;
    case 11: //Fechar Pedido
        fecharPedido();
        break;
    case 12: //Estabelecer estoque mínimo
        estoqueMinimo();
        break;
    }

  }while (op!=0);

}//Fim main
