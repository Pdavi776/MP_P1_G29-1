/*******************************************
 * Asignatura: Metodología de la programación
 * Curso: 1
 * Tarea que realiza el programa: Gestión de clientes, habitaciones y reservas de un hotel
 * Alumno 1: <Marcos Tabernero Martín>
 * Alumno 2: <David Montero Esteban>
 * Grupo de laboratorio: <29_1>
 * Fecha: <24/02/2025>
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>

#define MAX_CLIENTES 100
#define MAX_HABITACIONES 50
#define MAX_LONGITUD 100
#define MAX_DIAS 30
#define MAX_RESERVAS_CLIENTE 5

typedef struct
{
    char nombre[MAX_LONGITUD];
    char apellidos[MAX_LONGITUD];
    char dni[10];
    int tipoCliente;
    int habReservadas; // contador de hab reservadas
} tReg_Cliente;

typedef struct
{
    char codigo[7];
    int tipoHabitacion;
    float precioNoche;
} tReg_Habitacion;

void mensajeBienvenida();
void gestionClientes(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes);
void gestionHabitaciones(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones);
void gestionReservas(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int *cont_reservas);
// void informesEconomicos();
// void importarHabitaciones();
int buscarcliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, char dni[10]);

void altaCliente(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes);
void bajaCliente(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes);
void modificarCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);
void consultaCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);
void listadoGeneralClientes(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);
void listadoPorCategoria(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);

void altaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones);
void bajaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones);
void modificarHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones);
int buscarHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char codigo[7]);
void consultaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones);
void listadoGeneralHabitaciones(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones);

void realizarReserva(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int *cont_reservas);
void cancelarReserva(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int *cont_reservas);
void consultarReservasCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10]);
void listadoGeneralReservas(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int cont_reservas);

int main()
{
    tReg_Cliente clientes[MAX_CLIENTES];            // registro de clientes
    tReg_Habitacion habitaciones[MAX_HABITACIONES]; // registro de habitaciones

    char reservas[MAX_DIAS][MAX_HABITACIONES][10]; // matriz de reservas

    for (int i = 0; i < MAX_DIAS; i++)
    {
        for (int j = 0; j < MAX_HABITACIONES; j++)
        {
            reservas[i][j][0] = '\0'; // Marca la celda como vacía
        }
    }

    int opcion, cont_habitaciones = 0, cont_clientes = 0, cont_reservas = 0;

    setlocale(LC_ALL, "spanish");

    mensajeBienvenida();

    do
    {
        system("cls");
        printf("MENÚ PRINCIPAL");
        printf("\n-----------------------");
        printf("\n\t 1.- Gestion de clientes");
        printf("\n\t 2.- Gestion de habitaciones");
        printf("\n\t 3.- Gestion de reservas");
        printf("\n\t 4.- Informes Económicos");
        printf("\n\t 5.- Importar Habitaciones desde Fichero");
        printf("\n\t 0.- Salir");
        printf("\n Elija opción: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            gestionClientes(clientes, &cont_clientes);
            break;
        case 2:
            gestionHabitaciones(habitaciones, &cont_habitaciones);
            break;
        case 3:
            gestionReservas(clientes, cont_clientes, habitaciones, cont_habitaciones, reservas, &cont_reservas);
            break;
        case 4:
            // informesEconomicos();
            break;
        case 5:
            // importarHabitaciones();
            break;
        case 0:
            break;
        default:
            printf("Por favor, introduzca una opción válida.\n\n");
            system("pause");
            break;
        }
    } while (opcion != 0);

    return 0;
}

void mensajeBienvenida()
{
    system("cls");
    printf("\n\n\tBienvenido al programa GEST-HOTEL\n\n");
    system("pause");
}

void gestionClientes(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes)
{
    int opcion;

    do
    {
        system("cls");
        printf("GESTIÓN DE CLIENTES");
        printf("\n----------------------------------");
        printf("\n\t 1.- Alta");
        printf("\n\t 2.- Baja");
        printf("\n\t 3.- Modificación");
        printf("\n\t 4.- Consulta");
        printf("\n\t 5.- Listado general");
        printf("\n\t 6.- Listado por categoría");
        printf("\n\t 0.- Volver al menú principal");

        printf("\n Elija opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            altaCliente(clientes, &*cont_clientes);
            break;
        case 2:
            bajaCliente(clientes, &*cont_clientes);
            break;
        case 3:
            modificarCliente(clientes, *cont_clientes);
            break;
        case 4:
            consultaCliente(clientes, *cont_clientes);
            break;
        case 5:
            listadoGeneralClientes(clientes, *cont_clientes);
            break;
        case 6:
            listadoPorCategoria(clientes, *cont_clientes);
            break;
        case 0:
            break;

        default:
            printf("Por favor, introduzca una opción válida.\n\n");
            system("pause");
            break;
        }
    } while (opcion != 0);
}

void gestionHabitaciones(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones)
{
    int opcion;

    do
    {
        system("cls");
        printf("GESTIÓN DE HABITACIONES");
        printf("\n----------------------------------");
        printf("\n\t 1.- Alta");
        printf("\n\t 2.- Baja");
        printf("\n\t 3.- Modificación");
        printf("\n\t 4.- Consulta");
        printf("\n\t 5.- Listado general");
        printf("\n\t 0.- Volver al menú principal");
        printf("\n Elija opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            altaHabitacion(habitaciones, &*cont_habitaciones);
            break;
        case 2:
            bajaHabitacion(habitaciones, &*cont_habitaciones);
            break;
        case 3:
            modificarHabitacion(habitaciones, *cont_habitaciones);
            break;
        case 4:
            consultaHabitacion(habitaciones, *cont_habitaciones);
            break;
        case 5:
            listadoGeneralHabitaciones(habitaciones, *cont_habitaciones);
            break;
        case 0:
            break;
        default:
            printf("Por favor, introduzca una opción válida.\n\n");
            system("pause");
            break;
        }
    } while (opcion != 0);
}

void gestionReservas(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int *cont_reservas)
{
    system("cls");
    int opcion;

    do
    {
        system("cls");
        printf("GESTIÓN DE RESERVAS");
        printf("\n----------------------------------");
        printf("\n\t 1.- Realizar Reserva");
        printf("\n\t 2.- Cancelar Reserva");
        printf("\n\t 3.- Consultar Reservas de un Cliente");
        printf("\n\t 4.- Listado General de Reservas");
        printf("\n\t 0.- Volver al menú principal");
        printf("\n Elija opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            realizarReserva(clientes, cont_clientes, habitaciones, cont_habitaciones, reservas, &*cont_reservas);
            break;
        case 2:
            cancelarReserva(clientes, cont_clientes, habitaciones, cont_habitaciones, reservas, &*cont_reservas);
            break;

        case 3:
            consultarReservasCliente(clientes, cont_clientes, habitaciones, cont_habitaciones, reservas);
            break;

        case 4:
            listadoGeneralReservas(clientes, cont_clientes, habitaciones, cont_habitaciones, reservas, *cont_reservas);
            break;

        case 0:
            break;

        default:
            printf("Por favor, introduzca una opción válida.\n\n");
            system("pause");
            break;
        }
    } while (opcion != 0);
}
/*
void informesEconomicos()
{
    int opcion;
    do
    {
        system("cls");
        printf("\nINFORMES ECONÓMICOS");
        printf("\n----------------------------------");
        printf("\n\t 1.- Informe mensual por categoría de cliente\n");
        printf("\n\t 2.- Informe mensual de ocupación de habitaciones\n");
        printf("\n\t 3.- Informe mensual de ingresos por reservas\n");
        printf("\n\t 0.- Volver al menú principal\n\n\n");
        printf("\n Elija opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            informeMensualCategoriaCliente();
            system("cls");
            break;

        case 2:
            informeMensualOcupacionHabitaciones();
            system("cls");
            break;

        case 3:
            informeMensualIngresosReservas();
            system("cls");
            break;

        case 0:
            system("cls");
            return;

        default:
            printf("Por favor, introduzca una opción válida.\n\n");
            system("pause");
            break;
        }
    } while (opcion != 0);
}*/

