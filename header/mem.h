/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:20:48 by arasal            #+#    #+#             */
/*   Updated: 2023/05/31 23:20:51 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

void	*advanced_calloc(size_t size, size_t times, void **tobe_malloced);
void	ft_cleanup(t_alloc *allocations);
#endif