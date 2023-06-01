#include "proyecto.h"

void inicializar_jugador(Jugador *jug, char *n)
{
    int clase;
    printf("\nSelecciona una clase:\n\n1. Guerrero: Vida: 2000, Stamina: 20, Dano: 750, Agilidad: 5.\n\nLos guerreros tienen mucha vida y resistencia, lo que les permite aguantar mucho daño y\n mantenerse en pie durante mucho tiempo en el campo de batalla. Aunque no son muy agiles, su\n fuerza y habilidad con armas pesadas les permiten infligir un gran dano.\n\n2. Mago: Vida: 750, Stamina: 10, Dano: 200, Agilidad: 13.\n\nLos magos no tienen mucha vida ni resistencia fisica, pero su habilidad con la magia les permite \ncausar un gran dano a distancia. Son muy agiles y pueden evadir los ataques enemigos con\n facilidad, pero necesitan gestionar su stamina cuidadosamente para no quedarse sin mana durante \nuna pelea.\n\n3. Ladron: Vida: 1000, Stamina: 15, Dano: 500, Agilidad: 12.\n\nLos ladrones tienen una vida y resistencia media, pero son muy agiles y habiles con armas agiles\n como dagas y arcos. Pueden infligir un gran dano con ataques criticos y pueden desactivar trampas\n y abrir cerraduras.\n\n4. Clerigo: Vida: 1500, Stamina: 15, Dano: 300, Agilidad: 8.\n\nLos clerigos tienen una vida y resistencia media, pero su habilidad con la magia divina les permite\n curar a los aliados y causar un dano magico a los enemigos. No son muy agiles, pero\n tienen habilidades para proteger a sus aliados y resistir el dano magico.\n\nElija una opcion> ");
    jug->name = (char *)malloc(strlen(n) + 1);
    strcpy(jug->name, n);
    scanf("%d", &clase);
    switch (clase)
    {
    case GUERRERO:
        jug->vida = 2000;
        jug->stamina = 20;
        jug->dano = 750;
        jug->agilidad = 3;
        jug->posGf = 0;
        jug->pociones = 0;
        strcpy(jug->clase, "Guerrero");
        break;
    case MAGO:
        jug->vida = 750;
        jug->stamina = 10;
        jug->dano = 200;
        jug->agilidad = 5;
        jug->posGf = 0;
        jug->pociones = 0;
        strcpy(jug->clase, "Mago");
        break;
    case LADRON:
        jug->vida = 1000;
        jug->stamina = 15;
        jug->dano = 500;
        jug->agilidad = 6;
        jug->posGf = 0;
        jug->pociones = 0;
        strcpy(jug->clase, "Ladron");
        break;
    case CLERICO:
        jug->vida = 1500;
        jug->stamina = 15;
        jug->dano = 300;
        jug->agilidad = 1;
        jug->posGf = 0;
        jug->pociones = 0;
        strcpy(jug->clase, "Clerico");
        break;
    default:
        break;
    }
    jug->fuenteHabilidad = 0;
    jug->Inventario = create_list();
}
void inicializar_enemy(Enemy *ene, char *n, int v, char *des)
{
    ene->name = (char *)malloc(strlen(n) + 1);
    strcpy(ene->name, n);
    ene->vida = v;
    ene->descrip = (char *)malloc(strlen(des) + 1);
    strcpy(ene->descrip, des);
}

void menu(Enemy *enemys, List2 *grafo)

