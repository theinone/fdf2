/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:36:33 by theinone          #+#    #+#             */
/*   Updated: 2020/07/22 18:05:15 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_drawline(int x0, int y0, int x1, int y1, t_mlx tmlx, int color)
{
    int dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx; 
	while(x < x1)
	{
		if(p >= 0)
		{
			mlx_pixel_put(tmlx.ptr, tmlx.win, x, y, mlx_get_color_value(tmlx.ptr, color));
			y = y + 1;
			p= p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(tmlx.ptr, tmlx.win, x, y, mlx_get_color_value(tmlx.ptr, color));
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
   	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void ft_draw(t_list *points)
{
	t_mlx tmlx;
	int	x;
	int y;
	int	scale;
	int padding;
	t_point point;
	t_point nextpoint;
	t_point vpoint;
	t_point vnextpoint;
	int color = 0x0000ff;

	x = 0;
	y = 0;
	scale = 30;
	padding = 0;
	tmlx.ptr = mlx_init();
	tmlx.win = mlx_new_window(tmlx.ptr, 1200, 1200, "fdf");
 	while (points->next)
	{
		point.x = points->h_point.x;
		point.y = points->h_point.y;
		point.z = points->h_point.z;
		nextpoint.x = points->next->h_point.x;
		nextpoint.y = points->next->h_point.y;
		nextpoint.z = points->next->h_point.z;
		
		vpoint.x = points->v_point.x;
		vpoint.y = points->v_point.y;
		vpoint.z = points->v_point.z;
		vnextpoint.x = points->next->v_point.x;
		vnextpoint.y = points->next->v_point.y;
		vnextpoint.z = points->next->v_point.z;
		
		if (point.z < 9 || nextpoint.z < 9)
			color = 0x00ff00;
		else
			color = 0xff0000;
		iso(&point.x, &point.y, point.z);
		iso(&nextpoint.x, &nextpoint.y, nextpoint.z);
		iso(&vpoint.x, &vpoint.y, point.z);
		iso(&vnextpoint.x, &vnextpoint.y, vnextpoint.z);
	//	ft_drawline(x * scale, y * scale, (x + 1) * scale, (y + 1) * scale, tmlx);
		//ft_drawline(points->x * scale, points->y * scale, points->next->x * scale, points->next->y * scale, tmlx);
		//ft_drawline(vpoint.x * scale + padding, vpoint.y * scale + padding, vnextpoint.x * scale + padding, vnextpoint.y * scale + padding, tmlx, color);
		ft_drawline(point.x * scale + padding, point.y * scale + padding, nextpoint.x * scale + padding, nextpoint.y * scale + padding, tmlx, color);
		
					color = 0x00ff00;

		ft_drawline(points->h_point.x * scale, points->h_point.y * scale, points->next->h_point.x * scale, points->next->h_point.y * scale, tmlx, color);
		points = points->next;
	}
	mlx_loop(tmlx.ptr);
}
