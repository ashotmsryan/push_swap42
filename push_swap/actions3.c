/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:14:16 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 17:12:24 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	index_check(t_data *stack)
{
	t_stack	*tmp;
	int		count;
	t_stack	*min;

	count = stack->size;
	tmp = stack->a;
	min = stack->a;
	while (stack->a)
	{
		stack->a->index = -1;
		stack->a = stack->a->next;
	}
	stack->a = tmp;
	while (count--)
	{
	min = norm_index(stack, min, tmp);
	stack->a = tmp;
	}
	stack->a = tmp;
}

t_stack	*norm_index(t_data *stack, t_stack *min, t_stack *tmp)
{
	static int	i;

	while (stack->a)
	{
		if (min->data > stack->a->data && stack->a->index == -1)
			min = stack->a;
		stack->a = stack->a->next;
	}
	stack->a = tmp;
	min->index = i;
	while (stack->a)
	{
		if (stack->a->index == -1)
		{
			min = stack->a;
			break ;
		}
		stack->a = stack->a->next;
	}
	i++;
	return (min);
}

void	count(t_data *stack, char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{	
		stack->size++;
		i++;
	}
}

t_stack	*ft_prelast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_rrr(t_data *stack)
{
	ft_rra(stack, 0);
	ft_rrb(stack, 0);
	write (1, "rrr\n", 4);
}
