/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:17:36 by hublanc           #+#    #+#             */
/*   Updated: 2016/11/08 18:12:15 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*zone;

	zone = 0;
	if (!(zone = (void*)malloc(size)))
		return (0);
	while (size)
	{
		zone[size] = 0;
		size--;
	}
	zone[size] = 0;
	return (zone);
}
