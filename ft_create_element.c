/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:11:56 by theinone          #+#    #+#             */
/*   Updated: 2020/02/23 14:42:58 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_create_elem(t_point h_point)
{
	t_list *new_thingy;

	new_thingy = malloc(sizeof(t_list));
	new_thingy->h_point.x = h_point.x;
	new_thingy->h_point.y = h_point.y;
	new_thingy->h_point.z = h_point.z;
	new_thingy->next = NULL;
	return (new_thingy);
}
