/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:09:46 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 22:11:42 by mayan            ###   ########.fr       */
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
	a->data[++a->top] = b->data[b->top--];
	ft_printf("pa\n");
}
