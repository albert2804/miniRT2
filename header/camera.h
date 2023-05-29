#ifndef CAMERA_H
# define CAMERA_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

double		distance_vp_camera(void);
t_viewport	*malloc_vp_coord(void); 
t_viewport	*viewport_coordinates(t_alloc *allocations);
t_vector	*viewport_coord_into_points(t_viewport vp, t_alloc *alloc);
void		calculate_color(t_ray *ray, t_obj obj);


#endif