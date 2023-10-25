/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:50:09 by mayan             #+#    #+#             */
/*   Updated: 2023/10/12 19:10:46 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stk *a)
{
	int	i;
	int	temp;

	if (a->top > 0)
	{
		i = a->top;
		temp = a->data[a->top];
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[0] = temp;
		ft_printf("%s", "ra\n");
	}
}

/*The function first checks if the stack `a`
has at least one element.
If the stack has at least one element,the function
rotates the stack by one element to the top.
To rotate the stack, the function first saves the value of the top element in a
temporary variable `temp`. It then shifts all the elements
 in the stack one position to the left,
starting from the bottom of the stack.
Finally, it sets the value of the top element
in the stack to the value of `temp`.									------->
For example,if the stack `a` contains the elements `[1, 2, 3, 4]`,
calling `ra(a)` will result in the stack `a`									<-
containing the elements `[2, 3, 4, 1]`.*/