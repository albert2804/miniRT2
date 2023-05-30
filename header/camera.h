#ifndef CAMERA_H
# define CAMERA_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

double		distance_vp_camera(void);
t_viewport	*malloc_vp_coord(void); 
t_viewport	*viewport_coordinates(t_alloc *allocations);
t_vector	*viewport_coord_into_points(t_viewport vp, t_alloc *alloc);

t_color		paint_color(double r, double g, double b);
void		paint_obj_color(t_ray *ray, t_obj obj);
void		ft_putlight(t_light L, t_struct *mrt);
void		create_ambient_light(t_struct *mrt);
void		ambient_light(t_ray *ray, t_struct *mrt);
#endif