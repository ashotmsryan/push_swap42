/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:59 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/15 17:20:39 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

int	ft_sa(t_data *stack, int flag)
{
	long int	i;
	long int	j;
	t_stack		*c;

	c = stack->a;
	i = stack->a->data;
	if (stack->a == NULL || stack->a->next == NULL)
		return (0);
	stack->a = stack->a->next;
	j = stack->a->data;
	stack->a->data = i;
	stack->a = c;
	stack->a->data = j;
	if (flag == 1)
		write(1, "sa\n", 3);
	return (0);
}

int	ft_sb(t_data *stack, int flag)
{
	long int	i;
	long int	j;
	t_stack		*c;

	if (stack->b == NULL || stack->b->next == NULL)
		return (0);
	c = stack->b;
	i = stack->b->data;
	stack->b = stack->b->next;
	j = stack->b->data;
	stack->b->data = i;
	stack->b = c;
	stack->b->data = j;
	if (flag == 1)
		write(1, "sb\n", 3);
	return (0);
}

void	ft_ss(t_data *stack)
{
	ft_sa(stack, 0);
	ft_sa(stack, 0);
	write(1, "ss\n", 3);
}

int	ft_pb(t_data *stack)
{
	t_stack	*tmp;

	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = NULL;
	if (!stack->b)
		stack->b = tmp;
	else
		ft_lstadd_front(&stack->b, tmp);
	write(1, "pb\n", 3);
	return (0);
}

int	ft_pa(t_data *stack)
{
	t_stack	*tmp;

	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = NULL;
	if (!stack->a)
		stack->a = tmp;
	else
		ft_lstadd_front(&stack->a, tmp);
	write(1, "pa\n", 3);
	return (0);
}
