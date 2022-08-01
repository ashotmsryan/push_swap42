/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:21:56 by amsryan           #+#    #+#             */
/*   Updated: 2022/07/31 18:10:34 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSW_H
# define PUSW_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	long int			data;
	long int			index;
	struct s_list		*next;
}				t_stack;

typedef struct s_data
{
	t_stack				*a;
	t_stack				*b;
	long int			size;
}				t_data;

t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_prelast(t_stack *lst);
t_stack	*norm_index(t_data *stack, t_stack *min, t_stack *tmp);
t_stack	*ft_change_type(t_data *stack, char **argv);
void	ft_del(t_data *stack);
void	ft_del_stack(t_stack *a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lsit, t_stack *new);
void	count(t_data *stack, char **s);
void	index_check(t_data *stack);
void	mng_3(t_data *stack);
void	mng_5(t_data *stack);
void	mng_other(t_data *stack);
void	ft_print_error(void);
void	check_max_min(t_stack *a);
void	ft_operation(t_data *stack);
void	ft_ss(t_data *stack);
void	ft_rrr(t_data *stack);
int		ft_sa(t_data *stack, int flag);
int		ft_sb(t_data *stack, int flag);
int		ft_pb(t_data *stack);
int		ft_pa(t_data *stack);
int		ft_ra(t_data *stack, int flag);
int		ft_rb(t_data *stack, int flag);
int		ft_rra(t_data *stack, int flag);
int		ft_rrb(t_data *stack, int flag);
int		ft_strcmp(char *s1, char *s2);
int		the_min(t_data *stack);
int		ifsort(t_data *stack);
int		ifelse(t_data *stack, int sz, int point);
long	ft_atoi(const char *str);
long	check_dbl(t_stack *a);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	**error_check(char **s, t_data *stack);
char	**ft_split(char const *s, char c);

#endif
