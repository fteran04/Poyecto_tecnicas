#ifndef LOGICA_CENTRAL
#define LOGICA_CENTRAL

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*Constantes:*/
#define VERTEX_NUMBER 5
// Menu principal
#define EXPLORAR 1
#define AVANZAR 2
#define ESTADISTICAS 3
#define INVENTARIO 4
#define BESTIARIO 5
#define SALIR 6

// explorar:
#define ANTORCHA 1
#define OBJETO 2
#define FUENTE_HABILIDAD 4
#define POCION 3
#define NADA 0

// pelea
#define ATAQUE_LIGERO 1
#define ATAQUE_PESADO 2
#define PARRY 3
#define HEAL 4
#define ATAQUE_MAGICO 5
#define ESQUIVAR 6

// Clases de jugador
#define GUERRERO 1
#define MAGO 2
#define LADRON 3
#define CLERICO 4

typedef struct Objeto
{
    char *data;
    struct Objeto *next;
} Objeto;

typedef struct List
{
    int size;
    Objeto *head;
} List;

typedef struct Enemy
{
    char *name;
    int vida;
    char *descrip;
} Enemy;

typedef struct Jugador
{
    char *name;
    int vida;
    int stamina;
    int dano;
    int agilidad;
    int fuenteHabilidad;
    List Inventario;
    char clase[9];
    int posGf;
    int pociones;

} Jugador;
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List2
{
    int size;
    struct Node *head;
} List2;

/*Prototipos*/

// Funciones que inician las estructuras
void inicializar_jugador(Jugador *jug, char *n);
void inicializar_enemy(Enemy *ene, char *n, int v, char *des);
// Funciones de tratado de lista para inventario
List create_list();
Objeto *create_node(char *data);
void push(List *list, char *data);
void pop(List *list);
void print_list(List list);
char *infoLista(List list, int position);
void remove_string(List *list, char *data);
void insertSorted(List *list, Objeto *objeto);
// Funciones de logica central
void menu(Enemy *enemys, List2 *grafo);
void menuPrincipal(Jugador *jug, Enemy *enemys, List2 *grafo);
void bestiario(Enemy *enemys);
void printLinea();
void explorar(Jugador *jud, Enemy *enemys);
Enemy pelea(int x, Jugador *jug, Enemy *enemys);
void inventario(Jugador *jug);
void estadisticas(Jugador *jug);
// dibujos
void dibujo();
void dibujo2();
// grafo
Node *create_vertex_node(int data);
List create_simple_list();
void add_node_to_list(List2 *list, int data);
void print_simple_list(List2 list);
void create_graph(List2 *arr);
void add_node_to_graph(List2 *arr, int node, int data);
void print_graph(List2 *graph);
void zonaActual(int node, List2 *graph, int *numNeighbors);
// Guardado
void guardarEstadisticas(Jugador *jugador, Enemy *enemigos, int numEnemigos);
void cargarEstadisticas(Jugador *jugador, Enemy **enemigos, int *numEnemigos);
int isFileEmpty(const char *filename);

#endif
