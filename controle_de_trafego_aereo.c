#include<stdio.h>   // biblioteca stdio.
#include<stdlib.h>  // biblioteca stdlib.
#include<string.h>  // biblioteca string.
#include<time.h>    // biblioteca temp.h

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct FILA{ 
    NO *ini;  
    NO *fim; 
}FILA;

void inicializaFila(FILA *f){
    f -> ini = NULL;
    f -> fim = NULL;
}

void enfileira(int dado, FILA *f){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("\t\tErro alocacao.\n");
        return;
    }
    else{
        ptr -> dado = dado;
        ptr ->prox = NULL;
        if(f -> ini ==NULL){
            f -> ini = ptr;
        }
        else{
            f -> fim -> prox = ptr;
        }

        f -> fim =ptr;
        return;
    }
}

int desenfileira (FILA *f){
        NO *ptr = f -> ini;
        int dado;
        if (ptr != NULL){
            f -> ini = ptr -> prox;
            ptr -> prox = NULL;
            dado = ptr -> dado;
            free(ptr);
            if(f -> ini == NULL){
                f -> fim = NULL;
            }
            return dado;
        }
        else{
            printf("\t\tFila vazia.\n");
        }
}

void imprimeFila(FILA *f){
    NO *ptr = f -> ini;

    if(ptr != NULL){
        while(ptr != NULL){
            printf("\t\t%d\n", ptr -> dado);
            ptr = ptr -> prox;
        }
        }
    
    else{
        printf("\t\tFila vazia.\n");
        return;
    }
}

void explicacao(void){
    printf("\t\tBem vindo ao simulador de Controle de trafego Aereo.\n");
    printf("\t\tA seguir sera dado 2 pistas para simular.\n");
    printf("\t\tUma de pousos (pista 1) e outras de decolagems (pista 2).\n");
    printf("\t\tA pista 1 possui como entrada 2 tipos de prioridades 1 (alta) e 2 (media).\n");
    printf("\t\tPrioridade 1 significa que sao avioes que nescessitam estao em situacao de alerta.\n");
    printf("\t\tA pista 1 possui como entrada 2 tipos de prioridades 1 (alta) e 2 (media).\n");
    printf("\t\tPrioridade 1 significa que sao avioes em que os passageioros tem uma nessecidade maior de tempo.\n");
    printf("\t\tSera dado uma instante de tempo (ut).\n");
    printf("\t\tA cada INSTANTE DE TEMPO 5 voos solicitam pouso ou decolagem e entram na respectiva FILA DE PRIORIDADES: FP1 ou FP2.\n");
    printf("\t\tPOUSOS utilizam 2 UNIDADES DE TEMPO para sua realizacao. Desse modo, a cada 2 uts a FP1 autoriza 1 pouso da FP1.\n");
    printf("\t\tDECOLAGENS utilizam 3 UNIDADES DE TEMPO para sua realizacao. Desse modo, a cada 3 uts a FP2 autoriza 1 decolagem da FP2.\n");
}

int main(){
    FILA *f21 = (FILA*) malloc(sizeof(FILA)); //Pista de decolagem.
    FILA *f11 = (FILA*) malloc(sizeof(FILA)); //Pista de pouso.
    FILA *f22 = (FILA*) malloc(sizeof(FILA)); //Pista de decolagem.
    FILA *f12 = (FILA*) malloc(sizeof(FILA)); //Pista de pouso.

    int ut = 0; //uts unidades de tempo.
    int i, r, t, o=0, o1=0, o2=0, k1=0, k=0, k2=0, u=0, j=0, p=0;
    explicacao();
            
    inicializaFila(f11);
    inicializaFila(f21);
    inicializaFila(f12);
    inicializaFila(f22);
    
    while(u < 50){

        ut++;
        printf("\t\tUnidade de tempo (ut) = %d\n", ut);
        printf("\t\t+ 5 voos entram nas listas de espera:\n");
        for(i = 0; i < 5; i++){
            printf("\t\tDigite se e pouso ou decolagem.(Digite 1 para pouso e 2 para decolagem.)\n");
            scanf("%d", &r);
            if(r == 1){
                printf("\t\tDigite a prioridade.(Digite 1 ou 2)\n");
                scanf("%d", &t);
                if(t == 1){
                    printf("\t\tSolicitado pouso de prioridade 1\n");
                    enfileira(1, f11);
                    printf("\t\tLista de espera de pouso:\n");
                    o1++;
                    j++;
                    imprimeFila(f11);
                    imprimeFila(f12);
                    
                }
                if(t == 2){
                    
                    printf("\t\tSolicitado pouso de prioridade 2\n");
                    enfileira(2, f12);
                    printf("\t\tLista de espera de pouso:\n");
                    o2++;
                    j++;
                    imprimeFila(f11);
                    imprimeFila(f12);
                    
                }
                }
            if(r == 2){
                printf("\t\tDigite a prioridade.(Digite 1 ou 2)\n");
                scanf("%d", &t);
                if(t == 1){
                    printf("\t\tSolicitado decolagem de prioridade 1\n");
                    enfileira(1, f21);
                    printf("\t\tLista de espera de pouso:\n");
                    k1++;
                    p++;
                    imprimeFila(f21);
                    imprimeFila(f22);
                    
                }
                if(t == 2){
                    printf("\t\tSolicitado decolagem de prioridade 2\n");
                    enfileira(2, f22);
                    printf("\t\tLista de espera de pouso:\n");
                    k2++;
                    p++;
                    imprimeFila(f21);
                    imprimeFila(f22);
                    
                }
                o++;
                k++;
            }
            if(o == 2){
                o==0;
                if(o1>0){
                    printf("\t\tLiberando um pouso.%d\n", desenfileira(f11));
                    o1--;
                    u++;
                }
                else{
                    if(o2>0){
                    printf("\t\tLiberando um pouso.%d\n", desenfileira(f12));
                    o2--;
                    u++;
                    }
                }
            }
             
            if(k == 3){
                k==0;
                if(k1>0){
                    printf("\t\tLiberando a decolagem.%d\n", desenfileira(f21));
                    k1--;
                    u++;
                }
                else{
                    if(k2>0){
                    printf("\t\tLiberando a decolagem.%d\n", desenfileira(f22));
                    k2--;
                    u++;
                    }
                }
            }
            }
        }
        printf("\t\tO numero de solitacoes de pouso:%d\n", j);
        printf("\t\tO numero de solitacoes de decolagem:%d\n", p);
        printf("\t\tPousos restantes na pista 1=\n");
        imprimeFila(f11);
        imprimeFila(f12);
        printf("\t\tDecolagens restantes na lista 2=\n");
        imprimeFila(f21);
        imprimeFila(f22);
     
    return 0;
}