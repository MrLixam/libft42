/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:31:31 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/11 15:06:41 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rv;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	rv = malloc(ft_strlen((const char *)s) + 1);
	if (!rv)
		return (rv);
	i = 0;
	while (s[i])
	{
		rv[i] = f(i, s[i]);
		i++;
	}
	rv[i] = '\0';
	return (rv);
}
