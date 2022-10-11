#include <stdio.h>
#include <string.h>
#include "tabelaHash.h"
#include "arvore.h"

int main(void) {
  FILE *arq, *password, *chave, *encodedPassword;
  char aux;
  char Pass[1000];
  char caracteres[32];
  int i = 0;
  
   //abrindo o arquivo com os caracteres permitidos
   arq = fopen("caracteres.txt", "r");
   //armazenando os caracteres em um vetor

   if(arq == NULL) {
     printf("Problemas com arquivos!\n");
     return 0;
   }

   while (!feof(arq))
   {
     char aux;
     fscanf(arq, "%c", &aux);
     caracteres[i] = aux;
     i++;
   }

   fclose(arq);

   //Abrindo o arquivo para registrar a SENHA
   password = fopen("senha.txt", "w");

   if (password == NULL)  // Se houve erro na abertura
   {
      printf("Problemas com arquivos!\n");
      return 0;
   }

   //Inserindo a senha
   printf("\nDigite a sua mensagem de acordo com os caracteres abaixo:\n\n");

   printf("\t");
   for(int i=0;i<32;i++){
     printf("%c", caracteres[i]);
   }
   printf("\n\n");
   printf("Mensagem: ");
   fgets(Pass, 1000, stdin);

  // Verificando se os caracteres sao validos
   for(int i = 0; Pass[i] != '\n'; i++){
     int w = 0;
     for(int j=0;j<32;j++) {
       if(Pass[i] == caracteres[j]) {
         w = 1;
         break;
       }   
     }
     if(w == 0){
         printf("Caractere(s) inválido(s)!\n");
         return 0;
       }
   }
   //inserindo a senha nao codificada no arquivo senha.txt
   int operationWorked = fputs(Pass, password);  
   if(operationWorked){ // se adicionou
     printf("Mensagem armazenada com sucesso!\n");
   } else {
     printf("Erro ao armazenar a senha!\n");
     return 0;
   }
   // fechando o arquivo
   fclose(password);

   // Criando tabela hash 
   Hash *ha = criar_hash(32);
   for(int i = 0; Pass[i] != '\n'; i++){
     inserir_endAberto(ha, Pass[i]);
   }
  
   mostrar_tabela(ha);
  
   // Abrindo o arquivo para registrar a Tabela hash preenchida
   chave = fopen("chave.txt", "w");
   if (chave == NULL)   // Se houve erro na abertura
   {
      printf("Problemas com arquivos!\n");
      return 0;
   }

   // consultando caracteres e armazenando os seus codigos no arquivo chave.txt
   int tamanhoString = strlen(Pass);
   for(int i = 0;i<tamanhoString-1;i++) {
     DADOS aux;
     buscar_hash_endAberto(ha, Pass[i], &aux);
     fprintf(chave, "'%c','", aux.character);
     for(int o = 0;o<5;o++){
       fprintf(chave, "%d", aux.codigo[o]);
     }
     fprintf(chave, "',");
   }
   fclose(chave);


   // Abrindo o arquivo para registrar a senha codificada
   encodedPassword = fopen("senhacodificada.txt", "w");
   if (encodedPassword == NULL)   // Se houve erro na abertura
   {
      printf("Problemas com arquivos!\n");
      return 0;
   }

   //buscando os caracteres e armazenando os seus respectivos codigos no arquivo senhacodificada.txt
   for(int i = 0;Pass[i]!= '\n';i++) {
     DADOS aux;
     buscar_hash_endAberto(ha, Pass[i], &aux);
     for(int o = 0;o<5;o++){
       fprintf(encodedPassword, "%d", aux.codigo[o]);
     }
   }
   fclose(encodedPassword);


  destruir_hash(ha);
  //Comeca a TERCEIRA PARTE

  char hash[400];

    arq = fopen("chave.txt","r");
    if(arq!=NULL) fgets(hash,400,arq),fclose(arq);
    else return printf("Erro ao ler o arquivo!\n"),1;

    //criando arvore
    Arvore *arv = criar_arvore();
    for(int i=0;i<strlen(hash);i+=12){
        char c = hash[i+1],pos[6];
        sprintf(pos,"%c%c%c%c%c",hash[i+5],hash[i+6],hash[i+7],hash[i+8],hash[i+9]);
        inserir_elemento(arv,c,pos);
    }


    //salvando a leitura em pre-ordem da arvore no arquivo preordem.txt
    char *preOrdem = getPre(arv);
    arq=fopen("preordem.txt","w");
    if(arq!=NULL) fputs(preOrdem,arq),fclose(arq);
    else return printf("Erro ao salvar o arquivo!\n"),1;


    //Comeca a QUARTA PARTE
    //lendo a pre-ordem que foi recebida
    char ordem[400];
    arq = fopen("preordem.txt","r");
    if(arq!=NULL) fgets(ordem,400,arq),fclose(arq);
    else return printf("Erro ao ler o arquivo!\n"),1;


    //reconstruindo arvore a partir da pre-ordem lida
    int pos=0;
    char elem[6]="",ant[6]="",aux2[6]="";
    Arvore* arv2 = criar_arvore();
    for(int i=2;i<strlen(ordem);i+=2){
        if(ordem[i]!='0' && ordem[i]!='1'){
            if(strlen(elem)<4){
                strncpy(aux2,ant,(4-(int)strlen(elem)));
                aux2[(4-(int)strlen(elem))]='\0';
                strcat(aux2,elem);
                strcpy(elem,aux2);
            }
            if(i+2 < strlen(ordem) && ordem[i+2]!='0' && ordem[i+2]!='1'){
                elem[4]='0';
                char c = ordem[i];
                i+=2;
                inserir_elemento(arv2,c,elem);
                c = ordem[i];
                elem[4]='1';
                inserir_elemento(arv2,c,elem);
            }
            else{
                elem[4]='0';
                char c = ordem[i];
                inserir_elemento(arv2,c,elem);
                elem[4]='1';
                inserir_elemento(arv2,c,elem);
            }
            strcpy(ant,elem);
            pos=0;
            elem[0]='\0';
        }
        else elem[pos++]=ordem[i],elem[pos]='\0';
    }

    //lendo o arquivo senhacodificada.txt
    char senhacodificada[400];
    arq = fopen("senhacodificada.txt","r");
    if(arq!=NULL) fgets(senhacodificada,400,arq),fclose(arq);
    else return printf("Erro ao ler o arquivo!\n"),1;

    char senhadecodificada[400]="";
    pos=0;

    //decodificando a senha
    for(int i=0;i<strlen(senhacodificada);i+=5){
        char ch[6];
        sprintf(ch,"%c%c%c%c%c",senhacodificada[i],senhacodificada[i+1],senhacodificada[i+2],senhacodificada[i+3],senhacodificada[i+4]);
        char append = buscar_elemento(arv2,ch);
        senhadecodificada[pos++]=append;
    }

    //armazenando a senha decodificada no arquivo senhadecodificada.txt
    arq=fopen("senhadecodificada.txt","w");
    if(arq!=NULL) fputs(senhadecodificada,arq),fclose(arq);
    else return printf("Erro ao salvar o arquivo!\n"),1;
    //destruindo arvores
    destruir_arvore(arv);
    destruir_arvore(arv2);

    printf("\nMensagem decodificada! Para acessa-la, abra o arquivo senhadecodificada.txt\n");

    return 0;
}