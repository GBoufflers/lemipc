/*
** xmalloc.c for malloc in /home/dell-a_f//projets/depot/copy2
** 
** Made by florian dell-aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Sat Mar 30 17:14:03 2013 florian dell-aiera
** Last update Sun Mar 31 20:32:36 2013 florian dell-aiera
*/

#include	"lemipc.h"

void		*xmalloc(int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  return (ptr);
}