void altaCliente(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes)
{
    char resp;
    int valido;

    do
    {
        do
        {
            valido = 1;

            system("cls");
            printf("ALTA DE CLIENTE");
            printf("\n----------------------------------");
            printf("\nIntroduce los siguientes datos del cliente %d:", *cont_clientes + 1);

            printf("\nDNI: "); // validacion
            scanf("%s", clientes[*cont_clientes].dni);

            for (int i = 0; i < *cont_clientes; i++) // buscar
            {
                if (strcmp(clientes[i].dni, clientes[*cont_clientes].dni) == 0)
                {
                    printf("\nERROR: DNI ya registrado. Inserte un DNI válido...\n");
                    system("pause");
                    valido = 0;
                    break;
                }
            }
        } while (valido == 0);

        printf("\nNOMBRE: ");
        fflush(stdin);
        fgets(clientes[*cont_clientes].nombre, MAX_LONGITUD, stdin);
        strtok(clientes[*cont_clientes].nombre, "\n");

        printf("\nAPELLIDOS: ");
        fflush(stdin);
        fgets(clientes[*cont_clientes].apellidos, MAX_LONGITUD, stdin);
        strtok(clientes[*cont_clientes].apellidos, "\n");

        do
        {
            printf("\nTIPO (1.- Normal)(2.- VIP)(3.- Empresa): ");
            scanf("%d", &clientes[*cont_clientes].tipoCliente);

            if ((clientes[*cont_clientes].tipoCliente != 1) && (clientes[*cont_clientes].tipoCliente != 2) && (clientes[*cont_clientes].tipoCliente != 3))
            {
                printf("\nERROR: Tipo de cliente no válido. Inserte un tipo de cliente válido...\n\n");
                system("pause");
            }

        } while ((clientes[*cont_clientes].tipoCliente != 1) && (clientes[*cont_clientes].tipoCliente != 2) && (clientes[*cont_clientes].tipoCliente != 3));

        (*cont_clientes)++;

        printf("\n\n ¿Desea seguir dandod de alta clientes? (Y/N)");

        scanf("%c", &resp);
        resp = tolower(resp);

    } while (*cont_clientes < MAX_CLIENTES && resp == 'y');
}

