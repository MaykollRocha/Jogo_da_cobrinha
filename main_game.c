#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
#include "cobra_prototipacao.h"
#include "alg_auxilio.h"
#include "cobra_criacao.h"
#include "comida_alg.h"
#include "gamplayavac.h"


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
    char c1,c2,c3;
    c1 = 'X';
    c2 = ' ';
    c3 = ' ';
    while (1)
    {
        printf("+------------+\n"
        "|[%c] Iníciar |\n"
        "|[%c] Opções  |\n"
        "|[%c] Sair    |\n"
        "+------------+\n",c1,c2,c3);
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
                }else{
                    c2 = ' ';
                    c3 = 'X';
                    ps = 2;
                }

                break;
            case 72:
                system("cls");
                if(ps == 2)
                {
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
                    case 0:gameplay(speed,lv);break;
                    case 1:
                        system("cls");
                        lv = opcoes();
                        speed = (lv == 1)?250:(lv == 2)?150:90;
                        break;
                    case 2: return;break;
                }
                system("cls");
                break;
        }
    }
}

int main()
{
    menu();
    return 0;
}
