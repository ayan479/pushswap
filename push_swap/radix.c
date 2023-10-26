/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:38:25 by mayan             #+#    #+#             */
/*   Updated: 2023/10/26 17:43:51 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printstack(t_stk *a)
// {
// 	int	i;

// 	i = a->top;
// 	while (i >= 0)
// 	{
// 		if (i == a->top)
// 		{
// 			ft_printf("%s", "\n");
// 			ft_printf("\033[1;31m%d\033[0m ", a->data[i]);
// 			ft_printf("%s", "\n");
// 		}
// 		else
// 		{
// 			ft_printf("\033[1;32m%d\033[0m ", a->data[i]);
// 			ft_printf("%s", "\n");
// 		}
// 		i--;
// 	}
// 	ft_printf("\n");
// }

void	radix2(t_stk *a, t_stk *b, int bits, int bitdex)
{
	int	size;

	size = b->top + 1;
	while (size-- && bitdex <= bits && !is_sorted(a))
	{
		if (((b->data[b->top] >> bitdex) & 1) == 0)
			rb(b);
		else
			pa(a, b);
	}
	if (is_sorted(a))
		while (b->top + 1 != 0)
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
		size >>= 1;
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
			// ft_printf("Stack after radix1 loop: %d", size);
			// printstack(a);
			// printstack(b);
		}
		radix2(a, b, bits, bitdex + 1);
		// ft_printf("Stack after radix2: ");
		// printstack(a);
		// printstack(b);
	}
	while (b->top + 1 != 0)
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
// void	radix_sort(t_stacks *s)
// {
// 	int	j;
// 	int	bit_size;
// 	int	size;

// 	bit_size = 0;
// 	// printf("a_size: %d\n", s->a_size);
// 	size = s->a_size;
// 	while (size > 1 && ++bit_size)
// 		size /= 2;
// 	j = -1;
// 	// printf("bit size: %d\n", bit_size);
// 	while (++j <= bit_size) //j = 0 bit_size = 3
// 	{
// 		// printf("j: %d\n", j); // added line
// 		size = s->a_size; // 8
// 		// printf("size: %d\n", size); // added line
// 		while (size-- && !is_array_sorted(s))
// 		{
// 			if (((s->a[0] >> j) & 1) == 0)
// 				push("pb", s);
// 			else
// 				rotate(s->a, s->a_size, "up", "a");
// 		}
// 		radix_sort_stack_b(s, s->b_size, bit_size, j + 1);
// 		// printf("a: ");
// 		// print_array(s->a, s->a_size);
// 		// printf("\nb: ");
// 		// print_array(s->b, s->b_size);
// 		// printf("\n");
// 	}
// 	while (s->b_size != 0)
// 		push("pa", s);
// 	// printf("a_size: %d\n", s->a_size);
// 	// printf("bit size: %d\n", bit_size);
// }