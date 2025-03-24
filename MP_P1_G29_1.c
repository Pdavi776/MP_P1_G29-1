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
#define MAX_DIAS 31

typedef struct
{
    char nombre[MAX_LONGITUD];
    char apellidos[MAX_LONGITUD];
    char dni[10];
    int tipoCliente;
    int habReservadas;
} tReg_Cliente;

typedef struct
{
    char codigo[7];
    int tipoHabitacion;
    float precioNoche;
} tReg_Habitacion;

void mensajeBienvenida(); // subprograma terminado
void gestionClientes();
void gestionHabitaciones();
void gestionHabitaciones();
void gestionReservas();
void informesEconomicos();
void importarHabitaciones();
int buscarcliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes, char dni[10]); // subprograma terminado

void altaCliente(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes); // subprograma terminado (probar)
void bajaCliente(tReg_Cliente clientes[MAX_CLIENTES], int *cont_clientes);
void modificarCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);
void consultaCliente(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);
void listadoGeneralClientes(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);
void listadoPorCategoria(tReg_Cliente clientes[MAX_CLIENTES], int cont_clientes);

void altaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones); // subprograma terminado (probar)
void bajaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int *cont_habitaciones);
void modificarHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones);
int buscarHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones, char codigo[7]);
void consultaHabitacion(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones);
void listadoGeneralHabitaciones(tReg_Habitacion habitaciones[MAX_HABITACIONES], int cont_habitaciones);

void realizarReserva();
void cancelarReserva();
void consultarReservasCliente();
void listadoGeneralReservas();

int main()
{
    tReg_Cliente clientes[MAX_CLIENTES];
    tReg_Habitacion habitaciones[MAX_HABITACIONES];
    int opcion;

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
            gestionClientes(clientes);
            break;
        case 2:
            gestionHabitaciones();
            break;
        case 3:
            gestionReservas();
            break;
        case 4:
            informesEconomicos();
            break;
        case 5:
            importarHabitaciones();
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

void gestionClientes(tReg_Cliente clientes[MAX_CLIENTES])
{
    int opcion, cont_clientes;

    cont_clientes = 0;

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
            altaCliente(clientes, &cont_clientes);
            break;
        case 2:
            bajaCliente(clientes, &cont_clientes);
            break;
        case 3:
            modificarCliente(clientes, cont_clientes);
            break;
        case 4:
            consultaCliente(clientes, cont_clientes);
            break;
        case 5:
            listadoGeneralClientes(clientes, cont_clientes);
            break;
        case 6:
            listadoPorCategoria(clientes, cont_clientes);
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

void gestionHabitaciones()
{
    int opcion, cont_habitaciones;

    cont_habitaciones = 0;

    tReg_Habitacion habitaciones[MAX_HABITACIONES];

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
            altaHabitacion(habitaciones, &cont_habitaciones);
            break;
        case 2:
            bajaHabitacion(habitaciones, &cont_habitaciones);
            break;
        case 3:
            modificarHabitacion(habitaciones, cont_habitaciones);
            break;
        case 4:
            consultaHabitacion(habitaciones, cont_habitaciones);
            break;
        case 5:
            listadoGeneralHabitaciones(habitaciones, cont_habitaciones);
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

void gestionReservas()
{
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
            realizarReserva();
            break;

        case 2:
            cancelarReserva();
            break;

        case 3:
            consultarReservasCliente();
            break;

        case 4:
            listadoGeneralReservas();
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
}

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
        } while ((valido = 0));

        printf("\nNOMBRE: ");
        fgets(clientes[*cont_clientes].nombre, MAX_LONGITUD, stdin);
        strtok(clientes[*cont_clientes].nombre, "\n");

        printf("\nAPELLIDOS: ");
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

        resp = scanf("%c", &resp);
        resp = tolower(resp);

    } while (*cont_clientes < MAX_CLIENTES && resp == 'y');
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

        resp = scanf("%c", &resp);

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
        } while ((valido = 0));

        do
        {
            printf("\nTIPO (1.- Individual)(2.- Doble)(3.- Suite): ");
            scanf("%d", &habitaciones[*cont_habitaciones].tipoHabitacion);

            if ((habitaciones[*cont_habitaciones].tipoHabitacion != 1) || (habitaciones[*cont_habitaciones].tipoHabitacion != 2) || (habitaciones[*cont_habitaciones].tipoHabitacion != 3))
            {
                printf("\nERROR: Tipo de habitación no válido. Inserte un tipo de habitación válido...\n\n");
                system("pause");
            }

        } while ((habitaciones[*cont_habitaciones].tipoHabitacion != 1) || (habitaciones[*cont_habitaciones].tipoHabitacion != 2) || (habitaciones[*cont_habitaciones].tipoHabitacion != 3));

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

        posicion = buscarhabitacion(habitaciones, cont_habitaciones, codigo);

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

                if ((habitaciones[posicion].tipoHabitacion != 1) || (habitaciones[posicion].tipoHabitacion != 2) || (habitaciones[posicion].tipoHabitacion != 3))
                {
                    printf("\nERROR: Tipo de habitación no válido. Inserte un tipo de habitación válido...\n\n");
                    system("pause");
                }

            } while ((habitaciones[posicion].tipoHabitacion != 1) || (habitaciones[posicion].tipoHabitacion != 2) || (habitaciones[posicion].tipoHabitacion != 3));
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

                if ((habitaciones[posicion].tipoHabitacion != 1) || (habitaciones[posicion].tipoHabitacion != 2) || (habitaciones[posicion].tipoHabitacion != 3))
                {
                    printf("\nERROR: Tipo de habitación no válido. Inserte un tipo de habitación válido...\n\n");
                    system("pause");
                }

            } while ((habitaciones[posicion].tipoHabitacion != 1) || (habitaciones[posicion].tipoHabitacion != 2) || (habitaciones[posicion].tipoHabitacion != 3));

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
        resp = scanf("%c", &resp);

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