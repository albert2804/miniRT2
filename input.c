/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:02:27 by arasal            #+#    #+#             */
/*   Updated: 2023/05/31 21:16:16 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	ft_atof(char *str)
{
	double	i;
	double	j;
	int		k;
	char	**l;

	if (!ft_strchr(str, '.'))
	{
		i = (double)ft_atoi(str);
		return (i);
	}
	else
	{
		l = ft_split(str, '.');
		i = (double)ft_atoi(l[0]);
		j = (double)ft_atoi(l[1]);
		k = (int)ft_strlen(l[1]);
		i = i + (j / pow(10, (double)k));
		return (i);
	}
}

static void	create_obj_plane(t_struct *mrt, char **split, int index)
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

static void	create_obj_sphere(t_struct *mrt, char **split, int index)
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

static void	create_obj_cylinder(t_struct *mrt, char **split, int index)
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

static void	create_camera(t_struct *mrt, char **split)
{
	t_camera	*camera;
	char		**split2;

	camera = ft_calloc(sizeof(t_camera), 1);
	split2 = ft_split(split[1], ',');
	camera->view_p.x = ft_atof(split2[0]) * (-1);
	camera->view_p.y = ft_atof(split2[1]) * (-1);
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

static void	create_light(t_struct *mrt, char **split)
{
	t_light		light;
	char		**split2;

	split2 = ft_split(split[1], ',');
	light.light_p.x = ft_atof(split2[0]);
	light.light_p.y = ft_atof(split2[1]);
	light.light_p.z = ft_atof(split2[2]);
	free_s(split2);
	light.intensity = ft_atof(split[2]);
	split2 = ft_split(split[3], ',');
	light.color.r = ft_atof(split2[0]) / (double)255;
	light.color.g = ft_atof(split2[1]) / (double)255;
	light.color.b = ft_atof(split2[2]) / (double)255;
	free_s(split2);
	mrt->light = light;
}

static void	create_amb(t_struct *mrt, char **split)
{
	t_amb		amb;
	char		**split2;

	amb.amb_ratio = ft_atof(split[1]);
	split2 = ft_split(split[2], ',');
	amb.color.r = ft_atof(split2[0]) / (double)255;
	amb.color.g = ft_atof(split2[1]) / (double)255;
	amb.color.b = ft_atof(split2[2]) / (double)255;
	free_s(split2);
	mrt->ambient = amb;
}

/**
int type is a flag to determine if the ray is a normal ray \
shadow or light
normal ray: shadow = 0;
normal ray: shadow = 1;
normal ray: shadow = 2;
*/
void init_ray(t_ray *ray, int type)
{
	ray->rgb.r = 0;
	ray->rgb.g = 0;
	ray->rgb.b = 0;
	ray->bounces = 0;
	ray->type = type;
	if (ray->type == 1)
		ray->t = 1;
	else
		ray->t = T_MAX;
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
		ft_putendl_fd(split[0], STDOUT_FILENO);
		if (!ft_strncmp(split[0], "pl", 2))
			create_obj_plane(mrt, split, index);
		if (!ft_strncmp(split[0], "sp", 2))
			create_obj_sphere(mrt, split, index);
		if (!ft_strncmp(split[0], "cy", 2))
			create_obj_cylinder(mrt, split, index);
		if (!ft_strncmp(split[0], "C", 1))
			create_camera(mrt, split);
		if (!ft_strncmp(split[0], "A", 1))
			create_amb(mrt, split);
		if (!ft_strncmp(split[0], "L", 1))
			create_light(mrt, split);
		free_s(split);
		str = get_next_line(fd);
		index++;
	}
}
