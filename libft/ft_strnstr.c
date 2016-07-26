/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:52:22 by jledieu           #+#    #+#             */
/*   Updated: 2015/11/27 16:37:45 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		i2;
	int		lens2;
	char	*strs1;

	i = 0;
	i2 = 0;
	lens2 = ft_strlen(s2);
	strs1 = (char *)s1;
	while (strs1[i] != '\0' && i < n)
	{
		i2 = 0;
		while ((strs1[i] == s2[i2] && i < n) && i2 < lens2)
		{
			i++;
			i2++;
		}
		if (i2 == lens2)
			return (&strs1[i - i2]);
		i++;
		i = i - i2;
	}
	return (NULL);
}
