/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:36:15 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/12 22:52:27 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*tmps;

	if (c > 255)
		c -= 256;
	tmps = (unsigned char *)s;
	while (n--)
	{
		if (*tmps == (unsigned char)c)
			return ((void *)tmps);
		tmps++;
	}
	return (T_NULL);
}
