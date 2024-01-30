/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:34:31 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/30 07:51:09 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
	gnl_storage() is used to keep track of the storage used by get_next_line()
	and be able to free it in gnl_release(), you can use it, but beware,
	modifying the stored values may result in incorrect results in future
	get_next_line() calls

	in: void

	out: char**, an array of 1024 strings, one for each valid fd
*/

char	**gnl_storage(void)
{
	static char	*file[1024] = {NULL};

	return (file);
}

/*
	gnl_release_all() frees up all current memory allocated to keep track of
	get_next_line() calls, you will probably need to close current open file
	descriptors, or at least duplicate them as read calls will continue from
	where they left off before freeing up memory
	this function is intended for memory cleanup after full execution.
	
	input: (void)
	
	output: (void)
*/

void	gnl_release(void)
{
	char	**storage;
	int		i;

	i = 0;
	storage = gnl_storage();
	while (i < 1024)
	{
		if (storage[i])
		{
			free(storage[i]);
			storage[i] = NULL;
		}
		i++;
	}
}

/*
	gnl_release_fd() is used to free up memory used to keep track of a given
	file descriptor, and resetting it for further future use in the code
	
	valid file descriptors are 0 to 1023 currently because thats the limit in
	my schools computers, might update later to be dynamic

	input : (void)

	output : (void)
*/

void	gnl_release_fd(int fd)
{
	char	**storage;

	if (fd < 0 || fd > 1023)
		return ;
	storage = gnl_storage();
	if (storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
	}
}

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