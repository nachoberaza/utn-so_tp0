#include "client.h"
#include<readline/readline.h>

int main(void) {

    int conexion;
    char *ip;
    char *puerto;
    char *valor;

    t_log *logger;
    t_config *config;

    logger = iniciar_logger();
    if (logger == NULL) {
        printf("No se pudo crear un logger\n\n");
        return 0;
    }
    log_info(logger, "Iniciando programa...");

    config = iniciar_config();
    if (config == NULL) {
        log_error(logger, "No se pudo crear un config");
        return 0;
    }

    ip = config_get_string_value(config, "IP");
    puerto = config_get_string_value(config, "PUERTO");

    conexion = crear_conexion(ip, puerto);
    if (conexion == NULL) {
        log_info(logger, "Error al crear la conexion...");
        return 0;
    }

    // Armamos y enviamos el paquete
    paquete(conexion);

    terminar_programa(conexion, logger, config);

    return 0;
}

t_log *iniciar_logger(void) {
    return log_create("tp0.log", "Client", false, LOG_LEVEL_INFO);
}

t_config *iniciar_config(void) {
    return config_create("../cliente.config");
}

void paquete(int conexion) {
    char *leido;
    t_paquete *paquete = crear_paquete();

    // Leemos y esta vez agregamos las lineas al paquete
    while (strcmp(leido, "") != 0) {
        leido = readline("> ");
        agregar_a_paquete(paquete, leido, string_length(leido));
    }
    enviar_paquete(paquete, conexion);

    free(leido);
    eliminar_paquete(paquete);
}

void terminar_programa(int conexion, t_log *logger, t_config *config) {
    liberar_conexion(conexion);
    log_destroy(logger);
    config_destroy(config);
}
