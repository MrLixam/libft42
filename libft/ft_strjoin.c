/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:01:10 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/16 14:31:16 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*rv;
	unsigned int	i;
	unsigned int	j;

	rv = malloc(1 + ft_strlen((const char *)s1) + ft_strlen((const char *)s2));
	if (!rv)
		return (T_NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		rv[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		rv[j] = s2[i];
		i++;
		j++;
	}
	rv[j] = '\0';
	return (rv);
}
