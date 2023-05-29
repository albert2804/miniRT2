#ifndef OBSTACLE_H
# define OBSTACLE_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

int			ft_intersection(t_ray *ray, t_struct *mrt);
void		ft_intersection_s(t_sphere sphere, t_ray *ray, int i, int *index); // calculates the nearest intersection point
void		ft_intersection_p(t_plane plane, t_ray *ray, int i, int *index);
void		ft_intersection_c(t_cylinder cylinder, t_ray *ray, int i, int *index);

double		ft_intersect_plane(t_ray *r, t_plane *p);
int			ft_dotplane(t_ray *r, t_plane *p);
t_vector	shadowray_start(t_obj *object, t_ray *ray, int obj_index);

// TO-DO
// t_vector	ft_intersection_c(t_cylinder cyl, t_ray ray); // calculates the nearest intersection point
// t_vector	ft_intersection_p(t_plane plane, t_ray ray); // calculates the nearest intersection point

# endif