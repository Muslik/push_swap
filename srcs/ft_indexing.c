
#include "push_swap.h"

int				ft_get_index(t_stack *stacks, int len, int val)
{
  int i;

  i = 0;
  while (i < len)
  {
	if (stacks->sorted[i] == val)
	  return (i);
	i++;
  }
  return (0);

}

void			ft_set_index(t_stack *stacks)
{
  int i;

  i = 0;
  while (i < stacks->size_a)
  {
	stacks->s_a[i].ind =
		ft_get_index(stacks, stacks->len, stacks->s_a[i].val);
	i++;
  }
}
