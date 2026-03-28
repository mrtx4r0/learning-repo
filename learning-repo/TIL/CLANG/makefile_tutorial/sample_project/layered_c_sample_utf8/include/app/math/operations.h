#ifndef APP_MATH_OPERATIONS_H
#define APP_MATH_OPERATIONS_H

#include <stddef.h>

typedef struct {
    double min;
    double max;
    double average;
} StatSummary;

int compute_stats(const double *values, size_t count, StatSummary *summary);

#endif /* APP_MATH_OPERATIONS_H */
