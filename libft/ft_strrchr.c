/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:21:55 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/12 20:19:06 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	while (c > 255)
		c -= 256;
	size = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + size);
	while (size--)
	{
		if (s[size] == (unsigned char)c)
		{
			while (size--)
				s++;
			return ((char *)s);
		}
	}
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	return (T_NULL);
}
