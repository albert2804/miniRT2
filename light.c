/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:00:32 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/31 19:25:12 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"

void	ambient_light(t_ray *ray, t_struct *mrt)
{
	ray->rgb.r = (ray->rgb.r + \
	mrt->ambient.amb_ratio * mrt->ambient.color.r) / 2;
	ray->rgb.g = (ray->rgb.g + \
	mrt->ambient.amb_ratio * mrt->ambient.color.g) / 2;
	ray->rgb.b = (ray->rgb.b + \
	mrt->ambient.amb_ratio * mrt->ambient.color.b) / 2;
}

//calculates the normalvector, depending on the position of the object
//returns a zerovector for the background.
t_vector	calc_normalvector(t_vector pos, t_obj *object, int obj_index)
{
	int			i;
	t_vector	normal;

	i = obj_index;
	normal.x = 0;
	normal.y = 0;
	normal.z = 0;
	if (object[i].sphere)
	{
		normal = ft_substractv(pos, object[i].sphere->centre_p);
		normal = ft_normalized(normal);
	}
	if (object[i].plane)
	{
		normal = object[i].plane->normal;
		normal = ft_multiply(normal, -1);
	}
	// if (object[i].cylinder)
	// {
	// 	normal2 = object[i].cylinder_tube->normal;
	// }
	return (normal);
}

int	diffuse_lighting(t_ray *ray, t_ray *lray, int obj_index, t_struct *mrt)
{
	t_vector	intersect;
	t_vector	surface_dir;
	t_vector	lray_dir;
	double		dot_product;
	double		intensity;

	intensity = 0;
	intersect = ft_calculate_point(*ray, ray->t);
	surface_dir = calc_normalvector(intersect, mrt->obj, obj_index);
	lray_dir = ft_normalized(lray->direction);
	lray_dir = ft_multiply(lray_dir, -1);
	dot_product = ft_dotp(surface_dir, lray_dir);
	if (dot_product < 0 && dot_product >= -0.1)
		dot_product /= -2.0;
	else if (dot_product < -0.1)
		return (1);
	intensity = dot_product;
	ray->rgb.r = (ray->rgb.r + intensity * mrt->light.color.r) / 2;
	ray->rgb.g = (ray->rgb.g + intensity * mrt->light.color.g) / 2;
	ray->rgb.b = (ray->rgb.b + intensity * mrt->light.color.b) / 2;
	return (0);
}
