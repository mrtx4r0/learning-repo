#ifndef READ_LINE_H
#define READ_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_SIZE 128 

typedef enum {
	READ_LINE_OK = 0,
	READ_LINE_EOF,
	READ_LINE_NOMEM
} read_line_status_t;


static read_line_status_t add_character(int ch);
read_line_status_t read_line(FILE *fp, char **line);
void free_buffer(void);

#endif /* READ_LINE_H */
