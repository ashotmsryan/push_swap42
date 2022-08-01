/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:03:10 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 16:50:32 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

int	find_range(long int sz)
{
	long int	range;

	range = 0;
	if (sz <= 100)
	{
		range = sz * 15;
		range /= 100;
	}
	else if (sz > 100)
	{
		range = sz * 30;
		range /= 500;
	}
	return (range);
}

void	push_a(t_data *stack)
{
	t_stack		*first;
	long int	place;
	long int	sz;

	sz = stack->size;
	place = 0;
	while (stack->b)
	{
		first = stack->b;
		while (sz - 1 != stack->b->index)
		{
			place++;
			stack->b = stack->b->next;
		}
		stack->b = first;
		if (place <= sz / 2)
			while (stack->b->index != sz - 1)
				ft_rb(stack, 1);
		else if (place > sz / 2)
			while (stack->b->index != sz - 1)
				ft_rrb(stack, 1);
		ft_pa(stack);
		place = 0;
		sz--;
	}
}

void	mng_other(t_data *stack)
{
	long int	count;
	long int	range;
	long int	sz;

	count = 0;
	sz = stack->size;
	index_check(stack);
	while (stack->a)
	{
		range = find_range(sz);
		if (stack->a->index <= count)
		{
			ft_pb(stack);
			ft_rb(stack, 1);
			count++;
		}
		else if (stack->a->index <= count + range)
		{
			ft_pb(stack);
			count++;
		}
		else
			ft_ra(stack, 1);
	}
	push_a(stack);
}