{
    Jugador jug;
    int option, empty;
    char nombre[15];
    char archivo[17] = "estadisticas.txt";
    dibujo2();
    while (option != 3)
    {
        printLinea();
        printf("\n1.Juego Nuevo \n2.Continuar\n3.Salir");
        printf("\nElija  una opcion > ");
        scanf("%d", &option);
        printLinea();

        switch (option)
        {
        case 1:
            system("cls");
            printLinea();
            dibujo();
            printLinea();
            printf("\nIngrese su nombre: ");
            scanf("%s", nombre);
            inicializar_jugador(&jug, nombre);

            printf("\nEstas listo %s para esta aventura?\n\nIniciando juego...", jug.name);
            menuPrincipal(&jug, enemys, grafo);
            break;
        case 2:
            empty = isFileEmpty(archivo);
            if (empty != 1)
            {
                int numEnemys;
                cargarEstadisticas(&jug, &enemys, &numEnemys);
                menuPrincipal(&jug, enemys, grafo);
            }
        case 3:
            printf("\nSaliendo...");
            break;
        default:
            printf("\nLa opcion indicada no existe...");
            break;
        }
    }
}

void menuPrincipal(Jugador *jug, Enemy *enemys, List2 *grafo)
{
    int option, j, flag, x;
    while (option != 6 && jug->vida > 0)
    {
        printLinea();
        printf("\n1. Explorar \n2. Avanzar \n3. Estadisticas \n4. Inventario \n5. Bestiario \n6. Salir");
        printf("\nElija  una opcion > ");
        scanf("%d", &option);
        switch (option)
        {
        case EXPLORAR:
            printLinea();
            printf("\nExplorando...");
            explorar(jug, enemys);
            break;
        case AVANZAR:
            flag = 0;
            int pos;
            int zonasPosibles[5];
            if (enemys[jug->posGf].vida > 0)
                enemys[jug->posGf] = pelea(jug->posGf, jug, enemys);
            else
            {
                zonaActual(jug->posGf, grafo, zonasPosibles);
                printf("\nSeleccione una zona > ");
                while (flag == 0)
                {
                    scanf("%d", &pos);
                    int i;
                    if (pos == jug->posGf)
                    {
                        flag = 1;
                        printf("\nRegresando al menu");
                    }
                    for (i = 0; i < 5 && flag == 0; i++)
                    {
                        if (pos == zonasPosibles[i])
                            flag = 1;
                    }
                    if (flag == 0)
                        printf("\nSeleccion invalida, seleccione una opcion valida");
                }
                jug->posGf = pos;
                if (enemys[pos].vida > 0)
                {
                    enemys[pos] = pelea(pos, jug, enemys);
                }
            }

            break;
        case ESTADISTICAS:
            estadisticas(jug);

            break;
        case INVENTARIO:
            inventario(jug);
            break;
        case BESTIARIO:
            printLinea();
            bestiario(enemys);
            break;
        case SALIR:
            printf("\nSaliendo...");
            break;
        default:
            printf("\nLa opcion indicada no existe...");
            break;
        }
    }
}

void bestiario(Enemy *enemys)
{

    int i = 0;
    char *space;
    printf("\nBestiario:");
    for (i = 0; i < 4; i++)
    {
        if (enemys[i].vida == 0)
        {
            printf("\n\n%s\nVida: %d\nDescripcion: %s",
                   enemys[i].name, enemys[i].vida, enemys[i].descrip);
        }
    }
    printf("\n");
}

