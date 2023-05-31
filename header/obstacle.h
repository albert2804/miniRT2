/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:21:01 by arasal            #+#    #+#             */
/*   Updated: 2023/05/31 23:38:15 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_H
# define OBSTACLE_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

int			ft_intersection(t_ray *ray, t_struct *mrt);
void		ft_intersection_s(t_sphere sphere, t_ray *ray, int i, int *index);
void		ft_intersection_p(t_plane plane, t_ray *ray, int i, int *index);
void		ft_intersection_c(t_cylinder cylinder, \
t_ray *ray, int i, int *index);
double		cal_m(double *t, t_cylinder cylinder, \
t_ray *ray, t_vector intersect);
double		ft_intersect_plane(t_ray *r, t_plane *p);
int			ft_dotplane(t_ray *r, t_plane *p);
t_vector	shadowray_start(t_obj *object, t_ray *ray, int obj_index);

#endif