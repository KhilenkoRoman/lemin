/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:21:58 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/01/27 14:22:00 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	*ft_read_f(char *file)
{
	int		fd;
	int		i;
	char	*str;
	char	buf[21];

	str = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (read(fd, buf, 0) == -1)
		return (NULL);
	while ((i = read(fd, buf, 20)))
	{
		buf[i] = '\0';
		str = ft_strjoin_f1(str, (char *)buf);
	}
	return (str);
}

char	*ft_read_fd(int fd)
{
	int		i;
	char	*str;
	char	buf[21];

	str = ft_strdup("");
	if (read(fd, buf, 0) == -1)
		return (NULL);
	while ((i = read(fd, buf, 20)))
	{
		buf[i] = '\0';
		str = ft_strjoin_f1(str, (char *)buf);
	}
	return (str);
}