void explorar(Jugador *jud, Enemy *enemys)
{
    int option, i, save, k, j;
    int arreglo[10] = {1, 1, 2, 2, 2, 3, 3, 0, 0, 0};

    char objetos[5][21] = {"Anillo Abisal", "Hacha Espiral", "Pandeyuca", "Escudo Ancestral", "Orbe Cosmico"};
    char descripciones[5][100] = {
        "Un anillo imbuido de poderes oscuros que aumenta la resistencia a la magia.",
        "Un hacha maldita que gana fuerza a medida que se derrama la sangre del enemigo.",
        "Una llama eterna que arde sin descanso, otorgando vida y calor a su portador.",
        "Un escudo ancestral pasado de generacion en generacion, resistente a todo daño.",
        "Un orbe cosmico que revela secretos ancestrales y otorga vision mas alla de la realidad."};
    char objetos2[5][21] = {"Espada Solar", "Ojo Embrujado", "Baston Lunar", "Gema Carcasa", "Calavera Fria"};
    char descripciones2[5][100] = {
        "Una poderosa espada imbuida con la energia del sol, capaz de infligir daño radiante.",
        "Un ojo misterioso y encantado que concede visiones y percepciones sobrenaturales.",
        "Un baston que canaliza la energia de la luna, otorgando poderes magicos y curativos.",
        "Una gema resplandeciente que protege al portador al absorber el daño entrante.",
        "Una calavera helada que emana frio y corrompe el alma de aquellos que la tocan."};
    char objetos3[5][21] = {"Llave Olvidada", "Fuego Livido", "Velo Sombrio", "Flor Ceniza", "Corazon Negro"};
    char descripciones3[5][100] = {
        "Una antigua llave que abre puertas olvidadas y revela tesoros ocultos.",
        "Un fuego palido y oscuro que consume todo a su paso, infundiendo terror en los corazones.",
        "Un velo impregnado de sombras que oculta al portador de los ojos curiosos.",
        "Una delicada flor que crece en cenizas y representa la renacer y la esperanza.",
        "Un corazon negro y lleno de oscuridad, corrupto por la maldad mas profunda."};
    char objetos4[5][21] = {"Martillo Ferreo", "Pluma Ardiente", "Sortija ignea", "Golem Sombra", "Linterna Solar"};
    char descripciones4[5][100] = {
        "Un imponente martillo de hierro forjado con habilidad y resistencia sobrehumanas.",
        "Una pluma ardiente que arroja chispas y permite escribir en llamas.",
        "Una sortija ardiente que otorga proteccion contra el fuego y aumenta los poderes piromanticos.",
        "Un gigantesco golem de sombras que obedece las ordenes de su portador y lucha a su lado.",
        "Una linterna encantada que ilumina las zonas mas oscuras y ahuyenta a las criaturas de la noche."};
    char objetos5[5][21] = {"Grillete Onix", "Cetro Icaro", "Idolo Tenebroso", "Efigie Ardiente", "Perla Lunar"};
    char descripciones5[5][100] = {
        "Un grillete hecho de onix negro que encierra el poder de las sombras y controla la voluntad.",
        "Un cetro de diseño antiguo, tallado con plumas de angel y bendecido con el poder del vuelo.",
        "Un idolo oscuro y misterioso, adorado por aquellos que se deleitan en la oscuridad y el caos.",
        "Una efigie ardiente que emana calor y protege al portador de los elementos del fuego.",
        "Una hermosa perla que brilla con la luz de la luna, concediendo sabiduria y magia lunar."};
    srand(time(NULL));
    i = rand() % 10;
    switch (arreglo[i])
    {
    case NADA:
        printLinea();
        printf("\nNo has encontrado nada\nVolviendo al menu...");

        break;
    case ANTORCHA:
        printLinea();
        printf("\nHas encontrado una antorcha!\nDesea guardar la partida?\n1.Si\n2.No\nSelecciona una opcion >");
        scanf("%d", &save);
        if (save == 1)
        {
            guardarEstadisticas(jud, enemys, 4);
            printf("\nGuardando la partida...\nSe ha guardado correctamente\nVolviendo al menu");
        }
        else if (save == 2)
        {
            printf("\nVolviendo al menu...");
        }
        else
        {
            printf("\nLa opcion ingresada no existe\nVolviendo al menu");
        }

        break;
    case OBJETO:
        srand(time(NULL));
        k = rand() % 5;
        printLinea();
        Objeto *dato;
        switch (jud->posGf)
        {
        case 0:
            printf("\nHas encontrado: %s\nDescripcion: %s", objetos[k], descripciones[k]);
            dato = create_node(objetos[k]);
            insertSorted(&(jud->Inventario), dato);
            break;
        case 1:
            printf("\nHas encontrado: %s\nDescripcion: %s", objetos2[k], descripciones2[k]);
            dato = create_node(objetos2[k]);
            insertSorted(&(jud->Inventario), dato);
            break;
        case 2:
            printf("\nHas encontrado: %s\nDescripcion: %s", objetos3[k], descripciones3[k]);
            dato = create_node(objetos3[k]);
            insertSorted(&(jud->Inventario), dato);
            break;
        case 3:
            printf("\nHas encontrado: %s\nDescripcion: %s", objetos4[k], descripciones4[k]);
            dato = create_node(objetos4[k]);
            insertSorted(&(jud->Inventario), dato);
            break;
        case 4:
            printf("\nHas encontrado: %s\nDescripcion: %s", objetos5[k], descripciones5[k]);
            dato = create_node(objetos5[k]);
            insertSorted(&(jud->Inventario), dato);
            break;
        default:
            break;
        }

        break;
    case FUENTE_HABILIDAD:
        printLinea();
        printf("\nHas encontrado una fuente de habilidad");
        jud->fuenteHabilidad++;
        break;
    case POCION:
        printLinea();
        printf("\nHas encontrado una pocion");
        jud->pociones++;
        break;
    default:
        break;
    }
}

