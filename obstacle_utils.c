/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:34:45 by arasal            #+#    #+#             */
/*   Updated: 2023/05/31 23:43:08 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/vector.h"
#include "header/obstacle.h"

double	cal_m(double *t, t_cylinder cylinder,
t_ray *ray, t_vector intersect)
{
	double	m[2];
	double	n;
	t_plane	p;

	m[0] = 0;
	m[1] = 0;
	n = 0;
	m[0] = (ft_dotp(ray->direction, cylinder.axis_normal) * \
	(cylinder.t1)) + ft_dotp(intersect, cylinder.axis_normal);
	m[1] = (ft_dotp(ray->direction, cylinder.axis_normal) * \
	(cylinder.t2)) + ft_dotp(intersect, cylinder.axis_normal);
	if ((m[0] >= ((cylinder.height / 2) * -1) && m[0] <= (cylinder.height / 2)) \
	|| (m[1] >= ((cylinder.height / 2) * -1) && m[1] <= (cylinder.height / 2)))
		return (m[1]);
	else
	{
		p.normal = cylinder.axis_normal;
		p.position_p = ft_addv(cylinder.centre_p, \
		ft_multiply(p.normal, cylinder.height / 2));
		if (ft_dotplane(ray, &p))
			n = ft_intersect_plane(ray, &p);
		if (n >= T_MIN && n <= T_MAX && n <= ray->t && n < *t)
			*t = n;
		return (-1);
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
