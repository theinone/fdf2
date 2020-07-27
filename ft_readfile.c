/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:27:06 by theinone          #+#    #+#             */
/*   Updated: 2020/02/24 13:17:36 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void convertdata(char *line, t_list **points, int currenty)
{
	int i;
	int start;
	int currentx;
	t_point h_point;

	i = 0;
	currentx = 1;
	start = 0;
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == ' ')
		{
			h_point.x = currentx;
			h_point.y = currenty;
			h_point.z =  ft_atoi(ft_strsub(line, start, (i - start)));

ft_list_push_front(points, h_point);
			start = i;
			currentx++;
		}
		while (line[i] == ' ')
			i++;
		i++;
	}
}

static void getvertical(t_list *points, t_point ypoints[], int currenty)
{
	while (points->next)
	{
		if (points->h_point.y == currenty)	
		{
			ypoints[currenty].x = points->h_point.x;
			ypoints[currenty].y = points->h_point.y;
			ypoints[currenty].z = points->h_point.z;
		ft_putendl("");
		ft_putnbr(ypoints[currenty].x);	
		return ;
		}
		points = points->next;
	}
}

static void convertvertical (t_list *points, t_point ypoints[], int i)
{
	while (points->next)
	{
		points->v_point.x = ypoints[i--].x;
		points->v_point.y = ypoints[i--].y;
		points->v_point.z = ypoints[i--].z;
		points = points->next;
	}

}

t_list *ft_readfile(char *filename)
{
	int 	fd;
	char 	*line;
	int		i;
	int		currenty;
	t_list	*points;
	t_point	ypoints[100];

	points = NULL;
	i = 0;
	currenty = 1;
	line = NULL;
	i = 0;
	fd = open(filename, O_RDONLY);
	while(get_next_line(fd, &line) == 1)
		convertdata(line, &points, currenty++);
	close(fd);
	i = currenty;
	while (currenty >= 0)
	{
		getvertical(points, ypoints, currenty);
		currenty--;
	}
	convertvertical(points, ypoints, i);
	return (points);
}
