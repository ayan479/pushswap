/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:35:26 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 20:26:56 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_whitespace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(char c, long long value, long sign, char **new_av)
{
	if (value > 2147483647 || (value * sign) < -2147483648
		|| ft_strlen(new_av[0]) > 11)
		return (0);
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_atol(const char *str, char **new_av, t_stk *a, t_stk *b)
{
	int			i;
	long		sign;
	long long	value;

	value = 0;
	sign = 1;
	i = 0;
	while (is_whitespace(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!is_valid_number(str[i], value, sign, new_av))
			free_and_exit_with_msg(a, b, "Error\n");
		value = value * 10 + (str[i++] - '0');
	}
	return ((int)(value * sign));
}

// int	main(void)
// {
// 	char	*c = "-2147483649";

// 	printf("%i\n", ft_atoi(c));
// 	printf("%i\n", atoi(c));
// }
