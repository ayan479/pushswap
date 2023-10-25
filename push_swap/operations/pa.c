/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:09:46 by mayan             #+#    #+#             */
/*   Updated: 2023/10/12 15:19:40 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** pa - Push the top element of stack b to stack a.
** @a: Stack a.
** @b: Stack b.
*/
void	pa(t_stk *a, t_stk *b)
{
	int	temp;

	if (b->top == -1)
		return ;
	temp = b->data[b->top];
	b->data[b->top] = 0;
	b->top--;
	a->top++;
	a->data[a->top] = temp;
	ft_printf("%s", "pa\n");
}
