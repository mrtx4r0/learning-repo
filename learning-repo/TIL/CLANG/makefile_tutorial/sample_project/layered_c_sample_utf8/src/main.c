#include <stdio.h>

#include "app/cli/cli.h"
#include "app/math/operations.h"

int main(int argc, char **argv)
{
    CliConfig config;
    if (!cli_parse(argc, argv, &config)) {
        cli_print_usage(argv[0]);
        return 1;
    }

    StatSummary summary;
    if (!compute_stats(config.values, config.count, &summary)) {
        fprintf(stderr, "internal error: failed to compute statistics\n");
        return 2;
    }

    cli_report(&config, &summary);
    return 0;
}