void bajaCliente(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes)
{
    char dni[10], resp;
    int posicion;

    do
    {
        system("cls");
        printf("BAJA DE CLIENTE");
        printf("\n----------------------------------");
        printf("\nIntroduce el DNI del cliente a dar de baja: ");
        scanf("%s", dni);

        posicion = buscarcliente(clientes, *cont_clientes, dni);

        if (posicion == -1)
        {
            printf("\nERROR: Cliente no encontrado\n");
            system("pause");
        }
        else
        {
            for (int i = posicion; i < *cont_clientes - 1; i++)
            {
                clientes[i] = clientes[i + 1];
            }
            (*cont_clientes)--;
            printf("\nCliente dado de baja correctamente.\n");
        }

        printf("\n\n ¿Desea seguir dando de baja clientes? (Y/N): ");
        
        scanf(" %c", &resp);
        resp = tolower(resp);

    } while (posicion == -1 || resp == 'y');
}

int buscarcliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, char dni[10])
{
    for (int i = 0; i < cont_clientes; i++)
    {
        if (strcmp(clientes[i].dni, dni) == 0)
        {
            return i;
        }
    }
    return -1;
}

// no se si está terminado
void consultaCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes)
{
    char dni[10];
    int posicion;

    system("cls");
    printf("CONSULTA DE CLIENTE");
    printf("\n----------------------------------");
    printf("\nIntroduce el DNI del cliente a consultar: ");
    scanf("%s", dni);

    posicion = buscarcliente(clientes, cont_clientes, dni);

    if (buscarcliente(clientes, cont_clientes, dni) == -1)
    {
        printf("\nERROR: Cliente no encontrado\n");
        system("pause");
    }
    else
    {
        printf("\nNombre: %s", clientes[posicion].nombre);
        printf("\nApellidos: %s", clientes[posicion].apellidos);
        printf("\nDNI: %s", clientes[posicion].dni);
        printf("\nTipo de cliente: %d", clientes[posicion].tipoCliente);
        printf("\nHabitaciones reservadas: %d", clientes[posicion].habReservadas);
    }
    system("pause");
}

void modificarCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes)
{
    int posicion, opcion;
    char dni[10], resp;

    do
    {
        system("cls");
        printf("MODIFICACIÓN DE CLIENTE");
        printf("\n----------------------------------");
        printf("\nIntroduce el DNI del cliente a modificar: ");
        scanf("%s", dni);

        posicion = buscarcliente(clientes, cont_clientes, dni);

        printf("\nInformación actual del cliente:");

        printf("\n\nDNI: %s", clientes[posicion].dni);
        printf("\nNombre: %s", clientes[posicion].nombre);
        printf("\nApellidos: %s", clientes[posicion].apellidos);
        printf("\nTipo de cliente: %d", clientes[posicion].tipoCliente);
        printf("\nHabitaciones reservadas: %d", clientes[posicion].habReservadas);

        printf("\n\nElija la informacion que desea modificar...\n<Excepto dni y habitaciones reservadas>\n(1.-Nombre, 2.-Apellidos, 3.-Tipo, 4.-Todo): ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: // codigo para mdificar el NOMBRE del cliente
            printf("\nNuevo nombre: ");
            fflush(stdin);
            fgets(clientes[posicion].nombre, MAX_LONGITUD, stdin);
            strtok(clientes[posicion].nombre, "\n");
            break;

        case 2: // codigo para modificar los APELLIDOS del cliente
            printf("\nNuevos apellidos: ");
            fgets(clientes[posicion].apellidos, MAX_LONGITUD, stdin);
            strtok(clientes[posicion].apellidos, "\n");
            break;

        case 3: // codigo para modificar el TIPO de cliente
            do
            {
                printf("\nTIPO (1.- Normal)(2.- VIP)(3.- Empresa): ");
                scanf("%d", &clientes[posicion].tipoCliente);

                if ((clientes[posicion].tipoCliente != 1) && (clientes[posicion].tipoCliente != 2) && (clientes[posicion].tipoCliente != 3))
                {
                    printf("\nERROR: Tipo de cliente no válido. Inserte un tipo de cliente válido...\n\n");
                    system("pause");
                }
            } while ((clientes[posicion].tipoCliente != 1) && (clientes[posicion].tipoCliente != 2) && (clientes[posicion].tipoCliente != 3));
            break;

        case 4: // codigo para modificar todos los campos posibles
            printf("\nNuevo nombre: ");
            fgets(clientes[posicion].nombre, MAX_LONGITUD, stdin);
            strtok(clientes[posicion].nombre, "\n");

            printf("\nNuevos apellidos: ");
            fgets(clientes[posicion].apellidos, MAX_LONGITUD, stdin);
            strtok(clientes[posicion].apellidos, "\n");

            do
            {
                printf("\nTIPO (1.- Normal)(2.- VIP)(3.- Empresa): ");
                scanf("%d", &clientes[posicion].tipoCliente);

                if ((clientes[posicion].tipoCliente != 1) && (clientes[posicion].tipoCliente != 2) && (clientes[posicion].tipoCliente != 3))
                {
                    printf("\nERROR: Tipo de cliente no válido. Inserte un tipo de cliente válido...\n\n");
                    system("pause");
                }
            } while ((clientes[posicion].tipoCliente != 1) && (clientes[posicion].tipoCliente != 2) && (clientes[posicion].tipoCliente != 3));

            break;

        default:
            printf("\nERROR: Opción no válida\n");
            system("pause");
            break;
        }

        if (posicion == -1)
        {
            printf("\nERROR: Cliente no encontrado\n");
            system("pause");
        }

        printf("\n\n ¿Desea seguir modificando clientes? (Y/N)");

        scanf("%c", &resp);

    } while (posicion == -1 || resp == 'y' || resp == 'Y');
}

