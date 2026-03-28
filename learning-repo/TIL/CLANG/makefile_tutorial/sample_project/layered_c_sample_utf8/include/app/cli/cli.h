#ifndef APP_CLI_CLI_H
#define APP_CLI_CLI_H

#include <stddef.h>

#include "app/math/operations.h"

#define CLI_MAX_VALUES 32

typedef struct {
    double values[CLI_MAX_VALUES];
    size_t count;
    double baseline;
} CliConfig;

int cli_parse(int argc, char **argv, CliConfig *config);
void cli_print_usage(const char *program_name);
void cli_report(const CliConfig *config, const StatSummary *summary);

#endif /* APP_CLI_CLI_H */
