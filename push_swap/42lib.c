/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42lib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:12:16 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/16 11:39:02 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		if (!str[i])
			return (0);
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{	
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	if (s1)
		free (s1);
	return (s);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	j;
	long	k;

	j = 0;
	k = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10;
		j = j + (str[i] - '0');
		i++;
	}
	return (j * k);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*a;

	i = ft_strlen(s);
	a = malloc((i + 1) * sizeof(char));
	i = 0;
	if (!a)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
