/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:10:46 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/31 20:36:53 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	place_pixel(t_ray *ray, mlx_image_t *img)
{
	int			color;
	uint32_t	x;
	uint32_t	y;

	color = get_rgba(ray->rgb.r * R, ray->rgb.g * G, ray->rgb.b * B, 255);
	x = (float)(((ray->viewport.x)* ((float)WIDTH / (float)V_W)) + \
	((float)WIDTH / 2));
	y = (float)(((-ray->viewport.y) * ((float)HEIGHT / (float)V_H)) + \
	((float)HEIGHT / 2));
	ft_putpixel(x, y, color, img);
}

bool	ft_putpixel(uint32_t x, uint32_t y, int color, mlx_image_t *img)
{	
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(img, x, y, color);
	else
		return (false);
	return (true);
}

void	ft_putlight(t_light L, t_struct *mrt)
{
	int			color;
	uint32_t	x;
	uint32_t	y;

	x = (float)((L.light_p.x * ((float)WIDTH / (float)V_W)) + \
	((float)WIDTH / 2));
	y = (float)((L.light_p.y * ((float)HEIGHT / (float)V_H)) + \
	((float)HEIGHT / 2));
	color = get_rgba(L.color.r * R, L.color.g * G, L.color.b * B, 255);
	ft_putpixel(x, y, color, mrt->img);
}