Enemy pelea(int x, Jugador *jug, Enemy *enemys)
{

    int vidaIniBoss = enemys[x].vida;
    int vidaIniJugador = jug->vida;
    int staminaIni = jug->stamina;
    int ataque;
    int prob, probEnemy;
    int iniStamina = jug->stamina;
    while (jug->vida > 0 && enemys[x].vida > 0)
    {
        printf("\nJefe: %s\nVida Jefe: %d/%d", enemys[x].name, enemys[x].vida, vidaIniBoss);
        printf("\nJugador\nVida: %d/%d\nStamina: %d/%d", jug->vida, vidaIniJugador, jug->stamina, staminaIni);

        printf("\n");
        printf("\nTipos de ataque:\n1.Ataque ligero\n2.Ataque pesado\n3.Parry\n4.Curarse\n5.Ataque Magico\n6.Esquivar\nSeleccione una opcion > ");
        scanf("%d", &ataque);
        printLinea();

        switch (ataque)
        {
        case ATAQUE_LIGERO:

            enemys[x].vida -= jug->dano / 2;
            jug->stamina -= 2;

            printf("\nAtaque ligero efectivo");

            // El enemigo tiene 80% de acierto
            srand(time(NULL));
            probEnemy = rand() % 11;
            if (probEnemy <= 8)
            {
                jug->vida -= 250;
                printf("\nUn ataque enemigo te ha impactado");
            }
            else
            {
                printf("\nEl enemigo ha fallado su ataque, es tu turno");
            }

            break;

        case ATAQUE_PESADO:

            if (jug->stamina > 3)
            {
                // Probabilida de acierto del ataque
                srand(time(NULL));
                prob = jug->agilidad - rand() % 5;
                if (prob >= 6)
                {
                    enemys[x].vida -= jug->dano;
                    printf("\nAtaque pesado efectivo");
                    jug->stamina -= 3;
                }
                else
                {
                    printf("\nEl ataque ha fallado, pierdes el turno");
                }
            }

            // El enemigo tiene 80% de acierto
            srand(time(NULL));
            probEnemy = rand() % 11;
            if (probEnemy <= 8)
            {
                jug->vida -= 250;
                printf("\nUn ataque enemigo te ha impactado");
            }
            else
            {
                printf("\nEl enemigo ha fallado su ataque, es tu turno");
            }

            break;

        case PARRY:
            // Probabilidad del parry
            srand(time(NULL));
            prob = jug->agilidad - rand() % 5;
            if (prob >= 7)
            {
                enemys[x].vida -= jug->dano * 2;
                printf("\nHas noqueado al enemigo y ha sufrido mucho dano");
            }
            else
                printf("\nHas fallado el parry pierdes turno");
            srand(time(NULL));
            probEnemy = rand() % 11;
            if (probEnemy <= 8)
            {
                jug->vida -= 250;
                printf("\nUn ataque enemigo te ha impactado");
            }
            else
            {
                printf("\nEl enemigo ha fallado su ataque, es tu turno");
            }

            jug->stamina -= 4;

            break;
        case HEAL:
            if (jug->pociones > 0)
            {
                jug->vida += 400;
                jug->pociones--;
                printf("\nCantidad de pociones restante: %d", jug->pociones);
            }
            else
                printf("\nNo tienes pociones disponibles, pierdes turno");
            if (jug->vida > vidaIniJugador)
                jug->vida = vidaIniJugador;
            srand(time(NULL));
            probEnemy = rand() % 11;
            if (probEnemy <= 8)
            {
                jug->vida -= 250;
                printf("\nUn ataque enemigo te ha impactado");
            }
            else
            {
                printf("\nEl enemigo ha fallado su ataque, es tu turno");
            }
            break;
        case ATAQUE_MAGICO:
            enemys[x].vida -= (jug->dano * jug->agilidad) / 4;
            jug->stamina -= 4;

            printf("\nAtaque magico efectivo");

            // El enemigo tiene 80% de acierto
            srand(time(NULL));
            probEnemy = rand() % 11;
            if (probEnemy <= 8)
            {
                jug->vida -= 150;
                printf("\nUn ataque enemigo te ha impactado");
            }
            else
            {
                printf("\nEl enemigo ha fallado su ataque, es tu turno");
            }
            break;
        case ESQUIVAR:
            srand(time(NULL));
            int probEsqui = rand() % 11;
            probEsqui += jug->agilidad;
            if (prob > 7)
            {
                printf("\nHas Esquivado el ataque");
                if (jug->stamina < iniStamina)
                    jug->stamina += 2;
            }
            else
            {
                printf("\nUn ataque enemigo te ha impactado");
                jug->vida -= 300;
                jug->stamina -= 4;
            }
            printf("\n");
            break;
        }

        if (jug->stamina < iniStamina)
            jug->stamina += 2;
    }
    if (jug->vida <= 0)
    {
        printf("\nHas muerto");
    }
    else
    {
        printf("\nFelicidades, has conseguido vencer a %s\nRecompensa 2 puntos de habilidad", enemys[x].name);
        enemys[x].vida = 0;
        jug->fuenteHabilidad += 4;
    }
    jug->vida = vidaIniJugador;
    return enemys[x];
}

