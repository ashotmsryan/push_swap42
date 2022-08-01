/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:40:57 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/05 14:39:19 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

int	ft_ra(t_data *stack, int flag)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stack->a == NULL || stack->a->next == NULL)
		return (0);
	first = stack->a;
	tmp = stack->a->next;
	stack->a = ft_lstlast(stack->a);
	stack->a->next = first;
	first->next = NULL;
	stack->a = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(t_data *stack, int flag)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stack->b == NULL || stack->b->next == NULL)
		return (0);
	first = stack->b;
	tmp = stack->b->next;
	stack->b = ft_lstlast(stack->b);
	stack->b->next = first;
	first->next = NULL;
	stack->b = tmp;
	if (flag == 1)
		write(1, "rb\n", 3);
	return (0);
}

void	ft_rr(t_data *stack)
{
	ft_ra(stack, 0);
	ft_rb(stack, 0);
	write (1, "rr\n", 1);
}

int	ft_rra(t_data *stack, int flag)
{
	t_stack	*prelast;
	t_stack	*first;

	if (stack->a == NULL || stack->a->next == NULL)
		return (0);
	first = stack->a;
	prelast = ft_prelast(stack->a);
	stack->a = first;
	stack->a = ft_lstlast(stack->a);
	prelast->next = NULL;
	stack->a->next = first;
	if (flag == 1)
		write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_data *stack, int flag)
{
	t_stack	*prelast;
	t_stack	*first;

	if (stack->b == NULL || stack->b->next == NULL)
		return (0);
	first = stack->b;
	prelast = ft_prelast(stack->b);
	stack->b = first;
	stack->b = ft_lstlast(stack->b);
	prelast->next = NULL;
	stack->b->next = first;
	if (flag == 1)
		write(1, "rrb\n", 4);
	return (0);
}
