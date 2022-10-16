/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:01:06 by lvincent          #+#    #+#             */
/*   Updated: 2022/10/16 14:31:29 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_str(const char *s, char c)
{
	unsigned int	nb_str;

	nb_str = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			nb_str++;
			continue ;
		}
		s++;
	}
	return (nb_str);
}

static char	*ft_get_str(char const *s, char c)
{
	char			*tmp;
	unsigned int	len;

	while (*s == c)
		s++;
	if (*s != c && *s != '\0')
	{
		len = 0;
		while (s[len] != c && s[len] != '\0')
			len++;
		tmp = ft_substr(s, 0, len);
		return (tmp);
	}
	tmp = ft_strdup("");
	return (tmp);
}

static void	ft_free_arr(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != T_NULL)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

static int	ft_check_val(char *str, char **arr)
{
	unsigned int	j;

	j = ft_strlen((const char *)str);
	if (j == 0)
		ft_free_arr(arr);
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	char			*cpy;
	unsigned int	u_ints[3];

	u_ints[2] = ft_count_str(s, c);
	strs = (char **)ft_calloc(u_ints[2] + 1, sizeof(char *));
	if (!strs)
		return (T_NULL);
	strs[u_ints[2]] = T_NULL;
	u_ints[0] = 0;
	while (u_ints[2])
	{
		cpy = ft_get_str(s, c);
		while (*s == c)
			s++;
		u_ints[1] = ft_check_val(cpy, strs);
		if (!u_ints[1])
			return (T_NULL);
		strs[u_ints[0]++] = ft_strdup(cpy);
		free(cpy);
		while (u_ints[1]--)
			s++;
		u_ints[2]--;
	}
	return (strs);
}

#include <stdio.h>

int main()
{
	char *s = "      split       this for   me  !       ";
	char **arr = ft_split(s, ' ');

	int i = 0;
	while (arr[i] != NULL)
		printf("%s\n", arr[i++]);
	return (0);
}