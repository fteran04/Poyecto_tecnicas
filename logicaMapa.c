#include "proyecto.h"
// Grafo
void zonaActual(int node, List *graph, int *numNeighbors)
{
    List list = graph[node];
    Node *current = list.head->next;
    int i = 0;
    printf("\nZona actual: %d\n", list.head->data);
    printf("A que zona quieres ir?: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        numNeighbors[i] = current->data;
        current = current->next;
        i++;
    }
    printf("\n");
    printf("Quedarse en zona actual: %d\n ", node);
}

Node *create_vertex_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

List create_simple_list()
{
    List list;
    list.size = 0;
    list.head = NULL;

    return list;
}

void add_node_to_list(List *list, int data)
{
    Node *node = create_vertex_node(data);

    Node *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    list->size += 1;
}

void print_simple_list(List list)
{
    Node *temp = list.head;

    printf("Vertice ");
    for (int i = 0; i < list.size; i++)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void create_graph(List *arr)
{
    for (int i = 0; i < VERTEX_NUMBER; i++)
    {
        List list = create_simple_list();
        list.head = create_vertex_node(i);
        list.size = 1;

        arr[i] = list;
    }
}

void add_node_to_graph(List *arr, int node, int data)
{
    List *list = &arr[node];
    add_node_to_list(list, data);
}

void print_graph(List *graph)
{
    for (int i = 0; i < VERTEX_NUMBER; i++)
    {
        print_simple_list(graph[i]);
        printf("\n");
    }
}
