/*
** test.c for test in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Wed Mar 27 14:27:14 2013 florian dell-aiera
** Last update Thu Mar 28 10:22:13 2013 florian dell-aiera
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
  shm_id= shmget(key, 42, SHM_R | SHM_W);
  if (shm_id != -1)
    addr = (char*)shmat(shm_id, NULL, SHM_R | SHM_W);
  return (addr);
}


void	set_position(t_map *ptr, int i)
{
  if (i == 0)
    {
      ptr->pos.x = 200;
      ptr->pos.y = 100;
    }
  else
    {
      ptr->pos.x += 55;
      if (i % 5 == 0)
	{
	  ptr->pos.y += 55;
	  ptr->pos.x = 200;
	}
    }
}


void	draw(t_map *ptr)
{
  int	i;
  
  i = 0;
  while (i < 25)
    {
      set_position(ptr, i);
      if (ptr->map[i] == 'o')
	SDL_FillRect(ptr->rectangle[i], NULL,
		     SDL_MapRGB(ptr->screen->format, 255, 255, 255));
      else if (ptr->map[i] == '1')
	SDL_FillRect(ptr->rectangle[i], NULL,
		     SDL_MapRGB(ptr->screen->format, 255, 0, 0));
      else if (ptr->map[i] == '2')
	SDL_FillRect(ptr->rectangle[i], NULL,
		     SDL_MapRGB(ptr->screen->format, 0, 0, 255));
      SDL_BlitSurface(ptr->rectangle[i], NULL, ptr->screen, &(ptr->pos));
      i++;
    }
  SDL_Flip(ptr->screen);
}


void	boucle(t_map *ptr)
{
  SDL_Event	event;

  ptr->continuer = 1;
  while (ptr->continuer)
    {
      SDL_PollEvent(&event);
      switch (event.type)
	{
	case SDL_QUIT:
	  ptr->continuer = 0;
	}
      draw(ptr);
    }
}

int	init(t_map *ptr)
{
  int	i;

  i = 0;
  ptr->screen = NULL;
  ptr->rectangle[25] = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (-1);
  ptr->screen = SDL_SetVideoMode(HEIGHT, WIDTH, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
  if (ptr->screen == NULL)
    return (-1);
  while (i < 25)
    {
      ptr->rectangle[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 50, 32, 0, 0, 0, 0);
      i++;
    }
  SDL_WM_SetCaption("lemIPC", NULL);
  return (0);
}

int	main(int ac, char **av)
{
  t_map	ptr;
  int	i;

  i = 0;
  if (ac != 2)
    return (-1);
  ptr.map = recup_map(av[1]);
  if (init(&ptr) == -1 || ptr.map == NULL)
    return (0);
  boucle(&ptr);
  while (i < 25)
    {
      SDL_FreeSurface(ptr.rectangle[i]);
      i++;
    }
  SDL_Quit(); 
  return (0);
}
