/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:16:02 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 16:14:29 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit_with_msg(t_stk *a, t_stk *b, char *msg)
{
	if (msg)
		printf("%s", msg);
	if (a != NULL)
		free(a->data);
	if (b != NULL)
		free(b->data);
	if (a != NULL)
		free(a);
	if (b != NULL)
		free(b);
	exit(1);
}

void	parsearg(t_stk *a, t_stk *b, char *av)
{
	char	**new_av;
	int		top;
	int		i;

	i = 0;
	new_av = ft_split(av, ' ');
	while (new_av[i])
		i++;
	a->data = malloc(sizeof(int) * i);
	b->data = malloc(sizeof(int) * i);
	a->top = i - 1;
	b->top = -1;
	top = a->top;
	i = -1;
	while (new_av[++i] && top >= 0)
		a->data[top--] = ft_atoi(new_av[i]);
	free_split(new_av);
}

char	*argconc(int ac, char **av)
{
	int		total_len;
	int		arg_i;
	char	*result;

	total_len = 0;
	arg_i = 1;
	while (arg_i < ac)
		total_len += ft_strlen(av[arg_i++]) + 1;
	result = ft_calloc(total_len, sizeof(char));
	if (!result)
		return (NULL);
	arg_i = 1;
	while (arg_i < ac)
	{
		ft_strcat(result, av[arg_i]);
		if (arg_i < ac - 1)
			ft_strcat(result, " ");
		arg_i++;
	}
	return (result);
}

// void	print_stack(t_stk *a)
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

int	main(int ac, char **av)
{
	t_stk	a;
	t_stk	b;
	char	*args;

	if (ac <= 1)
		ft_printf("%s", "not enough arguments");
	args = argconc(ac, av);
	parsearg(&a, &b, args);
	if (args != NULL)
		free(args);
	// ft_printf("top index: %d\n", a.top);
	// ft_printf("top number: %d\n", a.data[a.top]);
	// ft_printf("Stack a before sorting: ");
	// print_stack(&a);
	is_sorted(&a);
	has_duplicates(&a, &b);
	indexer(&a, &b);
	// ft_printf("Stack after index: ");
	// print_stack(&a);
	sort(&a, &b);
	// ft_printf("Stack a after sorting: ");
	// print_stack(&a);
	if (is_sorted(&a))
		free_and_exit_with_msg(&a, &b, "Sorted");
	free_and_exit_with_msg(&a, &b, NULL);
	return (0);
}

// (free(NULL), i = 0, j = 0, k = 0);