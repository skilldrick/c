#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;

  return NULL;
}

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) { // not found
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else // already there
    free((void *) np->defn);

  if ((np->defn = strdup(defn)) == NULL)
    return NULL;

  return np;
}

int undef(char *name)
{
  struct nlist *np, *prev;

  if ((np = lookup(name)) == NULL)
    return 0;
  else {
    int hashval = hash(name);
    prev = hashtab[hashval];

    // first node in list is the one we're undefing
    if (prev == np) {
      hashtab[hashval] = np->next;
      return 1;
    }

    for (; prev != NULL; prev = prev->next)
      if (prev->next == np) { // if nextnode is np
        prev->next = np->next; // remove np from list
        free(np->defn);
        free(np);
        return 1;
      }
  }

  return 0;
}


char *lookup_or_else(char *name)
{
  struct nlist *np;

  if ((np = lookup(name)) == NULL)
    return "<not found>";
  else
    return np->defn;
}

int main()
{
  install("hello", "world");
  install("hi", "whoa");
  install("yo", "yeah");
  install("yo", "hi");

  printf("%s\n", lookup_or_else("hello"));
  printf("%s\n", lookup_or_else("yo"));
  printf("%s\n", lookup_or_else("hi"));
  printf("%s\n", lookup_or_else("yop"));
  printf("%d\n", undef("hi"));
  printf("%s\n", lookup_or_else("hi"));
}
