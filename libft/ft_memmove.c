/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:20:24 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/16 12:49:52 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int i;

	if (src != dest)
	{
		if (src > dest)
		{
			i = 0;
			while (i < n)
			{
				((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
				i++;
			}
		}
		else
		{
			while (n--)
				((unsigned char *)dest)[n] = ((unsigned const char *)src)[n];
		}
	}
	return (dest);
}
