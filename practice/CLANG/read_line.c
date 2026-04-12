#define ALLOC_SIZE 256
static size_t current_buf_size = 0;
static size_t current_used_size = 0;
static char *line_buf = NULL;

typedef enum {
	READ_LINE_OK = 0,
	READ_LINE_EOF,
	READ_LINE_NOMEM
} read_line_status_t;

read_line_status_t read_line(FILE *fp, char **line)
{
	int ch;
	int i = 0;

	if (current_used_size > current_buf_size) {
		return READ_LINE_NOMEM;
	}

	while ((ch = fgetc(fp)) != EOF) {
		char *tmp;
		if (current_used_size == current_buf_size) {
			tmp = realloc(line_buf, sizeof(char) + ALLOC_SIZE);
			if (tmp == NULL) {
				return READ_LINE_NOMEM;
			}
			line_buf = tmp;
			current_buf_size += ALLOC_SIZE;
		}
		if (ch == '\n') {
			line_buf[current_used_size] = '\0';
			break;
		}
		line_buf[current_used_size] = ch;
		current_used_size++;
	}
	return READ_LINE_OK;
}
