/*
** check_map.c for check_map.c in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:12:32 2013 florian dell-aiera
** Last update Sun Mar 31 20:32:48 2013 florian dell-aiera
*/

#include	"lemipc.h"

int		check_map_top(char **map, char ennemie, int x, int y)
{
  int		nb;

  nb = 0;
  if (x >= 1 && map[x - 1][y] == ennemie)
    nb++;
  if (y >= 1 && map[x][y -1] == ennemie)
    nb++;
  if (x < 6 && map[x + 1][y] == ennemie)
    nb++;
  if (y < 6 && map[x][y + 1] == ennemie)
    nb++;
  return (nb);
}

int		check_map_diago(char **map, char ennemie, int x, int y)
{
  int		nb;

  nb = 0;
  if (x >= 1 && y >= 1 && map[x - 1][y - 1] == ennemie)
    nb++;
  if (x < 6 && map[x + 1][y - 1] == ennemie)
    nb++;
  if (x < 6 && y < 6 && map[x + 1][y + 1] == ennemie)
    nb++;
  if (x >= 1 && y < 6 && map[x -1][y + 1] == ennemie)
    nb++;
  return (nb);
}
