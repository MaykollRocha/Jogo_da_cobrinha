/***
 * @author Maykoll Rocha
 * @email <maykoll1412@gmail.com>
 * @date  (in�cio) 2023-07-19
 * @date  (Ultima Atualiza��o) 2023-07-20
***/
#ifndef cobra_criacao_h
#define cobra_criacao_h

//Cria a cobra ou parte delas
cobra *cria(int x,int y)
{
    //Aloca em um espa�o
    cobra *aux = malloc(sizeof(cobra));
    aux->pos_x = x;//Posi��o X
    aux->pos_y = y;//Posi��o Y
    aux->restcorp = NULL; //N�o tem nada para frente ainda
    return aux;//retorna a cria��o
}

//Aumenta o tamanho da cobra em lista encadeada
void aumentar(cobra *eu)
{
    //Cria uma nova gest�o da cobra
    cobra *newCobra = cria(eu->pos_x,eu->pos_y);
    cobra *aux = eu;//Pega a parte da cabe�a
    while(aux->restcorp != NULL)//Vai para a ultima parte da cobra
        aux = aux->restcorp;
    aux->restcorp = newCobra;//junta a cobra com o corpo
}

//Mostra a cobra
void mostrar(cobra *eu)
{
    if(eu)//Verifica se existe a cobra
    {
        mostrar(eu->restcorp);//Faz o recursivo
        gotoxy(eu->pos_x,eu->pos_y);//Vai para a posi��o
        printf("\033[47m"" ""\033[40m");//Pinta o pixel de cinza

    }
    return;//returna
}

//Atuliza a lista de acordo com o movimento
void atuliza(cobra *eu,int x,int y)
{
    if(eu)
    {
        atuliza(eu->restcorp,eu->pos_x,eu->pos_y);//passa o parmetro da cobra anterior para anterior at� perder o da ultima
        //Coloca a nova possi��o na cabe�a
        eu->pos_x = x;
        eu->pos_y = y;
    }
    return;
}
#endif
