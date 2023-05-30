/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:17:27 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/30 14:17:03 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "obstacle.h"

//returns the index of the objectlist
//if there is no intersection at all, the return value will be 0, which must be background
int		ft_intersection(t_ray *ray, t_struct *mrt) // calculates the nearest intersection point
{
	int			i;
	int			obj_index;
	
	i = 0;
	obj_index = 0;
	while (mrt->obj[i].exist)
	{
		if (mrt->obj[i].sphere)
		{
			ft_intersection_s(*mrt->obj[i].sphere, ray, i, &obj_index);
		}
		if (mrt->obj[i].plane)
		{	
			ft_intersection_p(*mrt->obj[i].plane, ray, i, &obj_index);
		}
		if (mrt->obj[i].cylinder)
		{
			ft_intersection_c(*mrt->obj[i].cylinder, ray, i, &obj_index);
		}
		i++;
	}
	return (obj_index);
}

void	ft_intersection_s(t_sphere sphere, t_ray *ray, int i, int *index) // calculates the nearest intersection point
{
	t_vector	intersect;
	double		a;
	double		b;
	double		c;
	double		d;

	intersect = ft_substractv(ray->origin_p, sphere.centre_p);
	a = ft_dotp(ray->direction, ray->direction);
	b = 2 * ft_dotp(intersect, ray->direction);
	c = ft_dotp(intersect, intersect) - pow(sphere.radius, 2);
	d = ft_midnight(a, b, c);
	if (d >= T_MIN && d <= ray->t)
	{
		ray->t = d;
		*index = i;
	}
}

static double	cal_m(double t, t_cylinder cylinder, t_ray *ray, t_vector intersect)
{
	double	m;

	m = 0;
	m = (ft_dotp(ray->direction, cylinder.axis_normal) * t) + ft_dotp(intersect, cylinder.axis_normal);
	if (m >= ((cylinder.height / 2) * -1) && m <= (cylinder.height / 2))
		return (m);
	else
		return (-1);
}

void	ft_intersection_c(t_cylinder cylinder, t_ray *ray, int i, int *index) // calculates the nearest intersection point
{
	t_vector	intersect;
	double		a;
	double		b;
	double		c;
	double		d;

	intersect = ft_substractv(ray->origin_p, cylinder.centre_p);
	a = ft_dotp(ray->direction, ray->direction) - pow(ft_dotp(ray->direction, cylinder.axis_normal), 2);
	b = 2 * (ft_dotp(intersect, ray->direction) - (ft_dotp(ray->direction, cylinder.axis_normal) * ft_dotp(intersect, cylinder.axis_normal)));
	c = ft_dotp(intersect, intersect) - pow(ft_dotp(intersect, cylinder.axis_normal), 2) - pow(cylinder.radius, 2);
	d = ft_midnight(a, b, c);
	if (d >= 0 && d <= ray->t && cal_m(d, cylinder, ray, intersect) != -1)
	{
		ray->t = d;
		*index = i;
	}
}

int	ft_dotplane(t_ray *r, t_plane *p)
{
	if (ft_dotp(r->direction, p->normal) == 0)
		return (0);
	return (1);
}

double	ft_intersect_plane(t_ray *r, t_plane *p)
{
	double		t;
	t_vector	sub;

	sub = ft_substractv(p->position_p, r->origin_p);
	t = ft_dotp(sub, p->normal);
	t = t / ft_dotp(r->direction, p->normal);
	if (t <= T_MIN || t >= T_MAX)
		return (0);
	return (t);
}

void	ft_intersection_p(t_plane plane, t_ray *ray, int i, int *index)
{
	double		d;

	d = 0;
	if (ft_dotplane(ray, &plane))
		d = ft_intersect_plane(ray, &plane);
	if (d >= T_MIN && d <= ray->t)
	{
		ray->t = d;
		*index = i;
	}
}
