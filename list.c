#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* ========== HELPERS ========== */
int song_comp(struct song* s1, struct song* s2) {
  //printf("Comparing\n\t%s: %s\n\t%s: %s\n", s1->artist, s1->name, s2->artist, s2->name);
  int a = strcmp(s1->artist, s2->artist);
  if (a != 0) return a;
  return strcmp(s1->name, s2->name);
}

struct song* find_previous_node(struct song* n, struct song* to_find) {
  struct song* p = n;
  struct song* previous;
  int val;
  while (p->next != NULL && 0 > (val = song_comp(p, to_find)) && val != 0) {
    previous = p;
    //printf("previous: %s: %s\n", previous->artist, previous->name);
    p = p->next;
    //printf("next: %s: %s\n", p->artist, p->name);
  }
  val = song_comp(p, to_find);
  if (val == 0) return previous;
  if (p->next == NULL || val > 0) return NULL;
  return previous;
}
/* ========== END HELPERS ========== */

struct song* make_song(char* artist, char* name) {
  //printf("making song--> [%s: %s]\n", artist, name);
  struct song* n;
  n = calloc(sizeof(struct song), 1);

  char a[100];
  strncpy(a, artist, 99);
  a[99] = 0;

  char na[100];
  strncpy(na, name, 99);
  a[99] = 0;

  // capitalize first char of artist and name!
  int x = (a)[0];
  if (x >= 97 && x <= 122) {
    x -= 32;
  }
  a[0] = (char)(x);

  x = (na)[0];
  if (x >= 97 && x <= 122) {
    x -= 32;
  }
  na[0] = (char)(x);

  strcpy(n->name, na);
  strcpy(n->artist, a);
  n->next = NULL;
  //printf("made song--> [%s: %s]\n", n->artist, n->name);
  return n;
}

void print_songs(struct song* n) {
  if (n != NULL) {
    struct song* p = n;
    while (p != NULL) {
      printf("%s: %s | ", p->artist, p->name);
      p = p->next;
    }
  }
  printf("\n");
}

void print_song(struct song* n) {
  printf("%s: %s\n", n->artist, n->name);
}

struct song* insert_front(struct song* n, char* name, char* artist) {
  struct song* new = make_song(name, artist);
  new->next = n;
  return new;
}

struct song* free_list(struct song* n) {
  if (n == NULL) {
    return n;
  }
  if (n->next == NULL) {
    free(n);
    n = NULL;
  }
  else {
    free_list(n->next);
    free(n);
    n = NULL;
  }
  return n;
}

//goes through and inserts song
struct song* insert_alpha(struct song* n, struct song* new_song) {
  struct song* p = n;
  //printf("inserting [%s: %s]\n", new_song->artist, new_song->name);

  if (p == NULL) {
    return new_song;
  }

  if (song_comp(p, new_song) > 0) {
    new_song->next = n;
    return new_song;
  }
  while (p->next != NULL && song_comp(p->next, new_song) < 0) {
    p = p->next;
  }
  new_song->next = p->next;
  p->next = new_song;
  return n;
}

//if found, returns pointer
//else returns NULL
struct song* find_node(struct song* n, struct song* to_find) {
  if (n == NULL) return NULL;
  struct song* p = n;
  int val;
  while (p->next != NULL && 0 > (val = song_comp(p, to_find)) && val != 0) {
    p = p->next;
  }
  if (p->next == NULL || val > 0) return NULL;
  return p;
}

struct song* find_artist(struct song* n, char* artist) {
  struct song* p = n;
  int val;
  while (p->next != NULL && 0 > (val = strcmp(p->artist, artist)) && val != 0) {
    p = p->next;
  }
  if (p->next == NULL || val > 0) return NULL;
  return p;
}

//haha still O(n)
struct song* random_song(struct song* n) {
  int count = 0;
  struct song* p = n;
  while (p != NULL) {
    count++;
    p = p->next;
  }
  // printf("count: %d\n", count);
  p = n;
  count = rand() % count;
  // printf("rand: %d\n", count);
  for ( ; count > 0; count--) {
    // printf("old p: %s: %s\n", p->artist, p->name);
    p = p->next;
    // printf("new p: %s: %s\n\n", p->artist, p->name);
  }
  return p;
}

struct song* remove_song(struct song* n, struct song* to_remove) {
  //AT SOME POINT FIGURE OUT HOW TO COMBINE CASES//
  if (song_comp(n, to_remove) == 0) {
    struct song* to_return = n->next;
    free(n);
    n = NULL;
    return to_return;
  }
  struct song* previous = find_previous_node(n, to_remove);
  if (previous == NULL) {
    // printf("NULL\n");
    return n;
  }

  struct song* found = previous->next;
  previous->next = found->next;
  free(found);
  found = NULL;
  return n;
}
