#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include "cobra_prototipacao.h"
#include "alg_auxilio.h"
#include "cobra_criacao.h"
#include "comida_alg.h"
#include "gamplayavac.h"

/***
 * @author Maykoll Rocha
 * @email <maykoll1412@gmail.com>
 * @date  (in�cio) 2023-07-19
 * @date  (Ultima Atualiza��o) 2023-07-20
***/


void save_records(char name[],int points)
{
    FILE *arq = fopen("PONTUA��ES.txt","a");
    fprintf(arq,"%s\n%i\n",name,points);
    fclose(arq);
}

void ranking()
{
	int i,j,k;
    printf("NOME|PONTUA��O\n");
    //Abre o arquivo em modo de leitura
    FILE *arq = fopen("PONTUA��ES.txt","r");
    //Caso n�o tenha arquivo ele n�o abre logo ela consta como invalido fala que n�o tem nada salvo e retorn ao menu.
    if(!arq)
    {
        printf("N�o h� nada registrado\n");
        return;
    }
    //Conta quantos valores tem.
    int p;
    p=0;
    arqs buff[100];
    while(!feof(arq))
    {
        fscanf(arq,"%s\n",&buff[p].name);
        fscanf(arq,"%i\n",&buff[p].pontos);
        p++;
    }
    fclose(arq);//Depois de tirar tudo do arquivo ele fecha.
    //Salva o n�mero de registro que tinha no arquivo
	int n=p;

	//Cheka qual nomes est�o repetidos nos codigo.
    for( i=0;i<p-1;i++)
        for( j=i+1;j<p;j++)
            if(strcmp(buff[i].name,buff[j].name)==0)
            {
                if(buff[i].pontos < buff[j].pontos)buff[i].pontos = buff[j].pontos;
                for( k=j;k<p-1;k++)
                {
                    buff[k] = buff[k+1];
                }
                p-=1;
            }

    //Nosso amado algoritmo da bolha para ordenar em ordem crescente de pontua��o nosso arquivo
	//OBS: eu fiz algo bom n�o otimizado.
    for(i=0;i<p-1;i++)
    {
        for(j=i+1;j<p;j++)
        {
            if(buff[i].pontos<buff[j].pontos)
            {
                arqs aux;
                aux = buff[i];
                buff[i] = buff[j];
                buff[j] = aux;
            }
        }
    }


    //Printa depois de ordenado o ranking
    for(i=0;i<p;i++)
        printf("%s|%i\n",buff[i].name,buff[i].pontos);

    //Caso tenha tido algo repetido arrumamos isso para que n�o ocorrar um aumento linear desnesses�rio no arquivo .
    if(n!=p)
    {
        FILE *arq = fopen("PONTUA��ES.txt","w");
        for(int i=0;i<p;i++)
            fprintf(arq,"%s\n%i\n",buff[i].name,buff[i].pontos);
        fclose(arq);
    }
}


int opcoes()
{
    int po;
    int lv;
    lv = 1;
    char op1,op2,op3;
    op1 = 'X';
    op2 = ' ';
    op3 = ' ';
    while(1)
    {
        printf("+-------------+\n"
        "| [%c] level 1 |\n"
        "| [%c] level 2 |\n"
        "| [%c] level 3 |\n"
        "+-------------+\n",op1,op2,op3);
        do{
            po = getch();
        }while(po != 13 && po != 72 && po != 80);

        switch(po){
            case 80:
                        system("cls");
                        if(lv == 1){
                            op2 = 'X';
                            op1 = ' ';
                            lv = 2;
                        }else{
                            op3 = 'X';
                            op2 = ' ';
                            lv = 3;
                        }
                        break;
            case 72:
                    system("cls");
                    if(lv == 3){
                        op2 = 'X';
                        op3 = ' ';
                        lv = 2;
                    }else{
                        op1 = 'X';
                        op2 = ' ';
                        lv = 1;
                    }
                    break;
            case 13:
                switch(lv)
                {
                    case 1:return 1;
                    case 2:return 2;
                    case 3:return 3;
                }
            }
        }

}

void menu()
{
    int po;
    int enter;
    int ps;
    int speed,lv;
    speed = 300;
    lv = 1;
    ps = 0;
    char c1,c2,c3,c4;
    c1 = 'X';
    c2 = ' ';
    c3 = ' ';
    c4 = ' ';
    while (1)
    {
        printf("+------------+\n"
        "|[%c] In�ciar |\n"
        "|[%c] Ranking |\n"
        "|[%c] Op��es  |\n"
        "|[%c] Sair    |\n"
        "+------------+\n",c1,c2,c3,c4);
        do{
            po = getch();
        }while(po != 13 && po != 72 && po != 80);



        switch(po)
        {
            case 80:
                system("cls");
                if(ps == 0)
                {
                    c1 = ' ';
                    c2 = 'X';
                    ps = 1;
                }else if(ps ==1){
                    c2 = ' ';
                    c3 = 'X';
                    ps = 2;
                }else{
                    c3 = ' ';
                    c4 = 'X';
                    ps = 3;
                }

                break;
            case 72:
                system("cls");
                if(ps == 3)
                {
                    c4 = ' ';
                    c3 = 'X';
                    ps = 2;
                }else if(ps == 2){
                    c3 = ' ';
                    c2 = 'X';
                    ps = 1;
                }else{
                    c2 = ' ';
                    c1 = 'X';
                    ps = 0;
                }
                break;
            case 13:
                switch(ps)
                {
                    case 0:
                        printf("Entre com o nome do jogador: ");
                        char name[15];
                        scanf("%s",&name);
                        int ponto = gameplay(speed,lv);
                        save_records(name,ponto);
                        break;
                    case 1:
                        system("cls");
                        ranking();
                        getch();
                        break;
                    case 2:
                        system("cls");
                        lv = opcoes();
                        speed = (lv == 1)?250:(lv == 2)?150:90;
                        break;
                    case 3: return;break;

                }
                system("cls");
                break;
        }
    }
}

int main()
{
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}
