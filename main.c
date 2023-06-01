#include "proyecto.h"

int main()
{
    // Inicializar NPC's
    Enemy Avorathoe, Borvath, Crysanthea, Gorgath, Xoron_Dragon_del_Abismo;
    inicializar_enemy(&Avorathoe, "Avorathoe, el Devorador de Almas", 1500, "\nUna bestia gigantesca con multiples cabezas, cada una con una boca llena de dientes afilados y \nojos ardientes. Se dice que Avorathoe se alimenta de las almas de los guerreros caidos en batalla, \nlo que le otorga un poder inmenso y lo convierte en una amenaza para todos los que se \ninterponen en su camino.");
    inicializar_enemy(&Borvath, "Borvath, el Cazador Oscuro", 2000, "\nUn ser humanoide vestido con una capa oscura y una mascara de cuervo. Borvath es un asesino \nimplacable que persigue a los enemigos mas peligrosos del reino, siempre en busca de su \nproxima presa. Se dice que su verdadera identidad es un misterio, y que incluso los guerreros \nmas poderosos tiemblan ante su presencia.");
    inicializar_enemy(&Crysanthea, "Crysanthea, la Reina del Hielo", 3000, "\nUna mujer hermosa con cabello blanco y ojos azules como el hielo. Se rumorea que Crysanthea \nes una poderosa hechicera que controla el frio y la nieve, y que ha construido su fortaleza en un \nreino de eterno invierno. Se dice que sus enemigos se congelan hasta la muerte en su presencia, \ny que su magia es capaz de crear tormentas de nieve mortales.");
    inicializar_enemy(&Gorgath, "Gorgath, el Coloso de Piedra", 4000, "\nUna criatura gigantesca hecha completamente de piedra, con una fuerza y una resistencia \nimpresionantes. Se dice que Gorgath fue creado por los dioses antiguos como un guardian de un \ntemplo sagrado, pero que ha sido corrompido por el poder oscuro. Ahora, se levanta en el \ncamino de aquellos que buscan penetrar en el templo, listo para aplastarlos con sus enormes \nmanos de roca.");
    inicializar_enemy(&Xoron_Dragon_del_Abismo, " Xoron Dragon del Abismo", 1250, "Un temible dragon que habita en el abismo y lanza fuego y caos a su paso");
    Enemy *arregloEnemys = (Enemy *)calloc(5, sizeof(Enemy));
    arregloEnemys[0] = Avorathoe;
    arregloEnemys[1] = Borvath;
    arregloEnemys[2] = Crysanthea;
    arregloEnemys[3] = Gorgath;
    arregloEnemys[4] = Xoron_Dragon_del_Abismo;
    List2 graph[VERTEX_NUMBER];
    create_graph(graph);

    add_node_to_graph(graph, 0, 1);
    add_node_to_graph(graph, 0, 2);
    add_node_to_graph(graph, 1, 0);
    add_node_to_graph(graph, 1, 3);
    add_node_to_graph(graph, 1, 4);
    add_node_to_graph(graph, 2, 0);
    add_node_to_graph(graph, 2, 4);
    add_node_to_graph(graph, 3, 1);
    add_node_to_graph(graph, 4, 1);
    add_node_to_graph(graph, 4, 2);

    menu(arregloEnemys, graph);
    return 0;
}
