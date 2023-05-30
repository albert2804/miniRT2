/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:00:32 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/30 14:45:04 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"

void	ambient_light(t_ray *ray, t_struct *mrt)
{
	ray->rgb.r += (mrt->ambient.amb_ratio * mrt->ambient.color.r) / 2;
	ray->rgb.g += (mrt->ambient.amb_ratio * mrt->ambient.color.g) / 2;
	ray->rgb.b += (mrt->ambient.amb_ratio * mrt->ambient.color.b) / 2;
}

// void	update_color(t_ray *ray, t_ray lray)
// {
	
// }