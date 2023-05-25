/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:25:09 by aestraic          #+#    #+#             */
/*   Updated: 2022/12/13 14:16:32 by aestraic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen(char const *c)
{
	int	count;

	count = 0;
	while (c[count] != '\0')
	{
		count++;
	}
	return (count);
}
