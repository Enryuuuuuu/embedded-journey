#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum SongGenre{
  ROCK,
  POP,
  JAZZ,
  DANGDUT,
  HIPHOP,
  JPOP
};

struct song{
  char * title;
  char * artist;
  enum SongGenre genre;
};

int main(){
  struct song * p_song = malloc(sizeof(struct song));
  // memeriksa hasil malloc untuk memastikan isinya bukan NULL
  if (p_song == NULL) {
    printf("Error: Gagal alokasi memori untuk struct!\n");
    return 1; // Keluar dari program
  }

  (*p_song).title = malloc(16 * sizeof(char));
  // memeriksa hasil malloc untuk memastikan isinya bukan NULL
  if (p_song->title  == NULL) {
    printf("Error: Gagal alokasi memori untuk title!\n");
    return 1; // Keluar dari program
  }

  (*p_song).artist = malloc(16 * sizeof(char));
  if (p_song->artist  == NULL) {
    printf("Error: Gagal alokasi memori untuk artist!\n");
    return 1; // Keluar dari program
  }

  strcpy(p_song->title, "Deshomasho");
  strcpy(p_song->artist, "Kenshi Yonezu");
  p_song->genre = JPOP;

  printf("judul lagu : %s\n", p_song->title);
  printf("Penyanyi : %s\n", p_song->artist);
  printf("genre : %d\n", p_song->genre);

  printf("alamat struct: %p\n", p_song);
  printf("alamat judul lagu : %p\n", &(*p_song).title);
  printf("alamat Penyanyi : %p\n", &(*p_song).artist);
  printf("alamat genre : %p\n", &(*p_song).genre);



  free((*p_song).title);
  free((*p_song).artist);
  free(p_song);

  return 0;
}

/*
Note: 
(*p_song).artist sama dengan p_song->artist
*/