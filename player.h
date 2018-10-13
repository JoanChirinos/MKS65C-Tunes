struct library {struct song* letter[27];};

struct library* add_song(struct library*, struct song*);

struct song* song_search(struct library*, char*, char*);

struct song* artist_search(struct library*, char*);

void print_by_letter(struct library*, char);

void print_by_artist(struct library*, char*);

void print_library(struct library*);

void shuffle(struct library*);

struct library* delete_song(struct library*, struct song*);

struct library* clear_library(struct library*);
