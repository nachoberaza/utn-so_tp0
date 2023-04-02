#include "client.h"
#include<readline/readline.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
    log_info(logger,"Iniciando programa...");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();
    ip = config_get_string_value(config,"IP");
    puerto = config_get_string_value(config,"PUERTO");
    valor = config_get_string_value(config,"VALOR");

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	//conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	//paquete(conexion);

	//terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
    log_destroy(logger);
    config_destroy(config);
    return 0;
}

t_log* iniciar_logger(void)
{
	return log_create("tp0.log","Client",false,LOG_LEVEL_INFO);
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("../src/tp0.config");
    return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido = readline("> ");

    while (strcmp(leido,"")){
        log_info(logger, leido);
        leido = readline("> ");
    }
    free(leido);
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
