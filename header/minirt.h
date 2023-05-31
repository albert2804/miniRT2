/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:20:56 by arasal            #+#    #+#             */
/*   Updated: 2023/06/01 00:08:13 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# include "libft.h"
# include "get_next_line_bonus.h"

# include "defines.h"
# include "structs.h"
# include "vector.h"
# include "camera.h"
# include "obstacle.h"
# include "mem.h"

# include <fcntl.h>

# include "../MLX42/include/MLX42/MLX42.h"

void	*advanced_calloc(size_t size, size_t times, void **tobe_malloced);
void	ft_cleanup(t_alloc *allocations);
void	place_pixel(t_ray *ray, mlx_image_t *img, t_camera camera);
bool	ft_putpixel(uint32_t x, uint32_t y, int color, mlx_image_t *img);
int		get_rgba(int r, int g, int b, int a);

void	print_s(char **str);
void	*free_s(char **str);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_input(t_struct *rt, char **argv);
void	create_light(t_struct *mrt, char **split);
void	create_amb(t_struct *mrt, char **split);
void	create_object(char **split, t_struct *mrt, int index);
double	ft_atof(char *str);
void	create_obj_plane(t_struct *mrt, char **split, int index);
void	create_obj_sphere(t_struct *mrt, char **split, int index);
void	create_obj_cylinder(t_struct *mrt, char **split, int index);
void	create_camera(t_struct *mrt, char **split);
void	ft_input(t_struct *mrt, char **argv);
void	init_ray(t_ray *ray, int type);
void	key_hook(void *param);
void	key_hook2(void *param);
void	draw_image(t_struct *mrt);
#endif