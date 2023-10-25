/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:35:26 by mayan             #+#    #+#             */
/*   Updated: 2023/10/03 19:18:25 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	is_whitespace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	value;
	int			sign;

	i = 0;
	value = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		value = (value * 10) + (str[i] - '0');
		if (value * sign > 2147483647)
			return (-1);
		else if (value * sign < -2147483648)
			return (0);
		i++;
	}
	return ((int)(value * sign));
}

// int	main(void)
// {
// 	char	*c = "-2147483649";

// 	printf("%i\n", ft_atoi(c));
// 	printf("%i\n", atoi(c));
// }
