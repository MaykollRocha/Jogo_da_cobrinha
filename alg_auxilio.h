/***
 * @author Maykoll Rocha
 * @email <maykoll1412@gmail.com>
 * @date  (início) 2023-07-19
 * @date  (Ultima Atualização) 2023-07-20
***/
#ifndef alg_auxilio_h
#define alg_auxilio_h


/**
    Tirei do site https://www.clubedohardware.com.br/forums/topic/729087-ajuda-com-a-função-gotoxyxy/
    ele usa para mexer o curso dentro do programa.
**/
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void campo()
{
    //Campo 100X10
    //Cria a aste superior
    printf("+");
    for(int i = 0;i<100;i++)printf("-");
    printf("+\n");

    //Faz o meio
    for(int j=0;j<10;j++)
    {
        printf("|");
        for(int  i = 0;i<100;i++)printf(" ");
        printf("|\n");
    }

    //Faz as bosdas
    printf("+");
    for(int i = 0;i<100;i++)printf("-");
    printf("+");
}

//Limpeza da cobra toda
void limpar(cobra *eu)
{
    if(eu)
    {
        limpar(eu->restcorp);
        free(eu);
    }
}

#endif
