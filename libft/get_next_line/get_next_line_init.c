/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 02:34:31 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/30 20:05:15 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*config_file(void)
{
	int		fd;
	char	*file;
	char	buffer[11];
	int		readb;

	file = NULL;
	buffer[10] = '\0';
	fd = open("/proc/self/limits", O_RDONLY);
	while (1)
	{
		readb = read(fd, buffer, 10);
		if (readb == -1 || readb == 0)
			break ;
		ft_strjoin_gnl(file, buffer);
	}
	if (readb == -1)
		if (file)
			ft_free(file);
	return (file);
}

static int	init_max_fd(void)
{
	char	*file;
	char	*line;

	file = config_file();
	if (file == NULL)
		return (1024);
	line = ft_strnstr(file, "Max open files", ft_strlen(file));
	if (!line)
		return (1024);
	line += 15;
	return (ft_atoi(line));
}

int	gnl_fd_max(void)
{
	static int	max_fd = -1;

	if (max_fd < 0)
		max_fd = init_max_fd();
	return (max_fd);
}
