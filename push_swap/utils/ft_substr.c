/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:17:32 by mayan             #+#    #+#             */
/*   Updated: 2023/10/05 13:41:34 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (!s)
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	substr = (char *) malloc (sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, &s[start], len);
	substr[len] = '\0';
	return (substr);
}

// int	main(void)
// {
//     char *original = "sixty";
//    printf("%s",ft_substr(original, 3, 2));
//     return 0;
// }
