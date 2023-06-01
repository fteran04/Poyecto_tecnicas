#include "proyecto.h"

void zonaActual(int node, List2 *graph, int *numNeighbors)
{
    List2 List2 = graph[node];
    Node *current = List2.head->next;
    int i = 0;
    printf("\nZona actual: %d\n", List2.head->data);
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

List2 create_simple_List()
{
    List2 List2;
    List2.size = 0;
    List2.head = NULL;

    return List2;
}

void add_node_to_List(List2 *List2, int data)
{
    Node *node = create_vertex_node(data);

    Node *temp = List2->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    List2->size += 1;
}

void print_simple_List(List2 List2)
{
    Node *temp = List2.head;

    printf("Vertice ");
    for (int i = 0; i < List2.size; i++)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void create_graph(List2 *arr)
{
    for (int i = 0; i < VERTEX_NUMBER; i++)
    {
        List2 List2 = create_simple_List();
        List2.head = create_vertex_node(i);
        List2.size = 1;

        arr[i] = List2;
    }
}

void add_node_to_graph(List2 *arr, int node, int data)
{
    List2 *List2 = &arr[node];
    add_node_to_List(List2, data);
}

void print_graph(List2 *graph)
{
    for (int i = 0; i < VERTEX_NUMBER; i++)
    {
        print_simple_List(graph[i]);
        printf("\n");
    }
}
