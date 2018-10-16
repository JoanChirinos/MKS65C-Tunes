#ifndef LIST_H
#define LIST_H

struct song {char name[100]; char artist[100]; struct song* next;};

struct song* make_song(char*, char*);

struct song* free_list(struct song*);

struct song* free_song(struct song*, struct song*);

void print_songs(struct song*);

void print_song(struct song*);

struct song* insert_front(struct song*, char*, char*);

struct song* insert_alpha(struct song*, struct song*);

struct song* find_node(struct song*, struct song*);

struct song* find_artist(struct song*, char*);

struct song* random_song(struct song* n);

struct song* remove_song(struct song*, struct song*);

//HELPERS

int song_comp(struct song*, struct song*);

#endif
