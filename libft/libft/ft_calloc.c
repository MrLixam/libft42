/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:19:32 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/30 07:53:09 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rv;

	if (nmemb > 0xFFFFFFFFUL || size > 0xFFFFFFFFUL)
		return (NULL);
	if (nmemb * size > 0xFFFFFFFFUL)
		return (NULL);
	rv = malloc(nmemb * size);
	if (!rv)
		return (NULL);
	else
	{
		ft_bzero(rv, nmemb * size);
		return (rv);
	}
}
