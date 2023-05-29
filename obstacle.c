/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:17:27 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/28 19:25:02 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "obstacle.h"

//returns the index of the objectlist
//if there is no intersection at all, the return value will be 0, which must be background
int		ft_intersection(t_obj *obj, t_ray *ray) // calculates the nearest intersection point
{
	int			i;
	int			obj_index;
	
	obj_index = 0;
	i = 0;
	while(obj[i].exist)
	{
		if (obj[i].sphere)
		{
			ft_intersection_s(*obj[i].sphere, ray, i, &obj_index);
			// if (ray->shadow == true && obj_index > 0)
			// 	break ;
		}
		if (obj[i].plane)
		{
			ft_intersection_p(*obj[i].plane, ray, i, &obj_index);
			// if (ray->shadow == true && obj_index > 0)
			// 	break ;
		}
		//obj_index = ft_intersection_c;
		i++;
	}
	// printf("RAY->T: %f\n", ray->t);
	// if (ray->t < T_MAX && ray->shadow == true)
	// {
	// 	print_vector("SHADOW ORIGIN:", ray->origin);
	// 	print_vector("SHADOW DIR:", ray->direction);
	// 	printf("SHADOW T: %f\n", ray->t);
	// }
	// else if (ray->t < T_MAX && ray->shadow == false)
	// {	
	// 	print_vector("LIGHT ORIGIN:", ray->origin);
	// 	print_vector("LIGHT DIR:", ray->direction);
	// 	printf("LIGHT T: %f\n", ray->t);
	// }
	return (obj_index);
}

//SPHERE
void	ft_intersection_s(t_sphere sphere, t_ray *ray, int i, int *index) // calculates the nearest intersection point
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
	// intersect = ft_normalized(intersect);
	a = ft_dotp(&ray->direction, &ray->direction);
	b = 2 * ft_dotp(&intersect, &ray->direction);
	c = ft_dotp(&intersect, &intersect) - sphere.radius * sphere.radius;
	d = ft_midnight(a, b ,c);
	if (d >= T_MIN && d <= ray->t)
	{
		ray->t = d;
		// printf("t_after: %f\n", ray->t);
		*index = i;
	}
	// printf("\n");
}

//PLANE
int	ft_dotplane(t_ray *r, t_plane *p)
{
	if (ft_dotp(&r->direction, &p->normal) == 0)
		return (0);
	return (1);
}

double	ft_intersect_plane(t_ray *r, t_plane *p)
{
	double		t;
	t_vector	sub;

	sub = ft_substractv(p->position, r->origin);
	t = ft_dotp(&sub, &p->normal);
	t = t / ft_dotp(&r->direction, &p->normal);
	if (t <= T_MIN || t >= T_MAX)
		return (0);
	return (t);
}

void	ft_intersection_p(t_plane plane, t_ray *ray, int i, int *index)
{
	double		d;

	printf("PLANE");
	d = 0;
	if (ft_dotplane(ray, &plane))
		d = ft_intersect_plane(ray, &plane);
	if (d >= T_MIN && d < ray->t)
	{
		ray->t = d;
		*index = i;
	}
}

//CYLINDER
