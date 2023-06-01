/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:36:03 by aestraic          #+#    #+#             */
/*   Updated: 2023/06/01 13:37:55 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"

static void	ft_init_obj(t_struct *mrt, char **argv)
{
	int		fd;
	int		number;
	char	*str;

	number = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	str = get_next_line(fd);
	while (str && ++number)
	{
		free(str);
		str = get_next_line(fd);
	}
	mrt->obj = ft_calloc(sizeof(t_obj), number);
	mrt->bg.color.r = 0;
	mrt->bg.color.g = 0;
	mrt->bg.color.b = 0;
	mrt->bg.exist = true;
	mrt->obj[0].background = &mrt->bg;
	mrt->obj[0].color = &mrt->bg.color;
	mrt->obj[0].exist = &mrt->bg.exist;
}

static void	ft_init(t_struct *mrt, char **argv)
{
	ft_init_obj(mrt, argv);
	ft_input(mrt, argv);
	mrt->allocations = ft_calloc(sizeof(t_alloc), 1);
	mrt->vp = viewport_coordinates(mrt->allocations);
	mrt->vp_coord = viewport_coord_into_points(*mrt->vp, \
	mrt->allocations, *mrt->camera);
	mrt->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	mrt->img = mlx_new_image(mrt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mrt->mlx, mrt->img, 0, 0);
}

void	ray_tracer(t_struct *mrt, int obj_index, int *in_shadow)
{
	if (obj_index > 0)
	{
		*in_shadow = hardshadows(&mrt->sray, &mrt->ray, obj_index, mrt);
		ambient_light(&mrt->ray, mrt);
		if (*in_shadow == 0)
		{
			diffuse_lighting(&mrt->ray, &mrt->lray, obj_index, mrt);
			send_ray(&mrt->lray, mrt->light.light_p, \
			ft_calculate_point(mrt->ray, mrt->ray.t));
		}
	}
	else
		paint_obj_color(&mrt->ray, mrt->obj[0]);
}

void	draw_image(t_struct *mrt)
{
	int			i;
	int			obj_index;
	int			in_shadow;

	i = 0;
	obj_index = 0;
	in_shadow = 0;
	while (i < (WIDTH * HEIGHT))
	{
		send_ray(&mrt->ray, mrt->camera->view_p, mrt->vp_coord[i]);
		while (mrt->ray.bounces < BOUNCES)
		{
			obj_index = ft_intersection(&mrt->ray, mrt);
			ray_tracer(mrt, obj_index, &in_shadow);
			mrt->ray.bounces++;
		}
		place_pixel(&mrt->ray, mrt->img, *mrt->camera);
		ft_putlight(mrt->light, mrt);
		mrt->ray.bounces = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_struct	mrt;

	if (argc != 2)
		return (1);
	ft_init(&mrt, argv);
	init_ray(&mrt.ray, 0);
	init_ray(&mrt.sray, 1);
	init_ray(&mrt.lray, 0);
	draw_image(&mrt);
	mlx_loop_hook(mrt.mlx, &key_hook, (void *)&mrt);
	mlx_loop_hook(mrt.mlx, &key_hook2, (void *)&mrt);
	mlx_loop(mrt.mlx);
	mlx_terminate(mrt.mlx);
	ft_cleanup(mrt.allocations);
	free(mrt.vp);
	system("leaks miniRT");
	return (0);
}
