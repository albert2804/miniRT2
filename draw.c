/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:10:46 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/23 17:06:46 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// void	draw_image(mlx_image_t *g_img, t_trans *transform)
// {
// 	int		x;
// 	int		y;
// 	size_t	node;
// 	int		color;

// 	node = 0;
// 	x = 0;
// 	y = 0;
// 	(void)g_img;
// 	while (node < transform->map_data->total_count)
// 	{
// 		color = get_rgba(transform->map_data->rgb_values[node][0], \
// 						transform->map_data->rgb_values[node][1], \
// 						transform->map_data->rgb_values[node][2], 255);
// 		x = transform->b_x[node];
// 		y = transform->b_y[node];
// 		ft_putpixel(x, y, color, transform);
// 		node ++;
// 	}
// 	draw_grid(transform, g_img);
// }

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	place_pixel(t_ray *ray, mlx_image_t *img)
{
	int color;
	uint32_t x;
	uint32_t y;
	
	color = get_rgba(ray->rgb.r * R, ray->rgb.g * G, ray->rgb.b * B, 255);
	x = (float)((ray->viewport.x * (float)(WIDTH / V_W)) + (float)(WIDTH / 2));
	y = (float)((-ray->viewport.y * (float)(HEIGHT / V_H)) + (float)(HEIGHT / 2));
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
