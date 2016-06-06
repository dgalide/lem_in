/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:59:37 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:14:41 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
/*
char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s || !c)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_countwords(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			tab[j] = ft_strsub(&s[i], 0, ft_lenwords(s, c, (j + 1)));
			i += (ft_lenwords(s, c, (j + 1)));
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
*/
static int		len_until_chr(char *s, int index, char c)
{
	int n;

	n = 0;
	while (s && s[index] && s[index] != c)
	{
		n += 1;
		index += 1;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char **tab;
	int i;
	int j;
	int l;

	i = 0;
	j = 0;
	l = ft_countwords(s, c);
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (l + 1));
	tab[l] = NULL;
	printf("SPLIT, buff == {%s}\n", s);
	while (s && s[i])
	{
		if (s[i] != c)
		{
			printf("SPLIT, buff[i] == {%c}\n", s[i]);
			tab[j] = ft_strsub(s, i, len_until_chr((char *)s, i, c));
			printf("SPLIT, sub OK\n");
			i += ft_strlen((char *)tab[j]);
			j += 1;
		}
		else
			i += 1;
	}
	return (tab);
}
