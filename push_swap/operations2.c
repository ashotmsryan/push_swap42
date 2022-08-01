/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:46:10 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 17:01:55 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	norm_4(t_data *stack)
{
	int	min;
	int	i;

	i = 1;
	while (i--)
	{	
		min = the_min(stack);
		if (min < 3)
		{
			while (min--)
				ft_ra(stack, 1);
			stack->size--;
		}
		else if (min >= 3)
		{
			min = stack->size - min;
			while (min--)
				ft_rra(stack, 1);
			stack->size--;
		}
		ft_pb(stack);
	}
}

void	norm_5(t_data *stack)
{
	int	min;
	int	i;

	i = 2;
	while (i--)
	{	
		min = the_min(stack);
		if (min < 3)
		{
			while (min--)
				ft_ra(stack, 1);
			stack->size--;
		}
		else if (min >= 3)
		{
			min = stack->size - min;
			while (min--)
				ft_rra(stack, 1);
			stack->size--;
		}
		ft_pb(stack);
	}
}

void	mng_5(t_data *stack)
{
	if (ifsort(stack) == 1)
	{	
		if (stack->size == 4)
		{
			norm_4(stack);
			mng_3(stack);
			ft_pa(stack);
		}
		else if (stack->size == 5)
		{
			norm_5(stack);
			mng_3(stack);
			ft_pa(stack);
			ft_pa(stack);
		}
	}
}
