#include	"lemipc.h"

char		**build_map(char *str)
{
  char		**map;
  int		i;
  int		j;
  int		k;

  i = j = k = 0;
  map = malloc(8 * sizeof(char *));
  while (i < 7)
    {
      map[i] = malloc(8 * sizeof(char));
      i++;      
    }
  map[7] = NULL;
  i = 0;
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

int		count_enemies(char **map, char team, char enemie, int coord[2])
{
  int		ret;

  ret = 0;
  if (coord[0] > 1 && map[coord[0] - 1][coord[1]] == enemie)
    ret++;
  if ((coord[0] > 1 && coord[1] > 1) && map[coord[0] - 1][coord[1] - 1] == enemie)
    ret++;
  if (coord[1] > 1 && map[coord[0]][coord[1] - 1] == enemie)
    ret++;
  if (coord[0] < 7 && coord[1] > 1 && (map[coord[0] + 1][coord[1] + 1]) == enemie)
    ret++;
  if (coord[0] < 7 && (map[coord[0] + 1][coord[1]] == enemie))
    ret++;
  if (coord[0] < 7 && coord[1] < 7 && (map[coord[0] + 1][coord[1] + 1] == enemie))
    ret++;
  if (coord[1] < 7 && (map[coord[0]][coord[1] - 1] == enemie))
    ret++;
  if (coord[0] > 1 && coord[1] < 7 && (map[coord[0] - 1][coord[1] + 1] == enemie))
    ret++;
  return (ret);
}

int		has_to_leave(char *p, char team, int pos, int coord[2])
{
  int		ret;
  char		**map;
  char		enemie;

  if (team == '1')
    enemie = '2';
  else
    enemie = '1';
  map = build_map(p);
  ret = count_enemies(map, team, enemie, coord);
  if (ret >= 2)
    {
      p[pos] = 'o';
      return (1);
    }
  return (0);
}

int		is_quitting(char *addr, char team, int pos)
{
  int		coord[2];
  
  coord[0] = getX(pos);
  coord[1] = getY(pos);
  return (has_to_leave(addr, team, pos, coord));
}
