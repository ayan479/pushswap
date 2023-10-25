/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:15:31 by mayan             #+#    #+#             */
/*   Updated: 2023/09/25 20:39:03 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	num_words(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	if (!s)
		return (0);
	tab = (char **)malloc((num_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (i < num_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		tab[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	tab[i] = 0;
	return (tab);
}

// int	main(void)
// {
// 	char	**tab;
// 	int		i;

// 	tab = ft_split(" joe bama 4 prez", ' ');
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("tab[%d] = %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }

// #include <stdlib.h>

// char	**ft_split(char *str)
// {
// 	int		i = 0;
// 	int		row = 0;
// 	int		column;
// 	int     wc = 0;

// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 			i++;
// 		if (str[i])
// 	}
// }
