#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "player.c"

int main() {
  unsigned long t;
  // t = time(NULL);
  t = 1539400079;
  srand(t);
  printf("SEED: %lu\n", t);

  struct song* head;
  struct song* s1 = make_song("Leslie Odom Jr.", "A Winter's Ball");
  struct song* s2 = make_song("Philipa Soo", "Burn");
  struct song* s3 = make_song("Watsky", "Don't Be Nice");
  struct song* s4 = make_song("Jonathan Groff", "You'll Be Back");
  struct song* s5 = make_song("Jonathan Groff", "What Comes Next?");
  struct song* s6 = make_song("Jonathan Groff", "I Know Him");
  struct song* s7 = make_song("Aesop Rock", "Rings");
  struct song* s8 = make_song("Bon Jovi", "Livin' on a Prayer");
  struct song* s9 = make_song("Childish Gambino", "3005");
  struct song* s10 = make_song("? & The Mysterians", "96 Tears");
  struct song* s11 = make_song("? & The Mysterians", "Up Side");
  struct song* s12 = make_song("Joan Chirinos", "Mixtape-o Numero Uno");

  printf("====================\n LINKED LIST TESTS \n====================\n");

  printf("\n=== COMPARING SONGS ===\n");
  int val;
  val = song_comp(s1, s2);
  printf("comparing [%s: %s] to [%s: %s]\n\t--> %d\n", s1->artist, s1->name, s2->artist, s2->name, val);
  val = song_comp(s5, s6);
  printf("comparing [%s: %s] to [%s: %s]\n\t--> %d\n", s5->artist, s5->name, s6->artist, s6->name, val);
  val = song_comp(s4, s4);
  printf("comparing [%s: %s] to [%s: %s]\n\t--> %d\n", s4->artist, s4->name, s4->artist, s4->name, val);

  printf("\n=== PRINTING SINGLE SONG ===\n");
  print_song(s5);

  printf("\n=== INSERTING SONGS (alpha) ===\n");
  head = insert_alpha(head, s1);
  print_songs(head);
  printf("\n");
  head = insert_alpha(head, s2);
  // print_songs(head);
  head = insert_alpha(head, s3);
  // print_songs(head);
  head = insert_alpha(head, s4);
  // print_songs(head);
  head = insert_alpha(head, s5);
  // print_songs(head);
  head = insert_alpha(head, s6);
  // print_songs(head);
  head = insert_alpha(head, s7);
  // print_songs(head);
  head = insert_alpha(head, s8);
  // print_songs(head);
  head = insert_alpha(head, s9);
  // print_songs(head);
  head = insert_alpha(head, s10);
  // print_songs(head);
  head = insert_alpha(head, s11);
  print_songs(head);

  printf("\n=== FINDING NODES ===\n");

  struct song* found;

  printf("Looking for [%s: %s]...\n", s12->artist, s12->name);
  found = find_node(head, s12);
  if (found == NULL) printf("Not found :(\n");
  else {
    printf("Found 'em: ");
    print_song(found);
  }
  printf("\n");


  printf("Looking for [%s: %s]...\n", s4->artist, s4->name);
  found = find_node(head, s4);
  if (found == NULL) printf("Not found :(\n");
  else {
    printf("Found 'em: ");
    print_song(found);
  }
  printf("\n");

  printf("\n=== FINDING ARTIST ===\n");
  char* search1 = "Joan Chirinos";
  printf("Looking for [%s]...\n", search1);
  found = find_artist(head, search1);
  if (found == NULL) printf("Not found :(\n");
  else {
    printf("Found 'em:\n");
    print_songs(found);
  }
  printf("\n");

  char* search2 = "Jonathan Groff";
  printf("Looking for [%s]...\n", search2);
  found = find_artist(head, search2);
  if (found == NULL) printf("Not found :(\n");
  else {
    printf("Found 'em:\n");
    print_songs(found);
  }
  printf("\n");

  printf("\n=== GETTING AND REMOVING RANDOM SONGS ===\n");
  printf("Before:\n");
  print_songs(head);
  printf("\n");
  int i;
  int count;
  struct song* p;
  for (i = 0; i < 3; i++) {
    p = random_song(head);
    print_song(p);
    head = remove_song(head, p);
  }
  printf("After removal:\n");
  print_songs(head);
  printf("\nAttempting to remove [%s: %s]\nAfter attept:\n", s12->artist, s12->name);
  head = remove_song(head, s12);
  print_songs(head);

  printf("\n=== FREEING LISt ===\n");
  head = free_list(head);
  printf("songs:\n");
  print_songs(head);

  printf("\n====================\nMUSIC LIBRARY TESTS\n====================\n\n");

  s1 = make_song("Leslie Odom Jr.", "A Winter's Ball");
  s2 = make_song("Philipa Soo", "Burn");
  s3 = make_song("Watsky", "Don't Be Nice");
  s4 = make_song("Jonathan Groff", "You'll Be Back");
  s5 = make_song("Jonathan Groff", "What Comes Next?");
  s6 = make_song("Jonathan Groff", "I Know Him");
  s7 = make_song("Aesop Rock", "Rings");
  s8 = make_song("Bon Jovi", "Livin' on a Prayer");
  s9 = make_song("Childish Gambino", "3005");
  s10 = make_song("? & The Mysterians", "96 Tears");
  s11 = make_song("? & The Mysterians", "Up Side");
  s12 = make_song("Joan Chirinos", "Mixtape-o Numero Uno");

  struct library* lib = make_lib();

  printf("\n=== BUILDING LIB ===\n");
  lib = add_song(lib, s1);
  print_library(lib);
  lib = add_song(lib, s2);
  // print_library(lib);
  lib = add_song(lib, s3);
  // print_library(lib);
  lib = add_song(lib, s4);
  // print_library(lib);
  lib = add_song(lib, s5);
  // print_library(lib);
  lib = add_song(lib, s6);
  // print_library(lib);
  lib = add_song(lib, s7);
  // print_library(lib);
  lib = add_song(lib, s8);
  // print_library(lib);
  lib = add_song(lib, s9);
  // print_library(lib);
  lib = add_song(lib, s10);
  // print_library(lib);
  lib = add_song(lib, s11);
  print_library(lib);

  printf("\n=== ARTIST SEARCH ===\n");
  printf("Searching for [%s]\n", s4->artist);
  found = artist_search(lib, s4->artist);
  if (found == NULL) printf("Not found :(\n");
  else print_songs(found);

  printf("Searching for [%s]\n", s12->artist);
  found = artist_search(lib, s12->artist);
  if (found == NULL) printf("Not found :(\n");
  else print_songs(found);

  printf("\n=== SONG SEARCH ===\n");
  printf("Searching for [%s: %s]\n", s2->artist, s2->name);
  found = song_search(lib, s2->name, s2->artist);
  if (found == NULL) printf("Not found :(\n");
  else printf("Found [%s, %s]\n", found->artist, found->name);

  printf("Searching for [%s: %s]\n", s12->artist, s12->name);
  found = song_search(lib, s12->name, s12->artist);
  if (found == NULL) printf("Not found :(\n");
  else printf("Found [%s, %s]\n", found->artist, found->name);

  printf("\n=== PRINT BY LETTER ===\n");
  print_by_letter(lib, 'a');
  print_by_letter(lib, 'J');
  print_by_letter(lib, 'G');
  print_by_letter(lib, '?');

  printf("\n=== PRINT BY ARTIST ===\n");
  print_by_artist(lib, "Philipa Soo");
  printf("\n");
  print_by_artist(lib, "Jonathan Groff");
  printf("\n");
  print_by_artist(lib, "Joan Chirinos");
  printf("\n");

  printf("\n=== DELETE SONGS ===\n");
  printf("Deleting\n\t");
  print_song(s5);
  lib = delete_song(lib, s5);
  print_library(lib);

  printf("Deleting\n\t");
  print_song(s12);
  lib = delete_song(lib, s12);
  print_library(lib);

  printf("=== CLEARING LIB ===\n");
  lib = clear_library(lib);
  //printf("freed\n");
  print_library(lib);
}
