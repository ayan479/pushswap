/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:06 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 22:14:51 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stk *b)
{
	int	i;
	int	temp;
	int	repp;
	int	top;

	i = 0;
	top = b->top;
	repp = b->data[top];
	while (i < top)
	{
		if (i == 0)
			temp = b->data[i];
		swap(&temp, &b->data[i + 1]);
		i++;
	}
	b->data[0] = repp;
	ft_printf("rb\n");
}