void listadoGeneralClientes(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes)
{
    system("cls");
    printf("LISTADO GENERAL DE CLIENTES");
    printf("\n--------------------------------------------------");

    printf("\n\t\t  Nombre y apellidos\t\tDNI\t\tCategoría\n");

    for (int i = 0; i < cont_clientes; i++)
    {
        printf("\n\t\t%s %s\t\t%s\t\t", clientes[i].nombre, clientes[i].apellidos, clientes[i].dni);

        switch (clientes[i].tipoCliente)
        {
        case 1:
            printf("Normal");
            break;
        case 2:
            printf("VIP");
            break;
        case 3:
            printf("Empresa");
            break;
        default:
            break;
        }
    }
    printf("\n\n");
    system("pause");
}

void altaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones)
{
    char resp;
    int valido;

    do
    {
        do
        {
            valido = 1;

            system("cls");
            printf("ALTA DE HABITACIÓN");
            printf("\n----------------------------------");
            printf("\nIntroduce los siguientes datos de la habitación %d:", *cont_habitaciones + 1);

            printf("\nCÓDIGO: ");
            scanf("%s", habitaciones[*cont_habitaciones].codigo);

            for (int i = 0; i < *cont_habitaciones; i++)
            {
                if (strcmp(habitaciones[i].codigo, habitaciones[*cont_habitaciones].codigo) == 0)
                {
                    printf("\nERROR: Código ya registrado. Inserte un código válido...\n");
                    system("pause");
                    valido = 0;
                    break;
                }
            }
        } while (valido == 0);

        do
        {
            printf("\nTIPO (1.- Individual)(2.- Doble)(3.- Suite): ");
            scanf("%d", &habitaciones[*cont_habitaciones].tipoHabitacion);

            if ((habitaciones[*cont_habitaciones].tipoHabitacion != 1) && (habitaciones[*cont_habitaciones].tipoHabitacion != 2) && (habitaciones[*cont_habitaciones].tipoHabitacion != 3))
            {
                printf("\nERROR: Tipo de habitación no válido. Inserte un tipo de habitación válido...\n\n");
                system("pause");
            }

        } while ((habitaciones[*cont_habitaciones].tipoHabitacion != 1) && (habitaciones[*cont_habitaciones].tipoHabitacion != 2) && (habitaciones[*cont_habitaciones].tipoHabitacion != 3));

        do
        {
            printf("\nPRECIO POR NOCHE: ");
            scanf("%f", &habitaciones[*cont_habitaciones].precioNoche);
            if (habitaciones[*cont_habitaciones].precioNoche < 0)
            {
                printf("\nERROR: Precio no válido. Inserte un precio válido...\n\n");
                system("pause");
            }
        } while (habitaciones[*cont_habitaciones].precioNoche < 0);

        (*cont_habitaciones)++;

        printf("\n\n ¿Desea seguir dandod de alta habitaciones? (Y/N)");
        resp = scanf("%c", &resp);
        resp = tolower(resp);

    } while (*cont_habitaciones < MAX_HABITACIONES && resp == 'y');
}

void bajaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones)
{
    char codigo[7], resp;
    int posicion;

    do
    {
        system("cls");
        printf("BAJA DE HABITACIÓN");
        printf("\n----------------------------------");
        printf("\nIntroduce el código de la habitación a dar de baja: ");
        scanf("%s", codigo);

        posicion = buscarHabitacion(habitaciones, *cont_habitaciones, codigo);

        if (posicion == -1)
        {
            printf("\nERROR: Habitación no encontrada\n");
            system("pause");
        }
        else
        {
            for (int i = posicion; i < *cont_habitaciones - 1; i++)
            {
                habitaciones[i] = habitaciones[i + 1];
            }
            (*cont_habitaciones)--;
            printf("\nHabitación dada de baja correctamente.\n");
        }

        printf("\n\n ¿Desea seguir dando de baja habitaciones? (Y/N)");
        resp = scanf("%c", &resp);

    } while (posicion == -1 || resp == 'y' || resp == 'Y');
}

int buscarHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char codigo[7])
{
    for (int i = 0; i < cont_habitaciones; i++)
    {
        if (strcmp(habitaciones[i].codigo, codigo) == 0)
        {
            return i;
        }
    }
    return -1;
}

void consultaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones)
{
    char codigo[7];
    int posicion;

    system("cls");
    printf("CONSULTA DE HABITACIÓN");
    printf("\n----------------------------------");
    printf("\nIntroduce el código de la habitación a consultar: ");
    scanf("%s", codigo);

    posicion = buscarHabitacion(habitaciones, cont_habitaciones, codigo);

    if (buscarHabitacion(habitaciones, cont_habitaciones, codigo) == -1)
    {
        printf("\nERROR: Habitación no encontrada\n");
        system("pause");
    }
    else
    {
        printf("\nCÓDIGO: %s", habitaciones[posicion].codigo);
        printf("\nTipo de habitación: %d", habitaciones[posicion].tipoHabitacion);
        printf("\nPrecio por noche: %.2f", habitaciones[posicion].precioNoche);
    }
    system("pause");
}

void modificarHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones)
{
    int posicion, opcion;
    char codigo[7], resp;

    do
    {
        system("cls");
        printf("MODIFICACIÓN DE HABITACIÓN");
        printf("\n----------------------------------");
        printf("\nIntroduce el código de la habitación a modificar: ");
        scanf("%s", codigo);

        posicion = buscarHabitacion(habitaciones, cont_habitaciones, codigo);

        printf("\nInformación actual de la habitación:");

        printf("\n\nCÓDIGO: %s", habitaciones[posicion].codigo);
        printf("\nTipo de habitación: %d", habitaciones[posicion].tipoHabitacion);
        printf("\nPrecio por noche: %.2f", habitaciones[posicion].precioNoche);

        printf("\n\nElija la informacion que desea modificar...\n<Excepto código>\n(1.-Tipo, 2.-Precio, 3.-Todo): ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: // codigo para mdificar el TIPO de la habitación
            do
            {
                printf("\nTIPO (1.- Individual)(2.- Doble)(3.- Suite): ");
                scanf("%d", &habitaciones[posicion].tipoHabitacion);

                if ((habitaciones[posicion].tipoHabitacion != 1) && (habitaciones[posicion].tipoHabitacion != 2) && (habitaciones[posicion].tipoHabitacion != 3))
                {
                    printf("\nERROR: Tipo de habitación no válido. Inserte un tipo de habitación válido...\n\n");
                    system("pause");
                }

            } while ((habitaciones[posicion].tipoHabitacion != 1) && (habitaciones[posicion].tipoHabitacion != 2) && (habitaciones[posicion].tipoHabitacion != 3));
            break;

        case 2: // codigo para modificar el PRECIO de la habitación
            do
            {
                printf("\nPRECIO POR NOCHE: ");
                scanf("%f", &habitaciones[posicion].precioNoche);
                if (habitaciones[posicion].precioNoche < 0)
                {
                    printf("\nERROR: Precio no válido. Inserte un precio válido...\n\n");
                    system("pause");
                }
            } while (habitaciones[posicion].precioNoche < 0);
            break;

        case 3: // codigo para modificar todos los campos posibles
            do
            {
                printf("\nTIPO (1.- Individual)(2.- Doble)(3.- Suite): ");
                scanf("%d", &habitaciones[posicion].tipoHabitacion);

                if ((habitaciones[posicion].tipoHabitacion != 1) && (habitaciones[posicion].tipoHabitacion != 2) && (habitaciones[posicion].tipoHabitacion != 3))
                {
                    printf("\nERROR: Tipo de habitación no válido. Inserte un tipo de habitación válido...\n\n");
                    system("pause");
                }

            } while ((habitaciones[posicion].tipoHabitacion != 1) && (habitaciones[posicion].tipoHabitacion != 2) && (habitaciones[posicion].tipoHabitacion != 3));

            do
            {
                printf("\nPRECIO POR NOCHE: ");
                scanf("%f", &habitaciones[posicion].precioNoche);
                if (habitaciones[posicion].precioNoche < 0)
                {
                    printf("\nERROR: Precio no válido. Inserte un precio válido...\n\n");
                    system("pause");
                }
            } while (habitaciones[posicion].precioNoche < 0);
            break;

        default:
            printf("\nERROR: Opción no válida\n");
            system("pause");
            break;
        }

        if (posicion == -1)
        {
            printf("\nERROR: Habitación no encontrada\n");
            system("pause");
        }

        printf("\n\n ¿Desea seguir modificando habitaciones? (Y/N)");
        scanf("%c", &resp);

    } while (posicion == -1 || resp == 'y' || resp == 'Y');
}

