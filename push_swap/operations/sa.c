/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:23:38 by mayan             #+#    #+#             */
/*   Updated: 2023/10/12 20:36:04 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stk	*a)
{
	swap(&a->data[a->top], &a->data[a->top - 1]);
	ft_printf("%s", "sa\n");
}
