/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:39:26 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/31 23:46:51 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/vector.h"
#include "header/obstacle.h"

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
