/***
 * @author Maykoll Rocha
 * @email <maykoll1412@gmail.com>
 * @date  (início) 2023-07-19
 * @date  (Ultima Atualização) 2023-07-20
***/
#ifndef gamplayavac_h
#define gamplayavac_h
int paratudo(cobra *eu)
{

    if(eu->pos_x>100 || eu->pos_y > 10 || eu->pos_y==0 || eu->pos_x==0)return 1;

    if(eu->restcorp)
    {
        int l = 0;
        cobra *aux = eu->restcorp;
        while(aux->restcorp != NULL)
        {
            if(eu->pos_x == aux->pos_x && eu->pos_y == aux->pos_y ) return 1;
            aux = aux->restcorp;
            l++;
        }
    }

    return 0;

}
//setas(72, 75, 77, 80)
void gameplay(int speed,int nivel)
{
        srand( (unsigned)time(NULL) );

    int po;
    int poits;
    poits = 0;
    cobra *eu = cria(50,5);
    comida *c = criar_comida(rand()%100+1,rand()%10+1);
    gotoxy(0,0);
    campo();

    eu->restcorp = cria(49,5);
    while(1)
    {
        gotoxy(0,12);
        printf("Pontos: %i", poits);
        cobra *aux = eu;
        while(aux->restcorp != NULL)
            aux = aux->restcorp;
        int ux,uy;
        ux=aux->pos_x;
        uy=aux->pos_y;

        mostrar_comida(c);
        mostrar(eu);

        gotoxy(ux,uy);
        printf(" ");

        if(kbhit()){
            po = getch();
        }


        switch(po)
        {
            case 72: atuliza(eu,eu->pos_x,eu->pos_y-1);break;
            case 75: atuliza(eu,eu->pos_x-1,eu->pos_y);break;
            case 80: atuliza(eu,eu->pos_x,eu->pos_y+1);break;
            case 77: atuliza(eu,eu->pos_x+1,eu->pos_y);break;
            default: po = getch(); break;
        }

        if(eu->pos_x == c->pos_x && eu->pos_y == c->pos_y)
        {
            gotoxy(c->pos_x,c->pos_y);
            printf(" ");
            aumentar(eu);
            mostrar(eu);
            free(c);
            c = criar_comida(rand()%100+1,rand()%10+1);
            poits += 100*nivel;
        }
        Sleep(speed);
        if(paratudo(eu))break;
    }
    //Anuncia a derrota
    gotoxy(45,4);
    printf("------------------\n");
    gotoxy(45,5);
    printf(" G A M E  O V E R \n");
    gotoxy(45,6);
    printf("------------------\n");

    //Limpeza
    free(c);//limpa a comoida
    limpar(eu);//limpa a cobra

    getch();
    return;
}
#endif
