/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:43:05 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 18:03:24 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

t_stack	*ft_change_type(t_data *stack, char **argv)
{
	long	i;
	char	**tmp;
	t_stack	*tmpa;

	i = 0;
	tmp = error_check(argv, stack);
	stack->a = ft_lstnew(0);
	tmpa = stack->a;
	while (tmp[i] != NULL)
	{
		stack->a->data = ft_atoi(tmp[i]);
		if (tmp[i + 1] != NULL)
			stack->a->next = ft_lstnew(0);
		free(tmp[i]);
		i++;
		stack->a = stack->a->next;
	}
	free(tmp);
	stack->a = tmpa;
	check_dbl(stack->a);
	check_max_min(stack->a);
	return (stack->a);
}