void inventario(Jugador *jug)
{
    printLinea();
    if ((jug->Inventario).size == 0)
    {
        printf("\nEl inventario esta vacio\nExplora para adquirir objetos");
    }
    else
    {
        printf("\nInventario:\n");
        print_list(jug->Inventario);
    }
}

void estadisticas(Jugador *jug)
{
    int opcion;
    printLinea();
    printf("\nClase: %s\nVida restante: %d\nAgilidad %d\nStamina %d\nDano %d", jug->clase, jug->vida, jug->agilidad, jug->stamina, jug->dano);
    printf("\nQuieres utilizar los puntos de habilidad?, punto de habilidad actuales: %d\n1. Si\n2.No\nSeleccione una opcion > ", jug->fuenteHabilidad);
    scanf("%d", &opcion);
    while (opcion != 1 && opcion != 2)
    {
        printf("\nSeleccion invalida\nEscoja otra opcion > ");
        scanf("%d", &opcion);
    }
    if (opcion == 1)
    {
        int h;
        printf("\nQue desea mejorar?\n1. Vida\n2. dano\n3. agilidad\n4. Stamina\nElija una opcion > ");
        scanf("%d", &h);
        switch (h)
        {
        case 1:
            jug->vida += 100;
            break;
        case 2:
            jug->dano += 25;
            break;
        case 3:
            jug->agilidad += 1;
            break;
        case 4:
            jug->stamina += 1;
            break;
        default:
            printf("\nSeleccion invalidad, Saliendo...");
            break;
        }
        jug->fuenteHabilidad--;
    }
}
