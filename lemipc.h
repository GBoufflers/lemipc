#ifndef		__LEMIPC_H__
#define		__LEMIPC_H__

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<sys/shm.h>
#include	<semaphore.h>
#include	<SDL/SDL.h>

#define	HEIGHT	640
#define	WIDTH	640

typedef struct	s_map
{
  char		*map;
  SDL_Surface	*screen;
  SDL_Surface	*rectangle[49];
  SDL_Rect	 pos;
  int		continuer;
}		t_map;

typedef struct	s_game
{
  key_t		key;
  int		shm_id;
  int		sem_id;
  char		*addr;
  struct sembuf sops;
  char		team;
  int		access;
  int		new;
  int		first;
  int		play;
}		t_game;

typedef struct	s_limit
{
  int		beg;
  int		end;
}		t_limit;

void		first_player(t_game *game);
void		others(t_game *game);
void		*xmalloc(int size);
char		*recup_map(char *str);
#endif
