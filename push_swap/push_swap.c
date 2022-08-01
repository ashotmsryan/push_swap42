/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:55:10 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/01 13:53:57 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

int	main(int argc, char **argv)
{
	t_data	stack;
	int		i;

	i = -1;
	if (argc >= 2)
	{
		while (argv[i++])
			if (argv[i] && !argv[i][0])
				ft_print_error();
		stack.a = NULL;
		stack.a = ft_change_type(&stack, argv);
		stack.b = NULL;
		ft_operation(&stack);
		ft_del(&stack);
	}
	else if (argc < 2)
		write(1, "Please, input arguments(int)\n", 29);
	return (0);
}
