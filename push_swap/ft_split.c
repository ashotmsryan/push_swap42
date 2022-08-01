/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:09:17 by amsryan           #+#    #+#             */
/*   Updated: 2022/03/25 16:16:20 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pusw.h"

char	*ft_substr(char const *s, unsigned int start, size_t l)
{
	size_t	lns;
	char	*str;
	char	*ptr;
	size_t	j;

	str = (char *)s;
	j = 0;
	lns = ft_strlen(str);
	if (start > lns || l == 0)
		j = 0;
	else if (lns - start + 1 > l)
		j = l;
	else
		j = lns - start;
	ptr = (char *)malloc((1 + j));
	if (!ptr)
		return (0);
	lns = 0;
	while (str[start] && lns < j)
		ptr[lns++] = str[start++];
	ptr[lns] = '\0';
	return (ptr);
}

static int	stime(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{	
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		else if (j == 1 && *s == c)
			j = 0;
		s++;
	}
	return (i);
}

static int	szword(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static void	*freeing(char **arr, int i)
{
	while (i-- > 0)
	{
		free (arr[i]);
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**arr;

	i = 0;
	len = stime((char *)s, c);
	arr = (char **)malloc((len * sizeof (char *) + 1));
	if (!arr)
		return (NULL);
	while (len--)
	{
		while (*s == c && *s)
			s++;
		arr[i] = ft_substr((char *)s, 0, szword((char *)s, c));
		if (!arr[i])
			return (freeing(arr, i));
		s = s + szword((char *)s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
