/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:20:07 by arasal            #+#    #+#             */
/*   Updated: 2023/05/31 23:20:27 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

double		distance_vp_camera(void);
t_viewport	*malloc_vp_coord(void);
t_viewport	*viewport_coordinates(t_alloc *allocations);
t_vector	*viewport_coord_into_points(t_viewport vp, \
t_alloc *alloc, t_camera camera);

t_color		paint_color(double r, double g, double b);
void		paint_obj_color(t_ray *ray, t_obj obj);
void		ft_putlight(t_light L, t_struct *mrt);
void		create_ambient_light(t_struct *mrt);
void		ambient_light(t_ray *ray, t_struct *mrt);
int			diffuse_lighting(t_ray *ray, t_ray *lray, \
int obj_index, t_struct *mrt);
t_vector	calc_normalvector(t_vector pos, t_obj *object, int obj_index);

#endif