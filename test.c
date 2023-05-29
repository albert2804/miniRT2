/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:34:14 by arasal            #+#    #+#             */
/*   Updated: 2023/05/23 17:57:38 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			return (0);
	}
	return (0);
}

void	print_s(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		ft_putendl_fd(str[i], STDOUT_FILENO);
		i++;
	}
}

void	*free_s(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!str[0])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (str[i] != NULL)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}
