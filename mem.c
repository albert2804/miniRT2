/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:14:59 by aestraic          #+#    #+#             */
/*   Updated: 2023/05/19 18:22:19 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
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

// void	init_allocs(char **argv, t_table *table)
// {
// 	table->thread_array = advanced_calloc (sizeof(pthread_t), ft_atoi(argv[1]) \
// 	+ 1, (void *) &table->allocations.thread_array);
// 	if (!table->thread_array)
// 		ft_cleanup(table);
// }
