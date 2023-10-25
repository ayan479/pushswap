/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:44:55 by mayan             #+#    #+#             */
/*   Updated: 2023/10/25 15:09:49 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stk
{
	int		top;
	int		*data;
}			t_stk;

//utils
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strlen(const char *str);
int			ft_strcat(char *dest, char *src);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		swap(int *a, int *b);
void		free_split(char **str);
int			numsmall(t_stk *a);
void		free_and_exit_with_msg(t_stk *a, t_stk *b, char *msg);
//ps funcs
void		parsearg(t_stk *a, t_stk *b, char *av);
char		*argconc(int ac, char **av);
int			is_sorted(t_stk *a);
void		has_duplicates(t_stk *a, t_stk *b);
void		sortthree(t_stk *a);
void		sortfour(t_stk *a, t_stk *b);
void		sortfive(t_stk *a, t_stk *b);
void		sort(t_stk *a, t_stk *b);
void		indexer(t_stk *a, t_stk *b);
void		radix(t_stk *a, t_stk *b);
void		radix2(t_stk *a, t_stk *b, int bits, int bitdex);

//moves
void		sa(t_stk *a);
void		sb(t_stk *b);
void		ss(t_stk *a, t_stk *b);
void		pa(t_stk *a, t_stk *b);
void		pb(t_stk *a, t_stk *b);
void		ra(t_stk *a);
void		rb(t_stk *b);
void		rr(t_stk *a, t_stk *b);
void		rra(t_stk *a);
void		rrb(t_stk *b);
void		rrr(t_stk *a, t_stk *b);

#endif
