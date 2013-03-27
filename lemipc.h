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
  SDL_Surface	*rectangle[25];
  SDL_Rect	 pos;
  int		continuer;
}		t_map;

#endif
