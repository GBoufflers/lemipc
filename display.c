/*
** test.c for test in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Wed Mar 27 14:27:14 2013 florian dell-aiera
** Last update Sat Mar 30 17:16:11 2013 florian dell-aiera
*/

#include "lemipc.h"

void	draw(t_map *ptr)
{
  int	i;
  
  i = 0;
  while (i < 49)
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
  while (i < 49)
    {
      SDL_FreeSurface(ptr.rectangle[i]);
      i++;
    }
  SDL_Quit(); 
  return (0);
}
