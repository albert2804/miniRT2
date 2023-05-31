/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:11:40 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/31 23:41:32 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

void	key_hook(void *param)
{
	t_struct	*mrt;

	mrt = (t_struct *)param;
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mrt->mlx);
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_UP))
		mrt->camera->view_p.y += 0.1;
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_DOWN))
		mrt->camera->view_p.y -= 0.1;
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_LEFT))
		mrt->camera->view_p.x -= 0.1;
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_RIGHT))
		mrt->camera->view_p.x += 0.1;
	else
		return ;
	draw_image(mrt);
}

void	key_hook2(void *param)
{
	t_struct	*mrt;

	mrt = (t_struct *)param;
	if (mlx_is_key_down(mrt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mrt->mlx);
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_W))
		mrt->move_y += 0.1;
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_S))
		mrt->move_y -= 0.1;
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_A))
		mrt->move_x -= 0.1;
	else if (mlx_is_key_down(mrt->mlx, MLX_KEY_D))
		mrt->move_x += 0.1;
	else
		return ;
	draw_image(mrt);
}
