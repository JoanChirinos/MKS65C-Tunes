#include <stdio.h>

#include "player.h"
#include "list.c"

struct library* make_lib() {
  struct library* lib = calloc(sizeof(struct song), 27);

  int i;
  for (i = 0; i < 27; i++) {
    (lib->letter)[i] = NULL;
  }

  return lib;
}

void print_library(struct library* lib) {
  printf("===============\n|START LIBRARY|\n===============\n");
  if (lib != NULL) {
    int i;
    for (i = 0; i < 26; i++) {
      if ((lib->letter)[i] != NULL) {
        printf("===\n|%c|\n===\n", (char)(i + 65));
        print_songs((lib->letter)[i]);
      }
    }
    if ((lib->letter)[26] != NULL) {
      printf("=======\n|Other|\n=======\n");
      print_songs((lib->letter)[26]);
    }
  }
  printf("=============\n|END LIBRARY|\n=============\n");
}

struct library* add_song(struct library* lib, struct song* s) {
  int first_letter = (s->artist)[0];

  struct song* l;
  if (first_letter >= 65 && first_letter <= 90) {
    int where = first_letter - 65;
    lib->letter[where] = insert_alpha((lib->letter)[where], s);
  }
  else {
    lib->letter[26] = insert_alpha((lib->letter)[26], s);
  }
  return lib;
}

struct song* artist_search(struct library* lib, char* artist) {
  int where = artist[0];
  if (where >= 65 && where <= 90) where -= 65;
  else where = 26;
  struct song* p = lib->letter[where];
  while (p != NULL) {
    if (strcmp(p->artist, artist) == 0) return p;
    p = p->next;
  }
  return NULL;
}

struct song* song_search(struct library* lib, char* name, char* artist) {
  struct song* a = artist_search(lib, artist);
  while (a != NULL) {
    if (strcmp(a->artist, artist) == 0 && strcmp(a->name, name) == 0) return a;
    a = a->next;
  }
  return NULL;
}

struct song* pre_song_search(struct library* lib, char* name, char* artist) {
  struct song* a = artist_search(lib, artist);
  if (a != NULL) {
    struct song* pre = NULL;
    while (a != NULL) {
      if (strcmp(a->artist, artist) == 0 && strcmp(a->name, name) == 0) return pre;
      pre = a;
      a = a->next;
    }
  }
  return NULL;
}

void print_by_letter(struct library* lib, char a) {
  if (a >= 65 && a <= 90) {
    printf("===\n|%c|\n===\n", a);
    a -= 65;
  }
  else if (a >= 97 && a <= 122) {
    a -= 32;
    printf("===\n|%c|\n===\n", a);
    a -= 65;
  }
  else {
    printf("===\n|%c|\n===\n", a);
    a = 26;
  }
  print_songs(lib->letter[a]);
}

void print_by_artist(struct library* lib, char* artist) {
  printf("Searching for [%s]\n", artist);
  struct song* a = artist_search(lib, artist);
  if (a == NULL) {
    printf("Not found :(\n");
  }
  else {
    while(a != NULL && strcmp(a->artist, artist) == 0) {
      printf("%s: %s | ", a->artist, a->name);
      a = a->next;
    }
  }
  printf("\n");
}

struct library* delete_song(struct library* lib, struct song* song) {
  if (song_search(lib, song->name, song->artist) == NULL) {
    //printf("SONG NOT FOUND\n");
    return lib;
  }

  struct song* pre = pre_song_search(lib, song->name, song->artist);
  if (pre != NULL) { //not first el
    struct song* to_remove = pre->next;
    pre->next = pre->next->next;
    free(to_remove);
    to_remove = NULL;
    return lib;
  }
  else {
    int where = song->artist[0];
    if (where >= 65 && where <= 90) {
      where -= 65;
    }
    else where = 26;
    struct song* to_remove = lib->letter[where];
    lib->letter[where] = lib->letter[where]->next;
    free(to_remove);
    to_remove = NULL;
  }
  return lib;
}

struct library* clear_library(struct library* lib) {
  int i;
  for (i = 0; i < 27; i++) {
    //printf("freeing:\n\t");
    //print_songs(lib->letter[i]);
    lib->letter[i] = free_list(lib->letter[i]);
  }
  //printf("freed each song list\n");
  //free(lib->letter);
  free(lib);
  lib = NULL;
  return lib;
}
