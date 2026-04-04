#include "app/math/operations.h"

int compute_stats(const double *values, size_t count, StatSummary *summary)
{
    if (values == NULL || summary == NULL || count == 0U) {
        return 0;
    }

    double min_val = values[0];
    double max_val = values[0];
    double total = 0.0;

    for (size_t i = 0; i < count; ++i) {
        const double current = values[i];
        if (current < min_val) {
            min_val = current;
        }
        if (current > max_val) {
            max_val = current;
        }
        total += current;
    }

    summary->min = min_val;
    summary->max = max_val;
    summary->average = total / (double)count;
    return 1;
}
