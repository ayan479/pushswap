/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:38:25 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 16:16:21 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix2(t_stk *a, t_stk *b, int bits, int bitdex)
{
	int	size;

	size = b->top + 1;
	while (bitdex <= bits && !is_sorted(a) && size--)
	{
		if (((b->data[b->top] >> bitdex) & 1) == 0)
			rb(b);
		else
			pa(a, b);
	}
	if (is_sorted(a))
		while (b->top != -1)
			pa(a, b);
}

void	radix(t_stk *a, t_stk *b)
{
	int	bitdex;
	int	size;
	int	bits;

	size = a->top + 1;
	bits = 0;
	while (size > 1 && ++bits)
		size /= 2;
	bitdex = -1;
	while (++bitdex <= bits)
	{
		size = a->top + 1;
		while (size-- && !is_sorted(a))
		{
			if (((a->data[a->top] >> bitdex) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		radix2(a, b, bits, bitdex + 1);
	}
	while (b->top != -1)
		pa(a, b);
}
// Bit Size Calculation explanation
// Initially, bit_size is 0, and size is 10
// Binary representation of size is 1010.
// First Iteration (j = 0):

// size = 10 (1010 in binary, bit_size = 0)
// Right-shift size by 1: size = 5 (0101 in binary, bit_size = 1)
// Second Iteration (j = 1):

// size = 5 (0101 in binary, bit_size = 1)
// Right-shift size by 1: size = 2 (0010 in binary, bit_size = 2)
// Third Iteration (j = 2):

// size = 2 (0010 in binary, bit_size = 2)
// Right-shift size by 1: size = 1 (0001 in binary, bit_size = 3)
//bit size comes from the no. of numbers there are,
//and as we have indexed all the numbers,
//we know the highest number is simply the last index
