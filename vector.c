/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:39:26 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/29 19:11:42 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "obstacle.h"

double	ft_amplitude(t_vector t)
{
	return (sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2)));
}

t_vector	ft_normalized(t_vector t)
{
	double		l;
	t_vector	n;

	l = ft_amplitude(t);
	n.x = t.x / l;
	n.y = t.y / l;
	n.z = t.z / l;
	return (n);
}

double	ft_dotp(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	ft_crossp(t_vector v1, t_vector v2)
{
	t_vector	cp;

	cp.x = v1.y * v2.z - v1.z * v2.y;
	cp.y = v1.z * v2.x - v1.x * v2.z;
	cp.z = v1.x * v2.y - v1.y * v2.x;
	return (cp);
}

t_vector	ft_multiply(t_vector t, double l)
{
	t_vector	vect;

	vect.x = t.x * l;
	vect.y = t.y * l;
	vect.z = t.z * l;
	return (vect);
}

t_vector	ft_divide(t_vector t, double l)
{
	t_vector	vect;

	vect.x = t.x / l;
	vect.y = t.y / l;
	vect.z = t.z / l;
	return (vect);
}

t_vector	ft_add(t_vector t, double l)
{
	t_vector	vect;

	vect.x = t.x + l;
	vect.y = t.y + l;
	vect.z = t.z + l;
	return (vect);
}

t_vector	ft_substract(t_vector t, double l)
{
	t_vector	vect;

	vect.x = t.x - l;
	vect.y = t.y - l;
	vect.z = t.z - l;
	return (vect);
}

t_vector	ft_addv(t_vector v1, t_vector v2)
{
	t_vector	t;

	t.x = v1.x + v2.x;
	t.y = v1.y + v2.y;
	t.z = v1.z + v2.z;
	return (t);
}

t_vector	ft_substractv(t_vector v1, t_vector v2)
{
	t_vector	t;

	t.x = v1.x - v2.x;
	t.y = v1.y - v2.y;
	t.z = v1.z - v2.z;
	return (t);
}

t_vector	ft_calculate_point(t_ray r, double t)
{
	t_vector point;

	point = ft_addv(r.origin_p, ft_multiply(r.direction, t));
	return (point);
}

// void		send_ray(t_struct *mrt, int i)
// {
// 	t_vector	direction;

// 	mrt->ray->viewport = mrt->vp_coord[i];
// 	mrt->ray->origin_p = mrt->zero;
// 	direction = ft_substractv(mrt->vp_coord[i], mrt->zero);
// 	mrt->ray->direction = ft_normalized(&direction);
// 	mrt->ray->t = T_MAX;
// }

void		send_ray(t_ray *ray, t_vector p1, t_vector p2)
{
	t_vector direction;
	
	ray->viewport = p2;
	ray->origin_p = p1;
	direction = ft_substractv(p2, p1);
	// ray->direction = ft_normalized(direction);
	ray->direction = direction;
	ray->t = T_MAX;
	ray->rgb.r = 0;
	ray->rgb.g = 0;
	ray->rgb.b = 0;
	ray->bounces = 0;
	ray->shadow = false;
}

void		send_shadowray(t_ray *sray, t_vector intersect_p, t_vector light_p)
{
	t_vector direction;
	
	sray->origin_p = intersect_p;
	direction = ft_substractv(light_p, intersect_p);
	// sray->direction = ft_normalized(direction);
	sray->direction = direction;
	sray->t = T_MAX;
	sray->rgb.r = 0;
	sray->rgb.g = 0;
	sray->rgb.b = 0;
	sray->shadow = true;
}

double	ft_midnight(double a, double b, double c)
{
	double t1;
	double t2;

	t1 = 0.0;
	t2 = 0.0;
	if (b * b >= 4 * a * c)
	{
		t1 = (double)((-b + sqrt(b * b - 4 * a * c))) / (double)(2 * a);
		t2 = (double)((-b - sqrt(b * b - 4 * a * c))) / (double)(2 * a);
		// printf("t1: %f\t", t1);
		// printf("t2: %f\n", t2);
	}
	else
		return (-1);
	if (t1 >= T_MIN && t2 >= T_MIN && t1 >= t2)
		return(t2);
	else if(t1 >= T_MIN && t2 >= T_MIN && t2 >= t1)
		return(t1);
	else if(t1 >= T_MIN && t2 < T_MIN)
		return(t1);
	else if(t2 >= T_MIN && t1 < T_MIN)
		return(t2);
	return (-1);
}


t_vector	vec_from_points(t_vector point1, t_vector point2)
{
	t_vector vector;

	vector.x = point2.x - point1.x;
	vector.y = point2.y - point1.y;
	vector.z = point2.z - point1.z;
	return (vector);
}

void	print_vector(const char *str, t_vector a)
{
	printf("=====\n");
	printf("%s", str);
	printf("\n=====\n");
	printf("   /%f\\\n", a.x);
	printf("V:| %f |\n", a.y);
	printf("   \\%f/\n", a.z);
	printf("Amp: %f\n", ft_amplitude(a));
}

void print_ray(const char *str, t_ray ray, double t)
{
	printf("=====\n");
	printf("%s", str);
	printf("\n=====\n");
	printf("\tOrigin\n");
	printf("   /%f\\\n", ray.origin_p.x);
	printf("R:| %f |\n", ray.origin_p.y);
	printf("   \\%f/\n", ray.origin_p.z);
	printf("AMP: %f\n", ft_amplitude(ray.origin_p));
	printf("\tDirection\n");
	printf("   /%f\\\n", ray.direction.x);
	printf("D:| %f |\n", ray.direction.y);
	printf("   \\%f/\n", ray.direction.z);
	printf("AMP: %f\n", ft_amplitude(ray.direction));
	printf("\tPoint\n");
	printf("   /%f\\\n", ft_calculate_point(ray, t).x);
	printf("P:| %f |\n", ft_calculate_point(ray, t).y);
	printf("   \\%f/\n", ft_calculate_point(ray, t).z);
	printf("t: %f\n", t);
}