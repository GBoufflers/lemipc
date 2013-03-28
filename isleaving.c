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

int		is_quitting(char *addr, char team, int pos)
{
  printf("pos = %d", pos);
  return (0);
}
