/*
** test.c for test in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Wed Mar 27 14:27:14 2013 florian dell-aiera
** Last update Sun Mar 31 20:17:15 2013 florian dell-aiera
*/

#include	"lemipc.h"

static void	check_game(t_map *ptr)
{
  if (ptr->nb_players == 1)
    {
      if (count_team(ptr->map, '1') <= 1)
	{
	  printf("blue win\n");
	  ptr->continuer = 0;
	}
      if (count_team(ptr->map, '2') <= 1)
	{
	  printf("red win\n");
	  ptr->continuer = 0;
	}
    }
}

static void	draw_map(t_map *ptr)
{
  int		i;

  i = 0;
  while (ptr->map[i])
    {
      if (i % 7 == 0)
	printf("\n");
      printf("%c", ptr->map[i]);
      i++;
    }
  printf("\n");
}

static void	draw(t_map *ptr)
{
  int		i;

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
  usleep(500000);
  draw_map(ptr);
  if ((count_team(ptr->map, '1') + count_team(ptr->map, '2')) >= 4)
    ptr->nb_players = 1;
  check_game(ptr);
}

static void	boucle(t_map *ptr)
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

int		main()
{
  t_map		ptr;
  char		*str;
  int		i;

  i = 0;
  str = getenv("PWD");
  if (str == NULL)
    {
      printf("variable pwd null\n");
      return (-1);
    }
  ptr.map = recup_map(str);
  if (init_display(&ptr) == -1 || ptr.map == NULL)
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