void listadoGeneralHabitaciones(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones)
{
    system("cls");
    printf("LISTADO GENERAL DE HABITACIONES");
    printf("\n--------------------------------------------------");

    printf("\n\t\t Código\t\tTipo\t\tPrecio/noche(€)\n");

    for (int i = 0; i < cont_habitaciones; i++)
    {
        printf("\n\t\t %s\t\t", habitaciones[i].codigo);

        switch (habitaciones[i].tipoHabitacion)
        {
        case 1:
            printf("Individual");
            break;
        case 2:
            printf("Doble");
            break;
        case 3:
            printf("Suite");
            break;
        default:
            break;
        }

        printf("\t\t%.2f", habitaciones[i].precioNoche);
    }
    printf("\n\n");
    system("pause");
}

void realizarReserva(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int *cont_reservas)
{
    char dni[10], codigo[7];
    int posicionCliente, posicionHabitacion, diames;

    // cargarDatosReservas(reservas, MAX_DIAS, MAX_HABITACIONES);

    system("cls");
    printf("REALIZAR RESERVA");
    printf("\n----------------------------------");

    printf("\nIntroduce el DNI del cliente: ");
    scanf("%s", dni);

    posicionCliente = buscarcliente(clientes, cont_clientes, dni);

    if (posicionCliente == -1)
    {
        printf("\nERROR: Cliente no encontrado\n");
        system("pause");
        return;
    }
    else if (clientes[posicionCliente].habReservadas == MAX_RESERVAS_CLIENTE)
    {
        printf("\nERROR: El cliente ya tiene el máximo de habitaciones (5) reservadas\n");
        system("pause");
        return;
    }

    printf("\nIntroduce el código de la habitación: ");
    scanf("%s", codigo);

    posicionHabitacion = buscarHabitacion(habitaciones, cont_habitaciones, codigo);

    if (posicionHabitacion == -1)
    {
        printf("\nERROR: Habitación no encontrada\n");
        system("pause");
        return;
    }

    printf("\nIntroduce el día del mes: ");
    scanf("%d", &diames);

    if (diames < 1 || diames > 31)
    {
        printf("\nERROR: Día no válido\n");
        system("pause");
        return;
    }

    // Si no está vacío, ya está reservada
    if (reservas[diames - 1][posicionHabitacion][0] != '\0')
    {
        printf("\nERROR: Habitación ya reservada en ese día\n");
        system("pause");
        return;
    }

    // Almacenar el DNI del cliente
    strcpy(reservas[diames - 1][posicionHabitacion], dni);
    clientes[posicionCliente].habReservadas++; // Incrementar el contador de habitaciones reservadas del cliente
    (*cont_reservas)++;
    printf("\nReserva realizada correctamente.\n");
    system("pause");
}

