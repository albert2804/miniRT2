#ifndef MEM_H
# define MEM_H

# include <libft.h>
# include "defines.h"
# include "structs.h"

void	*advanced_calloc(size_t size, size_t times, void **tobe_malloced);
void	ft_cleanup(t_alloc *allocations);
#endif