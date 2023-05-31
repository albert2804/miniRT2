/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:14:59 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/31 23:42:54 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minirt.h"
/**
 * cleanup function frees all allocations which are connecetd to malloc_struct
*/
void	ft_cleanup(t_alloc *allocations)
{
	if (allocations->vp_x)
		free(allocations->vp_x);
	if (allocations->vp_y)
		free(allocations->vp_y);
	if (allocations->points)
		free(allocations->points);
	if (allocations)
		free(allocations);
}

/**
 * takes a variable size and times (like in calloc),
 * and sets the alloced array to the adress of the malloc_struct(
 * given as parameter tobe_malloced).
*/
void	*advanced_calloc(size_t size, size_t times, void **tobe_malloced)
{
	void	*array;

	array = ft_calloc(size, times);
	if (!array)
		return (NULL);
	(void) tobe_malloced;
	*tobe_malloced = array;
	return (array);
}
