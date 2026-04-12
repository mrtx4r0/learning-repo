#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#define DEFAULT_NLINES 10

void help();
void do_head(FILE *f, long nlines);

int main(int argc, char *argv[])
{
	long nlines = 0;
	int opt;
	char *endptr;
	int i;
	FILE *f;

	struct option longopt[] = {
		{"lines", required_argument, NULL, 'n'},
		{"lines=", required_argument, NULL, 'n'},
		{"help", no_argument, NULL, 'h'},
		{0, 0, 0, 0}
	};
	
	if (argc < 2) {
		/* if no argument, file: stdin, nlines: default count */
		do_head(stdin, DEFAULT_NLINES);
		exit(EXIT_SUCCESS);
	}
	while ((opt = getopt_long(argc, argv, "n:h", longopt, NULL)) != -1) {
		switch(opt) {
			case 'n':
				nlines = strtol(optarg, &endptr, 10);
				if (nlines == 0 || *endptr != '\0') {
					fprintf(stderr, "%s: illegal line count -- %s\n", argv[0], optarg);
					exit(EXIT_FAILURE);
				}
				break;
			case 'h':
				fprintf(stderr, "%s: unrecognized option -- %c\n", argv[0], (char)opt);
				help();
				exit(EXIT_FAILURE);
			case '?':
				fprintf(stderr, "%s: invalid option -- %c\n", argv[0], (char)optopt);
				help();
				exit(EXIT_FAILURE);
			default:
				break;
		}	
	}	

	if ((nlines > 0) && (argv[optind] == NULL)) {
		/* if no files are passed as argument, read from stdin */
		do_head(stdin, nlines);
		exit(EXIT_SUCCESS);
	}

	if (nlines == 0) {
		/* if no option provided, set default count */
		nlines = DEFAULT_NLINES; 
	}

	for (i = optind; i < argc; i++) {
		f = fopen(argv[i], "r");
		if (!f) {
			fprintf(stderr, "%s: %s: ", argv[0], argv[optind]);
			perror(NULL);
			continue;
		}
	    if ((argc - optind) > 1) {
			/* if 2 or more files are passed as arguments, also print filepath as header */
			fprintf(stdout, "==> %s <==\n", argv[i]);
		}

		do_head(f, nlines);

		if ((argc - optind) > 1) {
			/* if 2 or more files are passed as arguments, insert a new line */
			fprintf(stdout, "\n");
		}
	
		if (fclose(f) != 0) {
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}

void do_head(FILE *f, long nlines)
{
	int ch;

	while ((ch = fgetc(f)) != EOF) {
		if (fputc(ch, stdout) == EOF) {
			exit(EXIT_FAILURE);
		}
		if (ch == '\n') {
			nlines--;
		    if (nlines == 0) {
				break;
			}
		}
	}	
	return;
}

void help()
{
	fprintf(stdout, "usage: ./head3 -n <nlines> <filepath>\n");
	return;
}
