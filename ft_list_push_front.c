/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:39:10 by theinone          #+#    #+#             */
/*   Updated: 2020/02/23 14:46:26 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_list_push_front(t_list **begin_list, t_point h_point)
{
	t_list *new_one;
	new_one = ft_create_elem(h_point);
	new_one->next = *begin_list;
	*begin_list = new_one;
}
