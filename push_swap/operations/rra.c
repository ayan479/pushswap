/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:01 by mayan             #+#    #+#             */
/*   Updated: 2023/10/12 20:26:12 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//reverse rotate a - shift down all elements of stack a by 1.
//The last element becomes the first one.
void	rra(t_stk *a)
{
	int	temp;
	int	i;

	if (a->top <= 0)
		return ;
	temp = a->data[0];
	i = 0;
	while (i < a->top)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->top] = temp;
	ft_printf("rra\n");
}
