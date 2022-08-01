/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:52:47 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 18:21:38 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	ft_del_stack(t_stack *a)
{
	while (a)
	{
		free(a);
		a = a->next;
	}
}

void	ft_del(t_data *stack)
{
	while (stack->a)
	{
		free(stack->a);
		stack->a = stack->a->next;
	}
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
