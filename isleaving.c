/*
** isleaving.c for lempic in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:07:07 2013 florian dell-aiera
** Last update Sun Mar 31 20:21:37 2013 florian dell-aiera
*/

#include	"lemipc.h"

static char	**construct_map(char **map, char *str)
{
  int		i;
  int		k;
  int		j;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    {
      if (k < 7)
	map[j][k] = str[i];
      else
	{
	  map[j][k] = '\0';
	  k = 0;
	  j++;
	  map[j][k] = str[i];
	}
      k++;
      i++;
    }
  return (map);
}

static char	**build_map(char *str)
{
  char		**map;
  int		i;

  i = 0;
  map = xmalloc(8 * sizeof(char *));
  while (i < 7)
    {
      map[i] = xmalloc(8 * sizeof(char));
      i++;
    }
  map[7] = NULL;
  map = construct_map(map, str);
  return (map);
}

static int	check_map(char **map, char ennemie, int x, int y)
{
  int		nb;

  nb = 0;
  nb += check_map_top(map, ennemie, x, y);
  nb += check_map_diago(map, ennemie, x, y);
  return (nb);
}

static int	check_ennemie(char **map, char team, int x, int y)
{
  char		ennemie;
  int		nb;

  if (team == '1')
    ennemie = '2';
  else if (team == '2')
    ennemie = '1';
  nb = check_map(map, ennemie, x, y);
  return (nb);
}

int		is_quitting(t_game *game, char team, int pos)
{
  int		ret;
  int		x;
  int		y;
  char		**map;

  x = getX(pos);
  y = getY(pos);
  map = build_map(game->addr);
  ret = check_ennemie(map, team, x, y);
  if (ret >= 2)
    {
      game->addr[pos] = 'o';
      game->team = 'o';
      return (1);
    }
  return (0);
}
