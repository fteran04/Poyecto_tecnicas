#include "proyecto.h"

List create_list()
{
    List list;
    list.size = 0;
    list.head = NULL;
    return list;
}
Objeto *create_node(char *data)
{
    Objeto *node = (Objeto *)malloc(sizeof(Objeto));
    node->data = (char *)malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}
void pop(List *list)
{
    if (list->size == 0)
    {
        printf("Lista vacia.\n");
        return;
    }
    Objeto *ref = NULL;
    Objeto *n = list->head;
    while (n->next != NULL)
    {
        ref = n;
        n = n->next;
    }
    if (ref == NULL)
    {
        list->head = NULL;
    }
    else
    {
        ref->next = NULL;
    }
    free(n->data);
    free(n);
    list->size--;
}
void push(List *l, char *data)
{
    Objeto *node = create_node(data);
    if (l->size == 0)
    {
        l->head = node;
    }
    else
    {
        Objeto *n = l->head;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = node;
    }
    l->size += 1;
}
void print_list(List list)
{

    int i = 0;
    Objeto *tmp = list.head;
    while (i < list.size)
    {
        printf("%d. %s\n", i + 1, tmp->data);
        tmp = tmp->next;
        i += 1;
    }
}
char *infoLista(List list, int position)
{

    Objeto *current = list.head;
    int i = 1;

    // Recorrer la lista hasta la posicion deseada
    while (i < position)
    {
        current = current->next;
        i++;
    }

    return current->data;
}
void remove_string(List *list, char *data)
{
    if (list->size == 0)
    {
        printf("Lista vacia.\n");
        return;
    }

    Objeto *current = list->head;
    Objeto *previous = NULL;

    // Buscar el nodo que contiene la cadena de texto
    while (current != NULL)
    {
        if (strcmp(current->data, data) == 0)
        {
            break;
        }
        previous = current;
        current = current->next;
    }

    // Si se encontro el nodo, eliminarlo
    if (current != NULL)
    {
        if (previous == NULL)
        {
            // El nodo a eliminar es el primero de la lista
            list->head = current->next;
        }
        else
        {
            // El nodo a eliminar esta en medio o al final de la lista
            previous->next = current->next;
        }

        free(current->data);
        free(current);
        list->size--;

        printf("Cadena eliminada: %s\n", data);
    }
    else
    {
        printf("Cadena no encontrada: %s\n", data);
    }
}
void insertSorted(List *list, Objeto *objeto)
{
    if (list->head == NULL || strcmp(objeto->data, list->head->data) < 0)
    {
        objeto->next = list->head;
        list->head = objeto;
    }
    else
    {
        Objeto *current = list->head;
        while (current->next != NULL && strcmp(objeto->data, current->next->data) > 0)
        {
            current = current->next;
        }
        objeto->next = current->next;
        current->next = objeto;
    }

    list->size++;
}
