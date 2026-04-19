#include "read_line.h"

static size_t current_buffer_size = 0;
static size_t current_used_size = 0;
static char *line_buffer = NULL;

/* 
 *
 */
static read_line_status_t add_character(int ch)
{
	if (current_used_size == current_buffer_size) {
		char *tmp;
		current_buffer_size = current_buffer_size ? current_buffer_size * 2 : ALLOC_SIZE;
		tmp = realloc(line_buffer, current_buffer_size);
		if (tmp == NULL) {
			return READ_LINE_NOMEM;
		}
		line_buffer = tmp;
	}
	line_buffer[current_used_size] = ch;
	current_used_size++;
	
	return READ_LINE_OK;	
}

/* 
 *
 */
read_line_status_t read_line(FILE *fp, char **line)
{
	int ch;
	read_line_status_t status = READ_LINE_OK;

	current_used_size = 0;
	if (current_used_size > current_buffer_size) {
		return READ_LINE_NOMEM;
	}

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') {
			if ((status = add_character('\0')) != READ_LINE_OK) {
				goto error;
			}
			break;
		}
		if ((status = add_character(ch)) != READ_LINE_OK) {
			goto error;	
		}
	}
	if (ch == EOF) {
		if (current_used_size > 0) {
			if (add_character('\0') != READ_LINE_OK) {
				goto error;
			}
			status = READ_LINE_EOF;
		}
		else {
			return READ_LINE_EOF;
		}
	}
	
	*line = malloc(sizeof(char) * current_used_size);
	if (line == NULL) {
		status = READ_LINE_NOMEM;
		goto error;
	}
	strcpy(*line, line_buffer);	
	
  error:
	if (status != READ_LINE_OK && status != READ_LINE_EOF) {
		free_buffer();
	}

	return status;
}

/*
 *
 */
void free_buffer(void)
{
	free(line_buffer);
	line_buffer = NULL;
	current_buffer_size = 0;
	current_used_size = 0;
	return;
}
