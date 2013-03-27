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
}		t_game;

#endif
