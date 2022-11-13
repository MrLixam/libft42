/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:55:09 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/12 18:47:19 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{	
		if (s1[i] != s2[i])
		{
			if (s1[i] < 0)
				return (s2[i] - s1[i]);
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
