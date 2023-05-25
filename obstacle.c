/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:17:27 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/23 16:25:00 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "obstacle.h"

t_vector	ft_intersection_s(t_sphere sphere, t_ray *ray) // calculates the nearest intersection point
{
	t_vector	O;
	t_vector	intersect;
	double		a;
	double		b;
	double		c;
	double		d;
	
	O.x = 0.0f;
	O.y = 0.0f;
	O.z = 0.0f;
	intersect = ft_substractv(O, sphere.centre);
	a = ft_dotp(&ray->direction, &ray->direction);
	b = 2 * ft_dotp(&intersect, &ray->direction);
	c = ft_dotp(&intersect, &intersect) - sphere.radius * sphere.radius;
	d = ft_midnight(a, b, c);
	if (d < 0)
		return (intersect.x = CAMERA_X, intersect.y = CAMERA_Y, intersect.z = CAMERA_Z, O);
	intersect = ft_calculate_point(ray, d);
	return (intersect);
}
