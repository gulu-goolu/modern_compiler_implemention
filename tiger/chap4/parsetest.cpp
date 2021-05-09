#include <cstdio>
#include <cstdlib>

#include "parse.h"

extern int yyparse(void);

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: a.out filename\n");
    exit(1);
  }
  parse(argv[1]);
  return 0;
}
