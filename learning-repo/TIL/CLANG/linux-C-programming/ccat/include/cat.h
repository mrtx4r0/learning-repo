#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

extern void do_cat(const char* path);
extern void do_cat_stdin(void);
extern void die(const char* s);
