/*
** init.c for lempic in /home/dell-a_f//projets/depot/copy2
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sat Mar 30 17:15:44 2013 florian dell-aiera
** Last update Sat Mar 30 17:16:31 2013 florian dell-aiera
*/

#include "lemipc.h"

char	*recup_map(char *str)
{
  key_t	key;
  int	shm_id;
  int		sem_id;
  char		*addr;
  struct sembuf sops;

  key = ftok(str, 0);
  shm_id= shmget(key, 52, SHM_R | SHM_W);
  if (shm_id != -1)
    addr = (char*)shmat(shm_id, NULL, SHM_R | SHM_W);
  return (addr);
}


void	set_position(t_map *ptr, int i)
{
  if (i == 0)
    {
      ptr->pos.x = 150;
      ptr->pos.y = 100;
    }
  else
    {
      ptr->pos.x += 55;
      if (i % 7 == 0)
	{
	  ptr->pos.y += 55;
	  ptr->pos.x = 150;
	}
    }
}

int	init(t_map *ptr)
{
  int	i;

  i = 0;
  ptr->screen = NULL;
  ptr->rectangle[49] = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (-1);
  ptr->screen = SDL_SetVideoMode(HEIGHT, WIDTH, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
  if (ptr->screen == NULL)
    return (-1);
  while (i < 49)
    {
      ptr->rectangle[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
      i++;
    }
  SDL_WM_SetCaption("lemIPC", NULL);
  return (0);
}
