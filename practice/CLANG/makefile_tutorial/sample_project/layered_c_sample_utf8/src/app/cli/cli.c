#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app/cli/cli.h"

static int parse_double(const char *text, double *out)
{
    char *end = NULL;
    errno = 0;
    const double value = strtod(text, &end);
    if (errno != 0 || end == text || (end != NULL && *end != '\0')) {
        return 0;
    }
    *out = value;
    return 1;
}

int cli_parse(int argc, char **argv, CliConfig *config)
{
    if (config == NULL || argv == NULL) {
        return 0;
    }

    config->count = 0U;
    config->baseline = 0.0;

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        if (strncmp(arg, "--baseline=", 11) == 0) {
            if (!parse_double(arg + 11, &config->baseline)) {
                fprintf(stderr, "cannot parse baseline from '%s'\n", arg);
                return 0;
            }
            continue;
        }

        if (config->count >= CLI_MAX_VALUES) {
            fprintf(stderr, "too many values (max %d)\n", CLI_MAX_VALUES);
            return 0;
        }

        if (!parse_double(arg, &config->values[config->count])) {
            fprintf(stderr, "cannot parse measurement '%s'\n", arg);
            return 0;
        }

        ++config->count;
    }

    if (config->count == 0U) {
        fprintf(stderr, "provide at least one measurement\n");
        return 0;
    }

    return 1;
}

void cli_print_usage(const char *program_name)
{
    fprintf(stderr,
            "Usage: %s [--baseline=value] measurement1 measurement2 ...\n",
            program_name != NULL ? program_name : "layered_stats");
    fprintf(stderr,
            "Example: %s --baseline=25.0 24.2 26 25.5\n",
            program_name != NULL ? program_name : "layered_stats");
}

void cli_report(const CliConfig *config, const StatSummary *summary)
{
    if (config == NULL || summary == NULL) {
        return;
    }

    printf("Processed %zu measurements\n", config->count);
    printf("Baseline      : %6.2f\n", config->baseline);
    printf("Minimum value : %6.2f\n", summary->min);
    printf("Maximum value : %6.2f\n", summary->max);
    printf("Average value : %6.2f\n", summary->average);
    printf("Delta vs base : %6.2f\n", summary->average - config->baseline);
}
