/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:22:25 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/23 16:16:26 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "mem.h"
#include "defines.h"

/*
calculates the distance in z-direction 
from the viewport z-coordinates to the camera z-coodrinates
*/
double	distance_vp_camera(void)
{
	double distance;

	distance = V_W / (2 * tan(FOV_R / 2));
	return (distance);
}

t_viewport	*viewport_coordinates(t_alloc *allocations)
{
	int			i;
	int			j;
	t_viewport	*vp;
	
	j = 0;
	i = 0;
	vp = ft_calloc(sizeof(t_viewport), 1);
	vp->x = advanced_calloc(sizeof(double), WIDTH, (void *)&allocations->vp_x);
	vp->y = advanced_calloc(sizeof(double), HEIGHT, (void *)&allocations->vp_y);
	if(!vp->x || !vp->y)
		ft_cleanup(allocations);
	vp->distance = distance_vp_camera();
	while (i < WIDTH)
	{
		vp->x[i] = (i) * V_W / WIDTH - V_W / 2;
		i++;
	}
	while (j < HEIGHT)
	{
		vp->y[j] = V_H / 2 -(j) * V_H / HEIGHT ;
		j++;
	}
	return (vp);
}

t_vector	*viewport_coord_into_points(t_viewport vp, t_alloc *alloc)
{
	int			w;
	int			h;
	int			i;
	t_vector	*points;

	points = advanced_calloc(sizeof(t_vector), WIDTH * HEIGHT, (void *)&alloc->points);
	w = 0;
	h = 0;
	i = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			points[i].x = vp.x[w];
			points[i].y = vp.y[h];
			points[i].z = vp.distance;
			i++;
			w++;
		}
		h++;
	}
	return (points);
}

//makes a black background color
t_color		background_color(void)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	
	return (color);
}

// updates the color for that ray at intersection point
//for testing the intersection points are green
void		calculate_color(t_ray *ray, t_obj obj)
{
	ray->rgb = *obj.color;
}