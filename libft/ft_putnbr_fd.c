/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:15:28 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/12 18:36:03 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	big;

	if (n == NULL)
		return ;
	big = n;
	if (big < 0)
	{
		ft_putchar_fd('-', fd);
		big = big * -1;
	}
	if (big <= 9)
		ft_putchar_fd('0' + big, fd);
	else
	{
		ft_putnbr_fd(big / 10, fd);
		ft_putchar_fd('0' + big % 10, fd);
	}
}
