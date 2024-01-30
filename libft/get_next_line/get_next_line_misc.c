/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_misc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:03:14 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/30 20:02:40 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	in the name, counts the number of lines in a given file pointed by the file
	descriptor fd, because of my school, I can't use fcntl() to check if fd is
	a valid file descriptor, will add when possible

	input : fd, a valid file descriptor
	
	output: the number of lines in the file, as a size_t
*/

size_t	gnl_count_lines(int fd)
{
	size_t	i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			i++;
			free(line);
			continue ;
		}
		if (!line)
			break ;
	}
	gnl_release_fd(fd);
	return (i);
}
