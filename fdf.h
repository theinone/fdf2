/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:04:02 by theinone          #+#    #+#             */
/*   Updated: 2020/02/24 13:08:20 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx/mlx.h"
# include <math.h>
#include <stdlib.h>

typedef struct	s_mlx {
		void	*ptr;
		void	*win;
}				t_mlx;
typedef struct	s_point {
		int		x;
		int		y;
		int		z;
}				t_point;

typedef struct		s_list
{
	struct s_list		*next;
	t_point				h_point;
	t_point				v_point;
}					t_list;

t_list			*ft_create_elem(t_point h_point);
void	ft_list_push_front(t_list **begin_list, t_point h_point);
t_list *ft_readfile(char *filename);
void ft_draw(t_list *points);
#endif
