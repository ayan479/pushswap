/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:51:13 by mayan             #+#    #+#             */
/*   Updated: 2023/10/26 18:57:11 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sortthree(t_stk *a)
{
	int	x;
	int	y;
	int	z;

	x = a->data[0];
	y = a->data[1];
	z = a->data[2];
	if (x > y && y < z && x > z)
		sa(a);
	else if (x > y && y < z && x < z)
		ra(a);
	else if (x < y && y < z && x < z)
	{
		sa(a);
		rra(a);
	}
	else if (x < y && y > z && x < z)
		rra(a);
	else if (x < y && y > z && x > z)
	{
		sa(a);
		ra(a);
	}
}

void	sortfour(t_stk *a, t_stk *b)
{
	if (numsmall(a) <= a->top / 2)
		while (numsmall(a) != a->top)
			rra(a);
	else
		while (numsmall(a) != a->top)
			ra(a);
	pb(a, b);
	sortthree(a);
	pa(a, b);
}

void	sortfive(t_stk *a, t_stk *b)
{
	while (numsmall(a) != a->top)
	{
		if (numsmall(a) <= a->top / 2)
			rra(a);
		else
			ra(a);
		if (is_sorted(a) == 1)
			free_and_exit_with_msg(a, b, NULL);
	}
	pb(a, b);
	sortfour(a, b);
	pa(a, b);
}
