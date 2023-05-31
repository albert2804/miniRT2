/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midnight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:47:56 by arasal            #+#    #+#             */
/*   Updated: 2023/05/31 23:48:13 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/vector.h"
#include "header/obstacle.h"

t_vector	ft_calculate_point(t_ray r, double t)
{
	t_vector	point;

	point = ft_addv(r.origin_p, ft_multiply(r.direction, t));
	return (point);
}

double	ft_midnight(double a, double b, double c)
{
	double	t1;
	double	t2;

	t1 = 0.0;
	t2 = 0.0;
	if (b * b >= 4 * a * c)
	{
		t1 = (double)((-b + sqrt(b * b - 4 * a * c))) / (double)(2 * a);
		t2 = (double)((-b - sqrt(b * b - 4 * a * c))) / (double)(2 * a);
	}
	else
		return (-1);
	if (t1 >= T_MIN && t2 >= T_MIN && t1 >= t2)
		return (t2);
	else if (t1 >= T_MIN && t2 >= T_MIN && t2 >= t1)
		return (t1);
	else if (t1 >= T_MIN && t2 < T_MIN)
		return (t1);
	else if (t2 >= T_MIN && t1 < T_MIN)
		return (t2);
	return (-1);
}

double	ft_midnight2(double a, double b, double c, t_cylinder *cylinder)
{
	double	t1;
	double	t2;

	t1 = 0;
	t2 = 0;
	if (b * b >= 4 * a * c)
	{
		t1 = (double)((-b + sqrt(b * b - 4 * a * c))) / (double)(2 * a);
		t2 = (double)((-b - sqrt(b * b - 4 * a * c))) / (double)(2 * a);
	}
	else
		return (-1);
	cylinder->t1 = t1;
	cylinder->t2 = t2;
	if (t1 >= T_MIN && t2 >= T_MIN && t1 >= t2)
		return (t2);
	else if (t1 >= T_MIN && t2 >= T_MIN && t2 > t1)
		return (t1);
	else if (t1 >= T_MIN && t2 < T_MIN)
		return (t1);
	else if (t2 >= T_MIN && t1 < T_MIN)
		return (t2);
	return (-1);
}
