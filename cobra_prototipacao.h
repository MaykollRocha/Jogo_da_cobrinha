/***
 * @author Maykoll Rocha
 * @email <maykoll1412@gmail.com>
 * @date  (in�cio) 2023-07-19
 * @date  (Ultima Atualiza��o) 2023-07-20
***/
#ifndef cobra_prototipacao_h
#define cobra_prototipacao_h
void gotoxy(int x, int y);;//Fun��o de andar no espa�o geom�trico
//Cria��o das estruturas
typedef struct _cobra
{
    int pos_x;//Local em X da cobra
    int pos_y;//Local em Y da cobra
    struct _cobra *restcorp;//Resto do corpo
}cobra;

//Estrutura do alimento
typedef struct comida
{
    int pos_x;//Local X da comida
    int pos_y;// Local Y da comida
}comida;

//estrutura para tirar arquivos
typedef struct _arqs
{
    char name[255];
    int pontos;
}arqs;
//Fun��es para cobra
cobra *cria(int x,int y);//Iniciar uma cobra ou peda�os dela
void aumentar(cobra *eu);// aumenta a cobra
void mostrar(cobra *eu);//Mostra a cobra
void atuliza(cobra *eu,int x,int y);//Atuliza o novo espa�o que a cobra se econtra

//Fun��es da comida
comida *criar_comida(int x,int y);//Cria uma nova estrutura de comida
void mostrar_comida(comida *comid);//Mostra a comida na tela

//Gameplays
void campo();
int paratudo(cobra *eu);//`Verifica se deu algum problema
int gameplay(int speed,int nivel);//Gameplay avan�ada

//Menus
int opcoes();
void menu();

//limpar estrutura encadeada
void limpar(cobra *eu);

#endif
