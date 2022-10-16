/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:58:32 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/16 13:38:28 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;


	if (*little == '\0' || big == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i <= len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while ((big[i + j] == little[j]) && little[j] && big[i + j])
				j++;
			if (little[j] == 0 && (i + j) <= len)
			{
				while (i--)
					big++;
				return ((char *)big);
			}
		}
		i++;
	}
	return (T_NULL);
}
