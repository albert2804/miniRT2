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
void	place_pixel(t_ray *ray, mlx_image_t *img);
bool	ft_putpixel(uint32_t x, uint32_t y, int color, mlx_image_t *img);
int		get_rgba(int r, int g, int b, int a);

void	print_s(char **str);
void	*free_s(char **str);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_input(t_struct *rt, char **argv);
void	init_ray(t_ray *ray, int type);
#endif