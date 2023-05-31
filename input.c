/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:02:31 by arasal            #+#    #+#             */
/*   Updated: 2023/06/01 00:05:09 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

void	create_light(t_struct *mrt, char **split)
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

void	create_amb(t_struct *mrt, char **split)
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

void	init_ray(t_ray *ray, int type)
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

void	create_object(char **split, t_struct *mrt, int index)
{
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
}

double	ft_atof(char *str)
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
		free_s(l);
		return (i);
	}
}
