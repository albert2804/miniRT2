#ifndef OBSTACLE_H
# define OBSTACLE_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

t_vector	ft_intersection_s(t_sphere sphere, t_ray *ray); // calculates the nearest intersection point
//TO-DO
// t_vector	ft_intersection(t_obj obj, t_ray ray); // calculates the nearest intersection point
// {
// 	ft_intersection_s;
// 	ft_intersection_c;
// 	ft_intersection_p;
// }

// t_vector	ft_intersection_c(t_cylinder cyl, t_ray ray); // calculates the nearest intersection point
// t_vector	ft_intersection_p(t_plane plane, t_ray ray); // calculates the nearest intersection point

# endif