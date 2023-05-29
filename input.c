/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:02:27 by arasal            #+#    #+#             */
/*   Updated: 2023/05/28 18:36:12 by arasal           ###   ########.fr       */
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

	p = malloc(sizeof(t_plane));
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
	p->color.r = ft_atof(split2[0]) / (double)510;
	p->color.g = ft_atof(split2[1]) / (double)510;
	p->color.b = ft_atof(split2[2]) / (double)510;
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

	s = malloc(sizeof(t_sphere));
	split2 = ft_split(split[1], ',');
	s->centre_p.x = ft_atof(split2[0]);
	s->centre_p.y = ft_atof(split2[1]);
	s->centre_p.z = ft_atof(split2[2]);
	free_s(split2);
	s->radius = ft_atof(split[2]) / 2;
	split2 = ft_split(split[3], ',');
	s->color.r = ft_atof(split2[0]) / (double)510;
	s->color.g = ft_atof(split2[1]) / (double)510;
	s->color.b = ft_atof(split2[2]) / (double)510;
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

	c = malloc(sizeof(t_cylinder));
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
	c->color.r = ft_atof(split2[0]) / (double)510;
	c->color.g = ft_atof(split2[1]) / (double)510;
	c->color.b = ft_atof(split2[2]) / (double)510;
	free_s(split2);
	c->exist = true;
	mrt->obj[index].color = &(c->color);
	mrt->obj[index].exist = &(c->exist);
	mrt->obj[index].cylinder = c;
}

void	ft_input(t_struct *mrt, char **argv)
{
	int			index;
	int			fd;
	char		*str;
	char		**split;

	index = 0;
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
		free_s(split);
		str = get_next_line(fd);
		index++;
	}
}
