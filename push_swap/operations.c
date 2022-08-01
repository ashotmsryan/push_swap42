/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:43:27 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 17:01:01 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

int	ifsort(t_data *stack)
{
	t_stack	*tmp;
	t_stack	*prv;

	tmp = stack->a;
	prv = stack->a;
	stack->a = stack->a->next;
	while (stack->a)
	{
		if (prv->data > stack->a->data)
		{
			stack->a = tmp;
			return (1);
		}
		prv = stack->a;
		stack->a = stack->a->next;
	}
	stack->a = tmp;
	return (0);
}

int	the_min(t_data *stack)
{
	t_stack	*min;
	int		t;
	t_stack	*tmp;

	t = 0;
	tmp = stack->a;
	min = stack->a;
	stack->a = stack->a->next;
	while (stack->a != NULL)
	{
		if (min->data > stack->a->data)
			min = stack->a;
		stack->a = stack->a->next;
	}
	stack->a = tmp;
	while (stack->a != min)
	{
		stack->a = stack->a->next;
		t++;
	}
	stack->a = tmp;
	return (t);
}

void	norm_3(t_data *stack, long int first, long int mid, long int last)
{
	if (first < last && first > mid)
		ft_sa(stack, 1);
	else if (first > last && first < mid)
		ft_rra(stack, 1);
	else if (first < last && mid > last)
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	else if (first > last && mid < last)
		ft_ra(stack, 1);
	else if (first > last && mid > last)
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
}

void	mng_3(t_data *stack)
{
	t_stack		*tmp;
	t_stack		*tt;
	long int	first;
	long int	mid;
	long int	last;

	tmp = stack->a;
	tt = stack->a->next;
	if (stack->size == 2 && tmp->data > tt->data)
	{
		ft_sa(stack, 1);
		stack->a = tmp;
	}
	else if (stack->size == 3 && ifsort(stack) == 1)
	{
		first = tmp->data;
		mid = tt->data;
		stack->a = ft_lstlast(stack->a);
		last = stack->a->data;
		stack->a = tmp;
		norm_3(stack, first, mid, last);
	}
}

void	ft_operation(t_data *stack)
{
	t_stack	*first;
	t_stack	*firstb;

	first = stack->a;
	firstb = stack->b;
	if (ifsort(stack) == 1)
	{
		if (stack->size <= 3)
			mng_3(stack);
		else if (stack->size <= 5)
			mng_5(stack);
		else if (stack->size > 5)
			mng_other(stack);
	}
}
