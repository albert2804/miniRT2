#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include "defines.h"
# include "structs.h"
# include "minirt.h"

double		ft_amplitude(t_vector *t);
t_vector	ft_add(t_vector *t, double l);
t_vector	ft_substract(t_vector *t, double l);
t_vector	ft_multiply(t_vector *t, double l);
t_vector	ft_divide(t_vector *t, double l);
t_vector	ft_addv(t_vector v1, t_vector v2);
t_vector	ft_substractv(t_vector v1, t_vector v2);
double		ft_dotp(t_vector *v1, t_vector *v2);
t_vector	ft_crossp(t_vector *v1, t_vector *v2);
t_vector	ft_calculate_point(t_ray *r, double t);
t_vector	ft_normalized(t_vector *t);

t_vector	vec_from_points(t_vector point1, t_vector point2);
void		send_ray(t_struct *mrt, int i);
void		print_vector(const char *str, t_vector a);
void		print_ray(const char *str, t_ray ray, int t);
double		ft_midnight(double a, double b, double c);
double		ft_midnight2(double a, double b, double c);


//TODO
// void		calc_ray(t_ray *ray, t_vector intersect);

# endif