#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
    Variaveis globais que vão guardar os detalhes do pedido do cliente
*/
int gelo;   // se vai querer gelo ou não
int tamanho;   // indice para o vetor tamanhoCopos
int bebida; // indice para o vetorBebidas
int delivery;   //  se vai ser delivery

/*
    vetores com os valores, para facilitar a impressão do pedido
*/
int tamanhoCopos[3] = {300,500,700};
char vetorBebidas[4][20] = {"Coca","Guarana","Suco de Uva","Suco de Laranja"};

void imprimir_pedido();
void leitura();
int quant_gelo();
int isRefri();
void pegaCopo();
void colocaGelo();
void colocaBebida();
void colocaTampa();
void produz();

int isRefri(){
    /*
        verifica se é refrigerante
    */
    if(bebida == 1 || bebida == 2){
        return 1;   
                  
    }else if(bebida == 3 || bebida == 4){
        return 0;                
    }

    return -1;
}

void colocaGelo(){
    system("cls");
    if(gelo == 1){
        if(isRefri() == 1){
            printf("COLOCANDO 6 PEDRAS DE GELO NO COPO");
        }else if(isRefri() == 0){
            printf("COLOCANDO 12 PEDRAS DE GELO NO COPO");
        }
    }else{
        // se não pedir gelo não acontece nada
    }
}

void pegaCopo(){
    system("cls");
    if(isRefri() == 1){
        switch(tamanho){
            case 1:
                    printf("PEGANDO COPO DE PAPEL 300ml");
            break;
            case 2:
                    printf("PEGANDO COPO DE PAPEL 500ml");
            break;
            case 3:
                    printf("PEGANDO COPO DE PAPEL 700ml");
            break;
            default:
            break;

        }
    }else if(isRefri() == 0){
        switch(tamanho){
            case 1:
                    printf("PEGANDO COPO DE PLASTICO 300ml");
            break;
            case 2:
                    printf("PEGANDO COPO DE PLASTICO 500ml");
            break;
            default:
            break;
        }
    }else{
        printf("\n ERRO NO SISTEMA \n");
    }
}

void colocaBebida(){
    system("cls");
    switch(bebida){
        case 1:
            printf("COLOCANDO %iml DE COCA",tamanhoCopos[tamanho-1]);
        break;
        case 2:
            printf("COLOCANDO %iml DE GUARANA",tamanhoCopos[tamanho-1]);
        break;
        case 3:
            printf("COLOCANDO %iml DE SUCO DE UVA",tamanhoCopos[tamanho-1]);
        break;
        case 4:
            printf("COLOCANDO %iml DE SUCO DE LARANJA",tamanhoCopos[tamanho-1]);
        break;
        default:
        break;
    }
}

void colocaTampa(){
    system("cls");
    if(delivery == 1){
        printf("COLOCANDO TAMPA SEM FURO");
    }else if(delivery == 2){
        printf("COLOCANDO TAMPA COM FURO");
    }
}

int quant_gelo(){
    /*
        retorna a quantidade de gelos que vão na bebida
    */
    if(gelo == 1){
        if(bebida == 1 || bebida == 2){
            return 6;
        }else{
            return 12;
        }
    }else{
        return 0;
    }
}

void imprimir_pedido(){
    /*
        função para imprimir o pedido conforme as especificações
    */
    printf("Seu pedido seria : %s %iml %i gelos ", vetorBebidas[bebida-1],tamanhoCopos[tamanho-1],quant_gelo());
   
    if(delivery == 1){
        printf("para Delivery.");
    }else{
        printf("para comer no restaurante. ");
    }
}

void leitura(){
    // função responsavel pela leitura do pedido
    int estado = 1;
    int confirma = 0;
    
    // reset das variaveis globais
    gelo = -1;
    tamanho = -1;
    bebida = -1;
    delivery = -1;
    
    // maquina de estados
    while(estado != 6){
        switch(estado){
            case 1:
                 // selecao de bebidas
                printf("Escolha a sua bebida : \n [1] Coca. \n [2] Guarana. \n [3] Suco de Uva. \n [4] Suco de Laranja. \n");
                scanf("%i",&bebida);
                system("cls");
                if(bebida < 1 || bebida > 4){
                    printf("ERRO opcao invalida \n");
                    Sleep(2000);
                    system("cls");
                    estado = 1;
                }else{
                    estado = 2;
                }
            break;
            case 2:
                // tamanho de bebidas
                if(isRefri() == 1){
                    
                    //selecao de tamanhos de bebida para refrigerante
                    printf("Qual o tamanho da bebida : \n [1] 300ml. \n [2] 500ml. \n [3] 700ml. \n");
                    scanf("%i",&tamanho);
                    system("cls");
                    if(tamanho > 3 || tamanho < 1){
                        estado = 2;
                        printf("ERRO , tamanho de bebida invalido \n");
                        Sleep(2000);
                        system("cls");
                    }else{
                        estado = 3;
                    }
                
                }else if(isRefri() == 0){
                    //selecao de tamanhos de bebida para sucos
                    printf("Qual o tamanho da bebida : \n [1] 300ml. \n [2] 500ml. \n");
                    scanf("%i",&tamanho);
                    system("cls");
                    if(tamanho > 2 || tamanho < 1){
                        estado = 2;
                        printf("ERRO , tamanho de bebida invalido \n");
                        Sleep(2000);
                        system("cls");
                    }else{
                        estado = 3;
                    }

                }
            break;
            case 3:
                    // escolher gelo
                    printf("Gostaria de gelo ? : \n [1] Sim. \n [2] Nao. \n");
                    scanf("%i",&gelo);
                    system("cls");
                    if(gelo == 1 || gelo == 2){
                        estado = 4;
                    }else{
                        estado = 3;
                        printf("ERRO, opcao invalida");
                        Sleep(2000);
                        system("cls");
                    }
            break;
            case 4:
                    // delivery ou comer no restaurante
                    printf("Delivery ou Comer no restaurante ? : \n [1] Delivery. \n [2] Comer no restaurante. \n");
                    scanf("%i",&delivery);
                    system("cls");
                    if(delivery == 1 || delivery == 2){
                        estado = 5;
                    }else{
                        estado = 4;
                        printf("ERRO opcao invalida \n");
                        Sleep(2000);
                        system("cls");
                    }
            break;
            case 5:
                    // confirmação de pedido
                    imprimir_pedido();
                    printf("\n CONFIRMAR ? \n [1] SIM. \n [2] NAO.");
                    scanf("%i",&confirma);
                    system("cls");
                    if(confirma == 1){
                        estado = 6;
                    }else if(confirma == 2){
                        estado = 1;
                    }else{
                        printf("ERRO opcao invalida \n");
                        Sleep(2000);
                        system("cls");
                    }
            break;
            case 6:
                    //estado de aceitação
            break;
        }
    }
    
    
}

void produz(){
    Sleep(3000);
    pegaCopo();
    Sleep(3000);
    colocaGelo();
    Sleep(3000);
    colocaBebida();
    Sleep(3000);
    colocaTampa();
    Sleep(3000);
    system("cls");
    printf("FIM");
    // os Sleeps são para que todos os procedimentos tenham o seu tempo para execução
}


int main(void){
    leitura();
    produz();
    return 0;
}

