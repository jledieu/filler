/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:39:17 by jledieu           #+#    #+#             */
/*   Updated: 2015/11/29 22:51:57 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*is1;
	unsigned char	*is2;

	i = 0;
	is1 = (unsigned char *)s1;
	is2 = (unsigned char *)s2;
	while (n--)
	{
		if (is1[i] != is2[i])
			return (is1[i] - is2[i]);
		i++;
	}
	return (0);
}
