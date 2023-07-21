/***
 * @author Maykoll Rocha
 * @email <maykoll1412@gmail.com>
 * @date  (início) 2023-07-19
 * @date  (Ultima Atualização) 2023-07-20
***/
#ifndef comida_alg_h
#define comida_alg_h

void mostrar_comida(comida *comid)
{
    gotoxy(comid->pos_x,comid->pos_y);
    printf("\033[42m"" ""\033[40m");
}

comida *criar_comida(int x,int y)
{
    comida *aux = malloc(sizeof(comida));
    aux->pos_x = x;
    aux->pos_y = y;
    return aux;
}

#endif
