/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:11:47 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 22:11:12 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stk *a, t_stk *b)
{
	b->data[++b->top] = a->data[a->top];
	a->top--;
	ft_printf("pb\n");
}
