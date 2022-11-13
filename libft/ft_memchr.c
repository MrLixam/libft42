/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:36:15 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/12 18:30:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmps;

	if (s == NULL)
		return (NULL);
	tmps = (unsigned char *)s;
	while (n--)
	{
		if (*tmps == (unsigned char)c)
			return ((void *)tmps);
		tmps++;
	}
	return (NULL);
}
