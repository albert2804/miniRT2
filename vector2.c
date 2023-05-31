/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:45:56 by arasal            #+#    #+#             */
/*   Updated: 2023/06/01 00:09:29 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/vector.h"
#include "header/obstacle.h"

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
