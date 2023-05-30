/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:21:23 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/30 15:03:19 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obstacle.h" 
#include "vector.h"
#include "camera.h"

void		send_ray(t_ray *ray, t_vector p1, t_vector p2)
{
	t_vector direction;
	
	ray->viewport = p2;
	ray->origin_p = p1;
	direction = ft_substractv(p2, p1);
	// ray->direction = ft_normalized(direction);
	ray->direction = direction;
	ray->t = T_MAX;
}

void		send_shadowray(t_ray *sray, t_vector intersect_p, t_vector light_p)
{
	t_vector direction;
	
	sray->origin_p = intersect_p;
	direction = ft_substractv(light_p, intersect_p);
	// sray->direction = ft_normalized(direction);
	sray->direction = direction;
	sray->t = 1;
}

void make_hardshadows(t_ray *sray, t_ray *ray, int obj_index, t_struct *mrt)
{
	send_shadowray(sray, shadowray_start(mrt->obj, ray, obj_index), mrt->light.light_p);
	if (ft_intersection(sray, mrt) > 0)
		ray->rgb = paint_color(0,0,0);
	else
		paint_obj_color(ray, mrt->obj[obj_index]);
}

//used for calculating a incremented offset value, to avoid shadow acne
t_vector shadowray_start(t_obj *object, t_ray *ray, int obj_index)
{
	t_vector	ray_intersect;
	t_vector	sray_intersect;
	int			i;

	i = obj_index;
	ray_intersect = ft_calculate_point(*ray, ray->t);
	sray_intersect = ft_calculate_point(*ray, ray->t);
	if (object[i].sphere)
	{
		sray_intersect = ft_substractv(ray_intersect, object[i].sphere->centre_p);
		sray_intersect = ft_multiply(sray_intersect, (1 + T_MIN));
		sray_intersect = ft_addv(object[i].sphere->centre_p, sray_intersect);
	}
	else if (object[i].plane)
	{
		sray_intersect = ft_multiply(object[i].plane->normal, T_MIN);
		sray_intersect = ft_addv(ray_intersect, sray_intersect);
	}
	return (sray_intersect);
}