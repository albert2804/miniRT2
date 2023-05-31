/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:02:27 by arasal            #+#    #+#             */
/*   Updated: 2023/06/01 00:13:45 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

void	create_obj_plane(t_struct *mrt, char **split, int index)
{
	t_plane		*p;
	char		**split2;

	p = ft_calloc(sizeof(t_plane), 1);
	split2 = ft_split(split[1], ',');
	p->position_p.x = ft_atof(split2[0]);
	p->position_p.y = ft_atof(split2[1]);
	p->position_p.z = ft_atof(split2[2]);
	free_s(split2);
	split2 = ft_split(split[2], ',');
	p->normal.x = ft_atof(split2[0]);
	p->normal.y = ft_atof(split2[1]);
	p->normal.z = ft_atof(split2[2]);
	free_s(split2);
	split2 = ft_split(split[3], ',');
	p->color.r = ft_atof(split2[0]) / (double)255;
	p->color.g = ft_atof(split2[1]) / (double)255;
	p->color.b = ft_atof(split2[2]) / (double)255;
	free_s(split2);
	p->exist = true;
	mrt->obj[index].color = &(p->color);
	mrt->obj[index].exist = &(p->exist);
	mrt->obj[index].plane = p;
}

void	create_obj_sphere(t_struct *mrt, char **split, int index)
{
	t_sphere	*s;
	char		**split2;

	s = ft_calloc(sizeof(t_sphere), 1);
	split2 = ft_split(split[1], ',');
	s->centre_p.x = ft_atof(split2[0]);
	s->centre_p.y = ft_atof(split2[1]);
	s->centre_p.z = ft_atof(split2[2]);
	free_s(split2);
	s->radius = ft_atof(split[2]) / 2;
	split2 = ft_split(split[3], ',');
	s->color.r = ft_atof(split2[0]) / (double)255;
	s->color.g = ft_atof(split2[1]) / (double)255;
	s->color.b = ft_atof(split2[2]) / (double)255;
	free_s(split2);
	s->exist = true;
	mrt->obj[index].color = &(s->color);
	mrt->obj[index].exist = &(s->exist);
	mrt->obj[index].sphere = s;
}

void	create_obj_cylinder(t_struct *mrt, char **split, int index)
{
	t_cylinder	*c;
	char		**split2;

	c = ft_calloc(sizeof(t_cylinder), 1);
	split2 = ft_split(split[1], ',');
	c->centre_p.x = ft_atof(split2[0]);
	c->centre_p.y = ft_atof(split2[1]);
	c->centre_p.z = ft_atof(split2[2]);
	free_s(split2);
	split2 = ft_split(split[2], ',');
	c->axis_normal.x = ft_atof(split2[0]);
	c->axis_normal.y = ft_atof(split2[1]);
	c->axis_normal.z = ft_atof(split2[2]);
	free_s(split2);
	c->radius = ft_atof(split[3]) / 2;
	c->height = ft_atof(split[4]);
	split2 = ft_split(split[5], ',');
	c->color.r = ft_atof(split2[0]) / (double)255;
	c->color.g = ft_atof(split2[1]) / (double)255;
	c->color.b = ft_atof(split2[2]) / (double)255;
	free_s(split2);
	c->exist = true;
	mrt->obj[index].color = &(c->color);
	mrt->obj[index].exist = &(c->exist);
	mrt->obj[index].cylinder = c;
}

void	create_camera(t_struct *mrt, char **split)
{
	t_camera	*camera;
	char		**split2;

	camera = ft_calloc(sizeof(t_camera), 1);
	split2 = ft_split(split[1], ',');
	camera->view_p.x = ft_atof(split2[0]);
	camera->view_p.y = ft_atof(split2[1]);
	camera->view_p.z = ft_atof(split2[2]);
	free_s(split2);
	split2 = ft_split(split[2], ',');
	camera->orientation.x = ft_atof(split2[0]);
	camera->orientation.y = ft_atof(split2[1]);
	camera->orientation.z = ft_atof(split2[2]);
	free_s(split2);
	camera->orientation = ft_normalized(camera->orientation);
	camera->fov = ft_atof(split[3]);
	mrt->camera = camera;
}

void	ft_input(t_struct *mrt, char **argv)
{
	int			index;
	int			fd;
	char		*str;
	char		**split;

	index = 1;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		split = ft_split(str, ' ');
		free(str);
		ft_putendl_fd(split[0], STDOUT_FILENO);
		create_object(split, mrt, index);
		free_s(split);
		str = get_next_line(fd);
		index++;
	}
}
