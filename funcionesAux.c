#include "proyecto.h"

void printLinea()
{
    printf("\n------------------------------------------------------------------------------------------------------\n");
}

void guardarEstadisticas(Jugador *jugador, Enemy *enemigos, int numEnemigos)
{
    FILE *archivo = fopen("estadisticas.txt", "w");

    fprintf(archivo, "Jugador:\n");
    fprintf(archivo, "Nombre: %s\n", jugador->name);
    fprintf(archivo, "Vida: %d\n", jugador->vida);
    fprintf(archivo, "Stamina: %d\n", jugador->stamina);
    fprintf(archivo, "Daño: %d\n", jugador->dano);
    fprintf(archivo, "Agilidad: %d\n", jugador->agilidad);
    fprintf(archivo, "Fuente de Habilidad: %d\n", jugador->fuenteHabilidad);
    fprintf(archivo, "Clase: %s\n", jugador->clase);
    fprintf(archivo, "Posicion en el juego: %d\n", jugador->posGf);
    fprintf(archivo, "Pociones: %d\n", jugador->pociones);
    fprintf(archivo, "\n");
    fprintf(archivo, "Inventario:\n");
    Objeto *current = jugador->Inventario.head;
    while (current != NULL)
    {
        fprintf(archivo, "Objeto: %s\n", current->data);
        current = current->next;
    }
    fprintf(archivo, "\n");
    fprintf(archivo, "Enemigos:\n");
    for (int i = 0; i < numEnemigos; i++)
    {
        fprintf(archivo, "Nombre: %s\n", enemigos[i].name);
        fprintf(archivo, "Vida: %d\n", enemigos[i].vida);
        fprintf(archivo, "Descripcion: %s\n", enemigos[i].descrip);
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

void cargarEstadisticas(Jugador *jugador, Enemy **enemigos, int *numEnemigos)
{
    FILE *archivo = fopen("estadisticas.txt", "r");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        if (strcmp(buffer, "Jugador:\n") == 0)
        {
            fgets(buffer, sizeof(buffer), archivo); // Leer nombre
            jugador->name = strdup(buffer + strlen("Nombre: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer vida
            jugador->vida = atoi(buffer + strlen("Vida: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer stamina
            jugador->stamina = atoi(buffer + strlen("Stamina: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer daño
            jugador->dano = atoi(buffer + strlen("Daño: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer agilidad
            jugador->agilidad = atoi(buffer + strlen("Agilidad: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer fuente de habilidad
            jugador->fuenteHabilidad = atoi(buffer + strlen("Fuente de Habilidad: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer clase
            strcpy(jugador->clase, buffer + strlen("Clase: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer posicion en el juego
            jugador->posGf = atoi(buffer + strlen("Posicion en el juego: "));
            fgets(buffer, sizeof(buffer), archivo); // Leer pociones
            jugador->pociones = atoi(buffer + strlen("Pociones: "));
        }
        else if (strcmp(buffer, "Inventario:\n") == 0)
        {
            List inventario = create_list();
            while (fgets(buffer, sizeof(buffer), archivo) != NULL && strcmp(buffer, "\n") != 0)
            {
                if (strncmp(buffer, "Objeto: ", strlen("Objeto: ")) == 0)
                {
                    char *objeto = strdup(buffer + strlen("Objeto: "));
                    push(&inventario, objeto);
                }
            }
            jugador->Inventario = inventario;
        }
        else if (strcmp(buffer, "Enemigos:\n") == 0)
        {
            // Codigo para cargar enemigos
        }
    }

    fclose(archivo);
}

int isFileEmpty(const char *filename)
{
    FILE *file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        fclose(file);
        return 1; // El archivo esta vacio
    }

    fclose(file);
    return 0; // El archivo no esta vacio
}
void dibujo()
{
    printf("      _                      _______                      _\n");
    printf("   _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_\n");
    printf("  dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb\n");
    printf("  V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~      V\n");
    printf("           `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'\n");
    printf("            `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'\n");
    printf("       __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __\n");
    printf("     ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.\n");
    printf("  _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb._\n");
    printf(" <MMP'     `~YMMa_   YOOo   @  OOO  @   oOOP   _adMP~'      `YMM>\n");
    printf("              `YMMMM\\`OOOo     OOO     oOOO'/MMMMP'\n");
    printf("      ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.\n");
    printf("    ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.\n");
    printf("   ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM.\n");
    printf("   MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM\n");
    printf("   YMb           ~YMMMM\\`OOOOI`````IOOOOO'/MMMMP~           dMP\n");
    printf("    `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'\n");
    printf("      `'                  `OObNNNNNdOO'                   `'\n");
    printf("                            `~OOOOO~'  \n");
}
void dibujo2()
{
    printf(" _   __        _         _      _         ___       _                      _                           \n");
    printf("| | / /       (_)       | |    | |       / _ \\     | |                    | |                          \n");
    printf("| |/ /  _ __   _   __ _  | |__  | |_     / /_\\ \\  __| |__   __  ___  _ __  | |_  _   _  _ __   ___  ___ \n");
    printf("|    \\ | '_ \\ | | / _` | | '_ \\ | __|    |  _  | / _` |\\ \\ / / / _ \\| '_ \\ | __|| | | || '__| / _ \\/ __|\n");
    printf("| |\\  \\| | | || || (_| | | | | || |_     | | | || (_| | \\ V / |  __/| | | || |_ | |_| || |   |  __/\\__ \\\n");
    printf("\\_| \\_/|_| |_|\\__, | |_| |_| \\__|    \\_| |_/ \\__,_|  \\_/   \\___||_| |_| \\__| \\__,_||_|    \\___||___/\n");
    printf("               __/ |                                                                                   \n");
    printf("              |___/                                                                                    \n");
}