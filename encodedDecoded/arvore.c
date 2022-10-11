#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Arvore* criar_arvore(){
    Arvore* arv = (Arvore*) malloc(sizeof(Arvore));
    if(arv!=NULL){
        NO* no = (NO*) malloc(sizeof(NO));
        if(no!=NULL){
            no->dado='0';
            no->r=NULL;
            no->l=NULL;
            *arv=no;
        }        
        return arv;
    } else {
      return 0;
    }
}
int inserir_elemento(Arvore* arv, char c, char *pos){
    if(arv==NULL) return 0;
    NO* atual = *arv;
    for(int i=0;i<5;i++){
        if(pos[i]=='0'){
            if(atual->l==NULL){
                NO* no1 = (NO*) malloc(sizeof(NO));
                no1->dado=pos[i];
                no1->l=NULL;
                no1->r=NULL;
                atual->l=no1;
            }
            atual=atual->l;
        } 
        else{
            if(atual->r==NULL){
                NO* no1 = (NO*) malloc(sizeof(NO));
                no1->dado=pos[i];
                no1->l=NULL;
                no1->r=NULL;
                atual->r=no1;
            }
            atual=atual->r;
        }
        if(i==4) atual->dado = c;
    }
    return 0;
}
char buscar_elemento(Arvore* arv, char *pos){
    NO* atual = *arv;
    for(int i=0;i<5;i++){
        if(pos[i]=='0') atual=atual->l;
        else atual=atual->r;
    }
    return atual->dado;
}
void write_pre(Arvore* arv, char *c){
    if(arv==NULL || *arv==NULL) return;
    char aux[15];
    sprintf(aux,"%c ",(*arv)->dado);
    if(*arv!=NULL) strcat(c,aux),write_pre(&((*arv)->l),c),write_pre(&((*arv)->r),c);
}
void imprimir_arvore_pre(Arvore* arv){
    if(arv==NULL) return;
    char carv[500]="";
    write_pre(arv,carv);
    printf("%s\n",carv);
}
char* getPre(Arvore* arv){
    char* carv = malloc(500);
    sprintf(carv,"");
    write_pre(arv,carv);
    return carv;
}
void destruir(NO* no){
    if(no == NULL) return;
    destruir(no->l);
    destruir(no->r);
    free(no);
}
void destruir_arvore(Arvore* arv){
    if(arv==NULL) return;
    destruir(*arv);
    free(arv);
}