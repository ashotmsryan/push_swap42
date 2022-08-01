/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:15:43 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 18:23:17 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	check_max_min(t_stack *a)
{
	t_stack	*first;

	first = a;
	while (a != NULL)
	{
		if (a->data > 2147483647 || a->data < -2147483648)
		{
			a = first;
			ft_del_stack(a);
			ft_print_error();
		}
		a = a->next;
	}
}

long	check_dbl(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*b;
	t_stack	*first;

	tmp = a;
	first = tmp;
	while (a != NULL)
	{
		b = a;
		a = a->next;
		first = a;
		while (a != NULL)
		{
			if (a->data == b->data)
			{
				a = tmp;
				ft_del_stack(a);
				ft_print_error();
			}
			a = a->next;
		}
		a = first;
	}
	a = tmp;
	return (0);
}

char	**ft_read_numb(char **s, t_data *stack)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	while (s[i] != NULL)
	{
		if (!str)
			str = ft_strdup(s[i]);
		else
			str = ft_strjoin(str, s[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	s = ft_split(str, ' ');
	free(str);
	count(stack, s);
	return (s);
}

char	**my_while(int i, char **s)
{
	int	j;

	j = 0;
	while (s[i][j] != '\0')
	{
		if (((s[i][j] == '+' || s[i][j] == '-')
			&& (s[i][j + 1] == '+'
			|| s[i][j + 1] == '-')) || ((s[i][j] == '+'
			|| s[i][j] == '-') && s[i][j + 1] == '\0'))
			ft_print_error();
		else if (((s[i][j - 1] >= 48 || s[i][j - 1] <= 57)
			&& s[i][j - 1]) && ((s[i][j + 1] >= 48
			|| s[i][j + 1] <= 57) && j != 0)
			&& (s[i][j] == '+' || s[i][j] == '-'))
			ft_print_error();
		else if ((s[i][j] < 48 || s[i][j] > 57)
			&& s[i][j] != '+' && s[i][j] != '-')
			ft_print_error();
		j++;
	}
	return (s);
}

char	**error_check(char **nbr, t_data *stack)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	j = 0;
	s = ft_read_numb(nbr, stack);
	while (s[i] != NULL)
	{
		s = my_while(i, s);
		i++;
	}
	return (s);
}
