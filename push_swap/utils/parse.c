/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:15:58 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 15:44:39 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stk *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	has_duplicates(t_stk *a, t_stk *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->top)
	{
		j = i + 1;
		while (j <= a->top)
		{
			if (a->data[i] == a->data[j])
			{
				free_and_exit_with_msg(a, b, "Error Duplicate\n");
			}
			j++;
		}
		i++;
	}
}

//i; index of the numbers
//j; index of the numbers being compared to i
//k; numbers lesser than i/ascending order position
void	indexer(t_stk *a, t_stk *b)
{
	int	i;
	int	j;
	int	k;
	int	size;
	int	*indxdray;

	size = a->top + 1;
	indxdray = malloc(sizeof(int) * size);
	if (!indxdray)
		free_and_exit_with_msg(a, b, "Error\n");
	i = -1;
	while (++i < size)
	{
		j = -1;
		k = 0;
		while (++j < size)
			if (a->data[i] > a->data[j])
				k++;
		indxdray[i] = k;
	}
	while (size--)
		a->data[size] = indxdray[size];
	free(indxdray);
}

void	sort(t_stk *a, t_stk *b)
{
	if (a->top == 0)
	{
		ft_printf("Stack has only one number, already sorted\n");
		exit(EXIT_FAILURE);
	}
	else if (a->top == 1)
	{
		if (a->data[a->top] > a->data[a->top - 1])
			sa(a);
	}
	else if (a->top == 2)
		sortthree(a);
	else if (a->top == 3)
		sortfour(a, b);
	else if (a->top == 4)
		sortfive(a, b);
	else if (a->top > 4)
		radix(a, b);
}