void cancelarReserva(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int *cont_reservas)
{
    char dni[10];
    int posicionCliente, reservasEliminadas = 0;

    // time_t tiempo actual, meter arriba una variable y esto sirve para los ficheros

    system("cls");
    printf("CANCELAR RESERVA");
    printf("\n----------------------------------");
    printf("\nIntroduce el DNI del cliente: ");
    scanf("%s", dni);

    // validardni(); // Validar el DNI con el subprograma indicado

    posicionCliente = buscarcliente(clientes, cont_clientes, dni);

    if (posicionCliente == -1)
    {
        printf("\nERROR: Cliente no encontrado\n");
        system("pause");
        return;
    }

    // Cancelar la reserva
    for (int i = 0; i < MAX_DIAS; i++)
    {
        for (int j = 0; j < MAX_HABITACIONES; j++)
        {
            if (strcmp(reservas[i][j], dni) == 0)
            {
                reservas[i][j][0] = '\0'; // Eliminar la reserva
                reservasEliminadas++;

                if (*cont_reservas > 0)
                {
                    (*cont_reservas)--;
                } // Decrementar el contador de reservas totales si es mayor que 0

                clientes[posicionCliente].habReservadas--; // Decrementar el contador de habitaciones reservadas del cliente
            }
        }
    }

    if (reservasEliminadas > 0)
    {
        printf("\nSe han eliminado %d reservas asociadas al cliente con DNI %s.\n", reservasEliminadas, dni);
    }
    else
    {
        printf("\nNo se encontraron reservas asociadas al cliente con DNI %s.\n", dni);
    }
    // falta meterlo al fichero cada una de las reservas que se quitan
    system("pause");
}

void consultarReservasCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10])
{
    char resp;
    char dni[10];
    float importeTotal = 0.0;

    do
    {
        system("cls");
        printf("CONSULTAR RESERVAS DE UN CLIENTE");
        printf("\n-----------------------------------------------");
        printf("\nIntroduce el DNI del cliente a considerar: ");
        scanf("%s", dni);

        int posicionCliente = buscarcliente(clientes, cont_clientes, dni);

        if (posicionCliente == -1)
        {
            printf("\nERROR: Cliente no encontrado\n");
            system("pause");
            return;
        }

        printf("\nReservas del cliente %s %s con DNI: %s):\n", clientes[posicionCliente].nombre, clientes[posicionCliente].apellidos, clientes[posicionCliente].dni);
        printf("\nDía\tCódigo Habitación\tTipo Habitación\tPrecio por Noche\n");
        printf("---------------------------------------------------------------\n");

        // Recorrer la matriz de reservas para buscar las habitaciones reservadas por el cliente
        for (int i = 0; i < MAX_DIAS; i++)
        {
            for (int j = 0; j < cont_habitaciones; j++)
            {
                if (strcmp(reservas[i][j], dni) == 0)
                {
                    printf("%d\t%s\t\t\t%d\t\t%.2f\n", i + 1, habitaciones[j].codigo, habitaciones[j].tipoHabitacion, habitaciones[j].precioNoche);
                    importeTotal += habitaciones[j].precioNoche;
                }
            }
        }

        printf("\nImporte total de las reservas: %.2f\n", importeTotal);

        printf("\n\n ¿Desea seguir consultando reservas de clientes? (Y/N): ");
        scanf(" %c", &resp);

    } while (resp == 'y' || resp == 'Y');
}

void listadoGeneralReservas(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char reservas[MAX_DIAS][MAX_HABITACIONES][10], int cont_reservas)
{
    system("cls");
    printf("LISTADO GENERAL DE RESERVAS");
    printf("\n-----------------------------------------------");
    printf("\n\t  Nombre Cliente \t\tCódigo habitación \t\tTipo habitación");

    for (int i = 0; i < MAX_DIAS; i++)
    {
        for (int j = 0; j < cont_habitaciones; j++)
        {
            // Comprobar si la reserva está ocupada para no tener errores posteriores
            if (reservas[i][j][0] != '\0')
            {
                // Buscar al cliente por su DNI en la matriz de reservas
                int posicionCliente = buscarcliente(clientes, cont_clientes, reservas[i][j]);
                if (posicionCliente != -1)
                {
                    printf("%s %s\t\t%s\t\t%d\n", clientes[posicionCliente].nombre, clientes[posicionCliente].apellidos, habitaciones[j].codigo, habitaciones[j].tipoHabitacion);
                }
            }
        }
    }

    printf("\n\n TOTAL: %d reservas activas", cont_reservas);

    system("pause");
}