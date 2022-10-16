/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:14:48 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/16 14:30:39 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static unsigned int	ft_tr_st(char *str, char *set)
{
	unsigned int	rv;
	unsigned int	i;

	i = 0;
	rv = 0;
	while (str[i])
	{
		if (!ft_inset(str[i++], set))
			break ;
		else
			rv++;
	}
	return (rv);
}

static unsigned int	ft_tr_nd(char *str, char *set)
{
	unsigned int	rv;
	int				i;

	i = ft_strlen((const char *)str) - 1;
	rv = i;
	while (i > 0)
	{
		if (!ft_inset(str[i--], set))
			break ;
		else
			rv--;
	}
	return (rv);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*rv;

	start = ft_tr_st((char *)s1, (char *)set);
	end = ft_tr_nd((char *)s1, (char *)set);
	if (start > end)
		return (ft_strdup(""));
	rv = ft_substr(s1, start, end - start + 1);
	if (!rv)
		return (T_NULL);
	else
		return (rv);
}
