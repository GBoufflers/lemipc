/*
** get.c for lempic in /home/dell-a_f//projets/depot/lemipc
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sun Mar 31 14:07:22 2013 florian dell-aiera
** Last update Sun Mar 31 14:07:23 2013 florian dell-aiera
*/

#include	"lemipc.h"

void		init(t_limit *limit)
{
  limit[0].beg = 0;
  limit[0].end = 6;
  limit[1].beg = 7;
  limit[1].end = 13;
  limit[2].beg = 14;
  limit[2].end = 20;
  limit[3].beg = 21;
  limit[3].end = 27;
  limit[4].beg = 28;
  limit[4].end = 34;
  limit[5].beg = 35;
  limit[5].end = 42;
  limit[6].beg = 43;
  limit[6].end = 49;
}

int		getX(int pos)
{
  return (pos % 7);
}

int		getY(int pos)
{
  return (pos / 7);
}
