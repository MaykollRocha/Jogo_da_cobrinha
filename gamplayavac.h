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
    //Cheka se bateu em uma das bordas
    if(eu->pos_x>100 || eu->pos_y > 10 || eu->pos_y==0 || eu->pos_x==0)return 1;

    //checa se bateu nela mesma
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

int gameplay(int speed,int nivel)
{
    //Para começar com um numero aleatório plantando uma semente
    srand( (unsigned)time(NULL) );

    int po;//Posição da ceta
    int poits;//Placar marcado
    poits = 0;//começa em zero
    cobra *eu = cria(50,5);//Começa no meio do jogo
    comida *c = criar_comida(rand()%100+1,rand()%10+1);//cria a comida num espaço aleatório
    //Gera o corpo
    gotoxy(0,0);
    campo();

    eu->restcorp = cria(49,5);//cria um corpo de 2 espaço

    //laço infinito
    while(1)
    {
        //Apresenta os pontos
        gotoxy(0,12);
        printf("Pontos: %i", poits);
        //Pega o final da cobra
        cobra *aux = eu;
        while(aux->restcorp != NULL)//vai para o ultimo rastro
            aux = aux->restcorp;

        //Mostra a comida e a cobra em game
        mostrar_comida(c);
        mostrar(eu);

        //Apaga o ultimo rastro da cobra
        gotoxy(aux->pos_x,aux->pos_y);
        printf(" ");

        //Serve para não parar o codigo
        if(kbhit()){
            po = getch();
        }


        switch(po)
        {
            case 72: atuliza(eu,eu->pos_x,eu->pos_y-1);break;
            case 75: atuliza(eu,eu->pos_x-1,eu->pos_y);break;
            case 80: atuliza(eu,eu->pos_x,eu->pos_y+1);break;
            case 77: atuliza(eu,eu->pos_x+1,eu->pos_y);break;
            default: po = getch(); break;//Para o codigo caso não entre com uma ceta
        }


        //Checa se pegou a comida
        if(eu->pos_x == c->pos_x && eu->pos_y == c->pos_y)
        {
            //vai para posisão antiga dela e paga seu rastro
            gotoxy(c->pos_x,c->pos_y);
            printf(" ");
            //Aumenta a cobra
            aumentar(eu);
            mostrar(eu);
            free(c);
            //Limpa e gra uma nova comida
            c = criar_comida(rand()%100+1,rand()%10+1);
            poits += 100*nivel;//Aumenta o ponto de acordo com a dificuldade
        }
        Sleep(speed);//aumenta a velocidade de acordo com a velocidade
        if(paratudo(eu))break;//Para o jogo em caso de Game Over
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
    return poits;
}
#endif
