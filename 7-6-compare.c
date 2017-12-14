#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

FILE *fopen_or_exit(char *prog, char *name)
{
  FILE *fp;

  if ((fp = fopen(name, "r")) == NULL) {
    fprintf(stderr, "%s: can't open %s\n", prog, name);
    exit(1);
  } else {
    return fp;
  }
}

int main(int argc, char *argv[])
{
  char *prog = argv[0];

  if (argc != 3) {
    fprintf(stderr, "%s expects exactly two file arguments\n", prog);
    exit(1);
  } else {
    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    int i;
    fp1 = fopen_or_exit(prog, argv[1]);
    fp2 = fopen_or_exit(prog, argv[2]);

    for (i = 0; fgets(line1, MAXLINE, fp1) && fgets(line2, MAXLINE, fp2); i++) {
      if (strcmp(line1, line2)) {
        printf("Difference on line %d:\n< %s---\n> %s", i, line1, line2);
        exit(0);
      }
    }

    printf("No differences found\n");
  }
}



