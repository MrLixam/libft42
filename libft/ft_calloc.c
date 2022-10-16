/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:19:32 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/16 14:33:10 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long nmemb, unsigned long size)
{
	void	*rv;

	if (nmemb > 0xFFFFFFFFUL || size > 0xFFFFFFFFUL)
		return (T_NULL);
	if (nmemb * size > 0xFFFFFFFFUL)
		return (T_NULL);
	rv = malloc(nmemb * size);
	if (!rv)
		return (T_NULL);
	else
	{
		ft_bzero(rv, nmemb * size);
		return (rv);
	}
}
