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


int		check_map(char **map, char ennemie, int x, int y)
{
  int		nb;

  nb = 0;
  if (x >= 1 && map[x -1][y] == ennemie)
    nb++;
  if (x >= 1 && y >= 1 && map[x - 1][y - 1] == ennemie)
    nb++;
  if (y >= 1 && map[x][y -1] == ennemie)
    nb++;
  if (x < 6 && map[x + 1][y - 1] == ennemie)
    nb++;
  if (x < 6 && map[x + 1][y] == ennemie)
    nb++;
  if (x < 6 && y < 6 && map[x + 1][y + 1] == ennemie)
    nb++;
  if (y < 6 && map[x][y + 1] == ennemie)
    nb++;
  if (x >= 1 && y < 6 && map[x -1][y + 1] == ennemie)
    nb++;
  return (nb);
}

int		check_ennemie(char **map, char team, int x, int y)
{
  char		ennemie;
  int		nb;

  if (team == '1')
    ennemie = '2';
  else
    ennemie = '1';
  nb = check_map(map, ennemie, x, y);
  if (nb >= 2)
    printf("NB =====>>>>> %d la team qui doit rester %c ", nb, team);
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
      printf("le X ===> %d et le Y =>>> %d\n", x, y);
      game->team = 'o';
      return (1);
    }
  return (0);
}
